<?php
/**
 * @file
 * Migrates contributors and functions from Mistral.
 */

/**
 * Migration class for functions.
 * 
 */
class FunctionMigration extends Migration {
	public function __construct() {
		parent::__construct();

		// DESCRIPTION
		$this->description = t('Migrate functions from mistral source database to Drupal Functions vocabulary');

		// SOURCE		
		$query = Database::getConnection('default', 'mistral')->select('function');
		$query->fields('function', array('functionid','printname','name'));

		$this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));

		// DESTINATION
		$this->destination = new MigrateDestinationTerm('functions');

		// MAP
		$this->map = new MigrateSQLMap(
				$this->machineName,
				array(
						'functionid' => array(
								'type' => 'int',
								'unsigned' => TRUE,
								'not null' => TRUE,
								'description' => 'Mistral function ID',
						)
				),
				MigrateDestinationTerm::getKeySchema()
		);

		// FIELDS MAPPING
		$this->addFieldMapping('name', 'name');
	}
}

/**
 * Migration class for contributors.
 * 
 * We retrieve only contributors linked to a importable article.
 * The mysql query to run is :
 * 
 * SELECT DISTINCT c.name, c.firstname, c.pseudoname, c.pseudofirstname, c.biography
 * FROM contributor c
 * JOIN bookcontributor bc ON bc.contributorid=c.contributorid
 * WHERE bc.bookid IN (
 *   SELECT a.bookid
 *   FROM `article` a
 *   JOIN book b ON b.bookid=a.bookid
 *   JOIN priceandtirage pt ON pt.articleid=a.articleid and pt.isvalidated='1'
 *   JOIN realprice rp ON rp.articleid=a.articleid and rp.iscurrentprice='1'
 *   JOIN fabricationplan fp ON fp.articleid=a.articleid 
 *   JOIN format f ON f.formatid=b.formatid
 *   GROUP BY a.articleid
 * )
 */
class ContributorMigration extends Migration {
	public function __construct() {
		parent::__construct();
		
		// DESCRIPTION
		$this->description = t('Migrate contributors from mistral source database to Drupal Contributor nodes');
		
		// SOURCE
// 		$subquery = Database::getConnection('default', 'mistral')->select('article','a');
// 		$subquery->join('book','b','b.bookid=a.bookid');
// 		$subquery->join('priceandtirage','pt','pt.articleid=a.articleid AND pt.isvalidated=1');
// 		$subquery->join('realprice','r','r.articleid=a.articleid AND r.iscurrentprice=1');
// 		$subquery->join('fabricationplan','fp','fp.articleid=a.articleid');
// 		$subquery->join('format','f','f.formatid=b.formatid');
// 		$subquery->fields('a', array('bookid'));
		
		$query = Database::getConnection('default', 'mistral')->select('contributor','c');
		$query->join('bookcontributor','bc','bc.contributorid=c.contributorid');
		$query->fields('c', array('contributorid','name','firstname','pseudoname','pseudofirstname','biography'));
		//$query->condition('bc.bookid', $subquery, 'IN');
		$query->distinct();
		
		$this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
		
		// DESTINATION
		$this->destination = new MigrateDestinationNode('contributor');
		
		// MAP
		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'contributorid' => array(
					'type' => 'int',
					'unsigned' => TRUE,
					'not null' => TRUE,
					'alias' => 'c',
					'description' => 'Mistral contributor id.',	
				)
			),
			MigrateDestinationNode::getKeySchema()
		);
		
		// FIELDS MAPPING
		$this->addFieldMapping('field_contributor_id', 'contributorid');
		$this->addFieldMapping('title', 'name');
		$this->addFieldMapping('field_lastname', 'name');
		$this->addFieldMapping('field_firstname', 'firstname');
		$this->addFieldMapping('field_pseudonyme', 'pseudoname');
		$this->addFieldMapping('body', 'biography');
		
	}
	
	/**
	 * Data handling before mapping.
	 */
	function prepareRow($row) {
		parent::prepareRow($row);
		
		// Pseudo
		$row->pseudoname = $row->pseudofirstname . ' ' . $row->pseudoname;
		
		// Biography text cleaning.
		$row->biography = html_entity_decode(strip_tags($row->biography));
	}
	
	/**
	 * Data handling before node saving.
	 */
	function prepare($node, stdClass $row) {
		// Title
		$node->title = $node->title . ' ' . $row->firstname;		

		// Picture file
		$picture_filename = $row->contributorid . '.jpg';
		$host = variable_get('contributor_pictures_url','http://rouergue.abrege.net/util/auteurs_rouergue/');
		$url = $host . $picture_filename;
		
		if(!$file = system_retrieve_file($url, 'public://catalog/contributor-pictures/' . $picture_filename, TRUE, FILE_EXISTS_REPLACE)) {
			$image_filename = variable_get('default_contributor_picture','contributor-pic-400x600.png');
			$url = $host . $image_filename;
			$file = system_retrieve_file($url, 'public://catalog/contributor-pictures/' . $image_filename, TRUE, FILE_EXISTS_RENAME);
		}
		
		$node->field_picture[LANGUAGE_NONE]['0']['fid'] = $file->fid;
	}
}