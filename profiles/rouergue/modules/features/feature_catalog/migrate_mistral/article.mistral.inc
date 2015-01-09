<?php
/**
 * @file
 * Migrates articles, themes from Mistral.
 */

/**
 * Migration class for themes.
 *
 * We retrieve only themes linked to a importable article.
 * The mysql query to run is :
 *
 * SELECT DISTINCT t.themeid, t.name FROM theme t
 * JOIN booktheme bt ON bt.themeid=t.themeid
 * WHERE bt.bookid IN (
 *   SELECT a.bookid
 *   FROM `article` a
 *   JOIN priceandtirage pt ON pt.articleid=a.articleid and pt.isvalidated='1'
 *   JOIN realprice rp ON rp.articleid=a.articleid and rp.iscurrentprice='1'
 *   JOIN fabricationplan fp ON fp.articleid=a.articleid 
 *   JOIN format f ON f.formatid=fp.finalformatid
 *   GROUP BY a.articleid
 * )
 */
class ThemeMigration extends Migration {
	public function __construct() {
		parent::__construct();

		// DESCRIPTION
		$this->description = t('Migrate themes from mistral source database to Drupal Themes vocabulary');

		// SOURCE
		$subquery = Database::getConnection('default', 'mistral')->select('article','a');
		$subquery->join('priceandtirage','pt','pt.articleid=a.articleid AND pt.isvalidated=1');
		$subquery->join('realprice','r','r.articleid=a.articleid AND r.iscurrentprice=1');
		$subquery->join('fabricationplan','fp','fp.articleid=a.articleid');
		$subquery->join('format','f','f.formatid=fp.finalformatid');
		$subquery->fields('a', array('bookid'));
		
		$query = Database::getConnection('default', 'mistral')->select('theme','t');
		$query->join('booktheme','bt','t.themeid=bt.themeid');
		$query->fields('t', array('themeid','name'));
		$query->condition('bt.bookid', $subquery, 'IN');
		$query->distinct();

		$this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));

		// DESTINATION
		$this->destination = new MigrateDestinationTerm('themes');

		// MAP
		$this->map = new MigrateSQLMap(
				$this->machineName,
				array(
						'themeid' => array(
								'type' => 'int',
								'unsigned' => TRUE,
								'not null' => TRUE,
								'description' => 'Mistral theme ID',
								'alias' => 't'
						)
				),
				MigrateDestinationTerm::getKeySchema()
		);

		// FIELDS MAPPING
		$this->addFieldMapping('name', 'name');
	}
}

/**
 * Migration class for readerships.
 *
 * The mysql query to run is :
 *
 * SELECT readershipid, name 
 * FROM readership
 */
class ReadershipMigration extends Migration {
	public function __construct() {
		parent::__construct();

		// DESCRIPTION
		$this->description = t('Migrate readerships from mistral source database to Drupal Lectorat vocabulary');

		// SOURCE
		$query = Database::getConnection('default', 'mistral')->select('readership');
		$query->fields('readership', array('readershipid','name'));

		$this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));

		// DESTINATION
		$this->destination = new MigrateDestinationTerm('readership');

		// MAP
		$this->map = new MigrateSQLMap(
				$this->machineName,
				array(
						'readershipid' => array(
								'type' => 'int',
								'unsigned' => TRUE,
								'not null' => TRUE,
								'description' => 'Mistral readership ID',
						)
				),
				MigrateDestinationTerm::getKeySchema()
		);

		// FIELDS MAPPING
		$this->addFieldMapping('name', 'name');
	}
}

