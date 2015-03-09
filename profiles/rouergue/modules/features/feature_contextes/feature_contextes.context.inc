<?php
/**
 * @file
 * feature_contextes.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_contextes_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all';
  $context->description = 'All pages';
  $context->tag = 'Layout';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'custom_search_blocks-1' => array(
          'module' => 'custom_search_blocks',
          'delta' => '1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'content',
          'weight' => '-10',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'feature_core-rouergue_copyright' => array(
          'module' => 'feature_core',
          'delta' => 'rouergue_copyright',
          'region' => 'footer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages');
  t('Layout');
  $export['all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'Front page only';
  $context->tag = 'Layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news-news_block' => array(
          'module' => 'views',
          'delta' => 'news-news_block',
          'region' => 'content',
          'weight' => '-29',
        ),
        'views-first_level_universes-block' => array(
          'module' => 'views',
          'delta' => 'first_level_universes-block',
          'region' => 'content',
          'weight' => '-28',
        ),
        'views-catalog-catalog_new_books_block' => array(
          'module' => 'views',
          'delta' => 'catalog-catalog_new_books_block',
          'region' => 'content',
          'weight' => '-27',
        ),
        'views-events-agenda_front_block' => array(
          'module' => 'views',
          'delta' => 'events-agenda_front_block',
          'region' => 'content',
          'weight' => '-26',
        ),
        'views-workshops-workshops_front_block' => array(
          'module' => 'views',
          'delta' => 'workshops-workshops_front_block',
          'region' => 'content',
          'weight' => '-25',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front page only');
  t('Layout');
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'not-front';
  $context->description = 'All pages but front';
  $context->tag = 'Layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~catalogue/multi-criteres' => '~catalogue/multi-criteres',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-universe' => array(
          'module' => 'menu',
          'delta' => 'menu-universe',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages but front');
  t('Layout');
  $export['not-front'] = $context;

  return $export;
}
