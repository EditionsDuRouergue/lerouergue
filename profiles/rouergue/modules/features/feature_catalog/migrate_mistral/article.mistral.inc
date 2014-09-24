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

		$this->source = new MigrateSourceSQL($query);

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

		$this->source = new MigrateSourceSQL($query);

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
 * rp.price, f.name as format, fp.finalnbpage as nbpage, 
 * GROUP_CONCAT(bt.themeid) as theme_list, GROUP_CONCAT(DISTINCT br.readershipid) as readership_list, 
 * CONCAT(cp.year,'-',right(concat('0',cp.month),2),'-01') as pubdate
 * FROM `article` a
 * JOIN book b ON b.bookid=a.bookid
 * LEFT JOIN collection c ON c.collectionid=b.collectionid
 * LEFT JOIN subcollection sc ON sc.subcollectionid=b.subcollectionid
 * LEFT JOIN series s ON s.seriesid=b.seriesid
 * JOIN commercialplan cp ON cp.articleid=a.articleid
 * JOIN fabricationplan fp ON fp.articleid=a.articleid
 * JOIN priceandtirage pt ON pt.articleid=a.articleid and pt.isvalidated='1'
 * JOIN realprice rp ON rp.articleid=a.articleid and rp.iscurrentprice='1'
 * LEFT JOIN booktheme bt ON bt.bookid=a.bookid
 * LEFT JOIN bookreadership br ON br.bookid=b.bookid
 * JOIN format f ON f.formatid=fp.finalformatid
 * GROUP BY a.articleid
 * ORDER BY a.articleid ASC
 */
class ArticleMigration extends Migration {
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
		$query->join('priceandtirage','pt','pt.articleid=a.articleid AND pt.isvalidated=1');
		$query->join('realprice','rp','rp.articleid=a.articleid AND rp.iscurrentprice=1');
		$query->leftJoin('booktheme','bt','bt.bookid=b.bookid');
		$query->leftJoin('bookreadership','br','br.bookid=b.bookid');
		$query->join('format','f','f.formatid=fp.finalformatid');
				
		$query
		->fields('a', array('articleid','bookid','isbn13','gencod'))
		->fields('b', array('title','subtitle','resume','backcover'))
		->fields('rp', array('price'));
    $query->addField('f','name','format');
    $query->addField('fp','finalnbpage','nbpage');
    $query->addField('c','name','collection');
    $query->addField('sc','name','subcollection');
    $query->addField('s','name','series');
		$query->addExpression('GROUP_CONCAT(bt.themeid)', 'theme_list');
		$query->addExpression('GROUP_CONCAT(DISTINCT br.readershipid)', 'readership_list');
		$query->addExpression("CONCAT(cp.year,'-',right(concat('0',cp.month),2),'-01')",'pubdate');
		
		$query->groupBy('a.articleid');
		$query->orderBy('a.articleid', 'ASC');
		
		$this->source = new MigrateSourceSQL($query);
		
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
	}
	
	/**
	 * Data handling before mapping.
	 */	
	function prepareRow($row) {
		parent::prepareRow($row);
		
		// Backcover text cleaning.
		$row->backcover = html_entity_decode(strip_tags($row->backcover));
	}
	
	/**
	 * Data handling before node saving.
	 */
	function prepare($node, stdClass $row) {
		// Cover image
		$image_filename = 'syndrome-indigo-test-image.jpg'; // 	A REMPLACER PAR : $image_filename = $row->gencod . 'jpg';
		$host = 'http://www.korora.fr/'; // A REMPLACER PAR :	$host = 'http://www.lerouergue.fr/...';
		$url = $host . $image_filename;
	
		$file = system_retrieve_file($url, 'public://catalog/cover-images/' . $image_filename, TRUE, FILE_EXISTS_RENAME); // A REMPLACER PAR :	...FILE_EXISTS_REPLACE);
		$node->field_cover_image[LANGUAGE_NONE]['0']['fid'] = $file->fid;
// 		dpm($file);
// 		dpm($node);
	}
}
