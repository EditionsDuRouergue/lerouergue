<?php
/**
 * @file
 * feature_core.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function feature_core_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'rouergue noir',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '0007e2ce-750f-4ef6-a648-3b465add8036',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '63ed8920-edfe-4b4e-ae83-6cafb9fd9673',
    ),
  );
  $terms[] = array(
    'name' => '12x12',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '01014525-94b0-414e-acd9-7ccc6eda4dc7',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'c536a140-ecd1-4080-9e71-eb2977f5e55f',
    ),
  );
  $terms[] = array(
    'name' => 'Romans Jeunesse',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 64,
    'uuid' => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'dacodac',
    'description' => 'Description de l\'univers...',
    'format' => 'full_html',
    'weight' => 4,
    'uuid' => '0af3c4aa-630d-48a0-98ca-51752eba0778',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'romans',
    'description' => '<p>Description de l\'univers...</p>
',
    'format' => 'full_html',
    'weight' => 6,
    'uuid' => '13c26811-5ade-4018-b8bb-5642b42fc1da',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'à la petite semaine',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1875786a-6d12-4e8b-8786-a7dcc77cd95d',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '7f31083c-7346-459e-9ec5-f44936788c0e',
    ),
  );
  $terms[] = array(
    'name' => 'La brune',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 58,
    'uuid' => '1cc5d1ae-4297-4a31-bc83-ec57da26f285',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Albums Jeunesse',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 65,
    'uuid' => '21b526e8-954a-4878-a43a-7fcdc8955938',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'tic tac',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '238c7664-3155-4a75-8d18-ee167c39fa2c',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '6113be70-821f-44af-989e-c72d4135d2d1',
    ),
  );
  $terms[] = array(
    'name' => 'polars',
    'description' => 'Description de l\'univers...',
    'format' => 'full_html',
    'weight' => 5,
    'uuid' => '2796300b-4322-4e79-8dcf-f3d7447c31dd',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'bâti',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '287736de-2aeb-48bd-a91d-5510b786ccaf',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    ),
  );
  $terms[] = array(
    'name' => 'Régions',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 60,
    'uuid' => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'doado noir',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '2a73fe7d-1781-42b7-8127-dd7a268d6bdd',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'fbfacf65-522b-4683-80d6-d17681e3e425',
    ),
  );
  $terms[] = array(
    'name' => 'histoire',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '2a9aceff-4613-4b1e-aa0b-f902a13b6f81',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'a82a3692-1790-4ef9-a0bb-15bb01fa5029',
    ),
  );
  $terms[] = array(
    'name' => 'à la petite semaine',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3178b576-6073-4472-81ef-4c5c8edf9fb6',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'f023f562-dc45-4a75-906e-de7dec903fc2',
    ),
  );
  $terms[] = array(
    'name' => 'rouergue en poche',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '322aa47f-7585-4688-b4ee-08e83eca5d28',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    ),
  );
  $terms[] = array(
    'name' => 'cuisine',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '3ec4f92d-32c1-45c6-a0b7-be9ea50872cc',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    ),
  );
  $terms[] = array(
    'name' => 'doado noir',
    'description' => 'Description de l\'univers...',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '4269d4f5-45c0-4629-abab-b5d15e824200',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Graphisme & Illustrations',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 66,
    'uuid' => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'botanique',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '48169487-b368-480b-83a4-46ddb4205188',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    ),
  );
  $terms[] = array(
    'name' => 'essais',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '53c9815b-ac19-4b74-8abb-a727270582bd',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    ),
  );
  $terms[] = array(
    'name' => 'grands chefs',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '557341af-5bdc-4f6f-8a24-a368f78c524b',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    ),
  );
  $terms[] = array(
    'name' => 'aveyron',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '5c231e18-ad97-4038-b7e1-a1da158dc904',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    ),
  );
  $terms[] = array(
    'name' => 'grand format',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '5d89969d-47af-4c0d-a22b-589fb6ea57a2',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    ),
  );
  $terms[] = array(
    'name' => 'Epik (Fantasy)',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 63,
    'uuid' => '5ea55aec-1f9b-4ff9-a577-2ff4e9076370',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'romans dès 6 ans',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6113be70-821f-44af-989e-c72d4135d2d1',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'assassins sans visage',
    'description' => 'Description de l\'univers...',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6332356c-9e6d-4c86-b14f-c39fbd7352e1',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '63ed8920-edfe-4b4e-ae83-6cafb9fd9673',
    ),
  );
  $terms[] = array(
    'name' => 'polars',
    'description' => 'Description de l\'univers...',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => '63ed8920-edfe-4b4e-ae83-6cafb9fd9673',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    ),
  );
  $terms[] = array(
    'name' => 'zig zag',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '652fe62a-ec9a-43b9-8443-9c44f9ebb44d',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'f023f562-dc45-4a75-906e-de7dec903fc2',
    ),
  );
  $terms[] = array(
    'name' => 'romans',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    ),
  );
  $terms[] = array(
    'name' => 'albums dès 4 ans',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '6f0d710e-3dd0-466b-9eb8-661c179170a9',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '21b526e8-954a-4878-a43a-7fcdc8955938',
    ),
  );
  $terms[] = array(
    'name' => 'toutazimute',
    'description' => 'Voyez ce jeu exquis wallon, de graphie en kit mais bref. Portez ce vieux whisky au juge blond qui fume sur son île intérieure, à côté de l\'alcôve ovoïde, où les bûches se consument dans l\'âtre, ce qui lui permet de penser à la cænogenèse de l\'être dont il est question dans la cause ambiguë entendue à Moÿ, dans un.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '75291089-f665-47fc-96c5-eba17480b851',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    ),
  );
  $terms[] = array(
    'name' => 'romans dès 7 ans',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '781eb291-8dd2-49db-9042-7fcb77aa5bdd',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'jardin',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '7bf1968c-cf26-4fe6-a839-f70abf339851',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    ),
  );
  $terms[] = array(
    'name' => 'albums dès 6 ans',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '7f31083c-7346-459e-9ec5-f44936788c0e',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '21b526e8-954a-4878-a43a-7fcdc8955938',
    ),
  );
  $terms[] = array(
    'name' => 'écologie',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '80df7f9b-4f8b-47eb-89c7-2da7ff929d20',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    ),
  );
  $terms[] = array(
    'name' => 'voyages',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '8148f50e-ef2e-497c-b285-efe2dd258ff3',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    ),
  );
  $terms[] = array(
    'name' => 'santé',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '85b490bb-bfae-46e2-9a1f-130057789068',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    ),
  );
  $terms[] = array(
    'name' => 'objets littéraires',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '88728848-477d-401c-8d67-287baaaad668',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    ),
  );
  $terms[] = array(
    'name' => 'epik',
    'description' => 'Description de l\'univers...',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => '8c1782e1-88a6-4aac-87d7-4d29ed483c9b',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'comptines en continu',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '904edf51-1d02-40a7-bfc4-54004970a09a',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'c536a140-ecd1-4080-9e71-eb2977f5e55f',
    ),
  );
  $terms[] = array(
    'name' => 'régions de France',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '92100609-a178-4183-8c5f-e091e442c265',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    ),
  );
  $terms[] = array(
    'name' => 'doado',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '950d4168-1130-460f-902e-46a961b7ad69',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'fbfacf65-522b-4683-80d6-d17681e3e425',
    ),
  );
  $terms[] = array(
    'name' => 'art',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9e65659d-3259-480c-a3f6-5fb69acef58a',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'a82a3692-1790-4ef9-a0bb-15bb01fa5029',
    ),
  );
  $terms[] = array(
    'name' => 'société',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'a34c3c50-a9d8-4c67-81d3-b64581938481',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'a82a3692-1790-4ef9-a0bb-15bb01fa5029',
    ),
  );
  $terms[] = array(
    'name' => 'Art & Histoire',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 59,
    'uuid' => 'a82a3692-1790-4ef9-a0bb-15bb01fa5029',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'romans dès 9 ans',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'a85c3603-43ad-41a9-97ae-3973ac55ac98',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'la brune',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'aba0e77d-4004-47d1-83aa-0dcc982091ba',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    ),
  );
  $terms[] = array(
    'name' => 'nature',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'ae01c103-055b-41e3-a1e1-3e5c6a9aa320',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    ),
  );
  $terms[] = array(
    'name' => 'dacodac',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b4bb6966-c17a-401e-a705-907a9e42b69b',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'a85c3603-43ad-41a9-97ae-3973ac55ac98',
    ),
  );
  $terms[] = array(
    'name' => 'Littérature',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 57,
    'uuid' => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'romans',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'c27add62-baf4-45de-b445-27d7fef13a4f',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    ),
  );
  $terms[] = array(
    'name' => 'albums dès 2 ans',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c536a140-ecd1-4080-9e71-eb2977f5e55f',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '21b526e8-954a-4878-a43a-7fcdc8955938',
    ),
  );
  $terms[] = array(
    'name' => 'vins',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c838c944-79ea-4767-be9b-f66f87756c86',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    ),
  );
  $terms[] = array(
    'name' => 'Numérique',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 67,
    'uuid' => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'la brune',
    'description' => 'Description de l\'univers...',
    'format' => 'full_html',
    'weight' => 3,
    'uuid' => 'ce61d6fc-faa2-47f8-a6e9-976257d809d8',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'romans graphiques',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'e0e69acb-e53c-41af-bcbb-085df9bd1cf9',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    ),
  );
  $terms[] = array(
    'name' => 'catalogues d\'exposition',
    'description' => 'Description de l\'univers...',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => 'e2c94656-1a56-402b-a016-81e7455633d2',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    ),
  );
  $terms[] = array(
    'name' => 'boomerang',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e6aea4fd-4293-40c5-beab-f90ddae63def',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '781eb291-8dd2-49db-9042-7fcb77aa5bdd',
    ),
  );
  $terms[] = array(
    'name' => 'romans dès 8 ans',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'f023f562-dc45-4a75-906e-de7dec903fc2',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'Gastronomie',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 62,
    'uuid' => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'témoignages',
    'description' => '<p>Description de l\'univers...</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'f4654d87-9e93-4505-b1b2-01d4b537edfe',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'c27add62-baf4-45de-b445-27d7fef13a4f',
    ),
  );
  $terms[] = array(
    'name' => 'doado',
    'description' => 'Description de l\'univers...',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'faaf7a44-b11c-478a-b05f-e2ca1892f5b7',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'romans ados',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'fbfacf65-522b-4683-80d6-d17681e3e425',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'Nature & Jardin',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 61,
    'uuid' => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  return $terms;
}
