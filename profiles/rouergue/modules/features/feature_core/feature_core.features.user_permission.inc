<?php
/**
 * @file
 * feature_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use custom search'.
  $permissions['use custom search'] = array(
    'name' => 'use custom search',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'redactor' => 'redactor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'custom_search',
  );

  return $permissions;
}