/**
 * Migration class for articles.
 *
 * The mysql query to run is :
 *
 * SELECT a.articleid, a.bookid, a.isbn13, a.gencod, b.title, b.subtitle, b.resume, b.backcover, 
 * c.name as collection, sc.name as subcollection, s.name as series, 
 * rp.price, fp.finalnbpage as nbpage,
 * pt.isvalidated as price_validated,
 * GROUP_CONCAT(bt.themeid) as theme_list, GROUP_CONCAT(DISTINCT br.readershipid) as readership_list, 
 * CONCAT(cp.year,'-',right(concat('0',cp.month),2),'-01') as pubdate,
 * CASE WHEN (fp.finalformatid IS NOT NULL AND fp.finalformatid>0) THEN f2.name ELSE f1.name END AS format
 * FROM `article` a
 * JOIN book b ON b.bookid=a.bookid
 * LEFT JOIN collection c ON c.collectionid=b.collectionid
 * LEFT JOIN subcollection sc ON sc.subcollectionid=b.subcollectionid
 * LEFT JOIN series s ON s.seriesid=b.seriesid
 * JOIN commercialplan cp ON cp.articleid=a.articleid
 * JOIN fabricationplan fp ON fp.articleid=a.articleid
 * JOIN priceandtirage pt ON pt.articleid=a.articleid
 * JOIN realprice rp ON rp.articleid=a.articleid and rp.iscurrentprice='1'
 * LEFT JOIN booktheme bt ON bt.bookid=a.bookid
 * LEFT JOIN bookreadership br ON br.bookid=b.bookid
 * JOIN format f1 ON f1.formatid=b.formatid
 * LEFT JOIN format f2 ON f2.formatid=fp.finalformatid
 * WHERE a.statusid <> 1
 * AND b.projecttype <> 'PLV'
 * GROUP BY a.articleid
 * ORDER BY a.articleid ASC

 */
class ArticleMigration extends Migration {
	// Universes <-> Collections/Subcollections/Series mapping data
	protected $univ_coll_mapping = array();
	
	protected $univ_tids = array();
	
