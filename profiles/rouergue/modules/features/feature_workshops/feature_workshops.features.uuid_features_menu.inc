<?php
/**
 * @file
 * feature_workshops.features.uuid_features_menu.inc
 */

/**
 * Implements hook_menu_default_uuid_features_menu().
 */
function feature_workshops_menu_default_uuid_features_menu() {
  $menu_uuid_links = array();

  // Exported menu link: cbcae01d-af54-4264-a92c-a8dd25bb2697
  $menu_uuid_links['cbcae01d-af54-4264-a92c-a8dd25bb2697'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'fabrique',
    'router_path' => 'fabrique',
    'link_title' => 'Fabrique',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'uuid' => 'cbcae01d-af54-4264-a92c-a8dd25bb2697',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Fabrique');

  return $menu_uuid_links;
}
