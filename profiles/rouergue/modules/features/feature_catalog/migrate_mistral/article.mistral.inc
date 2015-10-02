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
 *   -- JOIN format f ON f.formatid=fp.finalformatid
 *   GROUP BY a.articleid
 * )
 */
class ThemeMigration extends Migration {
	public function __construct($arguments) {
		parent::__construct($arguments);

		// DESCRIPTION
		$this->description = t('Migrate themes from mistral source database to Drupal Themes vocabulary');

		// SOURCE
		$subquery = Database::getConnection('default', 'mistral')->select('article','a');
		$subquery->join('priceandtirage','pt','pt.articleid=a.articleid AND pt.isvalidated=1');
		$subquery->join('realprice','r','r.articleid=a.articleid AND r.iscurrentprice=1');
		$subquery->join('fabricationplan','fp','fp.articleid=a.articleid');
		//$subquery->join('format','f','f.formatid=fp.finalformatid');
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
	public function __construct($arguments) {
		parent::__construct($arguments);

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
 * SELECT a.articleid, a.bookid, a.isbn13, a.gencod, b.title, b.subtitle, b.resume, b.backcover, b.height, b.width,
 * c.name as collection, sc.name as subcollection, s.name as series, 
 * rp.price, fp.finalnbpage as nbpage,
 * pt.isvalidated as price_validated,
 * GROUP_CONCAT(bt.themeid) as theme_list, GROUP_CONCAT(DISTINCT br.readershipid) as readership_list, 
 * CONCAT(cp.year,'-',right(concat('0',cp.month),2),'-01') as pubdate,
 * CASE WHEN (fp.finalformatid IS NOT NULL AND fp.finalformatid>0) THEN f2.name ELSE f1.name END AS format
 * FROM `article` a
 * JOIN book b ON b.bookid=a.bookid
 * ////// LEFT JOIN collection c ON c.collectionid=b.collectionid
 * ////// LEFT JOIN subcollection sc ON sc.subcollectionid=b.subcollectionid
 * ////// LEFT JOIN series s ON s.seriesid=b.seriesid
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
	
	protected $univ_uuids_tids = array();
	
  public function __construct(array $arguments) {
  	//$this->systemOfRecord = Migration::DESTINATION;
  	
    $this->arguments = $arguments;
    parent::__construct($arguments);
    
    $this->store = '';
    $this->cover_images_dir = '';
    $this->default_cover_image = '';
		
		// DESCRIPTION.
		$this->description = t('Migrate articles from mistral source database to Drupal Article nodes');
		
		//$this->dependencies = array('Theme');
		
		// SOURCE
		$query = Database::getConnection('default', 'mistral')->select('article','a');
		$query->join('book', 'b', 'b.bookid = a.bookid');
		// $query->leftJoin('collection', 'c', 'c.collectionid=b.collectionid');
		// $query->leftJoin('subcollection', 'sc', 'sc.subcollectionid=b.subcollectionid');
		// $query->leftJoin('series', 's', 's.seriesid=b.seriesid');
		//$query->join('commercialplan','cp','cp.articleid=a.articleid');
		$query->join('fabricationplan', 'fp', 'fp.articleid = a.articleid');
		$query->join('priceandtirage','pt','pt.articleid=a.articleid');
		$query->join('realprice','rp','rp.articleid=a.articleid AND rp.iscurrentprice=1');
		$query->leftJoin('booktheme','bt','bt.bookid=b.bookid');
		$query->leftJoin('bookreadership','br','br.bookid=b.bookid');
		//$query->join('format','f1','f1.formatid=b.formatid');
		//$query->leftJoin('format','f2','f2.formatid=fp.finalformatid');
				
		$query
		->fields('a', array('articleid','bookid','isbn13','gencod','statusid'))
		->fields('b', array('title','subtitle','collectionid','subcollectionid','seriesid','resume','backcover','height','width','firstpublicationdate'))
		->fields('rp', array('price'));
    $query->addField('fp','finalnbpage','nbpage');
    // $query->addField('c','name','collection');
    // $query->addField('sc','name','subcollection');
		// $query->addField('s','name','series');
    $query->addField('pt','isvalidated','price_validated');
		$query->addExpression('GROUP_CONCAT(bt.themeid)', 'theme_list');
		$query->addExpression('GROUP_CONCAT(DISTINCT br.readershipid)', 'readership_list');
		//$query->addExpression("CONCAT(cp.year,'-',right(concat('0',cp.month),2),'-01')",'pubdate');
		//$query->addExpression("CASE WHEN (fp.finalformatid IS NOT NULL AND fp.finalformatid>0) THEN f2.name ELSE f1.name END",'format');
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
		$this->addFieldMapping('field_mistral_status', 'statusid');		
		$this->addFieldMapping('title', 'title');
		$this->addFieldMapping('field_subtitle', 'subtitle');
		//$this->addFieldMapping('field_format', 'format');
		$this->addFieldMapping('field_number_pages', 'nbpage');
		$this->addFieldMapping('field_width', 'width');
		$this->addFieldMapping('field_height', 'height');
		$this->addFieldMapping('field_price', 'price');
		$this->addFieldMapping('field_price_validated', 'price_validated');
		$this->addFieldMapping('field_isbn', 'isbn13');
		$this->addFieldMapping('field_gencod', 'gencod');
		$this->addFieldMapping('field_release_date', 'firstpublicationdate');
		$this->addFieldMapping('body', 'backcover');
		
		$this->addFieldMapping('field_themes', 'theme_list')
			->sourceMigration('Theme')
			->separator(',');
		$this->addFieldMapping('field_themes:source_type')->defaultValue('tid');
		
		$this->addFieldMapping('field_readership', 'readership_list')
			->sourceMigration('Readership')
			->separator(',');
		$this->addFieldMapping('field_readership:source_type')->defaultValue('tid');
		
		$this->addFieldMapping('field_universe', 'collection')
			->separator(',');
		$this->addFieldMapping('field_universe:source_type')->defaultValue('tid');
		
		// UNIVERSE TERMS IDs FETCHING
		if (empty($this->univ_uuids_tids)) {
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
	  $row->backcover = html_entity_decode(strip_tags($text, '<b><i>'));

	  // First publication date handling.
	  $date_parts = explode('/', $row->firstpublicationdate);
	  $date_parts[0] = ($date_parts[0] < 10) ?  '0' . $date_parts[0] : $date_parts[0];
	  $row->firstpublicationdate = $date_parts[1] . '-' . $date_parts[0] . '-01';

		
	  // Rouergue universes. Attribution based on Drupal universes/Mistral collections mapping.
	  // $row->collection source data is used as container to stored the retrieved universe term ids.
	  $row->collection = $this->rouergue_get_universe_term_ids($row->collectionid, $row->subcollectionid, $row->seriesid);

	  if (empty($row->price_validated)) {
		  $row->price_validated = 0;
	  }
	  // Add a default time value of 02:00:00 to ISO date.
	  // Saved date will be 00:00:00 (02:00:00 minus 2 hours) during summer time period instead of 22:00:00,
	  // which corresponds to the last day of the previous month.
	  // and 01:00:00 (02:00:00 minus 1 hour) during winter time period instead of 23:00:00,
	  // which also corresponds to the last day of the previous month.
	  // This fixes the wrong pubdate's month display.
	  $row->pubdate = $row->pubdate . 'T02:00:00';
	}
	
	/**
	 * Data handling before node saving.
	 */
	function prepare($node, stdClass $row) {
		// Cover image		
		if ($this->store == '') {
			$this->store = rtrim(variable_get('rouergue_data_store', ''), '/') . '/';
		}
		if ($this->cover_images_dir == '') {
			$this->cover_images_dir = rtrim(variable_get('rouergue_cover_images_dir', 'catalog/cover-images'), '/') . '/';
		}
		$filename = $row->gencod . '.jpg';
		$cover_filename = $this->store . $this->cover_images_dir . $filename;
		
		if (!file_exists($cover_filename)) {
			if ($this->default_cover_image == '') {
				$this->default_cover_image = variable_get('rouergue_default_cover_image', 'article-cover-400x600.png');
			}
			$filename = $this->default_cover_image;
			$cover_filename = $this->store . $this->cover_images_dir . $filename;
		}
		
		if ($picture = file_get_contents($cover_filename)) {
			$file = file_save_data($picture, 'public://catalog/cover-images/' . $filename, FILE_EXISTS_REPLACE);
			if ($file) {
				$node->field_cover_image[LANGUAGE_NONE]['0']['fid'] = $file->fid;
			}
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
		
///////  Obsolete code, previously used to build universe vocabulary tree of names (to be kept, in case of).
// 		$tree = taxonomy_get_tree($voc->vid);
// 		$parents = array();
// 		$previous_depth = 0;
// 		foreach ($tree as $term) {
// 			if ($term->depth == 0) {
// 				$this->univ_tids[$term->name]['tid'] = $term->tid;
// 				$parents = array();
// 			}
// 			else {
// 				if($term->depth > $previous_depth) {
// 					array_push($parents, $previous_term);
// 				}
// 				elseif ($term->depth < $previous_depth) {
// 					array_pop($parents);
// 				}
// 				$this->rouergue_universes_insert($this->univ_tids, $parents, $term->name, $term->tid);
// 			}
// 			$previous_depth = $term->depth;
// 			$previous_term = $term->name;

		$query = new EntityFieldQuery();
		$query->entityCondition('entity_type', 'taxonomy_term');
		$query->propertyCondition('vid',$voc->vid);
		$result = $query->execute();
		
		$terms = entity_load('taxonomy_term', array_keys($result['taxonomy_term']));
		
		$terms_uuids_tids = array();
		foreach ($terms as $term) {
			$this->univ_uuids_tids[$term->uuid] = $term->tid;
		}
	}
	
	/**
	 * Inserts a term id in array $this->universe_tids.
	 * Used by previous version of function rouergue_fetch_universe_terms_ids().
	 * To be kept, in case of.
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
// 	function rouergue_universes_insert(&$array, $keys, $term, $tid) {
// 		foreach($keys as $key) {
// 			if(!array_key_exists($key, $array) || array_key_exists($key, $array) && !is_array($array[$key])) {
// 				$array[$key] = array();
// 			}
// 			$array = &$array[$key];
// 		}
// 		$array[$term]['tid'] = $tid;
// 	}
	
	/**
	 * Stores mapping between Mistral Collection/Subcollection/Series and Drupal Universes terms
	 * in array $this->univ_coll_mapping.
	 * 
	 * Mapping is based on uuid (Drupal side) and collectionid, subcollectionid, seriesid values instead of name values
	 * to prevent any name change, in Drupal as well as in Mistral, to break the mapping system.
	 * 
	 * Univers terms uuid values are displayed by the view 'Utils (Taxo)', display 'UUID des univers'.
	 * View url = /uuids-univers
	 * 
	 * And collectionid, subcollectionid, seriesid can be retrieved from mistral dump using the following sql query :
	 * 
	 * SELECT c.collectionid, c.name, sc.subcollectionid, sc.name, s.seriesid, s.name
	 * FROM collection c
	 * left join subcollection sc on sc.collectionid=c.collectionid
	 * left join series s on s.subcollectionid=sc.subcollectionid
	 * where c.name <> 'NE PAS UTILISER - ROUERGUE4'
	 * and c.name <> 'PLV'
	 * order by c.name asc, sc.name asc, s.name asc
	 */
	function rouergue_set_mapping() {
		//************************************************** Rouergue Albums Jeunesse ***********************************************************************
		// Rouergue Albums Jeunesse - 496 | 12x12 - 522   ===>   Albums jeunesse > Albums dès 2 ans > 12 x 12 - 01014525-94b0-414e-acd9-7ccc6eda4dc7
		$this->univ_coll_mapping['496']['522']['tids'] = $this->univ_uuids_tids['01014525-94b0-414e-acd9-7ccc6eda4dc7'];
		
		// Rouergue Albums Jeunesse - 496 | à la petite semaine - 571   ===>   Albums jeunesse > Albums dès 6 ans > à la petite semaine - 1875786a-6d12-4e8b-8786-a7dcc77cd95d
		// ----------------------------------------------------------   ===>   Romans jeunesse > Romans dès 8 ans > à la petite semaine - 3178b576-6073-4472-81ef-4c5c8edf9fb6
		$this->univ_coll_mapping['496']['571']['tids'] = 
			$this->univ_uuids_tids['1875786a-6d12-4e8b-8786-a7dcc77cd95d'] . ',' . $this->univ_uuids_tids['3178b576-6073-4472-81ef-4c5c8edf9fb6'];
		
		// Rouergue Albums Jeunesse - 496 | albums - 523 | album dès 2 ans - 154   ===>   Albums jeunesse > Albums dès 2 ans - c536a140-ecd1-4080-9e71-eb2977f5e55f
		$this->univ_coll_mapping['496']['523']['154']['tids'] = $this->univ_uuids_tids['c536a140-ecd1-4080-9e71-eb2977f5e55f'];
		
		// Rouergue Albums Jeunesse - 496 | albums - 523 | album dès 4 ans - 155   ===>   Albums jeunesse > Albums dès 4 ans  - 6f0d710e-3dd0-466b-9eb8-661c179170a9
		$this->univ_coll_mapping['496']['523']['155']['tids'] = $this->univ_uuids_tids['6f0d710e-3dd0-466b-9eb8-661c179170a9'];
		
		// Rouergue Albums Jeunesse - 496 | albums - 523 | album dès 6 ans - 156   ===>   Albums jeunesse > Albums dès 6 ans - 7f31083c-7346-459e-9ec5-f44936788c0e
		$this->univ_coll_mapping['496']['523']['156']['tids'] = $this->univ_uuids_tids['7f31083c-7346-459e-9ec5-f44936788c0e'];
		
		// Rouergue Albums Jeunesse - 496 | albums - 523 | catalogue d'exposition - 131   ===>   Graphisme & Illustrations > Catalogues d'exposition - e2c94656-1a56-402b-a016-81e7455633d2
		$this->univ_coll_mapping['496']['523']['131']['tids'] = $this->univ_uuids_tids['e2c94656-1a56-402b-a016-81e7455633d2'];
		
		// Rouergue Albums Jeunesse - 496 | albums - 523 | essais - 132   ===>   Graphisme & Illustrations > Essais - 53c9815b-ac19-4b74-8abb-a727270582bd
		$this->univ_coll_mapping['496']['523']['132']['tids'] = $this->univ_uuids_tids['53c9815b-ac19-4b74-8abb-a727270582bd'];
		
		// Rouergue Albums Jeunesse - 496 | comptines en continu - 524   ===>   Albums jeunesse > Albums dès 2 ans > comptines en continu - 904edf51-1d02-40a7-bfc4-54004970a09a
		$this->univ_coll_mapping['496']['524']['tids'] = $this->univ_uuids_tids['904edf51-1d02-40a7-bfc4-54004970a09a'];
		
		// Rouergue Albums Jeunesse - 496 | livre graphique - 525 | roman graphique - 133   ===>   Graphisme & Illustrations > Romans graphiques - e0e69acb-e53c-41af-bcbb-085df9bd1cf9
		$this->univ_coll_mapping['496']['525']['133']['tids'] = $this->univ_uuids_tids['e0e69acb-e53c-41af-bcbb-085df9bd1cf9'];
		
		// Rouergue Albums Jeunesse - 496 | livre graphique - 525 | touzazimute - 134   ===>   Graphisme & Illustrations > Touzazimute - 75291089-f665-47fc-96c5-eba17480b851
		$this->univ_coll_mapping['496']['525']['134']['tids'] = $this->univ_uuids_tids['75291089-f665-47fc-96c5-eba17480b851'];
		
		//************************************************** Rouergue Beaux Livres **************************************************************************
		// Rouergue Beaux Livres  - 495 | Art - 512   ===>  Art & Histoire  > Art - 9e65659d-3259-480c-a3f6-5fb69acef58a
		$this->univ_coll_mapping['495']['512']['tids'] = $this->univ_uuids_tids['9e65659d-3259-480c-a3f6-5fb69acef58a'];
		
		// Rouergue Beaux Livres  - 495 | Art - 512 | Aveyron - 99  ===>   Art & Histoire > Art - 9e65659d-3259-480c-a3f6-5fb69acef58a
		// -------------------------------------------------------  ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		$this->univ_coll_mapping['495']['512']['99']['tids'] = 
			$this->univ_uuids_tids['9e65659d-3259-480c-a3f6-5fb69acef58a'] . ',' . $this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'];
		
		// Rouergue Beaux Livres  - 495 | Art - 512 | Cuisine - 100  ===>   Art & Histoire > Art - 9e65659d-3259-480c-a3f6-5fb69acef58a
		// --------------------------------------------------------  ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['495']['512']['100']['tids'] = 
			$this->univ_uuids_tids['9e65659d-3259-480c-a3f6-5fb69acef58a'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];

		// Rouergue Beaux Livres  - 495 | Art - 512 | Histoire - 101  ===>   Art & Histoire > Art - 9e65659d-3259-480c-a3f6-5fb69acef58a
		// ---------------------------------------------------------  ===>  Art & Histoire > Histoire - 2a9aceff-4613-4b1e-aa0b-f902a13b6f81
		$this->univ_coll_mapping['495']['512']['101']['tids'] = 
			$this->univ_uuids_tids['9e65659d-3259-480c-a3f6-5fb69acef58a'] . ',' . $this->univ_uuids_tids['2a9aceff-4613-4b1e-aa0b-f902a13b6f81'];
		
		// Rouergue Beaux Livres  - 495 | Art - 512 | Nature - 102  ===>   Art & Histoire > Art - 9e65659d-3259-480c-a3f6-5fb69acef58a
		// -------------------------------------------------------  ===>   Nature & Jardins > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		$this->univ_coll_mapping['495']['512']['102']['tids'] = 
			$this->univ_uuids_tids['9e65659d-3259-480c-a3f6-5fb69acef58a'] . ',' . $this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'];

		// Rouergue Beaux Livres  - 495 | Art - 512 | Société - 103  ===>   Art & Histoire > Art - 9e65659d-3259-480c-a3f6-5fb69acef58a
		// --------------------------------------------------------  ===>   Art & Histoire > Société - a34c3c50-a9d8-4c67-81d3-b64581938481
		$this->univ_coll_mapping['495']['512']['103']['tids'] = 
			$this->univ_uuids_tids['9e65659d-3259-480c-a3f6-5fb69acef58a'] . ',' . $this->univ_uuids_tids['a34c3c50-a9d8-4c67-81d3-b64581938481'];
		
		// Rouergue Beaux Livres  - 495 | Aveyron - 1130  ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		$this->univ_coll_mapping['495']['1130']['tids'] = $this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'];
		
		// Rouergue Beaux Livres  - 495 | Aveyron - 1130 | Cuisine - 104  ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		// -------------------------------------------------------------  ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['495']['1130']['104']['tids'] = 
			$this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Beaux Livres  - 495 | Bâti - 1158   ===>  Nature & Jardin > Bâti - 287736de-2aeb-48bd-a91d-5510b786ccaf
		$this->univ_coll_mapping['495']['1158']['tids'] = $this->univ_uuids_tids['287736de-2aeb-48bd-a91d-5510b786ccaf'];
		
		// Rouergue Beaux Livres  - 495 | Botanique - 1131   ===>  Nature & Jardins > Botanique - 48169487-b368-480b-83a4-46ddb4205188
		$this->univ_coll_mapping['495']['1131']['tids'] = $this->univ_uuids_tids['48169487-b368-480b-83a4-46ddb4205188'];
		
		// Rouergue Beaux Livres  - 495 | Ecologie - 1157   ===> Nature & Jardin > Écologie - 80df7f9b-4f8b-47eb-89c7-2da7ff929d20
		$this->univ_coll_mapping['495']['1157']['tids'] = $this->univ_uuids_tids['80df7f9b-4f8b-47eb-89c7-2da7ff929d20'];
		
		// Rouergue Beaux Livres  - 495 | Jardin - 1156   ===> Nature & Jardin > Jardin - 7bf1968c-cf26-4fe6-a839-f70abf339851
		$this->univ_coll_mapping['495']['1156']['tids'] = $this->univ_uuids_tids['7bf1968c-cf26-4fe6-a839-f70abf339851'];
		
		// Rouergue Beaux Livres  - 495 | Nature - 513   ===>   Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		$this->univ_coll_mapping['495']['513']['tids'] = $this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'];
		
		// Rouergue Beaux Livres  - 495 | Gastronomie - 515 | Cuisine - 105   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['495']['515']['105']['tids'] = $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Beaux Livres  - 495 | Gastronomie - 515 | Grand Chef - 106   ===>   Gastronomie > Grands Chefs - 557341af-5bdc-4f6f-8a24-a368f78c524b
		$this->univ_coll_mapping['495']['515']['106']['tids'] = $this->univ_uuids_tids['557341af-5bdc-4f6f-8a24-a368f78c524b'];
		
		// Rouergue Beaux Livres  - 495 | Gastronomie - 515 | Vins - 107   ===>   Gastronomie > Vins - c838c944-79ea-4767-be9b-f66f87756c86
		$this->univ_coll_mapping['495']['515']['107']['tids'] = $this->univ_uuids_tids['c838c944-79ea-4767-be9b-f66f87756c86'];
		
		// Rouergue Beaux Livres  - 495 | Histoire - 1132   ===>   Art & Histoire > Histoire - 2a9aceff-4613-4b1e-aa0b-f902a13b6f81
		$this->univ_coll_mapping['495']['1132']['tids'] = $this->univ_uuids_tids['2a9aceff-4613-4b1e-aa0b-f902a13b6f81'];
		
		// Rouergue Beaux Livres  - 495 | Histoire - 1132 | Aveyron - 108   ===>   Art & Histoire > Histoire - 2a9aceff-4613-4b1e-aa0b-f902a13b6f81
		// ---------------------------------------------------------------  ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		$this->univ_coll_mapping['495']['1132']['108']['tids'] = 
			$this->univ_uuids_tids['2a9aceff-4613-4b1e-aa0b-f902a13b6f81'] . ',' . $this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'];
		
		// Rouergue Beaux Livres  - 495 | Histoire - 1132 | Jardins - 109   ===>   Art & Histoire > Histoire - 2a9aceff-4613-4b1e-aa0b-f902a13b6f81
		// ---------------------------------------------------------------  ===>   Nature & Jardin > Jardin - 7bf1968c-cf26-4fe6-a839-f70abf339851
		$this->univ_coll_mapping['495']['1132']['109']['tids'] = 
			$this->univ_uuids_tids['2a9aceff-4613-4b1e-aa0b-f902a13b6f81'] . ',' . $this->univ_uuids_tids['7bf1968c-cf26-4fe6-a839-f70abf339851'];
		
		// Rouergue Beaux Livres  - 495 | Histoire - 1132 | Région - 110   ===>   Art & Histoire > Histoire - 2a9aceff-4613-4b1e-aa0b-f902a13b6f81
		// -------------------------------------------------------------   ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		$this->univ_coll_mapping['495']['1132']['110']['tids'] = 
			$this->univ_uuids_tids['2a9aceff-4613-4b1e-aa0b-f902a13b6f81'] . ',' . $this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'];
		
		// Rouergue Beaux Livres  - 495 | Histoire - 1132 | Vins - 111   ===>   Art & Histoire > Histoire - 2a9aceff-4613-4b1e-aa0b-f902a13b6f81
		// -----------------------------------------------------------   ===>   Gastronomie > Vins - c838c944-79ea-4767-be9b-f66f87756c86
		$this->univ_coll_mapping['495']['1132']['111']['tids'] = 
			$this->univ_uuids_tids['2a9aceff-4613-4b1e-aa0b-f902a13b6f81'] . ',' . $this->univ_uuids_tids['c838c944-79ea-4767-be9b-f66f87756c86'];
		
		// Rouergue Beaux Livres  - 495 | Histoire - 1132 | Voyages - 112   ===>   Art & Histoire > Histoire - 2a9aceff-4613-4b1e-aa0b-f902a13b6f81
		// --------------------------------------------------------------   ===>   Régions > Voyages - 8148f50e-ef2e-497c-b285-efe2dd258ff3
		$this->univ_coll_mapping['495']['1132']['112']['tids'] = 
			$this->univ_uuids_tids['2a9aceff-4613-4b1e-aa0b-f902a13b6f81'] . ',' . $this->univ_uuids_tids['8148f50e-ef2e-497c-b285-efe2dd258ff3'];
		
		// Rouergue Beaux Livres  - 495 | Nature - 1133 | Aveyron - 113   ===>   Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		// ------------------------------------------------------------   ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		$this->univ_coll_mapping['495']['1133']['113']['tids'] = 
			$this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'] . ',' . $this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'];
		
		// Rouergue Beaux Livres  - 495 | Nature - 1133 | Bati - 114   ===> Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		// ---------------------------------------------------------   ===>  Nature & Jardin > Bâti - 287736de-2aeb-48bd-a91d-5510b786ccaf
		$this->univ_coll_mapping['495']['1133']['114']['tids'] = 
			$this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'] . ',' . $this->univ_uuids_tids['287736de-2aeb-48bd-a91d-5510b786ccaf'];
		
		// Rouergue Beaux Livres  - 495 | Nature - 1133 | Cuisine - 115   ===>   Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		// ------------------------------------------------------------   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['495']['1133']['115']['tids'] = 
			$this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Beaux Livres  - 495 | Nature - 1133 | Jardins - 116   ===>   Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		// ------------------------------------------------------------   ===>   Nature & Jardin > Jardin - 7bf1968c-cf26-4fe6-a839-f70abf339851
		$this->univ_coll_mapping['495']['1133']['116']['tids'] = 
			$this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'] . ',' . $this->univ_uuids_tids['7bf1968c-cf26-4fe6-a839-f70abf339851'];
		
		// Rouergue Beaux Livres  - 495 | Nature - 1133 | Région - 117   ===>   Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		// ------------------------------------------------------------   ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		$this->univ_coll_mapping['495']['1133']['117']['tids'] = 
			$this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'] . ',' . $this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'];
		
		// Rouergue Beaux Livres  - 495 | Nature - 1133 | Voyages - 118   ===>   Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		// ------------------------------------------------------------   ===>   Régions  > Voyages - 8148f50e-ef2e-497c-b285-efe2dd258ff3
		$this->univ_coll_mapping['495']['1133']['118']['tids'] = 
			$this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'] . ',' . $this->univ_uuids_tids['8148f50e-ef2e-497c-b285-efe2dd258ff3'];
		
		// Rouergue Beaux Livres  - 495 | Objet Littéraire - 1134   ===>   Littérature - bff581ca-2883-4ec8-9e83-917be1285f49
		$this->univ_coll_mapping['495']['1134']['tids'] = $this->univ_uuids_tids['bff581ca-2883-4ec8-9e83-917be1285f49'];
			
		// Rouergue Beaux Livres  - 495 | Objet Littéraire - 1134 | Art - 119   ===>   Littérature > Objets littéraires - 88728848-477d-401c-8d67-287baaaad668
		// ------------------------------------------------------------------   ===>   Art & Histoire > Art - 9e65659d-3259-480c-a3f6-5fb69acef58a
		$this->univ_coll_mapping['495']['1134']['119']['tids'] = 
			$this->univ_uuids_tids['88728848-477d-401c-8d67-287baaaad668'] . ',' . $this->univ_uuids_tids['9e65659d-3259-480c-a3f6-5fb69acef58a'];
		
		// Rouergue Beaux Livres  - 495 | Polar - 1135   ===>   Littérature > Polars - 63ed8920-edfe-4b4e-ae83-6cafb9fd9673
		$this->univ_coll_mapping['495']['1135']['tids'] = $this->univ_uuids_tids['63ed8920-edfe-4b4e-ae83-6cafb9fd9673'];
		
		// Rouergue Beaux Livres  - 495 | Polar - 1135 | Voyages - 160   ===>   Littérature > Polars - 63ed8920-edfe-4b4e-ae83-6cafb9fd9673
		// ----------------------------------------------------------    ===>   Régions > Voyages - 8148f50e-ef2e-497c-b285-efe2dd258ff3
		$this->univ_coll_mapping['495']['1135']['160']['tids'] = 
			$this->univ_uuids_tids['63ed8920-edfe-4b4e-ae83-6cafb9fd9673'] . ',' . $this->univ_uuids_tids['63ed8920-edfe-4b4e-ae83-6cafb9fd9673'];
		
		// Rouergue Beaux Livres  - 495 | Région - 1136   ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		$this->univ_coll_mapping['495']['1136']['tids'] = $this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'];
		
		// Rouergue Beaux Livres  - 495 | Région - 1136 | Bati - 121   ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		// ---------------------------------------------------------   ===>   Nature & Jardin > Bâti - 287736de-2aeb-48bd-a91d-5510b786ccaf
		$this->univ_coll_mapping['495']['1136']['121']['tids'] = 
			$this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'] . ',' . $this->univ_uuids_tids['287736de-2aeb-48bd-a91d-5510b786ccaf'];
		
		// Rouergue Beaux Livres  - 495 | Région - 1136 | Grand Chef - 122   ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		// ---------------------------------------------------------------   ===>   Gastronomie > Grands Chefs - 557341af-5bdc-4f6f-8a24-a368f78c524b
		$this->univ_coll_mapping['495']['1136']['122']['tids'] = 
			$this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'] . ',' . $this->univ_uuids_tids['557341af-5bdc-4f6f-8a24-a368f78c524b'];
		
		// Rouergue Beaux Livres  - 495 | Région - 1136 | Histoire - 123   ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		// -------------------------------------------------------------   ===>   Art & Histoire > Histoire - 2a9aceff-4613-4b1e-aa0b-f902a13b6f81
		$this->univ_coll_mapping['495']['1136']['123']['tids'] = 
			$this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'] . ',' . $this->univ_uuids_tids['2a9aceff-4613-4b1e-aa0b-f902a13b6f81'];
		
		// Rouergue Beaux Livres  - 495 | Santé - 1137   ===>   Gastronomie > Santé - 85b490bb-bfae-46e2-9a1f-130057789068
		$this->univ_coll_mapping['495']['1137']['tids'] = $this->univ_uuids_tids['85b490bb-bfae-46e2-9a1f-130057789068'];
		
		// Rouergue Beaux Livres  - 495 | Société - 517   ===>   Art & Histoire > Société - a34c3c50-a9d8-4c67-81d3-b64581938481
		$this->univ_coll_mapping['495']['517']['tids'] = $this->univ_uuids_tids['a34c3c50-a9d8-4c67-81d3-b64581938481'];
		
		// Rouergue Beaux Livres  - 495 | Société - 517 | Aveyron - 124   ===>   Art & Histoire > Société - a34c3c50-a9d8-4c67-81d3-b64581938481
		// ------------------------------------------------------------   ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		$this->univ_coll_mapping['495']['517']['124']['tids'] = 
			$this->univ_uuids_tids['a34c3c50-a9d8-4c67-81d3-b64581938481'] . ',' . $this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'];
		
		// Rouergue Beaux Livres  - 495 | Société - 517 | Cuisine - 125   ===>   Art & Histoire > Société - a34c3c50-a9d8-4c67-81d3-b64581938481
		// ------------------------------------------------------------   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['495']['517']['125']['tids'] = 
			$this->univ_uuids_tids['a34c3c50-a9d8-4c67-81d3-b64581938481'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Beaux Livres  - 495 | Société - 517 | Histoire - 126   ===>   Art & Histoire > Société - a34c3c50-a9d8-4c67-81d3-b64581938481
		// -------------------------------------------------------------   ===>   Art & Histoire > Histoire - 2a9aceff-4613-4b1e-aa0b-f902a13b6f81
		$this->univ_coll_mapping['495']['517']['126']['tids'] = 
			$this->univ_uuids_tids['a34c3c50-a9d8-4c67-81d3-b64581938481'] . ',' . $this->univ_uuids_tids['2a9aceff-4613-4b1e-aa0b-f902a13b6f81'];
		
		// Rouergue Beaux Livres  - 495 | Société - 517 | Région - 127   ===>   Art & Histoire > Société - a34c3c50-a9d8-4c67-81d3-b64581938481
		// -----------------------------------------------------------   ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		$this->univ_coll_mapping['495']['517']['127']['tids'] = 
			$this->univ_uuids_tids['a34c3c50-a9d8-4c67-81d3-b64581938481'] . ',' . $this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'];
		
		// Rouergue Beaux Livres  - 495 | Voyages - 518  ===>   Régions > Voyages - 8148f50e-ef2e-497c-b285-efe2dd258ff3
		$this->univ_coll_mapping['495']['518']['tids'] = $this->univ_uuids_tids['8148f50e-ef2e-497c-b285-efe2dd258ff3'];
		
		// Rouergue Beaux Livres  - 495 | Voyages - 518 | Cuisine - 128   ===>   Régions > Voyages - 8148f50e-ef2e-497c-b285-efe2dd258ff3
		// ------------------------------------------------------------   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['495']['518']['128']['tids'] = 
			$this->univ_uuids_tids['8148f50e-ef2e-497c-b285-efe2dd258ff3'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Beaux Livres  - 495 | Voyages - 518 | Jardins - 130   ===>   Régions > Voyages - 8148f50e-ef2e-497c-b285-efe2dd258ff3
		// ------------------------------------------------------------   ===>   Nature & Jardin > Jardin - 7bf1968c-cf26-4fe6-a839-f70abf339851
		$this->univ_coll_mapping['495']['518']['130']['tids'] = 
			$this->univ_uuids_tids['8148f50e-ef2e-497c-b285-efe2dd258ff3'] . ',' . $this->univ_uuids_tids['7bf1968c-cf26-4fe6-a839-f70abf339851'];
		
		//************************************************** Rouergue Essai Jeunesse ************************************************************************
		// Rouergue Essai Jeunesse - 606   ===>   Graphisme & Illustrations > Essais - 53c9815b-ac19-4b74-8abb-a727270582bd
		$this->univ_coll_mapping['606']['tids'] = $this->univ_uuids_tids['53c9815b-ac19-4b74-8abb-a727270582bd'];
		
		//************************************************** Rouergue Littérature ***************************************************************************
		// Rouergue Littérature - 493 | Aveyron - 1139   ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		$this->univ_coll_mapping['493']['1139']['tids'] = $this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'];
		
		// Rouergue Littérature - 493 | Aveyron - 1139 | Cuisine - 135   ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		// ------------------------------------------------------------  ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['493']['1139']['135']['tids'] = 
			$this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Littérature - 493 | Cuisine - 1152   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		// -------------------------------------------   ===>   Littérature > Objet littéraire - 88728848-477d-401c-8d67-287baaaad668
		$this->univ_coll_mapping['493']['1152']['tids'] = 
			$this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'] . ',' . $this->univ_uuids_tids['88728848-477d-401c-8d67-287baaaad668'];
		
		// Rouergue Littérature - 493 | Ecologie - 1149 | Cuisine - 135   ===>   Nature & Jardin > Écologie - 80df7f9b-4f8b-47eb-89c7-2da7ff929d20
		// ------------------------------------------------------------   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['493']['1149']['135']['tids'] = 
			$this->univ_uuids_tids['80df7f9b-4f8b-47eb-89c7-2da7ff929d20'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Littérature - 493 | La Brune - 509   ===>   Littérature > La brune - aba0e77d-4004-47d1-83aa-0dcc982091ba
		// -------------------------------------------   ===>   La Brune - 1cc5d1ae-4297-4a31-bc83-ec57da26f285
		$this->univ_coll_mapping['493']['509']['tids'] = 
		$this->univ_uuids_tids['aba0e77d-4004-47d1-83aa-0dcc982091ba'] . ',' . $this->univ_uuids_tids['1cc5d1ae-4297-4a31-bc83-ec57da26f285'];
		
		// Rouergue Littérature - 493 | Objet littéraire - 1140   ===>   Littérature - bff581ca-2883-4ec8-9e83-917be1285f49
		$this->univ_coll_mapping['493']['1140']['tids'] = $this->univ_uuids_tids['bff581ca-2883-4ec8-9e83-917be1285f49'];
		
		// Rouergue Littérature - 493 | Objet littéraire - 1140 | Cuisine - 161   ===>   Littérature > Objets littéraires - 88728848-477d-401c-8d67-287baaaad668
		// --------------------------------------------------------------------   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['493']['1140']['161']['tids'] = 
			$this->univ_uuids_tids['88728848-477d-401c-8d67-287baaaad668'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Littérature - 493 | Polars - 510   ===>   Littérature > Polars - 63ed8920-edfe-4b4e-ae83-6cafb9fd9673
		$this->univ_coll_mapping['493']['510']['tids'] = $this->univ_uuids_tids['63ed8920-edfe-4b4e-ae83-6cafb9fd9673'];
		
		// Rouergue Littérature - 493 | Polars - 510 | Assassins sans visage - 136   ===>   Littérature > Polars > assassins sans visage- 6332356c-9e6d-4c86-b14f-c39fbd7352e1
		$this->univ_coll_mapping['493']['510']['136']['tids'] = $this->univ_uuids_tids['6332356c-9e6d-4c86-b14f-c39fbd7352e1'];
		
		// Rouergue Littérature - 493 | Polars - 510 | Rouergue noir - 137   ===>   Littérature > Polars > rouergue noir - 0007e2ce-750f-4ef6-a648-3b465add8036
		$this->univ_coll_mapping['493']['510']['137']['tids'] = $this->univ_uuids_tids['0007e2ce-750f-4ef6-a648-3b465add8036'];
		
		// Rouergue Littérature - 493 | Roman de société - 511   ===>   Littérature > Romans - c27add62-baf4-45de-b445-27d7fef13a4f

		//$this->univ_coll_mapping['493']['511']['tids'] = $this->univ_uuids_tids['c27add62-baf4-45de-b445-27d7fef13a4f'];
		
		// Rouergue Littérature - 493 | Roman de société - 511 | Témoignage - 138   ===>   Littérature > Romans > Témoignages - f4654d87-9e93-4505-b1b2-01d4b537edfe
		//  ---------------------------------------------------------------------   ===>   Région > Romans > Témoignages - d8f5d9a9-3965-44cf-a713-96533e493197
		$this->univ_coll_mapping['493']['511']['138']['tids'] =
			$this->univ_uuids_tids['f4654d87-9e93-4505-b1b2-01d4b537edfe'] . ',' . $this->univ_uuids_tids['d8f5d9a9-3965-44cf-a713-96533e493197'];

		// EN ATTENTE DE LA SERIE MISTRAL GRAND FORMAT
		// Rouergue Littérature - 493 | Roman de société - 511 | Grand format - 244 ===>   Littérature > Romans > Grand format - 58df9ecd-f479-4da4-ae71-da888aaaecd4
		//  ---------------------------------------------------------------------   ===>   Région > Romans > Grand format - 5d89969d-47af-4c0d-a22b-589fb6ea57a2
		$this->univ_coll_mapping['493']['511']['244']['tids'] =
		$this->univ_uuids_tids['58df9ecd-f479-4da4-ae71-da888aaaecd4'] . ',' . $this->univ_uuids_tids['5d89969d-47af-4c0d-a22b-589fb6ea57a2'];			
		
		// Rouergue Littérature - 493 | Rouergue en Poche - 943   ===>   Littérature > Romans > Rouergue en poche -  8f6cfb5a-e21d-4afe-9b75-389addf70654
		//  ----------------------------------------------------  ===>   Région > Romans > Rouergue en poche - 322aa47f-7585-4688-b4ee-08e83eca5d28		
		$this->univ_coll_mapping['493']['943']['tids'] =
			$this->univ_uuids_tids['8f6cfb5a-e21d-4afe-9b75-389addf70654'] . ',' . $this->univ_uuids_tids['322aa47f-7585-4688-b4ee-08e83eca5d28'];
		
		// Rouergue Littérature - 493 | Témoignage - 1141 | Aveyron - 139   ===>   Littérature > Romans > Témoignages - f4654d87-9e93-4505-b1b2-01d4b537edfe
		// --------------------------------------------------------------   ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		// --------------------------------------------------------------   ===>   Région > Romans > Témoignages - d8f5d9a9-3965-44cf-a713-96533e493197

		$this->univ_coll_mapping['493']['1141']['139']['tids'] = 
			$this->univ_uuids_tids['f4654d87-9e93-4505-b1b2-01d4b537edfe'] . ',' . $this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'] . ',' . $this->univ_uuids_tids['d8f5d9a9-3965-44cf-a713-96533e493197'];
		
		// Rouergue Littérature - 493 | Témoignage - 1141 | Jardins - 159   ===>   Littérature > Romans  > Témoignages - f4654d87-9e93-4505-b1b2-01d4b537edfe
		// --------------------------------------------------------------   ===>   Nature & Jardin > Jardin - 7bf1968c-cf26-4fe6-a839-f70abf339851
		// --------------------------------------------------------------   ===>   Région > Romans > Témoignages - d8f5d9a9-3965-44cf-a713-96533e493197

		$this->univ_coll_mapping['493']['1141']['159']['tids'] = 
			$this->univ_uuids_tids['f4654d87-9e93-4505-b1b2-01d4b537edfe'] . ',' . $this->univ_uuids_tids['7bf1968c-cf26-4fe6-a839-f70abf339851'] . ',' . $this->univ_uuids_tids['d8f5d9a9-3965-44cf-a713-96533e493197'];
		
		//************************************************** Rouergue Livres Pratiques **********************************************************************
		// Rouergue Livres Pratiques - 494 | Aveyron - 1142   ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		$this->univ_coll_mapping['494']['1142']['tids'] = $this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'];
		
		// Rouergue Livres Pratiques - 494 | Aveyron - 1142 | Cuisine - 140   ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		// ----------------------------------------------------------------   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['494']['1142']['140']['tids'] = 
			$this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Livres Pratiques - 494 | Botanique - 1143 | Aveyron - 141   ===>   Nature & Jardin > Botanique - 48169487-b368-480b-83a4-46ddb4205188
		// ------------------------------------------------------------------   ===>   Régions > Aveyron - 5c231e18-ad97-4038-b7e1-a1da158dc904
		$this->univ_coll_mapping['494']['1143']['141']['tids'] = 
			$this->univ_uuids_tids['48169487-b368-480b-83a4-46ddb4205188'] . ',' . $this->univ_uuids_tids['5c231e18-ad97-4038-b7e1-a1da158dc904'];
		
		// Rouergue Livres Pratiques - 494 | Botanique - 1143 | Jardins - 142   ===>   Nature & Jardin > Botanique - 48169487-b368-480b-83a4-46ddb4205188
		// ------------------------------------------------------------------   ===>   Nature & Jardin > Jardin - 7bf1968c-cf26-4fe6-a839-f70abf339851
		$this->univ_coll_mapping['494']['1143']['142']['tids'] = 
			$this->univ_uuids_tids['48169487-b368-480b-83a4-46ddb4205188'] . ',' . $this->univ_uuids_tids['7bf1968c-cf26-4fe6-a839-f70abf339851'];
		
		// Rouergue Livres Pratiques - 494 | Botanique - 1143 | Région - 143   ===>   Nature & Jardin > Botanique - 48169487-b368-480b-83a4-46ddb4205188
		// -----------------------------------------------------------------   ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		$this->univ_coll_mapping['494']['1143']['143']['tids'] = 
			$this->univ_uuids_tids['48169487-b368-480b-83a4-46ddb4205188'] . ',' . $this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'];
		
		// Rouergue Livres Pratiques - 494 | Cuisine - 1143 | Jardins - 144   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		// ----------------------------------------------------------------   ===>   Nature & Jardin > Jardin - 7bf1968c-cf26-4fe6-a839-f70abf339851
		$this->univ_coll_mapping['494']['1143']['144']['tids'] = 
			$this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'] . ',' . $this->univ_uuids_tids['7bf1968c-cf26-4fe6-a839-f70abf339851'];
		
		// Rouergue Livres Pratiques - 494 | Cuisine - 1143 | Vins - 150   ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		// -------------------------------------------------------------   ===>   Gastronomie > Vins - c838c944-79ea-4767-be9b-f66f87756c86
		$this->univ_coll_mapping['494']['1143']['150']['tids'] = 
			$this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'] . ',' . $this->univ_uuids_tids['c838c944-79ea-4767-be9b-f66f87756c86'];
		
		// Rouergue Livres Pratiques - 494 | Ecologie - 1144   ===>   Nature & Jardin > Écologie - 80df7f9b-4f8b-47eb-89c7-2da7ff929d20
		$this->univ_coll_mapping['494']['1144']['tids'] = $this->univ_uuids_tids['80df7f9b-4f8b-47eb-89c7-2da7ff929d20'];
		
		// Rouergue Livres Pratiques - 494 | Ecologie - 1144 | Bati - 145  ===>   Nature & Jardin > Écologie - 80df7f9b-4f8b-47eb-89c7-2da7ff929d20
		// -------------------------------------------------------------   ===>   Nature & Jardin > Bâti - 287736de-2aeb-48bd-a91d-5510b786ccaf
		$this->univ_coll_mapping['494']['1144']['145']['tids'] = 
			$this->univ_uuids_tids['80df7f9b-4f8b-47eb-89c7-2da7ff929d20'] . ',' . $this->univ_uuids_tids['287736de-2aeb-48bd-a91d-5510b786ccaf'];
		
		// Rouergue Livres Pratiques - 494 | Ecologie - 1144 | Jardins - 146  ===>   Nature & Jardin > Écologie - 80df7f9b-4f8b-47eb-89c7-2da7ff929d20
		// -------------------------------------------------------------   ===>   Nature & Jardin > Jardin - 7bf1968c-cf26-4fe6-a839-f70abf339851
		$this->univ_coll_mapping['494']['1144']['146']['tids'] = 
			$this->univ_uuids_tids['80df7f9b-4f8b-47eb-89c7-2da7ff929d20'] . ',' . $this->univ_uuids_tids['7bf1968c-cf26-4fe6-a839-f70abf339851'];
		
		// Rouergue Livres Pratiques - 494 | Gastronomie - 1145 | Cuisine - 147  ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['494']['1145']['147']['tids'] = $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Livres Pratiques - 494 | Gastronomie - 1145 | Grand Chef - 148  ===>   Gastronomie > Grands Chefs - 557341af-5bdc-4f6f-8a24-a368f78c524b
		$this->univ_coll_mapping['494']['1145']['148']['tids'] = $this->univ_uuids_tids['557341af-5bdc-4f6f-8a24-a368f78c524b'];
		
		// Rouergue Livres Pratiques - 494 | Nature - 521  ===>   Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		$this->univ_coll_mapping['494']['521']['tids'] = $this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'];
		
		// Rouergue Livres Pratiques - 494 | Nature - 521 | Jardins - 149  ===>   Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		//---------------------------------------------------------------  ===>    Nature & Jardin > Jardin - 7bf1968c-cf26-4fe6-a839-f70abf339851
		$this->univ_coll_mapping['494']['521']['149']['tids'] = 
			$this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'] . ',' . $this->univ_uuids_tids['7bf1968c-cf26-4fe6-a839-f70abf339851'];
		
		// Rouergue Livres Pratiques - 494 | Nature - 521 | Région - 151  ===>   Nature & Jardin > Nature - ae01c103-055b-41e3-a1e1-3e5c6a9aa320
		//--------------------------------------------------------------  ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		$this->univ_coll_mapping['494']['']['521']['151']['tids'] = 
			$this->univ_uuids_tids['ae01c103-055b-41e3-a1e1-3e5c6a9aa320'] . ',' . $this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'];
		
		// Rouergue Livres Pratiques - 494 | Région - 1146 | Cuisine - 152  ===>   Régions > Régions de France - 92100609-a178-4183-8c5f-e091e442c265
		//----------------------------------------------------------------  ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['494']['1146']['152']['tids'] = 
			$this->univ_uuids_tids['92100609-a178-4183-8c5f-e091e442c265'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		// Rouergue Livres Pratiques - 494 | Santé - 1147 | Cuisine - 153  ===> Gastronomie > Santé - 85b490bb-bfae-46e2-9a1f-130057789068
		//---------------------------------------------------------------  ===>   Gastronomie > Cuisine - 3ec4f92d-32c1-45c6-a0b7-be9ea50872cc
		$this->univ_coll_mapping['494']['1147']['153']['tids'] = 
			$this->univ_uuids_tids['85b490bb-bfae-46e2-9a1f-130057789068'] . ',' . $this->univ_uuids_tids['3ec4f92d-32c1-45c6-a0b7-be9ea50872cc'];
		
		//************************************************** ROUERGUE NUMÉRIQUE JEUNESSE *********************************************************************
		// ROUERGUE NUMÉRIQUE JEUNESSE - 463 | dacodac - 995   ===>   Livres numériques > dacodac - 0af3c4aa-630d-48a0-98ca-51752eba0778
		$this->univ_coll_mapping['463']['995']['tids'] = $this->univ_uuids_tids['0af3c4aa-630d-48a0-98ca-51752eba0778'];
		
		// ROUERGUE NUMÉRIQUE JEUNESSE - 463 | doado - 1009   ===>   Livres numériques > doado  - faaf7a44-b11c-478a-b05f-e2ca1892f5b7
		$this->univ_coll_mapping['463']['1009']['tids'] = $this->univ_uuids_tids['faaf7a44-b11c-478a-b05f-e2ca1892f5b7'];
		
		// ROUERGUE NUMÉRIQUE JEUNESSE  - 463 | doado noir - 1010   ===>   Livres numériques > doado noir  - 4269d4f5-45c0-4629-abab-b5d15e824200
		$this->univ_coll_mapping['463']['1010']['tids'] = $this->univ_uuids_tids['4269d4f5-45c0-4629-abab-b5d15e824200'];
		
		// ROUERGUE NUMÉRIQUE JEUNESSE  - 463 | epik - 1082   ===>   Livres numériques > epik - 8c1782e1-88a6-4aac-87d7-4d29ed483c9b
		$this->univ_coll_mapping['463']['1082']['tids'] = $this->univ_uuids_tids['8c1782e1-88a6-4aac-87d7-4d29ed483c9b'];
		
		// ROUERGUE NUMÉRIQUE TEXTE  - 462 | la brune - 1011   ===>   Livres numériques > la brune - ce61d6fc-faa2-47f8-a6e9-976257d809d8
		$this->univ_coll_mapping['462']['1011']['tids'] = $this->univ_uuids_tids['ce61d6fc-faa2-47f8-a6e9-976257d809d8'];
		
		// ROUERGUE NUMÉRIQUE TEXTE  - 462 | Polars - 1013  ===>   Livres numériques > polar - 2796300b-4322-4e79-8dcf-f3d7447c31dd
		$this->univ_coll_mapping['462']['1013']['tids'] = $this->univ_uuids_tids['2796300b-4322-4e79-8dcf-f3d7447c31dd'];
		
		// ROUERGUE NUMÉRIQUE TEXTE  - 462 | Romans - 1013  ===>   Livres numériques > roman - 13c26811-5ade-4018-b8bb-5642b42fc1da
		$this->univ_coll_mapping['462']['1013']['tids'] = $this->univ_uuids_tids['13c26811-5ade-4018-b8bb-5642b42fc1da'];
		
		//************************************************** Rouergue Romans Jeunesse **********************************************************************
		// Rouergue Romans Jeunesse - 497 | boomerang - 526   ===>   Romans jeunesse > Romans dès 7 ans > boomerang - e6aea4fd-4293-40c5-beab-f90ddae63def
		$this->univ_coll_mapping['497']['526']['tids'] = $this->univ_uuids_tids['e6aea4fd-4293-40c5-beab-f90ddae63def'];
		
		// Rouergue Romans Jeunesse - 497 | dacodac - 527  ===>   Romans jeunesse > Romans dès 9 ans > dacodac - b4bb6966-c17a-401e-a705-907a9e42b69b
		$this->univ_coll_mapping['497']['527']['tids'] = $this->univ_uuids_tids['b4bb6966-c17a-401e-a705-907a9e42b69b'];
		
		// Rouergue Romans Jeunesse - 497 | doado - 528   ===>   Romans jeunesse > Romans ados > doado - 950d4168-1130-460f-902e-46a961b7ad69
		$this->univ_coll_mapping['497']['528']['tids'] = $this->univ_uuids_tids['950d4168-1130-460f-902e-46a961b7ad69'];
		
		// Rouergue Romans Jeunesse - 497 | doado noir - 529   ===>   Romans jeunesse > Romans ados > doado noir - 2a73fe7d-1781-42b7-8127-dd7a268d6bdd
		$this->univ_coll_mapping['497']['529']['tids'] = $this->univ_uuids_tids['2a73fe7d-1781-42b7-8127-dd7a268d6bdd'];
		
		// Rouergue Romans Jeunesse - 497 | epik - 1083   ===>   Épik SF - Fantasy - 5ea55aec-1f9b-4ff9-a577-2ff4e9076370
		$this->univ_coll_mapping['497']['1083']['tids'] = $this->univ_uuids_tids['5ea55aec-1f9b-4ff9-a577-2ff4e9076370'];
		
		// Rouergue Romans Jeunesse - 497 | tic tac - 532   ===>   Romans jeunesse > Romans dès 6 ans > tic tac - 238c7664-3155-4a75-8d18-ee167c39fa2c
		$this->univ_coll_mapping['497']['532']['tids'] = $this->univ_uuids_tids['238c7664-3155-4a75-8d18-ee167c39fa2c'];
		
		// Rouergue Romans Jeunesse - 497 | zig zag - 530   ===>   Romans jeunesse > Romans dès 8 ans > zig zag - 652fe62a-ec9a-43b9-8443-9c44f9ebb44d
		$this->univ_coll_mapping['497']['530']['tids'] = $this->univ_uuids_tids['652fe62a-ec9a-43b9-8443-9c44f9ebb44d'];
		
/*
$this->univ_coll_mapping[''] = $this->univ_uuids_tids[''];
$this->univ_coll_mapping[''][''] = $this->univ_uuids_tids[''];
$this->univ_coll_mapping[''][''][''] = $this->univ_uuids_tids[''];
double classement non encore développé 
*/
	}
	
	/**
	 * Returns universe term id that matches the Mistral's collection, subcollection, series values of row being imported.
	 *
	 * @param string $collectionid
	 *   The collection the imported book belongs to.
	 * @param string $subcollectionid
	 *   The subcollection the imported book belongs to.
	 * @param string $seriesid
	 *   The series the imported book belongs to.
	 *
	 * @return
	 *   the tid of the Univers term the book has to be linked to.
	 */
	function rouergue_get_universe_term_ids($collectionid, $subcollectionid, $seriesid) {
		$term_ids = 0;
		if (isset($seriesid) && $seriesid != 0) {
			$term_ids = $this->univ_coll_mapping[$collectionid][$subcollectionid][$seriesid]['tids'];
		}
		else if (isset($subcollectionid) && $subcollectionid != 0) {
			$term_ids = $this->univ_coll_mapping[$collectionid][$subcollectionid]['tids'];
		}
		else {
			$term_ids = $this->univ_coll_mapping[$collectionid]['tids'];
		}
		return $term_ids;
	}
}

