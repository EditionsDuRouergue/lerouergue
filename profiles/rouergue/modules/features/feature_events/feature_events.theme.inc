<?php
/**
 * Returns the rendered site slogan.
*
* @ingroup themeable
*/
function theme_rouergue_agenda_nav($variables) {
	$output = '<ul class="nav nav-tabs" role="tablist">';
	foreach ($variables['agenda_nav_links'] as $title=>$link) {
	  $output .= '<li>' . l($title, arg(0) . '/' . $link) . '</li>';
	}
	$output .= '<ul>';
	return $output;
}