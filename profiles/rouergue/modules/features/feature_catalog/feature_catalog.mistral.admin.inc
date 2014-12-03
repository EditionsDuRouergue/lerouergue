<?php
function rouergue_mistral_settings_form() {
	$form['rouergue_mistral_settings'] = array(
			'#type' => 'fieldset',
			'#title' => t('Mistral import settings'),
	);
	$form['rouergue_mistral_settings']['cover_images_url'] = array(
			'#type' => 'textfield',
			'#title' => t('Cover images URL'),
			'#description' => t('Type in the URL which the book cover images are available from.'),
			'#size' => 100,
			'#default_value' => variable_get('cover_images_url', 'http://rouergue.abrege.net/util/couv_rouergue/'),
	);
	$form['rouergue_mistral_settings']['default_cover_image_name'] = array(
			'#type' => 'textfield',
			'#title' => t('URL'),
			'#description' => t('Name of the default image for cover pages.'),
			'#size' => 100,
			'#default_value' => variable_get('default_image_name', 'article-cover-400x600.png'),
	);

	return system_settings_form($form);
}