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
  $context->name = 'article_page';
  $context->description = '';
  $context->tag = 'Catalog';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-catalog-same_author_books' => array(
          'module' => 'views',
          'delta' => 'catalog-same_author_books',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-catalog-same_universe_books' => array(
          'module' => 'views',
          'delta' => 'catalog-same_universe_books',
          'region' => 'content',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Catalog');
  $export['article_page'] = $context;

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
          'weight' => '9',
        ),
        'views-events-agenda_author_block' => array(
          'module' => 'views',
          'delta' => 'events-agenda_author_block',
          'region' => 'content',
          'weight' => '10',
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'catalog';
  $context->description = 'Universes pages';
  $context->tag = 'Layout';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'universe' => 'universe',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-3d8281d3e9ec9ca5efce3f3c9ba806f7' => array(
          'module' => 'views',
          'delta' => '3d8281d3e9ec9ca5efce3f3c9ba806f7',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views--exp-universes-page' => array(
          'module' => 'views',
          'delta' => '-exp-universes-page',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'feature_catalog-rouergue_catalog_links' => array(
          'module' => 'feature_catalog',
          'delta' => 'rouergue_catalog_links',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  t('Universes pages');
  $export['catalog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'catalog_multi_criteria';
  $context->description = '';
  $context->tag = 'Layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'catalogue/multi-criteres' => 'catalogue/multi-criteres',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'feature_catalog-rouergue_catalog_links' => array(
          'module' => 'feature_catalog',
          'delta' => 'rouergue_catalog_links',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views--exp-catalog-catalog_multi' => array(
          'module' => 'views',
          'delta' => '-exp-catalog-catalog_multi',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  $export['catalog_multi_criteria'] = $context;

  return $export;
}
