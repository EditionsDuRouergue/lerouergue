<?php
/**
 * @file
 * feature_catalog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_catalog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_catalog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_features_date_format_default().
 */
function feature_catalog_features_date_format_default() {
  $fdf_config = array();

  $fdf_config[] = array(
    'dfid' => 36,
    'format' => 'F Y',
    'type' => 'custom',
    'locked' => 0,
  );
  return $fdf_config;
}

/**
 * Implements hook_features_date_type_default().
 */
function feature_catalog_features_date_type_default() {
  $fdt_config = array();

  $fdt_config[] = array(
    'is_new' => FALSE,
    'module' => '',
    'type' => 'release_date',
    'title' => 'Date parution',
    'locked' => 0,
  );
  return $fdt_config;
}

/**
 * Implements hook_node_info().
 */
function feature_catalog_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Un article (livre) de la base de données Mistral, à afficher sur le site web.'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'contributor' => array(
      'name' => t('Contributor'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nom Prénom'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
