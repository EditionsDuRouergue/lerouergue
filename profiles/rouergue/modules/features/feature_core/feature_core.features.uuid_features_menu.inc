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

  // Exported menu link: 5d2b8e31-b26e-4491-960e-f00a7c060995
  $menu_uuid_links['5d2b8e31-b26e-4491-960e-f00a7c060995'] = array(
    'menu_name' => 'management',
    'link_path' => 'tri-actualites',
    'router_path' => 'tri-actualites',
    'link_title' => 'Tri des actualités',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_tri-des-actualits:tri-actualites',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'uuid' => '5d2b8e31-b26e-4491-960e-f00a7c060995',
    'parent_uuid' => '67b5f11f-b62f-4789-a80b-a154425909ae',
  );
  // Exported menu link: 67b5f11f-b62f-4789-a80b-a154425909ae
  $menu_uuid_links['67b5f11f-b62f-4789-a80b-a154425909ae'] = array(
    'menu_name' => 'management',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'ROUERGUE ADMIN',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_rouergue-admin:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'uuid' => '67b5f11f-b62f-4789-a80b-a154425909ae',
    'parent_uuid' => 'ffa6cacc-ae0d-4e81-995c-7a17a380f569',
  );
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
  // Exported menu link: 9feb2a6e-9d52-4796-bff6-da4463097a1b
  $menu_uuid_links['9feb2a6e-9d52-4796-bff6-da4463097a1b'] = array(
    'menu_name' => 'management',
    'router_path' => 'admin/structure/nodequeue/%/view/%',
    'link_title' => 'Tri du bloc nouveautés',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_tri-du-bloc-nouveauts:admin/structure/nodequeue/new_books/view/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'uuid' => '9feb2a6e-9d52-4796-bff6-da4463097a1b',
    'parent_uuid' => '67b5f11f-b62f-4789-a80b-a154425909ae',
    'uuid_path' => 'admin/structure/nodequeue//view/',
  );
  // Exported menu link: bdab40aa-0b1b-430a-b9fb-f08471cac8f6
  $menu_uuid_links['bdab40aa-0b1b-430a-b9fb-f08471cac8f6'] = array(
    'menu_name' => 'management',
    'link_path' => 'catalogue/liste-nouveautes',
    'router_path' => 'catalogue/liste-nouveautes',
    'link_title' => 'Liste des nouveautés',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_liste-des-nouveauts:catalogue/liste-nouveautes',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'uuid' => 'bdab40aa-0b1b-430a-b9fb-f08471cac8f6',
    'parent_uuid' => '67b5f11f-b62f-4789-a80b-a154425909ae',
  );
  // Exported menu link: ffa6cacc-ae0d-4e81-995c-7a17a380f569
  $menu_uuid_links['ffa6cacc-ae0d-4e81-995c-7a17a380f569'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin',
    'router_path' => 'admin',
    'link_title' => 'Administration',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 9,
    'uuid' => 'ffa6cacc-ae0d-4e81-995c-7a17a380f569',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Accueil');
  t('Administration');
  t('Liste des nouveautés');
  t('ROUERGUE ADMIN');
  t('Tri des actualités');
  t('Tri du bloc nouveautés');

  return $menu_uuid_links;
}
