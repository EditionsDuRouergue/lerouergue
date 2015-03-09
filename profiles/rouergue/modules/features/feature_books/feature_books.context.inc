<?php
/**
 * @file
 * feature_books.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_books_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'house';
  $context->description = 'Rouergue House presentation';
  $context->tag = 'Books';
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
        'book-navigation' => array(
          'module' => 'book',
          'delta' => 'navigation',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Books');
  t('Rouergue House presentation');
  $export['house'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pro';
  $context->description = 'Pro space';
  $context->tag = 'Books';
  $context->conditions = array(
    'book' => array(
      'values' => array(
        'book-toc-2953' => 'book-toc-2953',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'book-navigation' => array(
          'module' => 'book',
          'delta' => 'navigation',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Books');
  t('Pro space');
  $export['pro'] = $context;

  return $export;
}
