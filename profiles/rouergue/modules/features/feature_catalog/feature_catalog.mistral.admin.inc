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
	$form['rouergue_import_settings']['rouergue_mistral_dumps_directory'] = array(
			'#type' => 'textfield',
			'#title' => t('Dump archive directory'),
			'#description' => t('Type in the URL which the contributor pictures are available from.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_mistral_dumps_directory', $_SERVER['DOCUMENT_ROOT'] . '/mistral_dumps/'),
	);
	$form['rouergue_import_settings']['rouergue_mistral_dump_filename'] = array(
			'#type' => 'textfield',
			'#title' => t('Dump archive filename'),
			'#description' => t('Name of the default image for cover pages.'),
			'#size' => 100,
			'#default_value' => variable_get('rouergue_mistral_dump_filename', 'mistral_site_rouergue.sql'),
	);
	$form['rouergue_import_settings']['rouergue_mistral_sync_day'] = array(
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