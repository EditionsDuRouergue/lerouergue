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

  // Exported menu link: 23dfce5b-3d30-4e34-8c1f-2beb2a83da6b
  $menu_uuid_links['23dfce5b-3d30-4e34-8c1f-2beb2a83da6b'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'workshops',
    'router_path' => 'workshops',
    'link_title' => 'Workshops',
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
    'weight' => 4,
    'uuid' => '23dfce5b-3d30-4e34-8c1f-2beb2a83da6b',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Workshops');

  return $menu_uuid_links;
}
