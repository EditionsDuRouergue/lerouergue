<?php
/**
 * @file
 * feature_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function feature_news_image_default_styles() {
  $styles = array();

  // Exported image style: news-block.
  $styles['news-block'] = array(
    'label' => 'news-block',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1140,
          'height' => 430,
        ),
        'weight' => 1,
      ),
      2 => array(
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

  // Exported image style: news-block-min.
  $styles['news-block-min'] = array(
    'label' => 'news-block-min',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 75,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function feature_news_node_info() {
  $items = array(
    'news' => array(
      'name' => t('Actualité'),
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
