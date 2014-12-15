<?php
/**
 * @file
 * feature_catalog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_catalog_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_couv_wrapper|node|article|full';
  $field_group->group_name = 'group_couv_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Couverture Wrapper',
    'weight' => '2',
    'children' => array(
      0 => 'field_cover_image',
      1 => 'field_publication_status',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Couverture Wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-couv-wrapper field-group-div couvWrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_couv_wrapper|node|article|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_infos_article|node|article|full';
  $field_group->group_name = 'group_infos_article';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Infos',
    'weight' => '5',
    'children' => array(
      0 => 'field_format',
      1 => 'field_gencod',
      2 => 'field_isbn',
      3 => 'field_number_pages',
      4 => 'field_price',
      5 => 'field_release_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Infos',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-infos-article field-group-div infosWrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_infos_article|node|article|full'] = $field_group;

  return $export;
}
