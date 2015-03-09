<?php
/**
 * @file
 * feature_books.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_books_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_books_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Page de livre'),
      'base' => 'node_content',
      'description' => t('<em>Les livres</em> possèdent une navigation hiérarchique intégrée. Cela est utile pour des guides ou des tutoriels.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
