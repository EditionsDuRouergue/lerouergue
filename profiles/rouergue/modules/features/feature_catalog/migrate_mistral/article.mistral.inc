<?php
/**
 * @file
 * Migrates articles, themes from Mistral.
 */

class ThemeMigration extends Migration {
	public function __construct() {
		parent::__construct();

		// DESCRIPTION
		$this->description = t('Migrate themes from mistral source database to Drupal Themes vocabulary');

		// SOURCE
		$query = Database::getConnection('default', 'mistral')->select('theme');
		$query->fields('theme', array('themeid','name'));

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
						)
				),
				MigrateDestinationTerm::getKeySchema()
		);

		// FIELDS MAPPING
		$this->addFieldMapping('name', 'name');
	}
}

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
 * The mysql query is as follows :
 *
 * SELECT c.contributorid, c.name, c.firstname, c.pseudoname, c.pseudofirstname, c.biography
 * FROM contributor c
 * JOIN bookcontributor bc ON bc.contributorid=c.contributorid
 * JOIN book b ON b.bookid=bc.bookid
 * JOIN article a ON a.bookid=b.bookid
 * WHERE a.isbn is not null
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
		$query->join('fabricationplan', 'fp', 'fp.articleid = a.articleid');
		$query->join('format','f','f.formatid=fp.finalformatid');
		$query->join('realprice','r','r.articleid=a.articleid AND r.iscurrentprice=1');
		$query->join('commercialplan','cp','cp.articleid=a.articleid');
		$query->Join('booktheme','bt','bt.bookid=b.bookid');
		$query->Join('bookreadership','br','br.bookid=b.bookid');
				
		$query
		->fields('a', array('articleid','bookid','isbn','gencod'))
		->fields('b', array('title','subtitle','resume','backcover'))
		->fields('r', array('price'));
    $query->addField('f','name','format');
    $query->addField('fp','finalnbpage','nbpage');
				
		//$query->isNotNull('isbn');
		$query->addExpression("CONCAT(cp.year,'-',right(concat('0',cp.month),2),'-01')",'pubdate');
		$query->addExpression('GROUP_CONCAT(bt.themeid)', 'theme_list');
		$query->addExpression('GROUP_CONCAT(DISTINCT br.readershipid)', 'readership_list');
		$query->groupBy('a.articleid');
		
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
