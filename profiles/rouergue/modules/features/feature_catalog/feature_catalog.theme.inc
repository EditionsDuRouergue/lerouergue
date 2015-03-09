<?php
/**
 * Returns the rendered site slogan.
*
* @ingroup themeable
*/
function theme_rouergue_catalog_links($variables) {
	return '<a href="' . $variables['catalog_links']['link_path'] . '" >' . $variables['catalog_links']['link_text'] . '</a>';
}