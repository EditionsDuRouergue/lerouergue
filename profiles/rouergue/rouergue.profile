<?php
/**
 * @file
 * Enables modules and site configuration for the Rouergue site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter install profile selection form.
 *
 * We have to call 'system' here because drupal doesn't seem to pick up on
 * the hook ('cms') at this level in the install process.
 */
function system_form_install_select_profile_form_alter(&$form, $form_state) {
   foreach($form['profile'] as $key => $element) {
     $form['profile'][$key]['#value'] = 'rouergue';
   }
}

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function rouergue_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name.
  $form['site_information']['site_name']['#default_value'] = 'Rouergue';
  $form['server_settings']['site_default_country']['#default_value'] = 'FR';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Paris';
  unset($form['server_settings']['date_default_timezone']['#attributes']);
}