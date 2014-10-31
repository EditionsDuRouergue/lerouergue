<?php

/**
 * @file
 * template.php
 */

// function rouergue_bootstrap_menu_local_action($variables) {
// 	return theme_menu_local_action($variables);
// }

function rouergue_bootstrap_menu_link($variables) {
	return theme_menu_link($variables);
}

if (!drupal_is_front_page()) {
	drupal_add_js(drupal_get_path('theme', 'rouergue_bootstrap') .'/js/universes_navigation.js', array('type' => 'file', 'scope' => 'footer'));
}

	drupal_add_js(drupal_get_path('theme', 'rouergue_bootstrap') .'/js/main.js', array('type' => 'file', 'scope' => 'footer'));

