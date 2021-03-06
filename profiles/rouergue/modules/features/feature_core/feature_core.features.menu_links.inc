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

  // Exported menu link: management_liste-des-nouveauts:catalogue/liste-nouveautes
  $menu_links['management_liste-des-nouveauts:catalogue/liste-nouveautes'] = array(
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
    'customized' => 1,
    'parent_identifier' => 'management_rouergue-admin:user',
  );
  // Exported menu link: management_rouergue-admin:user
  $menu_links['management_rouergue-admin:user'] = array(
    'menu_name' => 'management',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'ROUERGUE ADMIN',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_rouergue-admin:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: management_search-autocomplete-settings:admin/config/search/search_autocomplete
  $menu_links['management_search-autocomplete-settings:admin/config/search/search_autocomplete'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/search_autocomplete',
    'router_path' => 'admin/config/search/search_autocomplete',
    'link_title' => 'Search Autocomplete settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Choose settings and suggestion items for autocompletion in input forms.',
      ),
      'identifier' => 'management_search-autocomplete-settings:admin/config/search/search_autocomplete',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_search-and-metadata:admin/config/search',
  );
  // Exported menu link: management_tri-des-actualits:tri-actualites
  $menu_links['management_tri-des-actualits:tri-actualites'] = array(
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
    'customized' => 1,
    'parent_identifier' => 'management_rouergue-admin:user',
  );
  // Exported menu link: management_tri-du-bloc-nouveauts:admin/structure/nodequeue/new_books/view/1
  $menu_links['management_tri-du-bloc-nouveauts:admin/structure/nodequeue/new_books/view/1'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/nodequeue/new_books/view/1',
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
    'customized' => 1,
    'parent_identifier' => 'management_rouergue-admin:user',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Liste des nouveautés');
  t('ROUERGUE ADMIN');
  t('Search Autocomplete settings');
  t('Tri des actualités');
  t('Tri du bloc nouveautés');

  return $menu_links;
}
