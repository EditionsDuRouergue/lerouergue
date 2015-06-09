<?php
/**
 * @file
 * feature_catalog.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_catalog_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_auteurs:auteurs
  $menu_links['main-menu_auteurs:auteurs'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'auteurs',
    'router_path' => 'auteurs',
    'link_title' => 'Auteurs',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_auteurs:auteurs',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_catalogue:catalogue
  $menu_links['main-menu_catalogue:catalogue'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'catalogue',
    'router_path' => 'catalogue',
    'link_title' => 'Catalogue',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_catalogue:catalogue',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Auteurs');
  t('Catalogue');


  return $menu_links;
}
