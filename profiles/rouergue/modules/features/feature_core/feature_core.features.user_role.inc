<?php
/**
 * @file
 * feature_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_core_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 4,
    'machine_name' => '',
  );

  // Exported role: redactor.
  $roles['redactor'] = array(
    'name' => 'redactor',
    'weight' => 2,
    'machine_name' => '',
  );

  // Exported role: webmaster.
  $roles['webmaster'] = array(
    'name' => 'webmaster',
    'weight' => 3,
    'machine_name' => '',
  );

  return $roles;
}
