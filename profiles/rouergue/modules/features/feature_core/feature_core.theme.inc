<?php
/**
 * Returns the rendered site slogan.
 *
 * @ingroup themeable
 */
function theme_rouergue_copyright($variables) {
	return '<span class="rouergue-copyright-symbol">&copy;</span> ' . $variables['copyright-text'] . ' <span class="rouergue-copyright-symbol">' . date('Y') . '</span>';
}