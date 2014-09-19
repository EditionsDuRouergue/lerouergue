<?php
/**
 * @file
 * Migrates contributors and functions from Mistral.
 */

class FunctionMigration extends Migration {
	public function __construct() {
		parent::__construct();

		// DESCRIPTION
		$this->description = t('Migrate functions from mistral source database to Drupal Functions vocabulary');

		// SOURCE
		$query = Database::getConnection('default', 'mistral')->select('function');
		$query->fields('function', array('functionid','printname','name'));

		$this->source = new MigrateSourceSQL($query);

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
 * The mysql query is as follows :
 * 
 * SELECT c.contributorid, c.name, c.firstname, c.pseudoname, c.pseudofirstname, c.biography
 * FROM contributor c
 * JOIN bookcontributor bc ON bc.contributorid=c.contributorid
 * JOIN book b ON b.bookid=bc.bookid
 * JOIN article a ON a.bookid=b.bookid
 * WHERE a.isbn is not null
 */
class ContributorMigration extends Migration {
	public function __construct() {
		parent::__construct();
		
		// DESCRIPTION
		$this->description = t('Migrate contributors from mistral source database to Drupal Contributor nodes');
		
		// SOURCE
		$query = Database::getConnection('default', 'mistral')->select('contributor','c');
		$query->join('bookcontributor','bc','bc.contributorid=c.contributorid');
		$query->join('book','b','b.bookid=bc.bookid');
		$query->join('article','a','a.bookid=b.bookid');
		$query->join('commercialplan','cp','cp.articleid=a.articleid');
		$query->Join('booktheme','bt','bt.bookid=b.bookid');
		$query->Join('bookreadership','br','br.bookid=b.bookid');
		
		$query->fields('c', array('contributorid','name','firstname','pseudoname','pseudofirstname','biography'));
		
		//$query->isNotNull('a.isbn');
		
		$this->source = new MigrateSourceSQL($query);
		
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
		
		// Biography text cleaning.
		$row->biography = html_entity_decode(strip_tags($row->biography));
	}
	
	/**
	 * Data handling before node saving.
	 */
	function prepare($node, stdClass $row) {
		// Title
		$node->title = $node->title . ' ' . $row->firstname;
		// Pseudo
		$node->field_pseudonyme[LANGUAGE_NONE]['0']['value'] = $node->field_pseudonyme[LANGUAGE_NONE]['0']['value'] . ' ' . $row->pseudofirstname;
	}
}