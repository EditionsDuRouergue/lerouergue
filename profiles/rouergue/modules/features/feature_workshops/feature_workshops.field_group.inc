<?php
/**
 * @file
 * feature_workshops.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_workshops_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pdf_viewer|node|workshops|full';
  $field_group->group_name = 'group_pdf_viewer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'workshops';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lecteur PDF',
    'weight' => '18',
    'children' => array(
      0 => 'field_inner_pages',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Lecteur PDF',
      'instance_settings' => array(
        'id' => 'workshop-pdf',
        'classes' => 'modal fade',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pdf_viewer|node|workshops|full'] = $field_group;

  return $export;
}
