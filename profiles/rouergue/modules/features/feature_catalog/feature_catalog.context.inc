<?php
/**
 * @file
 * feature_catalog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_catalog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'author';
  $context->description = 'Author\'s page';
  $context->tag = 'Layout';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'contributor' => 'contributor',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-catalog-author_books' => array(
          'module' => 'views',
          'delta' => 'catalog-author_books',
          'region' => 'content',
          'weight' => '17',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Author\'s page');
  t('Layout');
  $export['author'] = $context;

  return $export;
}
