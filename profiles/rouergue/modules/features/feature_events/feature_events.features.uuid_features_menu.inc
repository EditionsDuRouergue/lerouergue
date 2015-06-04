<?php
/**
 * @file
 * feature_events.features.uuid_features_menu.inc
 */

/**
 * Implements hook_menu_default_uuid_features_menu().
 */
function feature_events_menu_default_uuid_features_menu() {
  $menu_uuid_links = array();

  // Exported menu link: 7ace2244-3a37-4448-95dc-05d162182be0
  $menu_uuid_links['7ace2244-3a37-4448-95dc-05d162182be0'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'agenda',
    'router_path' => 'agenda',
    'link_title' => 'Agenda',
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
    'weight' => -47,
    'uuid' => '7ace2244-3a37-4448-95dc-05d162182be0',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');

  return $menu_uuid_links;
}
