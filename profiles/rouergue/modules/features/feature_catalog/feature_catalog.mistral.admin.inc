<?php
function rouergue_mistral_settings_form() {
	// Data store
	$form['data_store_settings'] = array(
			'#type' => 'fieldset',
			'#title' => t('Data store settings'),
	);
	$form['data_store_settings']['rouergue_data_store'] = array(
			'#type' => 'textfield',
			'#title' => t('Data store'),
			'#description' => t('Type in the absolute path which the Rouergue data (images, dump) are available from.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_data_store', ''),
	);
	
	// Mistral data import settings
	$form['mistral_import_settings'] = array(
			'#type' => 'fieldset',
			'#title' => t('Mistral data import settings'),
	);
	$form['mistral_import_settings']['rouergue_mistral_dumps_directory'] = array(
			'#type' => 'textfield',
			'#title' => t('Dump archive directory'),
			'#description' => t('Type in the URL which the contributor pictures are available from.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_mistral_dumps_directory', '/mistral_dumps/'),
	);
	$form['mistral_import_settings']['rouergue_mistral_dump_filename'] = array(
			'#type' => 'textfield',
			'#title' => t('Dump archive filename'),
			'#description' => t('Name of the default image for cover pages.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_mistral_dump_filename', 'mistral_site_rouergue.sql'),
	);
	$form['mistral_import_settings']['rouergue_mistral_sync_day'] = array(
			'#type' => 'radios',
			'#title' => t('Synchronization day'),
			'#options' => array(
					'1' => 'lundi',
					'2' => 'mardi',
					'3' => 'mercredi',
					'4' => 'jeudi',
					'5' => 'vendredi',
					'6' => 'samedi',
					'7' => 'dimanche',
			),
			'#default_value' => variable_get('rouergue_mistral_sync_day', 4),
			'#description' => t('Day in week to launch the automatic synchronization process.'),
	);
	
	// Rouergue images import settings
	$form['rouergue_import_settings'] = array(
			'#type' => 'fieldset',
			'#title' => t('Rouergue images import setting'),
	);
	// Cover images
	$form['rouergue_import_settings']['rouergue_cover_images_dir'] = array(
			'#type' => 'textfield',
			'#title' => t('Cover images directory'),
			'#description' => t('Type in the absolute path which the book cover images are available from.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_cover_images_dir', 'catalog/cover-images'),
	);
	$form['rouergue_import_settings']['rouergue_default_cover_image'] = array(
			'#type' => 'textfield',
			'#title' => t('Default cover image filename'),
			'#description' => t('Name of the default image for cover pages.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_default_cover_image', 'article-cover-400x600.png'),
	);
	// Contributor pictures
	$form['rouergue_import_settings']['rouergue_contributor_pictures_dir'] = array(
			'#type' => 'textfield',
			'#title' => t('Contributor pictures directory'),
			'#description' => t('Type in the absolute path which the contributor pictures are available from.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_contributor_pictures_dir', 'catalog/contributor-pictures'),
	);
	$form['rouergue_import_settings']['rouergue_default_contributor_picture'] = array(
			'#type' => 'textfield',
			'#title' => t('Default contributor picture filename'),
			'#description' => t('Name of the default image for cover pages.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_default_contributor_picture', 'contributor-pic-400x600.png'),
	);

	// Drush command settings
	$form['rouergue_drush_settings'] = array(
			'#type' => 'fieldset',
			'#title' => t('Drush settings'),
	);
	$form['rouergue_drush_settings']['rouergue_drush_path'] = array(
			'#type' => 'textfield',
			'#title' => t('Drush path'),
			'#description' => t('Path to drush command.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_drush_path', '/opt/drush/drush'),
	);
	return system_settings_form($form);
}