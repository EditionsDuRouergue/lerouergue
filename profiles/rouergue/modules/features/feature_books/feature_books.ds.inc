<?php
/**
 * @file
 * feature_books.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function feature_books_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|livre_couv_li_e';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'livre_couv_li_e';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => 'tittle-couv-link',
      ),
    ),
  );
  $export['node|article|livre_couv_li_e'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_books_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|livre_couv_li_e';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'livre_couv_li_e';
  $ds_layout->layout = 'rouergue_12_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_cover_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_cover_image' => 'top',
      'title' => 'top',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'middle' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|livre_couv_li_e'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function feature_books_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'livre_couv_li_e';
  $ds_view_mode->label = 'Livre couv liée';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['livre_couv_li_e'] = $ds_view_mode;

  return $export;
}
