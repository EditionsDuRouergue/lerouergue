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
	public function __construct($arguments) {
		parent::__construct($arguments);

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
	public function __construct($arguments) {
		parent::__construct($arguments);
		
		$this->store = '';
		$this->contributor_pictures_dir = '';
		$this->default_contributor_picture = '';
		
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
		//$query->condition('c.contributorid', '');
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
		$this->addFieldMapping('field_pseudoname', 'pseudoname');
		$this->addFieldMapping('field_pseudofirstname', 'pseudofirstname');
		$this->addFieldMapping('body', 'biography');
	}
	
	/**
	 * Data handling before mapping.
	 */
	function prepareRow($row) {
		parent::prepareRow($row);

		// Biography text cleaning.
		$row->biography = html_entity_decode(strip_tags($row->biography));
		
		// Last name capitalization handling
		$parts = explode("-", $row->name);
		$capitalized_parts = array();
		foreach ($parts as $part) {
			$subparts = explode("'", $part);
			
			$capitalized_subparts = array();
			foreach($subparts as $subpart) {
				// $subpart treatment and storage in $capitalized_subparts
				$capitalized_subparts[] = ucwords(mb_strtolower($subpart));
			}
			// $part reassembling from treated subparts
			$part = implode("'", $capitalized_subparts);
			
			// $part storage in $capitalized_parts
			$capitalized_parts[] = $part;
		}
		// name reassembling from parts
		$row->name = implode("-", $capitalized_parts);
	}
	
	/**
	 * Data handling before node saving.
	 */
	function prepare($node, stdClass $row) {
		// Title, displayed name and sorting name handling.
		$title = $row->name . ' ' . $row->firstname;
		$displayed_name = $row->firstname . ' ' . $row->name;
		$sorting_name = $row->name;
		
		if (isset($row->pseudofirstname) && $row->pseudofirstname != '') {
			$title = $row->pseudoname . ' ' . $row->pseudofirstname;
			$displayed_name = $row->pseudofirstname . ' ' . $row->pseudoname;
			$sorting_name = $row->pseudoname;
		}
		else if(isset($row->pseudoname) && $row->pseudoname != '') {
			$title = $row->pseudoname;
			$displayed_name = $row->pseudoname;
			$sorting_name = $row->pseudoname;
		}

		$node->title = $title;
		$node->field_displayed_name[LANGUAGE_NONE]['0']['value'] = $displayed_name;
		$node->field_sorting_name[LANGUAGE_NONE]['0']['value'] = $sorting_name;

		// Picture file
		if ($this->store == '') {
			$this->store = rtrim(variable_get('rouergue_data_store', ''), '/') . '/';
		}
		if ($this->contributor_pictures_dir == '') {
			$this->contributor_pictures_dir = rtrim(variable_get('rouergue_contributor_pictures_dir', 'catalog/contributor-pictures'), '/') . '/';
		}
		$filename = $row->contributorid . '.jpg';
		$picture_filename = $this->store . $this->contributor_pictures_dir . $filename;
		
		if (!file_exists($picture_filename)) {
			if ($this->default_contributor_picture == '') {
				$this->default_contributor_picture = variable_get('rouergue_default_contributor_picture', 'contributor-pic-400x600.png');
			}
			$filename = $this->default_contributor_picture;
			$picture_filename = $this->store . $this->contributor_pictures_dir . $filename;
		}
		
		if ($picture = file_get_contents($picture_filename)) {
			$file = file_save_data($picture, 'public://catalog/contributor-pictures/' . $filename, FILE_EXISTS_REPLACE);
			if ($file) {
				$node->field_picture[LANGUAGE_NONE]['0']['fid'] = $file->fid;
			}
		}
	}
}