<?php
/**
 * @file
 * feature_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_accueil:<front>
  $menu_links['main-menu_accueil:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Accueil',
    'options' => array(
      'identifier' => 'main-menu_accueil:<front>',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Accueil');


  return $menu_links;
}
