<?php
/**
 * @file
 * feature_catalog.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_catalog_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access service links'.
  $permissions['access service links'] = array(
    'name' => 'access service links',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'service_links',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create contributor content'.
  $permissions['create contributor content'] = array(
    'name' => 'create contributor content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any contributor content'.
  $permissions['delete any contributor content'] = array(
    'name' => 'delete any contributor content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own contributor content'.
  $permissions['delete own contributor content'] = array(
    'name' => 'delete own contributor content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in functions'.
  $permissions['delete terms in functions'] = array(
    'name' => 'delete terms in functions',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in readership'.
  $permissions['delete terms in readership'] = array(
    'name' => 'delete terms in readership',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in themes'.
  $permissions['delete terms in themes'] = array(
    'name' => 'delete terms in themes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in universe'.
  $permissions['delete terms in universe'] = array(
    'name' => 'delete terms in universe',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any contributor content'.
  $permissions['edit any contributor content'] = array(
    'name' => 'edit any contributor content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own contributor content'.
  $permissions['edit own contributor content'] = array(
    'name' => 'edit own contributor content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in functions'.
  $permissions['edit terms in functions'] = array(
    'name' => 'edit terms in functions',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in readership'.
  $permissions['edit terms in readership'] = array(
    'name' => 'edit terms in readership',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in themes'.
  $permissions['edit terms in themes'] = array(
    'name' => 'edit terms in themes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in universe'.
  $permissions['edit terms in universe'] = array(
    'name' => 'edit terms in universe',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
