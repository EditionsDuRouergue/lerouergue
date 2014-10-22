<?php
/**
 * @file
 * feature_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access draggableviews'.
  $permissions['access draggableviews'] = array(
    'name' => 'access draggableviews',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'draggableviews',
  );

  return $permissions;
}
