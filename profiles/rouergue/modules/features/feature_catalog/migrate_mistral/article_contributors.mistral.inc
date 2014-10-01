<?php
/**
 * @file
 * Migrates Article-Contributor-Function Relationships.
 */

/**
 * Migration class for book-contributor-role associations.
 *
 * We retrieve only associations linked to a importable article.
 * The mysql query to run is :
 *
 * SELECT a.articleid, bc.contributorid, bc.functionid
 * FROM bookcontributor bc
 * JOIN article a ON a.bookid=bc.bookid
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
class ArticleContributorsMigration extends Migration {
	public function __construct() {
		parent::__construct();
		
		// DESCRIPTION
		$this->description = t("Migrate contributor/function relationships from mistral source database to Drupal Article's Contributors field (Field Collection)");
		
		// SOURCE
		$subquery = Database::getConnection('default', 'mistral')->select('article','a');
		$subquery->join('book','b','b.bookid=a.bookid');
		$subquery->join('priceandtirage','pt','pt.articleid=a.articleid AND pt.isvalidated=1');
		$subquery->join('realprice','r','r.articleid=a.articleid AND r.iscurrentprice=1');
		$subquery->join('fabricationplan','fp','fp.articleid=a.articleid');
		$subquery->join('format','f','f.formatid=b.formatid');
		$subquery->fields('a', array('bookid'));

		$query = Database::getConnection('default', 'mistral')->select('bookcontributor','bc');
		$query->Join('article','a','a.bookid=bc.bookid');
		$query->fields('a', array('articleid'))->fields('bc', array('contributorid','functionid'));
		$query->condition('bc.bookid', $subquery, 'IN');
		
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
								//'alias' => 'a',
								'description' => 'Mistral article id.'
						),
						'contributorid' => array(
								'type' => 'int',
								'unsigned' => TRUE,
								'not null' => true,
								//'alias' => 'c',
								'description' => 'Mistral contributor id.'
						),
						'functionid' => array(
								'type' => 'int',
								'unsigned' => TRUE,
								'not null' => true,
								//'alias' => 'f',
								'description' => 'Mistral function id.'
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