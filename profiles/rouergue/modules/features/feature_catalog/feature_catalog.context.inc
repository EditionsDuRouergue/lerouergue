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
    'node_taxonomy_uuid' => array(
      'values' => array(
        '1cc5d1ae-4297-4a31-bc83-ec57da26f285' => '1cc5d1ae-4297-4a31-bc83-ec57da26f285',
        'aba0e77d-4004-47d1-83aa-0dcc982091ba' => 'aba0e77d-4004-47d1-83aa-0dcc982091ba',
        'ce61d6fc-faa2-47f8-a6e9-976257d809d8' => 'ce61d6fc-faa2-47f8-a6e9-976257d809d8',
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
    'node_taxonomy_uuid' => array(
      'values' => array(
        '0007e2ce-750f-4ef6-a648-3b465add8036' => '0007e2ce-750f-4ef6-a648-3b465add8036',
        '2796300b-4322-4e79-8dcf-f3d7447c31dd' => '2796300b-4322-4e79-8dcf-f3d7447c31dd',
        '6332356c-9e6d-4c86-b14f-c39fbd7352e1' => '6332356c-9e6d-4c86-b14f-c39fbd7352e1',
        '63ed8920-edfe-4b4e-ae83-6cafb9fd9673' => '63ed8920-edfe-4b4e-ae83-6cafb9fd9673',
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
    'node_taxonomy_uuid' => array(
      'values' => array(
        '13c26811-5ade-4018-b8bb-5642b42fc1da' => '13c26811-5ade-4018-b8bb-5642b42fc1da',
        '322aa47f-7585-4688-b4ee-08e83eca5d28' => '322aa47f-7585-4688-b4ee-08e83eca5d28',
        '58df9ecd-f479-4da4-ae71-da888aaaecd4' => '58df9ecd-f479-4da4-ae71-da888aaaecd4',
        '5d89969d-47af-4c0d-a22b-589fb6ea57a2' => '5d89969d-47af-4c0d-a22b-589fb6ea57a2',
        '6d8d9942-6f62-48cb-8469-9bcee5ca29aa' => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
        '8f6cfb5a-e21d-4afe-9b75-389addf70654' => '8f6cfb5a-e21d-4afe-9b75-389addf70654',
        'c27add62-baf4-45de-b445-27d7fef13a4f' => 'c27add62-baf4-45de-b445-27d7fef13a4f',
        'd8f5d9a9-3965-44cf-a713-96533e493197' => 'd8f5d9a9-3965-44cf-a713-96533e493197',
        'f4654d87-9e93-4505-b1b2-01d4b537edfe' => 'f4654d87-9e93-4505-b1b2-01d4b537edfe',
      ),
      'options' => array(
        'node_form' => '1',
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
    'node_taxonomy_uuid' => array(
      'values' => array(
        '01014525-94b0-414e-acd9-7ccc6eda4dc7' => '01014525-94b0-414e-acd9-7ccc6eda4dc7',
        '02919f7b-735d-4f1a-acc6-0854803e8b56' => '02919f7b-735d-4f1a-acc6-0854803e8b56',
        '0af3c4aa-630d-48a0-98ca-51752eba0778' => '0af3c4aa-630d-48a0-98ca-51752eba0778',
        '1875786a-6d12-4e8b-8786-a7dcc77cd95d' => '1875786a-6d12-4e8b-8786-a7dcc77cd95d',
        '21b526e8-954a-4878-a43a-7fcdc8955938' => '21b526e8-954a-4878-a43a-7fcdc8955938',
        '238c7664-3155-4a75-8d18-ee167c39fa2c' => '238c7664-3155-4a75-8d18-ee167c39fa2c',
        '2a73fe7d-1781-42b7-8127-dd7a268d6bdd' => '2a73fe7d-1781-42b7-8127-dd7a268d6bdd',
        '3178b576-6073-4472-81ef-4c5c8edf9fb6' => '3178b576-6073-4472-81ef-4c5c8edf9fb6',
        '4269d4f5-45c0-4629-abab-b5d15e824200' => '4269d4f5-45c0-4629-abab-b5d15e824200',
        '4509ebf0-0dac-496e-b968-96e7f4b9d248' => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
        '53c9815b-ac19-4b74-8abb-a727270582bd' => '53c9815b-ac19-4b74-8abb-a727270582bd',
        '5ea55aec-1f9b-4ff9-a577-2ff4e9076370' => '5ea55aec-1f9b-4ff9-a577-2ff4e9076370',
        '6113be70-821f-44af-989e-c72d4135d2d1' => '6113be70-821f-44af-989e-c72d4135d2d1',
        '652fe62a-ec9a-43b9-8443-9c44f9ebb44d' => '652fe62a-ec9a-43b9-8443-9c44f9ebb44d',
        '6f0d710e-3dd0-466b-9eb8-661c179170a9' => '6f0d710e-3dd0-466b-9eb8-661c179170a9',
        '75291089-f665-47fc-96c5-eba17480b851' => '75291089-f665-47fc-96c5-eba17480b851',
        '781eb291-8dd2-49db-9042-7fcb77aa5bdd' => '781eb291-8dd2-49db-9042-7fcb77aa5bdd',
        '7f31083c-7346-459e-9ec5-f44936788c0e' => '7f31083c-7346-459e-9ec5-f44936788c0e',
        '8c1782e1-88a6-4aac-87d7-4d29ed483c9b' => '8c1782e1-88a6-4aac-87d7-4d29ed483c9b',
        '904edf51-1d02-40a7-bfc4-54004970a09a' => '904edf51-1d02-40a7-bfc4-54004970a09a',
        '950d4168-1130-460f-902e-46a961b7ad69' => '950d4168-1130-460f-902e-46a961b7ad69',
        'a85c3603-43ad-41a9-97ae-3973ac55ac98' => 'a85c3603-43ad-41a9-97ae-3973ac55ac98',
        'b4bb6966-c17a-401e-a705-907a9e42b69b' => 'b4bb6966-c17a-401e-a705-907a9e42b69b',
        'c536a140-ecd1-4080-9e71-eb2977f5e55f' => 'c536a140-ecd1-4080-9e71-eb2977f5e55f',
        'e0e69acb-e53c-41af-bcbb-085df9bd1cf9' => 'e0e69acb-e53c-41af-bcbb-085df9bd1cf9',
        'e2c94656-1a56-402b-a016-81e7455633d2' => 'e2c94656-1a56-402b-a016-81e7455633d2',
        'e6aea4fd-4293-40c5-beab-f90ddae63def' => 'e6aea4fd-4293-40c5-beab-f90ddae63def',
        'f023f562-dc45-4a75-906e-de7dec903fc2' => 'f023f562-dc45-4a75-906e-de7dec903fc2',
        'faaf7a44-b11c-478a-b05f-e2ca1892f5b7' => 'faaf7a44-b11c-478a-b05f-e2ca1892f5b7',
        'fbfacf65-522b-4683-80d6-d17681e3e425' => 'fbfacf65-522b-4683-80d6-d17681e3e425',
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
    'node_taxonomy_uuid' => array(
      'values' => array(
        '287736de-2aeb-48bd-a91d-5510b786ccaf' => '287736de-2aeb-48bd-a91d-5510b786ccaf',
        '28a7aacd-6429-4630-abe0-9f8fa916748e' => '28a7aacd-6429-4630-abe0-9f8fa916748e',
        '2a9aceff-4613-4b1e-aa0b-f902a13b6f81' => '2a9aceff-4613-4b1e-aa0b-f902a13b6f81',
        '3ec4f92d-32c1-45c6-a0b7-be9ea50872cc' => '3ec4f92d-32c1-45c6-a0b7-be9ea50872cc',
        '48169487-b368-480b-83a4-46ddb4205188' => '48169487-b368-480b-83a4-46ddb4205188',
        '557341af-5bdc-4f6f-8a24-a368f78c524b' => '557341af-5bdc-4f6f-8a24-a368f78c524b',
        '5c231e18-ad97-4038-b7e1-a1da158dc904' => '5c231e18-ad97-4038-b7e1-a1da158dc904',
        '7bf1968c-cf26-4fe6-a839-f70abf339851' => '7bf1968c-cf26-4fe6-a839-f70abf339851',
        '80df7f9b-4f8b-47eb-89c7-2da7ff929d20' => '80df7f9b-4f8b-47eb-89c7-2da7ff929d20',
        '8148f50e-ef2e-497c-b285-efe2dd258ff3' => '8148f50e-ef2e-497c-b285-efe2dd258ff3',
        '85b490bb-bfae-46e2-9a1f-130057789068' => '85b490bb-bfae-46e2-9a1f-130057789068',
        '88728848-477d-401c-8d67-287baaaad668' => '88728848-477d-401c-8d67-287baaaad668',
        '92100609-a178-4183-8c5f-e091e442c265' => '92100609-a178-4183-8c5f-e091e442c265',
        '9e65659d-3259-480c-a3f6-5fb69acef58a' => '9e65659d-3259-480c-a3f6-5fb69acef58a',
        'a34c3c50-a9d8-4c67-81d3-b64581938481' => 'a34c3c50-a9d8-4c67-81d3-b64581938481',
        'a82a3692-1790-4ef9-a0bb-15bb01fa5029' => 'a82a3692-1790-4ef9-a0bb-15bb01fa5029',
        'ae01c103-055b-41e3-a1e1-3e5c6a9aa320' => 'ae01c103-055b-41e3-a1e1-3e5c6a9aa320',
        'bff581ca-2883-4ec8-9e83-917be1285f49' => 'bff581ca-2883-4ec8-9e83-917be1285f49',
        'c838c944-79ea-4767-be9b-f66f87756c86' => 'c838c944-79ea-4767-be9b-f66f87756c86',
        'cdf5215e-8b85-4f0c-9f68-9ee517392c16' => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
        'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c' => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
        'fe160545-8a24-4647-9d4a-f3717dec5ef4' => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
      ),
      'options' => array(
        'node_form' => '1',
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
