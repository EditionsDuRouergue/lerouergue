<?php
function rouergue_mistral_settings_form() {
	$form['rouergue_cover_images'] = array(
			'#type' => 'fieldset',
			'#title' => t('Cover images'),
	);
	$form['rouergue_cover_images']['cover_images_url'] = array(
			'#type' => 'textfield',
			'#title' => t('Cover images URL'),
			'#description' => t('Type in the URL which the book cover images are available from.'),
			'#size' => 100,
			'#default_value' => variable_get('cover_images_url', 'http://rouergue.abrege.net/util/couv_rouergue/'),
	);
	$form['rouergue_cover_images']['default_cover_image'] = array(
			'#type' => 'textfield',
			'#title' => t('Default image filename'),
			'#description' => t('Name of the default image for cover pages.'),
			'#size' => 100,
			'#default_value' => variable_get('default_cover_image', 'article-cover-400x600.png'),
	);
	
	$form['rouergue_contributor_pictures'] = array(
			'#type' => 'fieldset',
			'#title' => t('Contributor pictures'),
	);
	$form['rouergue_contributor_pictures']['contributor_pictures_url'] = array(
			'#type' => 'textfield',
			'#title' => t('Contributor pictures URL'),
			'#description' => t('Type in the URL which the contributor pictures are available from.'),
			'#size' => 100,
			'#default_value' => variable_get('contributor_pictures_url', 'http://rouergue.abrege.net/util/auteurs_rouergue/'),
	);
	$form['rouergue_contributor_pictures']['default_contributor_picture'] = array(
			'#type' => 'textfield',
			'#title' => t('Default image filename'),
			'#description' => t('Name of the default image for cover pages.'),
			'#size' => 100,
			'#default_value' => variable_get('default_contributor_picture', 'contributor-pic-400x600.png'),
	);
	
	$form['rouergue_import_settings'] = array(
			'#type' => 'fieldset',
			'#title' => t('Mistral data import settings'),
	);
	$form['rouergue_import_settings']['dump_directory'] = array(
			'#type' => 'textfield',
			'#title' => t('Dump archive directory'),
			'#description' => t('Type in the URL which the contributor pictures are available from.'),
			'#size' => 100,
			'#default_value' => variable_get('dump_directory', $_SERVER['DOCUMENT_ROOT']),
	);
	$form['rouergue_import_settings']['dump_filename'] = array(
			'#type' => 'textfield',
			'#title' => t('Dump archive filename'),
			'#description' => t('Name of the default image for cover pages.'),
			'#size' => 100,
			'#default_value' => variable_get('dump_filename', 'mistral_site_rouergue.zip'),
	);

	return system_settings_form($form);
}