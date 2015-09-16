<?php
/**
 * @file
 * feature_catalog.box.inc
 */

/**
 * Implements hook_default_box().
 */
function feature_catalog_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'logo_bxlivres';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'logo_bxlivres';
  $box->options = array(
    'body' => array(
      'value' => '<p class="rtecenter"><img alt="" src="/sites/default/files/logo_bxlivres.png" /></p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['logo_bxlivres'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'logo_jeunesse';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'logo_jeunesse';
  $box->options = array(
    'body' => array(
      'value' => '<p class="rtecenter"><img alt="" src="/sites/default/files/logo_jeunesse.png" style="height:157px; width:150px" /></p>
',
      'format' => 'full_html',
    ),
  );
  $export['logo_jeunesse'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'logo_labrune';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'logo_labrune';
  $box->options = array(
    'body' => array(
      'value' => '<p class="rtecenter"><img alt="" src="/sites/default/files/logo_labrune.png" style="height:106px; width:150px" /></p>
',
      'format' => 'full_html',
    ),
  );
  $export['logo_labrune'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'logo_polars';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'logo_polars';
  $box->options = array(
    'body' => array(
      'value' => '<p class="rtecenter"><img alt="" src="/sites/default/files/logo_polars.png" style="height:96px; width:150px" /></p>
',
      'format' => 'full_html',
    ),
  );
  $export['logo_polars'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'logo_romans';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'logo_romans';
  $box->options = array(
    'body' => array(
      'value' => '<p class="rtecenter"><img alt="" src="/sites/default/files/logo_romans.png" style="height:50px; width:150px" /></p>
',
      'format' => 'full_html',
    ),
  );
  $export['logo_romans'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'logo_simple';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'logo_simple';
  $box->options = array(
    'body' => array(
      'value' => '<p class="rtecenter"><img alt="" src="/sites/default/files/logo_livres.png" style="height:50px; width:150px" /></p>
',
      'format' => 'full_html',
    ),
  );
  $export['logo_simple'] = $box;

  return $export;
}
