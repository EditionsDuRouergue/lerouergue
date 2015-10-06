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
    'path' => array(
      'values' => array(
        'catalogue' => 'catalogue',
      ),
    ),
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
    'context_uuid' => array(
      'values' => array(
        'taxonomy_term:aba0e77d-4004-47d1-83aa-0dcc982091ba' => 'taxonomy_term:aba0e77d-4004-47d1-83aa-0dcc982091ba',
        'taxonomy_term:1cc5d1ae-4297-4a31-bc83-ec57da26f285' => 'taxonomy_term:1cc5d1ae-4297-4a31-bc83-ec57da26f285',
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
    'context_uuid' => array(
      'values' => array(
        'taxonomy_term:63ed8920-edfe-4b4e-ae83-6cafb9fd9673' => 'taxonomy_term:63ed8920-edfe-4b4e-ae83-6cafb9fd9673',
        'taxonomy_term:6332356c-9e6d-4c86-b14f-c39fbd7352e1' => 'taxonomy_term:6332356c-9e6d-4c86-b14f-c39fbd7352e1',
        'taxonomy_term:0007e2ce-750f-4ef6-a648-3b465add8036' => 'taxonomy_term:0007e2ce-750f-4ef6-a648-3b465add8036',
        'taxonomy_term:2796300b-4322-4e79-8dcf-f3d7447c31dd' => 'taxonomy_term:2796300b-4322-4e79-8dcf-f3d7447c31dd',
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
    'context_uuid' => array(
      'values' => array(
        'taxonomy_term:58df9ecd-f479-4da4-ae71-da888aaaecd4' => 'taxonomy_term:58df9ecd-f479-4da4-ae71-da888aaaecd4',
        'taxonomy_term:f4654d87-9e93-4505-b1b2-01d4b537edfe' => 'taxonomy_term:f4654d87-9e93-4505-b1b2-01d4b537edfe',
        'taxonomy_term:8f6cfb5a-e21d-4afe-9b75-389addf70654' => 'taxonomy_term:8f6cfb5a-e21d-4afe-9b75-389addf70654',
        'taxonomy_term:6d8d9942-6f62-48cb-8469-9bcee5ca29aa' => 'taxonomy_term:6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
        'taxonomy_term:5d89969d-47af-4c0d-a22b-589fb6ea57a2' => 'taxonomy_term:5d89969d-47af-4c0d-a22b-589fb6ea57a2',
        'taxonomy_term:d8f5d9a9-3965-44cf-a713-96533e493197' => 'taxonomy_term:d8f5d9a9-3965-44cf-a713-96533e493197',
        'taxonomy_term:322aa47f-7585-4688-b4ee-08e83eca5d28' => 'taxonomy_term:322aa47f-7585-4688-b4ee-08e83eca5d28',
        'taxonomy_term:13c26811-5ade-4018-b8bb-5642b42fc1da' => 'taxonomy_term:13c26811-5ade-4018-b8bb-5642b42fc1da',
        'taxonomy_term:c27add62-baf4-45de-b445-27d7fef13a4f' => 'taxonomy_term:c27add62-baf4-45de-b445-27d7fef13a4f',
      ),
    ),
    'path' => array(
      'values' => array(
        'catalogue/litterature/romans' => 'catalogue/litterature/romans',
        'catalogue/litterature/romans/*' => 'catalogue/litterature/romans/*',
        'catalogue/regions/romans' => 'catalogue/regions/romans',
        'catalogue/regions/romans/*' => 'catalogue/regions/romans/*',
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
    'context_uuid' => array(
      'values' => array(
        'taxonomy_term:5ea55aec-1f9b-4ff9-a577-2ff4e9076370' => 'taxonomy_term:5ea55aec-1f9b-4ff9-a577-2ff4e9076370',
        'taxonomy_term:02919f7b-735d-4f1a-acc6-0854803e8b56' => 'taxonomy_term:02919f7b-735d-4f1a-acc6-0854803e8b56',
        'taxonomy_term:6113be70-821f-44af-989e-c72d4135d2d1' => 'taxonomy_term:6113be70-821f-44af-989e-c72d4135d2d1',
        'taxonomy_term:238c7664-3155-4a75-8d18-ee167c39fa2c' => 'taxonomy_term:238c7664-3155-4a75-8d18-ee167c39fa2c',
        'taxonomy_term:781eb291-8dd2-49db-9042-7fcb77aa5bdd' => 'taxonomy_term:781eb291-8dd2-49db-9042-7fcb77aa5bdd',
        'taxonomy_term:e6aea4fd-4293-40c5-beab-f90ddae63def' => 'taxonomy_term:e6aea4fd-4293-40c5-beab-f90ddae63def',
        'taxonomy_term:f023f562-dc45-4a75-906e-de7dec903fc2' => 'taxonomy_term:f023f562-dc45-4a75-906e-de7dec903fc2',
        'taxonomy_term:3178b576-6073-4472-81ef-4c5c8edf9fb6' => 'taxonomy_term:3178b576-6073-4472-81ef-4c5c8edf9fb6',
        'taxonomy_term:652fe62a-ec9a-43b9-8443-9c44f9ebb44d' => 'taxonomy_term:652fe62a-ec9a-43b9-8443-9c44f9ebb44d',
        'taxonomy_term:a85c3603-43ad-41a9-97ae-3973ac55ac98' => 'taxonomy_term:a85c3603-43ad-41a9-97ae-3973ac55ac98',
        'taxonomy_term:b4bb6966-c17a-401e-a705-907a9e42b69b' => 'taxonomy_term:b4bb6966-c17a-401e-a705-907a9e42b69b',
        'taxonomy_term:fbfacf65-522b-4683-80d6-d17681e3e425' => 'taxonomy_term:fbfacf65-522b-4683-80d6-d17681e3e425',
        'taxonomy_term:950d4168-1130-460f-902e-46a961b7ad69' => 'taxonomy_term:950d4168-1130-460f-902e-46a961b7ad69',
        'taxonomy_term:2a73fe7d-1781-42b7-8127-dd7a268d6bdd' => 'taxonomy_term:2a73fe7d-1781-42b7-8127-dd7a268d6bdd',
        'taxonomy_term:21b526e8-954a-4878-a43a-7fcdc8955938' => 'taxonomy_term:21b526e8-954a-4878-a43a-7fcdc8955938',
        'taxonomy_term:c536a140-ecd1-4080-9e71-eb2977f5e55f' => 'taxonomy_term:c536a140-ecd1-4080-9e71-eb2977f5e55f',
        'taxonomy_term:01014525-94b0-414e-acd9-7ccc6eda4dc7' => 'taxonomy_term:01014525-94b0-414e-acd9-7ccc6eda4dc7',
        'taxonomy_term:904edf51-1d02-40a7-bfc4-54004970a09a' => 'taxonomy_term:904edf51-1d02-40a7-bfc4-54004970a09a',
        'taxonomy_term:6f0d710e-3dd0-466b-9eb8-661c179170a9' => 'taxonomy_term:6f0d710e-3dd0-466b-9eb8-661c179170a9',
        'taxonomy_term:7f31083c-7346-459e-9ec5-f44936788c0e' => 'taxonomy_term:7f31083c-7346-459e-9ec5-f44936788c0e',
        'taxonomy_term:1875786a-6d12-4e8b-8786-a7dcc77cd95d' => 'taxonomy_term:1875786a-6d12-4e8b-8786-a7dcc77cd95d',
        'taxonomy_term:4509ebf0-0dac-496e-b968-96e7f4b9d248' => 'taxonomy_term:4509ebf0-0dac-496e-b968-96e7f4b9d248',
        'taxonomy_term:75291089-f665-47fc-96c5-eba17480b851' => 'taxonomy_term:75291089-f665-47fc-96c5-eba17480b851',
        'taxonomy_term:e2c94656-1a56-402b-a016-81e7455633d2' => 'taxonomy_term:e2c94656-1a56-402b-a016-81e7455633d2',
        'taxonomy_term:e0e69acb-e53c-41af-bcbb-085df9bd1cf9' => 'taxonomy_term:e0e69acb-e53c-41af-bcbb-085df9bd1cf9',
        'taxonomy_term:53c9815b-ac19-4b74-8abb-a727270582bd' => 'taxonomy_term:53c9815b-ac19-4b74-8abb-a727270582bd',
        'taxonomy_term:faaf7a44-b11c-478a-b05f-e2ca1892f5b7' => 'taxonomy_term:faaf7a44-b11c-478a-b05f-e2ca1892f5b7',
        'taxonomy_term:4269d4f5-45c0-4629-abab-b5d15e824200' => 'taxonomy_term:4269d4f5-45c0-4629-abab-b5d15e824200',
        'taxonomy_term:8c1782e1-88a6-4aac-87d7-4d29ed483c9b' => 'taxonomy_term:8c1782e1-88a6-4aac-87d7-4d29ed483c9b',
        'taxonomy_term:0af3c4aa-630d-48a0-98ca-51752eba0778' => 'taxonomy_term:0af3c4aa-630d-48a0-98ca-51752eba0778',
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
    'context_uuid' => array(
      'values' => array(
        'taxonomy_term:bff581ca-2883-4ec8-9e83-917be1285f49' => 'taxonomy_term:bff581ca-2883-4ec8-9e83-917be1285f49',
        'taxonomy_term:88728848-477d-401c-8d67-287baaaad668' => 'taxonomy_term:88728848-477d-401c-8d67-287baaaad668',
        'taxonomy_term:a82a3692-1790-4ef9-a0bb-15bb01fa5029' => 'taxonomy_term:a82a3692-1790-4ef9-a0bb-15bb01fa5029',
        'taxonomy_term:9e65659d-3259-480c-a3f6-5fb69acef58a' => 'taxonomy_term:9e65659d-3259-480c-a3f6-5fb69acef58a',
        'taxonomy_term:2a9aceff-4613-4b1e-aa0b-f902a13b6f81' => 'taxonomy_term:2a9aceff-4613-4b1e-aa0b-f902a13b6f81',
        'taxonomy_term:a34c3c50-a9d8-4c67-81d3-b64581938481' => 'taxonomy_term:a34c3c50-a9d8-4c67-81d3-b64581938481',
        'taxonomy_term:28a7aacd-6429-4630-abe0-9f8fa916748e' => 'taxonomy_term:28a7aacd-6429-4630-abe0-9f8fa916748e',
        'taxonomy_term:92100609-a178-4183-8c5f-e091e442c265' => 'taxonomy_term:92100609-a178-4183-8c5f-e091e442c265',
        'taxonomy_term:5c231e18-ad97-4038-b7e1-a1da158dc904' => 'taxonomy_term:5c231e18-ad97-4038-b7e1-a1da158dc904',
        'taxonomy_term:8148f50e-ef2e-497c-b285-efe2dd258ff3' => 'taxonomy_term:8148f50e-ef2e-497c-b285-efe2dd258ff3',
      ),
    ),
    'path' => array(
      'values' => array(
        'catalogue' => 'catalogue',
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
