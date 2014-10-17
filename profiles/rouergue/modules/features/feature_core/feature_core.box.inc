<?php
/**
 * @file
 * feature_core.box.inc
 */

/**
 * Implements hook_default_box().
 */
function feature_core_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'front_page_message';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Message page d\'accueil';
  $box->options = array(
    'body' => array(
      'value' => '<p class="rtecenter"><span style="font-size:18px"><strong>Phrase d’accroche</strong></span><br />
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis congue, lorem et dictum iaculis, quam enim molestie sem,<br />
vel feugiat lacus leo non felis. Etiam at nunc convallis nisl hendrerit pharetra sed vulputate risus.</p>
',
      'format' => 'full_html',
    ),
  );
  $export['front_page_message'] = $box;

  return $export;
}
