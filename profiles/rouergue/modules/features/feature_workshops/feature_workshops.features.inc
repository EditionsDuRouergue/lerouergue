<?php
/**
 * @file
 * feature_workshops.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_workshops_ctools_plugin_api($module = NULL, $api = NULL) {
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
function feature_workshops_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_workshops_image_default_styles() {
  $styles = array();

  // Exported image style: workshop-block.
  $styles['workshop-block'] = array(
    'label' => 'workshop-block',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 260,
          'height' => 200,
        ),
        'weight' => -10,
      ),
      9 => array(
        'name' => 'adaptive_image',
        'data' => array(
          'resolutions' => '1382, 992, 768, 480',
          'mobile_first' => 1,
          'height' => '',
          'width' => 1382,
          'upscale' => '',
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: workshop-carousel.
  $styles['workshop-carousel'] = array(
    'label' => 'workshop-carousel',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 340,
        ),
        'weight' => -10,
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
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: workshop-list.
  $styles['workshop-list'] = array(
    'label' => 'workshop-list',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 260,
          'height' => 200,
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
function feature_workshops_node_info() {
  $items = array(
    'workshops' => array(
      'name' => t('Workshop'),
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
