<?php
/**
 * @file
 * feature_workshops.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_workshops_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-workshops-workshops_front_block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'workshops-workshops_front_block',
    'module' => 'views',
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
