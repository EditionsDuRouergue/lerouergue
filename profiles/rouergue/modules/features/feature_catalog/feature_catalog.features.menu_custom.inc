<?php
/**
 * @file
 * feature_catalog.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function feature_catalog_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-universe.
  $menus['menu-universe'] = array(
    'menu_name' => 'menu-universe',
    'title' => 'Univers',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Univers');


  return $menus;
}
