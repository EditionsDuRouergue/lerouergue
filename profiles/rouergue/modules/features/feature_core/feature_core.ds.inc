<?php
/**
 * @file
 * feature_core.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function feature_core_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'block';
  $ds_view_mode->label = 'Bloc';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['block'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'carousel';
  $ds_view_mode->label = 'Carousel';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['carousel'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'list';
  $ds_view_mode->label = 'Liste';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['list'] = $ds_view_mode;

  return $export;
}
