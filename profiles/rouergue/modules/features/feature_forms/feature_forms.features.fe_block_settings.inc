<?php
/**
 * @file
 * feature_forms.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_forms_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-catalog_request_link'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'catalog_request_link',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'rouergue_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'rouergue_bootstrap',
        'weight' => 0,
      ),
      'rubik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'rubik',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
