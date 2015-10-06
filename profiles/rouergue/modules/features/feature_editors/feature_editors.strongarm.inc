<?php
/**
 * @file
 * feature_editors.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_editors_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_profiles';
  $strongarm->value = array(
    1 => array(
      'name' => 'webmaster',
      'usertab' => 1,
      'filesize' => '0',
      'quota' => '0',
      'tuquota' => '0',
      'extensions' => '*',
      'dimensions' => '1200x1200',
      'filenum' => '0',
      'directories' => array(
        0 => array(
          'name' => '.',
          'subnav' => 1,
          'browse' => 1,
          'upload' => 1,
          'thumb' => 1,
          'delete' => 1,
          'resize' => 1,
          'mkdir' => 1,
          'rmdir' => 1,
        ),
      ),
      'thumbnails' => array(
        0 => array(
          'name' => 'Small',
          'dimensions' => '90x90',
          'prefix' => 'small_',
          'suffix' => '',
        ),
        1 => array(
          'name' => 'Medium',
          'dimensions' => '120x120',
          'prefix' => 'medium_',
          'suffix' => '',
        ),
        2 => array(
          'name' => 'Large',
          'dimensions' => '180x180',
          'prefix' => 'large_',
          'suffix' => '',
        ),
      ),
      'mkdirnum' => '0',
    ),
    2 => array(
      'name' => 'Sample profile',
      'usertab' => 1,
      'filesize' => 1,
      'quota' => 2,
      'tuquota' => 0,
      'extensions' => 'gif png jpg jpeg',
      'dimensions' => '800x600',
      'filenum' => 1,
      'directories' => array(
        0 => array(
          'name' => 'u%uid',
          'subnav' => 0,
          'browse' => 1,
          'upload' => 1,
          'thumb' => 1,
          'delete' => 0,
          'resize' => 0,
          'mkdir' => 0,
          'rmdir' => 0,
        ),
      ),
      'thumbnails' => array(
        0 => array(
          'name' => 'Thumb',
          'dimensions' => '90x90',
          'prefix' => 'thumb_',
          'suffix' => '',
        ),
      ),
      'mkdirnum' => 2,
    ),
  );
  $export['imce_profiles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imce_roles_profiles';
  $strongarm->value = array(
    30037204 => array(
      'weight' => '0',
      'soundcloud_pid' => 0,
      'vimeo_pid' => 0,
      'public_pid' => 0,
    ),
    7178059 => array(
      'weight' => '0',
      'soundcloud_pid' => 0,
      'vimeo_pid' => 0,
      'public_pid' => 0,
    ),
    231346920 => array(
      'weight' => '0',
      'soundcloud_pid' => '1',
      'vimeo_pid' => '1',
      'public_pid' => '1',
    ),
    2 => array(
      'weight' => 11,
      'soundcloud_pid' => 0,
      'vimeo_pid' => 0,
      'public_pid' => 0,
    ),
    1 => array(
      'weight' => 12,
      'soundcloud_pid' => 0,
      'vimeo_pid' => 0,
      'public_pid' => 0,
    ),
  );
  $export['imce_roles_profiles'] = $strongarm;

  return $export;
}
