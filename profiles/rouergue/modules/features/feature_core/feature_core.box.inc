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
  $box->delta = 'footer_social_links';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Liens vers les pages Facebook.';
  $box->options = array(
    'body' => array(
      'value' => '<p class="rteright"><a href="https://fr-fr.facebook.com/rouergueadulte" target="_blank">ROUERGUE</a>&nbsp;<img alt="" src="/sites/default/files/logo_fb.png" style="float:right" /></p>

<p class="rteright"><a href="https://fr-fr.facebook.com/rouerguejeunesse" target="_blank">ROUERGUE jeunesse&nbsp;</a><img alt="" src="/sites/default/files/logo_fb.png" style="float:right; text-align:right" /></p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['footer_social_links'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'front_page_message';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Message page d\'accueil';
  $box->options = array(
    'body' => array(
      'value' => '<p class="rteright"><span style="font-size:18px">retrouvez-nous sur nos deux pages facebook pour échanger et commenter</span></p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['front_page_message'] = $box;

  return $export;
}
