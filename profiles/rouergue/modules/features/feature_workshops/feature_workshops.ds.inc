<?php
/**
 * @file
 * feature_workshops.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function feature_workshops_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|workshops|carousel';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'workshops';
  $ds_fieldsetting->view_mode = 'carousel';
  $ds_fieldsetting->settings = array(
    'fabrique_title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|workshops|carousel'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|workshops|list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'workshops';
  $ds_fieldsetting->view_mode = 'list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|workshops|list'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function feature_workshops_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'fabrique_title';
  $ds_field->label = 'fabrique_title';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'boxes|fabrique_title',
    'block_render' => '1',
  );
  $export['fabrique_title'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_workshops_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|workshops|block';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'workshops';
  $ds_layout->view_mode = 'block';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_video',
        1 => 'field_sound',
      ),
    ),
    'fields' => array(
      'field_video' => 'central',
      'field_sound' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|workshops|block'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|workshops|carousel';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'workshops';
  $ds_layout->view_mode = 'carousel';
  $ds_layout->layout = 'bootstrap_6_6';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'fabrique_title',
        1 => 'title',
      ),
      'right' => array(
        2 => 'field_workshop_image',
      ),
    ),
    'fields' => array(
      'fabrique_title' => 'left',
      'title' => 'left',
      'field_workshop_image' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|workshops|carousel'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|workshops|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'workshops';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'body',
        1 => 'field_planned_release_date',
        2 => 'field_gallery',
        3 => 'field_event_author',
      ),
    ),
    'fields' => array(
      'body' => 'central',
      'field_planned_release_date' => 'central',
      'field_gallery' => 'central',
      'field_event_author' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|workshops|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|workshops|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'workshops';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_planned_release_date',
        1 => 'field_inner_pages',
        2 => 'body',
        3 => 'field_collection_gallery',
        4 => 'field_event_author',
      ),
    ),
    'fields' => array(
      'field_planned_release_date' => 'central',
      'field_inner_pages' => 'central',
      'body' => 'central',
      'field_collection_gallery' => 'central',
      'field_event_author' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|workshops|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|workshops|list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'workshops';
  $ds_layout->view_mode = 'list';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_workshop_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_workshop_image' => 'central',
      'title' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|workshops|list'] = $ds_layout;

  return $export;
}
