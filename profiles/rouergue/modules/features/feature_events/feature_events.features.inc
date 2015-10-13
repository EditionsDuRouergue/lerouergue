<?php
/**
 * @file
 * feature_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_features_date_format_default().
 */
function feature_events_features_date_format_default() {
  $fdf_config = array();

  $fdf_config[] = array(
    'dfid' => 37,
    'format' => 'd M.',
    'type' => 'custom',
    'locked' => 0,
  );
  $fdf_config[] = array(
    'dfid' => 73,
    'format' => 'd F Y',
    'type' => 'custom',
    'locked' => 0,
  );
  return $fdf_config;
}

/**
 * Implements hook_features_date_type_default().
 */
function feature_events_features_date_type_default() {
  $fdt_config = array();

  $fdt_config[] = array(
    'is_new' => FALSE,
    'module' => '',
    'type' => 'event_date',
    'title' => 'Date événement',
    'locked' => 0,
  );
  return $fdt_config;
}

/**
 * Implements hook_image_default_styles().
 */
function feature_events_image_default_styles() {
  $styles = array();

  // Exported image style: event-block.
  $styles['event-block'] = array(
    'label' => 'event-block',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 265,
          'height' => 200,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'adaptive_image',
        'data' => array(
          'resolutions' => '1382, 992, 768, 480',
          'mobile_first' => 1,
          'height' => '',
          'width' => 1382,
          'upscale' => '',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: event-list.
  $styles['event-list'] = array(
    'label' => 'event-list',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 265,
          'height' => 170,
        ),
        'weight' => 1,
      ),
      6 => array(
        'name' => 'adaptive_image',
        'data' => array(
          'resolutions' => '1382, 992, 768, 480',
          'mobile_first' => 1,
          'height' => '',
          'width' => 1382,
          'upscale' => '',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: event-page.
  $styles['event-page'] = array(
    'label' => 'event-page',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 555,
          'height' => 370,
        ),
        'weight' => 1,
      ),
      8 => array(
        'name' => 'adaptive_image',
        'data' => array(
          'resolutions' => '1382, 992, 768, 480',
          'mobile_first' => 1,
          'height' => '',
          'width' => 1382,
          'upscale' => '',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function feature_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Événement'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
