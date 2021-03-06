<?php
/**
 * @file
 * feature_workshops.box.inc
 */

/**
 * Implements hook_default_box().
 */
function feature_workshops_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'fabrique_title';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Titre fabrique pour le carousel';
  $box->options = array(
    'body' => array(
      'value' => 'fabrique
',
      'format' => 'plain_text',
    ),
    'additional_classes' => '.fabrique_title',
  );
  $export['fabrique_title'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'workshops_header';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Description de la fabrique';
  $box->options = array(
    'body' => array(
      'value' => '<img alt="" class="img-responsive" src="/sites/default/files/fabrique-top.png"/>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['workshops_header'] = $box;

  return $export;
}
