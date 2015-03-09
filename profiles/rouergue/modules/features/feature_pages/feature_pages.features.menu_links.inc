<?php
/**
 * @file
 * feature_pages.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_pages_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_crdits:node/2867
  $menu_links['menu-footer-menu_crdits:node/2867'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/2867',
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
    'customized' => 0,
  );
  // Exported menu link: menu-footer-menu_espace-pro:node/2864
  $menu_links['menu-footer-menu_espace-pro:node/2864'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/2864',
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
    'customized' => 0,
  );
  // Exported menu link: menu-footer-menu_mentions-lgales:node/2866
  $menu_links['menu-footer-menu_mentions-lgales:node/2866'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/2866',
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
    'customized' => 0,
  );
  // Exported menu link: menu-footer-menu_prsentation-de-la-maison:node/2865
  $menu_links['menu-footer-menu_prsentation-de-la-maison:node/2865'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/2865',
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
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Crédits');
  t('Espace Pro');
  t('Mentions légales');
  t('Présentation de la maison');


  return $menu_links;
}
