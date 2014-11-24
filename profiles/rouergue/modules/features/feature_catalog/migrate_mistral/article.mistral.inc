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
 * GROUP BY a.articleid
 * ORDER BY a.articleid ASC

 */
class ArticleMigration extends Migration {
	// Universes <-> Collections/Subcollections/Series mapping data
	protected $univ_coll_mapping = array();
	
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
		->fields('b', array('title','subtitle','resume','backcover','projecttype'))
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
		$this->addFieldMapping('field_isbn', 'isbn');
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
		
		// COLLECTIONS---UNIVERSE MAPPING
		if (empty($this->univ_coll_mapping)) {
			//-------------------- Littérature --------------------
			$this->univ_coll_mapping['Rouergue Littérature']['La Brune'] = key(taxonomy_get_term_by_name('La Brune (littérature)'));
			$this->univ_coll_mapping['Rouergue Littérature']['Polar'] = key(taxonomy_get_term_by_name('Rouergue Noir'));
			// Two 'Romans de société' terms exist in 'Univers' vocabulary, here we need the first one.
			$tids = array_keys(taxonomy_get_term_by_name('Romans de société'));
			$this->univ_coll_mapping['Rouergue Littérature']['Roman de société'] = $tids[0];
			// TODO : Objet litéraire

			//-------------------- Art & Histoire --------------------
			$this->univ_coll_mapping['Rouergue Beaux Livres']['Société'] = key(taxonomy_get_term_by_name('Société'));
			$this->univ_coll_mapping['Rouergue Beaux Livres']['Histoire'] = key(taxonomy_get_term_by_name('Histoire'));
			$this->univ_coll_mapping['Rouergue Beaux Livres']['Art'] = key(taxonomy_get_term_by_name('Art'));

			//-------------------- Régions --------------------
// 			$this->univ_coll_mapping['collection']['subcollection']['Région'] = key(taxonomy_get_term_by_name('Régions de France'));
			// TODO : bouton manuel (drupal) Aveyron
			$this->univ_coll_mapping['Rouergue Beaux Livres']['Voyage'] = key(taxonomy_get_term_by_name('Voyages'));
			// TODO : comment répartir entre 'Rouergue en poche' et 'Grand format' ?

			//-------------------- Nature & Jardins --------------------
			// TODO : série Nature
			$this->univ_coll_mapping['Rouergue Beaux Livres']['Bx Livres Nature'] = key(taxonomy_get_term_by_name('Nature'));
// 			$this->univ_coll_mapping['collection']['subcollection']['Natures Humaines'] = key(taxonomy_get_term_by_name('Nature'));
// 			$this->univ_coll_mapping['collection']['subcollection']['Bâti'] = key(taxonomy_get_term_by_name('Bâti'));
// 			$this->univ_coll_mapping['collection']['subcollection']['Ecologie'] = key(taxonomy_get_term_by_name('Ecologie'));
// 			$this->univ_coll_mapping['collection']['subcollection']['Botanique'] = key(taxonomy_get_term_by_name('Botanique'));
// 			$this->univ_coll_mapping['collection']['subcollection']['Jardins'] = key(taxonomy_get_term_by_name('Jardins'));

			//-------------------- Gastronomie --------------------
			$this->univ_coll_mapping['Rouergue Beaux Livres']['Gastronomie'] = key(taxonomy_get_term_by_name('Grands chefs'));
			$this->univ_coll_mapping['Rouergue Livres Pratiques']['Cuisine'] = key(taxonomy_get_term_by_name('Cuisine'));
// 			$this->univ_coll_mapping['collection']['Vins'] = key(taxonomy_get_term_by_name('Vins'));
// 			$this->univ_coll_mapping['collection']['Santé'] = key(taxonomy_get_term_by_name('Santé'));

			//-------------------- Epik SF/Fantasy --------------------
			$this->univ_coll_mapping['Rouergue Romans Jeunesse']['Epik'] = key(taxonomy_get_term_by_name('Epik SF/Fantasy'));

			//-------------------- Romans jeunesse --------------------
			$this->univ_coll_mapping['Rouergue Romans Jeunesse']['tic tac'] = key(taxonomy_get_term_by_name('tic tac'));
			$this->univ_coll_mapping['Rouergue Romans Jeunesse']['Boomerang'] = key(taxonomy_get_term_by_name('Boomerang'));
			// Two 'A la petite semaine' terms exist in 'Univers' vocabulary, here we need the second one.
			$tids = array_keys(taxonomy_get_term_by_name('A la petite semaine'));
			$this->univ_coll_mapping['Rouergue Romans Jeunesse']['A la petite semaine'] = $tids[1];
			$this->univ_coll_mapping['Rouergue Romans Jeunesse']['Zig Zag'] = key(taxonomy_get_term_by_name('zig zag'));
			$this->univ_coll_mapping['Rouergue Romans Jeunesse']['dacOdac'] = key(taxonomy_get_term_by_name('dacOdac'));
			$this->univ_coll_mapping['Rouergue Romans Jeunesse']['DoAdo'] = key(taxonomy_get_term_by_name('DoAdo'));
			$this->univ_coll_mapping['Rouergue Romans Jeunesse']['DoAdo noir'] = key(taxonomy_get_term_by_name('DoAdo noir'));

			//-------------------- Albums jeunesse --------------------
			$this->univ_coll_mapping['Rouergue Albums Jeunesse']['12x12'] = key(taxonomy_get_term_by_name('12x12'));
			$this->univ_coll_mapping['Rouergue Albums Jeunesse']['Comptines en continu'] = key(taxonomy_get_term_by_name('Comptines en continu'));
			// TODO : lectorat 2 ans
			// TODO : lectorat 4ans
			// Two 'A la petite semaine' terms exist in 'Univers' vocabulary, here we get the first one.
			$tids = array_keys(taxonomy_get_term_by_name('A la petite semaine'));
			$this->univ_coll_mapping['Rouergue Albums Jeunesse']['A la petite semaine'] = key(taxonomy_get_term_by_name('A la petite semaine'));
			// TODO : lectorat 6 ans
			// TODO : Jeunesse

			//-------------------- Graphisme &  Illustrations --------------------
			// TODO : Collection Essai jeunesse ?
			$this->univ_coll_mapping['Rouergue Albums Jeunesse']['Livre graphique'] = key(taxonomy_get_term_by_name('Romans graphiques'));
			//$this->univ_coll_mapping['Rouergue Albums Jeunesse']['Livre graphique']['touzazimute'] = key(taxonomy_get_term_by_name('Toutazimute'));

			//-------------------- EPUB ? --------------------
			$this->univ_coll_mapping['NUM'] = key(taxonomy_get_term_by_name('Numérique'));
		}
	}

	/**
	 * Data handling before mapping.
	 */	
	function prepareRow($row) {
		parent::prepareRow($row);
		
		// Backcover text cleaning.
		$row->backcover = html_entity_decode(strip_tags($row->backcover));
		
		// Rouergue web site universe
		$row->collection = $this->rouergue_get_universe_term_id($row->projecttype, $row->collection, $row->subcollection, $row->series);
		
		if (empty($row->price_validated)) {
			$row->price_validated = 0;
		}
	}
	
	/**
	 * Data handling before node saving.
	 */
	function prepare($node, stdClass $row) {
		// Cover image
		$image_filename = 'test-cover-' . rand(1,4) . '.png'; // 	A REMPLACER PAR : $image_filename = $row->gencod . 'jpg';
		$host = 'http://www.korora.fr/'; // A REMPLACER PAR :	$host = 'http://www.lerouergue.fr/...';
		$url = $host . $image_filename;
	
		$file = system_retrieve_file($url, 'public://catalog/cover-images/' . $image_filename, TRUE, FILE_EXISTS_RENAME); // A REMPLACER PAR :	...FILE_EXISTS_REPLACE);
		$node->field_cover_image[LANGUAGE_NONE]['0']['fid'] = $file->fid;
	}
	
	/**
	 * Helper function handling matching between Mistral collection, subcollection, series classification
	 * and Rouergue web site Univers vocabulary.
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
	function rouergue_get_universe_term_id($projecttype, $collection, $subcollection, $series) {
		$term_id = 0;
		if ($projecttype == 'NUM') {
                	$term_id = $this->univ_coll_mapping[$projecttype];
        	}
		elseif (isset($series)) {
			$term_id = $this->univ_coll_mapping[$collection][$subcollection][$series];
		}
		else {
			$term_id = $this->univ_coll_mapping[$collection][$subcollection];
		}
		return $term_id;
	}
}
