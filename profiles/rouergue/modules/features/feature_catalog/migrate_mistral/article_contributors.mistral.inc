<?php
/**
 * @file
 * Migrates Article-Contributor-Function Relationships.
 */

class ArticleContributorsMigration extends Migration {
	public function __construct() {
		parent::__construct();
		
		// DESCRIPTION
		$this->description = t("Migrate contributor/function relationships from mistral source database to Drupal Article's Contributors field (Field Collection)");
		
		// SOURCE
// 		$query = Database::getConnection('default', 'mistral')->select('bookcontributor','bc');
// 		$query->join('article','a','a.bookid=bc.bookid');

		$query = Database::getConnection('default', 'mistral')->select('article','a');
		$query->join('fabricationplan', 'fp', 'fp.articleid = a.articleid');
		$query->join('format','f','f.formatid=fp.finalformatid');
		$query->join('realprice','r','r.articleid=a.articleid AND r.iscurrentprice=1');
		$query->join('commercialplan','cp','cp.articleid=a.articleid');
		$query->Join('booktheme','bt','bt.bookid=a.bookid');
		$query->Join('bookreadership','br','br.bookid=a.bookid');
		$query->Join('bookcontributor','bc','bc.bookid=a.bookid');
		
		$query
			->fields('a', array('articleid'))
			->fields('bc', array('contributorid','functionid'));
		
		$this->source = new MigrateSourceSQL($query);
		
		// DESTINATION
		$this->destination = new MigrateDestinationFieldCollection(
				'field_contributors',
				array('host_entity_type' => 'node')
		);
		
		// MAP
		$this->map = new MigrateSQLMap($this->machineName,
				array(
						'articleid' => array(
								'type' => 'int',
								'unsigned' => TRUE,
								'not null' => true,
								'alias' => 'a',
								'description' => 'Mistral article id.'
						),
				),
				MigrateDestinationFieldCollection::getKeySchema()
		);
		
		// FIELDS MAPPING
		// Link the field collection to its article
		$this->addFieldMapping('host_entity_id', 'articleid')->sourceMigration('Article');
		
		// Link the Contributor (node) to the Entity Reference field in the field collection
		$this->addFieldMapping('field_contributor', 'contributorid')->sourceMigration('Contributor');
		
		// Link the Function (taxonomy term) to the Term Reference field in the field collection
		$this->addFieldMapping('field_contributor_function', 'functionid')->sourceMigration('Function');
		$this->addFieldMapping('field_contributor_function:source_type')->defaultValue('tid');
		
		
		
	}
}