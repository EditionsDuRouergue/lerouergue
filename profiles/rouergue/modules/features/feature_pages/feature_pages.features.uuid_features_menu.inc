<?php
/**
 * @file
 * feature_pages.features.uuid_features_menu.inc
 */

/**
 * Implements hook_menu_default_uuid_features_menu().
 */
function feature_pages_menu_default_uuid_features_menu() {
  $menu_uuid_links = array();

  // Exported menu link: 7cea1ade-4c0e-448f-8c6f-5788cbbe355b
  $menu_uuid_links['7cea1ade-4c0e-448f-8c6f-5788cbbe355b'] = array(
    'menu_name' => 'menu-footer-menu',
    'router_path' => 'node/%',
    'link_title' => 'Présentation de la maison',
    'options' => array(
      'identifier' => 'menu-footer-menu_prsentation-de-la-maison:node/2865',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'uuid' => '7cea1ade-4c0e-448f-8c6f-5788cbbe355b',
    'uuid_path' => 'node/378e6d5f-5836-4a7e-8880-361e1d856028',
  );
  // Exported menu link: 88632b4a-6f25-4429-9668-aecb2363fa44
  $menu_uuid_links['88632b4a-6f25-4429-9668-aecb2363fa44'] = array(
    'menu_name' => 'menu-footer-menu',
    'router_path' => 'node/%',
    'link_title' => 'Espace Pro',
    'options' => array(
      'identifier' => 'menu-footer-menu_espace-pro:node/2864',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'uuid' => '88632b4a-6f25-4429-9668-aecb2363fa44',
    'uuid_path' => 'node/9e5ceb7a-78d2-4020-b1e8-f45d3263569d',
  );
  // Exported menu link: 95ebb652-0678-42db-bba8-1acf7fee96ae
  $menu_uuid_links['95ebb652-0678-42db-bba8-1acf7fee96ae'] = array(
    'menu_name' => 'menu-footer-menu',
    'router_path' => 'node/%',
    'link_title' => 'Mentions légales',
    'options' => array(
      'identifier' => 'menu-footer-menu_mentions-lgales:node/2866',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 15,
    'uuid' => '95ebb652-0678-42db-bba8-1acf7fee96ae',
    'uuid_path' => 'node/ad22d54d-1ca1-488d-b3ab-4adf635fa594',
  );
  // Exported menu link: e273edd7-f3c6-4145-b7c6-fcbf4cf10342
  $menu_uuid_links['e273edd7-f3c6-4145-b7c6-fcbf4cf10342'] = array(
    'menu_name' => 'menu-footer-menu',
    'router_path' => 'node/%',
    'link_title' => 'Crédits',
    'options' => array(
      'identifier' => 'menu-footer-menu_crdits:node/2867',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'uuid' => 'e273edd7-f3c6-4145-b7c6-fcbf4cf10342',
    'uuid_path' => 'node/dd133df7-d0a3-4397-a2f8-91d5c52c0c18',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Crédits');
  t('Espace Pro');
  t('Mentions légales');
  t('Présentation de la maison');

  return $menu_uuid_links;
}
