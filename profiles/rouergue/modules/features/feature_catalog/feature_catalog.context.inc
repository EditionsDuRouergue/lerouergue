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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_logo_labrune';
  $context->description = '';
  $context->tag = 'Logos';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        5 => 5,
        42 => 42,
        785 => 785,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'catalogue/litterature/la-brune' => 'catalogue/litterature/la-brune',
        'catalogue/la-brune' => 'catalogue/la-brune',
        'catalogue/numerique/la-brune' => 'catalogue/numerique/la-brune',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-logo_labrune' => array(
          'module' => 'boxes',
          'delta' => 'logo_labrune',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Logos');
  $export['context_logo_labrune'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_logo_polars';
  $context->description = '';
  $context->tag = 'Logos';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        1 => 1,
        23 => 23,
        781 => 781,
        783 => 783,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'catalogue/litterature/polars' => 'catalogue/litterature/polars',
        'catalogue/litterature/polars/*' => 'catalogue/litterature/polars/*',
        'catalogue/numerique/polars' => 'catalogue/numerique/polars',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-logo_polars' => array(
          'module' => 'boxes',
          'delta' => 'logo_polars',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Logos');
  $export['context_logo_polars'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_logo_romans';
  $context->description = '';
  $context->tag = 'Logos';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        13 => 13,
        20 => 20,
        46 => 46,
        779 => 779,
        787 => 787,
        948 => 948,
        949 => 949,
        950 => 950,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'catalogue/litterature/romans' => 'catalogue/litterature/romans',
        'catalogue/litterature/romans/*' => 'catalogue/litterature/romans/*',
        'catalogue/numerique/romans' => 'catalogue/numerique/romans',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-logo_romans' => array(
          'module' => 'boxes',
          'delta' => 'logo_romans',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Logos');
  $export['context_logo_romans'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_logo_rr';
  $context->description = '';
  $context->tag = 'Logos';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        2 => 2,
        3 => 3,
        4 => 4,
        6 => 6,
        7 => 7,
        10 => 10,
        12 => 12,
        15 => 15,
        17 => 17,
        21 => 21,
        22 => 22,
        24 => 24,
        26 => 26,
        27 => 27,
        28 => 28,
        30 => 30,
        35 => 35,
        37 => 37,
        41 => 41,
        44 => 44,
        47 => 47,
        50 => 50,
        51 => 51,
        52 => 52,
        54 => 54,
        778 => 778,
        782 => 782,
        784 => 784,
        786 => 786,
        788 => 788,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'catalogue/epik-fantasy' => 'catalogue/epik-fantasy',
        'catalogue/romans-jeunesse' => 'catalogue/romans-jeunesse',
        'catalogue/romans-jeunesse/*' => 'catalogue/romans-jeunesse/*',
        'catalogue/albums-jeunesse' => 'catalogue/albums-jeunesse',
        'catalogue/albums-jeunesse/*' => 'catalogue/albums-jeunesse/*',
        'catalogue/graphisme-illustrations' => 'catalogue/graphisme-illustrations',
        'catalogue/graphisme-illustrations/*' => 'catalogue/graphisme-illustrations/*',
        'catalogue/numerique/doado' => 'catalogue/numerique/doado',
        'catalogue/numerique/doado-noir' => 'catalogue/numerique/doado-noir',
        'catalogue/numerique/epik' => 'catalogue/numerique/epik',
        'catalogue/numerique/dacodac' => 'catalogue/numerique/dacodac',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-logo_jeunesse' => array(
          'module' => 'boxes',
          'delta' => 'logo_jeunesse',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Logos');
  $export['context_logo_rr'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_logo_simple';
  $context->description = '';
  $context->tag = 'Logos';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        8 => 8,
        9 => 9,
        11 => 11,
        14 => 14,
        16 => 16,
        18 => 18,
        19 => 19,
        29 => 29,
        31 => 31,
        32 => 32,
        33 => 33,
        34 => 34,
        36 => 36,
        38 => 38,
        39 => 39,
        40 => 40,
        43 => 43,
        45 => 45,
        48 => 48,
        49 => 49,
        53 => 53,
        55 => 55,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'catalogue/litterature' => 'catalogue/litterature',
        'catalogue/litterature/objets-litteraires' => 'catalogue/litterature/objets-litteraires',
        'catalogue/art-histoire' => 'catalogue/art-histoire',
        'catalogue/art-histoire/*' => 'catalogue/art-histoire/*',
        'catalogue/regions' => 'catalogue/regions',
        'catalogue/regions/*' => 'catalogue/regions/*',
        'catalogue/nature-jardin' => 'catalogue/nature-jardin',
        'catalogue/nature-jardin/*' => 'catalogue/nature-jardin/*',
        'catalogue/gastronomie' => 'catalogue/gastronomie',
        'catalogue/gastronomie/*' => 'catalogue/gastronomie/*',
        'catalogue/numerique' => 'catalogue/numerique',
        '~catalogue/regions/romans' => '~catalogue/regions/romans',
        '~catalogue/regions/romans/*' => '~catalogue/regions/romans/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-logo_simple' => array(
          'module' => 'boxes',
          'delta' => 'logo_simple',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Logos');
  $export['context_logo_simple'] = $context;

  return $export;
}
