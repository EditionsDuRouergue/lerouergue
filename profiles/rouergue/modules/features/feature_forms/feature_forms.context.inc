<?php
/**
 * @file
 * feature_forms.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_forms_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'catalog_request';
  $context->description = '';
  $context->tag = 'Forms';
  $context->conditions = array(
    'book' => array(
      'values' => array(
        'book-toc-2949' => 'book-toc-2949',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Forms');
  $export['catalog_request'] = $context;

  return $export;
}