  public function __construct(array $arguments) {
    $this->arguments = $arguments;
    parent::__construct();
		
		// DESCRIPTION.
		$this->description = t('Migrate articles from mistral source database to Drupal Article nodes');
		
		//$this->dependencies = array('Theme');
		
		// SOURCE
		$query = Database::getConnection('default', 'mistral')->select('article','a');
		$query->join('book', 'b', 'b.bookid = a.bookid');
		$query->leftJoin('collection', 'c', 'c.collectionid=b.collectionid');
		$query->leftJoin('subcollection', 'sc', 'sc.subcollectionid=b.subcollectionid');
		$query->leftJoin('series', 's', 's.seriesid=b.seriesid');
		$query->join('commercialplan','cp','cp.articleid=a.articleid');
		$query->join('fabricationplan', 'fp', 'fp.articleid = a.articleid');
		$query->join('priceandtirage','pt','pt.articleid=a.articleid');
		$query->join('realprice','rp','rp.articleid=a.articleid AND rp.iscurrentprice=1');
		$query->leftJoin('booktheme','bt','bt.bookid=b.bookid');
		$query->leftJoin('bookreadership','br','br.bookid=b.bookid');
		$query->join('format','f1','f1.formatid=b.formatid');
		$query->leftJoin('format','f2','f2.formatid=fp.finalformatid');
				
		$query
		->fields('a', array('articleid','bookid','isbn13','gencod'))
		->fields('b', array('title','subtitle','resume','backcover'))
		->fields('rp', array('price'));
    $query->addField('fp','finalnbpage','nbpage');
    $query->addField('c','name','collection');
    $query->addField('sc','name','subcollection');
    $query->addField('s','name','series');
    $query->addField('pt','isvalidated','price_validated');
		$query->addExpression('GROUP_CONCAT(bt.themeid)', 'theme_list');
		$query->addExpression('GROUP_CONCAT(DISTINCT br.readershipid)', 'readership_list');
		$query->addExpression("CONCAT(cp.year,'-',right(concat('0',cp.month),2),'-01')",'pubdate');
		$query->addExpression("CASE WHEN (fp.finalformatid IS NOT NULL AND fp.finalformatid>0) THEN f2.name ELSE f1.name END",'format');
		$query->condition('a.statusid','1','<>');
		$query->condition('b.projecttype','PLV','<>');
		$query->groupBy('a.articleid');
		$query->orderBy('a.articleid', 'ASC');
		
		$this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
		
		// DESTINATION
		$this->destination = new MigrateDestinationNode('article');
		
		// MAP
		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'articleid' => array(
					'type' => 'int',
					'unsigned' => TRUE,
					'not null' => TRUE,
					'alias' => 'a',
					'description' => 'Mistral article id.',	
				)
			),
			MigrateDestinationNode::getKeySchema()
		);
		
		// FIELDS MAPPING
		$this->addFieldMapping('field_mistral_articleid', 'articleid');
		$this->addFieldMapping('field_mistral_bookid', 'bookid');
		$this->addFieldMapping('title', 'title');
		$this->addFieldMapping('field_subtitle', 'subtitle');
		$this->addFieldMapping('field_format', 'format');
		$this->addFieldMapping('field_number_pages', 'nbpage');
		$this->addFieldMapping('field_price', 'price');
		$this->addFieldMapping('field_price_validated', 'price_validated');
		$this->addFieldMapping('field_isbn', 'isbn13');
		$this->addFieldMapping('field_gencod', 'gencod');
		$this->addFieldMapping('field_release_date', 'pubdate');
		$this->addFieldMapping('body', 'backcover');
		
		$this->addFieldMapping('field_themes', 'theme_list')
			->sourceMigration('Theme')
			->separator(',');
		$this->addFieldMapping('field_themes:source_type')->defaultValue('tid');
		
		$this->addFieldMapping('field_readership', 'readership_list')
			->sourceMigration('Readership')
			->separator(',');
		$this->addFieldMapping('field_readership:source_type')->defaultValue('tid');
		
		$this->addFieldMapping('field_universe', 'collection');
		$this->addFieldMapping('field_universe:source_type')->defaultValue('tid');
		
		// UNIVERSE TERMS IDS FETCHING
		if (empty($this->univ_tids)) {
			$this->rouergue_fetch_universe_terms_ids();
		}
		
		// COLLECTIONS---UNIVERSES MAPPING
		if (empty($this->univ_coll_mapping)) {
			$this->rouergue_set_mapping();			
		}
	}

	/**
	 * Data handling before mapping.
	 */	
	function prepareRow($row) {
		parent::prepareRow($row);
		
		// backcover or resume database field choice
		if (isset($row->backcover) && strlen($row->backcover) > 0) {
			$text = $row->backcover;
		}
		else {
			$text = $row->resume;
		}
		$row->backcover = html_entity_decode(strip_tags($text));
		
		// Rouergue universe granting based on Drupal universes/Mistral collections mapping.
		$row->collection = $this->rouergue_get_universe_term_id($row->collection, $row->subcollection, $row->series);
		
		if (empty($row->price_validated)) {
			$row->price_validated = 0;
		}
	}
	
	/**
	 * Data handling before node saving.
	 */
	function prepare($node, stdClass $row) {
		// Cover image
		//$image_filename = 'test-cover-' . rand(1,4) . '.png'; // 	A REMPLACER PAR : $image_filename = $row->gencod . 'jpg';
		$image_filename = $row->gencod . '.jpg';
		//$host = 'http://www.korora.fr/'; // A REMPLACER PAR :	$host = 'http://www.lerouergue.fr/...';
		//$host = 'http://rouergue.abrege.net/util/couv_rouergue/';
		$host = variable_get('cover_images_url','http://rouergue.abrege.net/util/couv_rouergue/');
		$url = $host . $image_filename;
	
		if(!$file = system_retrieve_file($url, 'public://catalog/cover-images/' . $image_filename, TRUE, FILE_EXISTS_REPLACE)) { // A REMPLACER PAR :	...FILE_EXISTS_REPLACE);
			$image_filename = variable_get('default_cover_image_name','article-cover-400x600.png');
			$url = $host . $image_filename;
			$file = system_retrieve_file($url, 'public://catalog/cover-images/' . $image_filename, TRUE, FILE_EXISTS_RENAME);
		}
		$node->field_cover_image[LANGUAGE_NONE]['0']['fid'] = $file->fid;
		
		if(!isset($row->collection) || $row->collection == 0) {
			watchdog('mistral', 'bookid = ' . $row->bookid . ', tid = ' . $row->collection);
		}
	}
	
	/**
	 * HELPER FUNCTIONS
	 */
	
	/**
	 * Builds the universe terms ids array, stored in $this->universe_tids.
	 */
	function rouergue_fetch_universe_terms_ids() {
		$voc = taxonomy_vocabulary_machine_name_load('universe');
		$tree = taxonomy_get_tree($voc->vid);
			
		$parents = array();
		$previous_depth = 0;
		foreach ($tree as $term) {
			if ($term->depth == 0) {
				$this->univ_tids[$term->name]['tid'] = $term->tid;
				$parents = array();
			}
			else {
				if($term->depth > $previous_depth) {
					array_push($parents, $previous_term);
				}
				elseif ($term->depth < $previous_depth) {
					array_pop($parents);
				}
				$this->rouergue_universes_insert($this->univ_tids, $parents, $term->name, $term->tid);
			}
			$previous_depth = $term->depth;
			$previous_term = $term->name;
		}
	}
	
	/**
	 * Inserts a term id in array $this->universe_tids.
	 * Used by previous function rouergue_fetch_universe_terms_ids().
	 * 
	 * @param array $array
	 *   The array storing terms ids.
	 * @param array $keys
	 *   An array containing the parent term names (from root to leaf).
	 * @param string $term
	 *   The term name whose tid is being stored.
	 * @param int $tid
	 *   The tid to store.
	 */
	function rouergue_universes_insert(&$array, $keys, $term, $tid) {
		foreach($keys as $key) {
			if(!array_key_exists($key, $array) || array_key_exists($key, $array) && !is_array($array[$key])) {
				$array[$key] = array();
			}
			$array = &$array[$key];
		}
		$array[$term]['tid'] = $tid;
	}
	
	/**
	 * Stores mapping between Mistral Collection/Subcollection/Series and Drupal Universes terms
	 * in array $this->univ_coll_mapping.
	 */
	function rouergue_set_mapping() {
		//-------------------- Numérique --------------------
		$this->univ_coll_mapping['ROUERGUE NUMERIQUE JEUNESSE']['dacOdac'] = $this->univ_tids['Numérique']['dacodac'];
		$this->univ_coll_mapping['ROUERGUE NUMERIQUE JEUNESSE']['dacOdac']['dacOdac illustrée'] = $this->univ_tids['Numérique']['dacodac'];
		$this->univ_coll_mapping['ROUERGUE NUMERIQUE JEUNESSE']['DoAdo'] = $this->univ_tids['Numérique']['doado'];
		$this->univ_coll_mapping['ROUERGUE NUMERIQUE JEUNESSE']['DoAdo noir'] = $this->univ_tids['Numérique']['doado noir'];
		$this->univ_coll_mapping['ROUERGUE NUMERIQUE JEUNESSE']['Epik'] = $this->univ_tids['Numérique']['epik'];
		
		$this->univ_coll_mapping['ROUERGUE NUMERIQUE TEXTE']['La Brune'] = $this->univ_tids['Numérique']['la brune'];
		$this->univ_coll_mapping['ROUERGUE NUMERIQUE TEXTE']['Polar'] = $this->univ_tids['Numérique']['polars'];
		$this->univ_coll_mapping['ROUERGUE NUMERIQUE TEXTE']['Roman de société (NUM)'] = $this->univ_tids['Numérique']['romans de société'];
		
		//-------------------- Beaux Livres --------------------
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Art (Rouergue Bx Livres)']['tid'] = $this->univ_tids['Art & Histoire']['art']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Art (Rouergue Bx Livres)']['Aveyron']['tid'] = $this->univ_tids['Art & Histoire']['art']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Art (Rouergue Bx Livres)']['Cuisine']['tid'] = $this->univ_tids['Art & Histoire']['art']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Art (Rouergue Bx Livres)']['Histoire']['tid'] = $this->univ_tids['Art & Histoire']['histoire']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Art (Rouergue Bx Livres)']['Nature']['tid'] = $this->univ_tids['Art & Histoire']['art']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Art (Rouergue Bx Livres)']['Société']['tid'] = $this->univ_tids['Art & Histoire']['art']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Aveyron (Rouergue Bx Lvres)']['tid'] = $this->univ_tids['Régions']['aveyron']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Aveyron (Rouergue Bx Lvres)']['Cuisine']['tid'] = $this->univ_tids['Régions']['aveyron']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Botanique (Rouergue Bx Lvres)']['tid'] = $this->univ_tids['Nature & Jardins']['botanique']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Gastronomie (Rouergue Bx Livres)']['Cuisine']['tid'] = $this->univ_tids['Gastronomie']['cuisine']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Gastronomie (Rouergue Bx Livres)']['Grand Chef']['tid'] = $this->univ_tids['Gastronomie']['grands chefs']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Gastronomie (Rouergue Bx Livres)']['Vins']['tid'] = $this->univ_tids['Gastronomie']['vins']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Histoire (Rouergue Bx Livres)']['tid'] = $this->univ_tids['Art & Histoire']['histoire']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Histoire (Rouergue Bx Livres)']['Aveyron']['tid'] = $this->univ_tids['Art & Histoire']['histoire']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Histoire (Rouergue Bx Livres)']['Jardins']['tid'] = $this->univ_tids['Nature & Jardins']['jardins']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Histoire (Rouergue Bx Livres)']['Région']['tid'] = $this->univ_tids['Art & Histoire']['histoire']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Histoire (Rouergue Bx Livres)']['Vins']['tid'] = $this->univ_tids['Art & Histoire']['histoire']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Histoire (Rouergue Bx Livres)']['Voyages']['tid'] = $this->univ_tids['Art & Histoire']['histoire']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Nature (Rouergue Bx Livres)']['Aveyron']['tid'] = $this->univ_tids['Régions']['aveyron']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Nature (Rouergue Bx Livres)']['Bati']['tid'] = $this->univ_tids['Nature & Jardins']['bâti']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Nature (Rouergue Bx Livres)']['Cuisine']['tid'] = $this->univ_tids['Nature & Jardins']['nature']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Nature (Rouergue Bx Livres)']['Jardins']['tid'] = $this->univ_tids['Nature & Jardins']['jardins']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Nature (Rouergue Bx Livres)']['Région']['tid'] = $this->univ_tids['Nature & Jardins']['nature']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Nature (Rouergue Bx Livres)']['Voyages']['tid'] = $this->univ_tids['Nature & Jardins']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Nature (Rouergue Bx Livres)']['tid'] = $this->univ_tids['Nature & Jardins']['nature']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Objet Littéraire']['Art']['tid'] = $this->univ_tids['Littérature']['objets littéraires']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Objet Littéraire']['Objet littéraire']['tid'] = $this->univ_tids['Littérature']['objets littéraires']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Polar']['tid'] = $this->univ_tids['Littérature']['polars']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Polar']['Voyages']['tid'] = $this->univ_tids['Littérature']['polars']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Région']['tid'] = $this->univ_tids['Régions']['régions de France']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Région']['Bati']['tid'] = $this->univ_tids['Nature & Jardins']['bâti']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Région']['Grand Chef']['tid'] = $this->univ_tids['Gastronomie']['grands chefs']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Région']['Histoire']['tid'] = $this->univ_tids['Art & Histoire']['histoire']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Santé']['tid'] = $this->univ_tids['Gastronomie']['santé']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Société']['tid'] = $this->univ_tids['Art & Histoire']['société']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Société']['Aveyron']['tid'] = $this->univ_tids['Art & Histoire']['société']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Société']['Cuisine']['tid'] = $this->univ_tids['Art & Histoire']['société']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Société']['Histoire']['tid'] = $this->univ_tids['Art & Histoire']['histoire']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Société']['Région']['tid'] = $this->univ_tids['Art & Histoire']['société']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Voyages']['tid'] = $this->univ_tids['Régions']['voyages']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Voyages']['Cuisine']['tid'] = $this->univ_tids['Gastronomie']['cuisine']['tid'];
		$this->univ_coll_mapping['Rouergue Beaux Livres']['Voyages']['Jardins']['tid'] = $this->univ_tids['Nature & Jardins']['jardins']['tid'];
		
		//-------------------- Littérature --------------------
		$this->univ_coll_mapping['Rouergue Littérature']['Aveyron (Rouergue Litté)']['tid'] = $this->univ_tids['Régions']['aveyron']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Aveyron (Rouergue Litté)']['Cuisine']['tid'] = $this->univ_tids['Régions']['aveyron']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Ecologie (Rouergue Littérature)']['Cuisine']['tid'] = $this->univ_tids['Nature & Jardins']['écologie']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['La Brune']['tid'] = $this->univ_tids['Littérature']['la brune']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Divers']['tid'] = $this->univ_tids['Littérature']['divers']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Objet littéraire (Rouergue Litté)']['tid'] = $this->univ_tids['Littérature']['objets littéraires']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Polar (Rouergue Litté)']['Assassins sans visage']['tid'] = $this->univ_tids['Littérature']['polars']['assassins sans visage']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Polar (Rouergue Litté)']['rouergue noir']['tid'] = $this->univ_tids['Littérature']['polars']['rouergue noir']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Roman de société']['tid'] = $this->univ_tids['Littérature']['romans de société']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Roman de société']['Témoignage']['tid'] = $this->univ_tids['Littérature']['romans de société']['témoignage']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Rouergue en Poche']['tid'] = $this->univ_tids['Littérature']['romans de société']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Témoignage (Rouergue Littérature)']['Aveyron']['tid'] = $this->univ_tids['Littérature']['romans de société']['témoignage']['tid'];
		$this->univ_coll_mapping['Rouergue Littérature']['Témoignage (Rouergue Littérature)']['Jardins']['tid'] = $this->univ_tids['Littérature']['romans de société']['témoignage']['tid'];
		
		//-------------------- Livres pratiques --------------------
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Aveyron']['Cuisine']['tid'] = $this->univ_tids['Gastronomie']['cuisine']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Aveyron']['tid'] = $this->univ_tids['Régions']['aveyron']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Botanique']['Aveyron']['tid'] = $this->univ_tids['Nature & Jardins']['botanique']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Botanique']['Jardins']['tid'] = $this->univ_tids['Nature & Jardins']['jardins']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Botanique']['Région']['tid'] = $this->univ_tids['Nature & Jardins']['botanique']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Botanique']['tid'] = $this->univ_tids['Nature & Jardins']['botanique']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Cuisine']['Jardins']['tid'] = $this->univ_tids['Gastronomie']['cuisine']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Cuisine']['Vins']['tid'] = $this->univ_tids['Gastronomie']['cuisine']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Ecologie (Rouergue Pratique)']['Bati']['tid'] = $this->univ_tids['Nature & Jardins']['bâti']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Ecologie (Rouergue Pratique)']['Jardins']['tid'] = $this->univ_tids['Nature & Jardins']['écologie']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Ecologie (Rouergue Pratique)']['tid'] = $this->univ_tids['Nature & Jardins']['écologie']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Gastronomie (Rouergue Pratique)']['Cuisine']['tid'] = $this->univ_tids['Gastronomie']['cuisine']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Gastronomie (Rouergue Pratique)']['Grand Chef']['tid'] = $this->univ_tids['Gastronomie']['grands chefs']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Nature (Rouergue Pratique)']['Jardins']['tid'] =  $this->univ_tids['Nature & Jardins']['jardins']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Nature (Rouergue Pratique)']['Région']['tid'] =  $this->univ_tids['Nature & Jardins']['nature']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Nature (Rouergue Pratique)']['tid'] =  $this->univ_tids['Nature & Jardins']['nature']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Région (Rouergue Pratique)']['Cuisine']['tid'] = $this->univ_tids['Gastronomie']['cuisine']['tid'];
		$this->univ_coll_mapping['Rouergue Livres Pratiques']['Santé (Rouergue Pratique)']['Cuisine']['tid'] = $this->univ_tids['Gastronomie']['cuisine']['tid'];
		
		//-------------------- Albums Jeunesse --------------------
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['tid'] = $this->univ_tids['Albums Jeunesse']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['12x12']['tid'] = $this->univ_tids['Albums Jeunesse']['albums dès 2 ans']['12x12']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['à la petite semaine']['tid'] = $this->univ_tids['Romans Jeunesse']['romans dès 8 ans']['à la petite semaine']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['albums (rouergue)']['tid'] = $this->univ_tids['Albums Jeunesse']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['albums (rouergue)']['album dès 2 ans']['tid'] = $this->univ_tids['Albums Jeunesse']['albums dès 2 ans']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['albums (rouergue)']['album dès 4 ans']['tid'] = $this->univ_tids['Albums Jeunesse']['albums dès 4 ans']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['albums (rouergue)']['album dès 6 ans']['tid'] = $this->univ_tids['Albums Jeunesse']['albums dès 6 ans']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['albums (rouergue)']["catalogue d'exposition"]['tid'] = $this->univ_tids['Albums Jeunesse']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['albums (rouergue)']['essais']['tid'] = $this->univ_tids['Albums Jeunesse']['albums dès 6 ans']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['comptines en continu']['tid'] = $this->univ_tids['Albums Jeunesse']['albums dès 2 ans']['comptines en continu']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['livre graphique']['roman graphique']['tid'] = $this->univ_tids['Graphisme & Illustrations']['romans graphiques']['tid'];
		$this->univ_coll_mapping['Rouergue Albums Jeunesse']['livre graphique']['touzazimute']['tid'] = $this->univ_tids['Graphisme & Illustrations']['toutazimute']['tid'];
		
		//-------------------- Essais Jeunesse --------------------
		$this->univ_coll_mapping['Rouergue Essai Jeunesse']['tid'] = $this->univ_tids['Graphisme & Illustrations']['essais']['tid'];
		
		//-------------------- Romans Jeunesse --------------------
		$this->univ_coll_mapping['Rouergue Romans Jeunesse']['tid'] = $this->univ_tids['Romans Jeunesse']['tid'];
		$this->univ_coll_mapping['Rouergue Romans Jeunesse']['boomerang']['tid'] = $this->univ_tids['Romans Jeunesse']['romans dès 7 ans']['boomerang']['tid'];
		$this->univ_coll_mapping['Rouergue Romans Jeunesse']['dacodac']['tid'] = $this->univ_tids['Romans Jeunesse']['romans dès 9 ans']['dacodac']['tid'];
		$this->univ_coll_mapping['Rouergue Romans Jeunesse']['doado']['tid'] = $this->univ_tids['Romans Jeunesse']['romans ados']['doado']['tid'];
		$this->univ_coll_mapping['Rouergue Romans Jeunesse']['doado noir']['tid'] = $this->univ_tids['Romans Jeunesse']['romans ados']['doado noir']['tid'];
		$this->univ_coll_mapping['Rouergue Romans Jeunesse']['epik']['tid'] = $this->univ_tids['Epik (Fantasy)']['tid'];
		$this->univ_coll_mapping['Rouergue Romans Jeunesse']['tic tac']['tid'] = $this->univ_tids['Romans Jeunesse']['romans dès 6 ans']['tic tac']['tid'];
		$this->univ_coll_mapping['Rouergue Romans Jeunesse']['zig zag']['tid'] = $this->univ_tids['Romans Jeunesse']['romans dès 8 ans']['zig zag']['tid'];
	}
	
	/**
	 * Returns universe term id that matches the Mistral's collection, subcollection, series values of row being imported.
	 *
	 * @param string $collection
	 *   The collection the imported book belongs to.
	 * @param string $subcollection
	 *   The subcollection the imported book belongs to.
	 * @param string $series
	 *   The series the imported book belongs to.
	 *
	 * @return
	 *   the tid of the Univers term the book has to be linked to.
	 */
	function rouergue_get_universe_term_id($collection, $subcollection, $series) {
		$term_id = 0;
		if (isset($series)) {
			$term_id = $this->univ_coll_mapping[$collection][$subcollection][$series]['tid'];
		}
		else if (isset($subcollection)) {
			$term_id = $this->univ_coll_mapping[$collection][$subcollection]['tid'];
		}
		else {
			$term_id = $this->univ_coll_mapping[$collection]['tid'];
		}
		return $term_id;
	}
}

