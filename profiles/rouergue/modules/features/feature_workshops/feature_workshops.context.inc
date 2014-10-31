<?php
/**
 * @file
 * feature_workshops.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_workshops_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'workshop';
  $context->description = '';
  $context->tag = 'Layout';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'workshops' => 'workshops',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-workshops-workshop_media_block' => array(
          'module' => 'views',
          'delta' => 'workshops-workshop_media_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-201361d91932b60a3949d0a85fbf3909' => array(
          'module' => 'views',
          'delta' => '201361d91932b60a3949d0a85fbf3909',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-workshops-workshop_page_block' => array(
          'module' => 'views',
          'delta' => 'workshops-workshop_page_block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  $export['workshop'] = $context;

  return $export;
}
