<?php
/**
 * @file
 * feature_forms.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function feature_forms_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Demande de catalogue';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'catalog_request_link';
  $fe_block_boxes->body = '<p><a class="btn btn-primary" href="/demande-de-catalogue">Demande de catalogue</a></p>
';

  $export['catalog_request_link'] = $fe_block_boxes;

  return $export;
}
