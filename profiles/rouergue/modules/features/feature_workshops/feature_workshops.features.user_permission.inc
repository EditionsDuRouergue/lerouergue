<?php
/**
 * @file
 * feature_workshops.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_workshops_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create workshops content'.
  $permissions['create workshops content'] = array(
    'name' => 'create workshops content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any workshops content'.
  $permissions['delete any workshops content'] = array(
    'name' => 'delete any workshops content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own workshops content'.
  $permissions['delete own workshops content'] = array(
    'name' => 'delete own workshops content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any workshops content'.
  $permissions['edit any workshops content'] = array(
    'name' => 'edit any workshops content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own workshops content'.
  $permissions['edit own workshops content'] = array(
    'name' => 'edit own workshops content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  return $permissions;
}
