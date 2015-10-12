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

function rouergue_bootstrap_field__field_inner_pages($variables) {
	$output = '<div class="modal fade" id="rouergue-pdf-viewer" tabindex="-1" role="dialog" aria-labelledby="ModalLabel" aria-hidden="true">';
		$output .= '<div class="modal-dialog">';
			$output .= '<div class="modal-content">';
				$output .= '<div class="modal-header">';
					$output .= '<button type="button" class="close" data-dismiss="modal">';
						$output .= '<span aria-hidden="true">&times;</span><span class="sr-only">Fermer</span>';
					$output .= '</button>';
					$output .= '<h4 class="modal-title" id="ModalLabel">feuilleter</h4>';
				$output .= '</div>';
				$output .= '<div class="modal-body">';
					$output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
				  foreach ($variables['items'] as $delta => $item) {
				    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
				    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
				  }
				  $output .= '</div>';
				$output .= '</div>';
			$output .= '</div>';
		$output .= '</div>';
	$output .= '</div>';

  return $output;
}

drupal_add_js(drupal_get_path('theme', 'rouergue_bootstrap') .'/js/main.js', array('type' => 'file', 'scope' => 'footer'));
drupal_add_js(drupal_get_path('theme', 'rouergue_bootstrap') . '/js/jquery.matchHeight-min.js', array('type' => 'file', 'scope' => 'footer'));

