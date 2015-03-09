<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function migrate_mistral_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'mistral' => array(
        'title' => t('Mistral migrations'),
      ),
    ),
    'migrations' => array(
      'function' => array(
        'class_name' => 'FunctionMigration',
        'group_name' => 'mistral',
      ),
      'contributor' => array(
        'class_name' => 'ContributorMigration',
        'group_name' => 'mistral',
      ),
      'theme' => array(
        'class_name' => 'ThemeMigration',
        'group_name' => 'mistral',
      ),
      'readership' => array(
        'class_name' => 'ReadershipMigration',
        'group_name' => 'mistral',
      ),
      'article' => array(
        'class_name' => 'ArticleMigration',
        'group_name' => 'mistral',
      ),
      'articleContributors' => array(
        'class_name' => 'ArticleContributorsMigration',
        'group_name' => 'mistral',
      ),
    ),
  );
  return $api;
}
?>