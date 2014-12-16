<?php
/**
 * @file
 * feature_core.features.uuid_features_menu.inc
 */

/**
 * Implements hook_menu_default_uuid_features_menu().
 */
function feature_core_menu_default_uuid_features_menu() {
  $menu_uuid_links = array();


  // Exported menu link: 76c26dd7-e99d-468e-aedd-0062f069e214
  $menu_uuid_links['76c26dd7-e99d-468e-aedd-0062f069e214'] = array(
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
    'uuid' => '76c26dd7-e99d-468e-aedd-0062f069e214',
  );
  
  // Translatables
  // Included for use with string extractors like potx.
  t('Accueil');
  
  return $menu_uuid_links;
}
