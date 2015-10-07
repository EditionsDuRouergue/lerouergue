<?php
/**
 * @file
 * feature_catalog.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function feature_catalog_uuid_features_default_terms() {
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
    'description' => 'Zig zag, dacodac, tic tac, boomerang, doado, épik : des mots imagés pour des collections en mouvement qui grandissent avec l’imaginaire des lecteurs, depuis l’âge de 6 ans jusqu’aux jeunes adultes.',
    'format' => 'plain_text',
    'weight' => 64,
    'uuid' => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Fêtes',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '04ab2cb3-250b-4a21-9a2a-716b04bed137',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Cuisine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '06516c9d-5488-4e3d-923f-4abf8d243309',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Coloriste',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '07d70955-f911-4339-91bc-d58b80b84390',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Universitaire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '082709e3-7748-4af2-8299-ec20e5d3c00f',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Parcs et jardins',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0860b3ef-305b-4962-8441-699977bfa6ac',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'dacodac',
    'description' => 'De vrais romans ok pour les 9/12 ans dans tous les genres, du polar aux aventures du quotidien. ',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '0af3c4aa-630d-48a0-98ca-51752eba0778',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Sport',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0bf241af-651e-4edf-be9d-8dda50cfca94',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Photographe',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0d93bbf8-1a75-41d6-8e71-66bef470492f',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Cadet',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '11344d15-1c45-4112-aa4a-bc43dcc47847',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Expressions',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '11f3cea3-c78f-4dbf-bb5b-7ee95db7ae3c',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Editeur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '12294421-38c1-4ba2-9b44-ea3975d220d1',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'romans',
    'description' => 'Quand la littérature raconte des histoires, elle s’ancre dans des lieux parfois sublimes, parfois tragiques, elle apprend des grands moments historiques, elle suit le destin des hommes. Cette riche collection née à la fin des années 1980 ne cesse d’accueillir de nouvelles voix et de faire entendre les changements du monde.',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '13c26811-5ade-4018-b8bb-5642b42fc1da',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Dès 14 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '162b534d-eabf-4002-8b9e-61f16c724529',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Adoption',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '186c7903-936d-4baa-96a7-7562f51b3c4b',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
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
    'name' => 'Auteur représenté',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '18971a86-345f-48e6-9c45-3336fe2aafe7',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Assistant(e)',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '18b13966-aeb0-4c22-ad72-1714c4cb4ebb',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Mensonge',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '193f9dda-5283-47c4-90c8-bd2a71dcceaa',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Adulte',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1ab9711b-ea92-4ff3-a91c-4d4c73493c3c',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Japon',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1bf85051-f6b2-4fea-b6fe-cae326c0db61',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'La brune',
    'description' => 'Une collection de romans francophones, ouverte aux tonalités littéraires les plus diverses. Auteurs confirmés et jeunes talents pour des lecteurs curieux et exigeants. ',
    'format' => 'plain_text',
    'weight' => 58,
    'uuid' => '1cc5d1ae-4297-4a31-bc83-ec57da26f285',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Arts du spectacle',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1d1e2f18-6dff-4a08-a8eb-b79066b7ad13',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Amour',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1d841ba9-186d-4a67-b52f-942d48049a3e',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Musicien',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1f655592-157f-4066-b6f2-9aab0d88100c',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Directeur d\'ouvrage',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '20b3ebdb-d53a-4b18-8f32-6ca8201cc126',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Voyages',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '21ad197c-e694-4388-bdef-50bea2695dea',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Albums Jeunesse',
    'description' => 'Les albums du rouergue jeunesse proposent des parcours inventifs, à travers les mots et les images. Pour un art du récit toujours renouvelé.',
    'format' => 'plain_text',
    'weight' => 65,
    'uuid' => '21b526e8-954a-4878-a43a-7fcdc8955938',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Directeur de collection',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '21f4ce5d-a5ee-4828-a4a8-ce5d5cb50708',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'tic tac',
    'description' => 'Destinés aux lecteurs en herbe, ces recueils d’histoires courtes et drôles, teintées d’absurde, très délicatement illustrées en noir et blanc, permettent de renouer avec le rituel de la lecture du soir, seul ou en famille !',
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
    'name' => 'Narrateur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '26b3454f-f85e-4393-a443-d2f408968540',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Plasticien',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '270995df-0765-4140-930b-2c8544cff209',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Voyages / Vacances',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '278340bd-f4fd-4b0a-a37a-98c5e2c79896',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'polars',
    'description' => 'La collection Rouergue noir est née de la publication des romans de Peter May, dont toute l’œuvre est traduite en français aux Éditions du Rouergue. Elle accueille principalement des auteurs français et anglo-saxons.',
    'format' => 'plain_text',
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
    'description' => 'Comment allier construction et écologie ? Matériaux naturels, couvertures végétales ou recyclage de l’eau, oui la nature peut être dans l’habitation.',
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
    'description' => 'Nées provinciales, les Éditions du Rouergue aiment regarder au-delà de leurs frontières. Leurs livres voyagent à travers les régions de France en y cherchant la singularité du vécu, la noblesse des patrimoines, les mouvements de l’Histoire. Elles ont consacré quelques-unes de leurs plus belles excursions aux Cévennes voisines, terres amies auxquelles elles ont consacré de nombreux ouvrages.',
    'format' => 'plain_text',
    'weight' => 60,
    'uuid' => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'doado noir',
    'description' => 'Pour les ados qui aiment se promener dans les zones d’ombre, polars, thrillers, romans noirs et explorations de la réalité sociale.',
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
    'description' => 'Au Rouergue, l’histoire ce sont les premiers horizons, ceux d’un département riche en patrimoine, avec le mémorable ouvrage de Robert Taussat, Sept siècles autour de la cathédrale de Rodez (1992, épuisé), mais ce sont aussi des incursions vers des pays lointains et des événements qui ont marqué le monde, avec par exemple le livre de Claude Hudelot et Guy Gallice sur l’histoire de la propagande maoïste : Le Mao (2009, épuisé).',
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
    'name' => 'Erotique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2ce7f56c-8670-4686-b038-9c9238ca1cc7',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Scénariste',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2e6d3d08-bb50-4058-9525-14809ba07c55',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Saisons',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2f2e0e96-4c30-4543-bd87-f2b7275d3fb8',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Santé / Médecine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2f9eaa95-f1e6-419c-9dbb-c524dc4ef1f6',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 10 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2faf2068-dc0e-4b89-8340-14c9fa8b4bed',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Potager et jardinage',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3037ed5e-6b51-4c2a-8924-02c8cbaae0a7',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'à la petite semaine',
    'description' => 'Sous la forme d’un cahier d’école, Rachel Corenblit au texte et Cécile Bonbon aux images tirent des leçons des matières scolaires pour les appliquer au quotidien. Des petits romans graphiques pour les 8/11 ans.',
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
    'weight' => 2,
    'uuid' => '322aa47f-7585-4688-b4ee-08e83eca5d28',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    ),
  );
  $terms[] = array(
    'name' => 'Mort / Deuil',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '334ba1cd-bae5-42e4-af52-7be37038ca9f',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Postfacier',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3496dbd6-703a-4e7a-9964-e011476eaf06',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Australie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3562db30-35c2-4d48-a6d0-7fd09117b916',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Amitiés',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '361b1440-3621-493b-895a-48f31af17022',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Cirque / Mime',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '36866ccb-4ed9-4343-97a9-8b22a4ebbb1f',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Habitat / Ville / Déménagement',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3718aaac-133a-44bd-a7f6-e6fff1b92913',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Histoire moderne et contemporaine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '37814a50-5791-4ae0-a4ec-4540e18c8f52',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Histoire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '38fbc723-b794-4eb7-8a1a-ec23bcf9ac04',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Aventure',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3bed0664-395b-4813-a9fe-479f2546bfe1',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'cuisine',
    'description' => '« La cuisine, c’est beaucoup plus que des recettes », professait le regretté Alain Chapel. Au Rouergue, nous en sommes convaincus. La cuisine ce sont des traditions, transmises depuis la naissance de l’humanité, ce sont des hommes et des femmes qui produisent avec soin fruits et légumes, élèvent sans brutalité de beaux animaux, ce sont des gestes à apprendre et à approfondir. La cuisine c’est un fil de saveurs et d’apprentissages auquel nous accrochons, chaque année, de nouveaux livres.',
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
    'name' => 'Impressionnisme',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '407765fa-d46f-4e3f-9634-842d2e1b5150',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Amérique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '417bb5ad-3907-4f34-b383-b8b56f5f043f',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Fantastique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '41bda948-01f3-4ad8-ae87-d69032449541',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Justice / Injustice',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '41c43780-79b2-42ee-8575-77fbd4af6062',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'doado noir',
    'description' => 'Pour les ados qui aiment se promener dans les zones d’ombre, polars, thrillers, romans noirs et explorations de la réalité sociale.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '4269d4f5-45c0-4629-abab-b5d15e824200',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Puberté / Sexualité',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '44ecf946-b45f-4a89-ba87-91f46ff000c0',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Graphisme & Illustrations',
    'description' => 'Lorsque les illustrations, les images s’invitent dans le livre pour les plus grands.',
    'format' => 'plain_text',
    'weight' => 66,
    'uuid' => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Etats - Unis',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4712c991-bd52-43a6-bafa-3f136ad3203a',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'botanique',
    'description' => 'Connaître les plantes, c’est aussi faire la part belle et protéger la biodiversité. Les Éditions du Rouergue publient un ensemble d’ouvrages de référence sous la signature de botanistes éminents.',
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
    'name' => 'Région Sud Ouest',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4c68bde9-699a-4ed7-a79f-12a2606c50b3',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Histoire de l\'art',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4e056955-ac62-47b0-98fa-78504b01e8f4',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'essais',
    'description' => 'Quand les acteurs de la littérature jeunesse interrogent leur propre histoire et leur parcours.',
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
    'description' => 'Au fil des années, les éditions du Rouergue ont construit leur singularité dans le domaine de la gastronomie. Dès 1991, avec la publication du Livre de Michel Bras (épuisé) qui a marqué l’édition culinaire, les Éditions du Rouergue ont créé des livres autour du travail de grands chefs tels que Michel Bras, Olivier Roellinger puis Thierry Marx, Jean-Luc Rabanel ou Michel Troisgros.',
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
    'name' => 'grand format',
    'description' => 'Description de l\'univers…',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '58df9ecd-f479-4da4-ae71-da888aaaecd4',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'c27add62-baf4-45de-b445-27d7fef13a4f',
    ),
  );
  $terms[] = array(
    'name' => 'Famille recomposée',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5b626155-95e4-4c8d-b14f-39b3a0769069',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Polars / Livres d’enquête',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5c1299ac-6302-41d1-a3dc-db27207f8422',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Architecture et urbanisme',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5c1972e6-bfe8-48bc-9d39-270f2f399167',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'aveyron',
    'description' => 'Les Éditions du Rouergue portent le nom de la région où elles ont vu le jour, celui de l’ancienne province du Rouergue devenue à la Révolution le département de l’Aveyron. Nées à Rodez, les Éditions du Rouergue ont largement développé des publications autour de l’histoire et du patrimoine régionaux.',
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
    'name' => 'Agriculture',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5d4769a4-dd2a-453f-981c-0f763ac5dfd3',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'grand format',
    'description' => 'Description de l\'univers...',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5d89969d-47af-4c0d-a22b-589fb6ea57a2',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    ),
  );
  $terms[] = array(
    'name' => 'Epik (Fantasy)',
    'description' => 'Cette collection regroupe des romans dédiés à l’imaginaire (SF, fantasy, dystopie, horreur, etc.) pour repousser les frontières du réel. À destination des ados et jeunes adultes.',
    'format' => 'plain_text',
    'weight' => 63,
    'uuid' => '5ea55aec-1f9b-4ff9-a577-2ff4e9076370',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Géologie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5ebb83cc-643d-417d-bfb1-e61d31bfa9f5',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 9 mois',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5ebd34d9-2b80-48cf-9d7e-f2efe6e2f402',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Petite enfance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5f71dd08-1b75-4c77-be1b-2d6bc56eea95',
    'vocabulary_machine_name' => 'readership',
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
    'name' => 'Dès 2 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6191e7ba-0452-4f57-aca5-cc22dee2e5c5',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Liberté',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '624feda2-9168-4102-b517-e5a7a4d05a54',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
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
    'description' => '<p>La collection Rouergue noir est née de la publication des romans de Peter May, dont toute l’œuvre est traduite en français aux Éditions du Rouergue. Elle accueille principalement des auteurs français et anglo-saxons.</p>
',
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
    'name' => 'Démocratie / Dictature',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '650a873a-c1f2-4b50-948f-aae4a455e476',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 9 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '65190f70-8440-4465-a3f6-e4cfb613f425',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'zig zag',
    'description' => 'Une collection de romans à partir de 8 ans qui propose un parcours de lecture entre texte et images, dans des histoires du quotidien souvent pleines d’humour.',
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
    'name' => 'Patrimoine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '67024bd6-a967-43b6-a772-db13fe1cc2c6',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Réalisateur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6b725625-8e2d-4e26-8668-c4e1fdd84eb6',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Société',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6c452356-cd78-4669-8665-c7fb3ff97d27',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'romans',
    'description' => 'Quand la littérature raconte des histoires, elle s’ancre dans des lieux parfois sublimes, parfois tragiques, elle apprend des grands moments historiques, elle suit le destin des hommes. Cette riche collection née à la fin des années 1980 ne cesse d’accueillir de nouvelles voix et de faire entendre les changements du monde.',
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
    'name' => 'Racisme / Différence',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6e6c2cfc-5ed8-463a-bbac-687780af0c38',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'albums dès 4 ans',
    'description' => 'Les albums du rouergue jeunesse proposent des parcours inventifs, à travers les mots et les images. Pour un art du récit toujours renouvelé.',
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
    'name' => 'Bretagne',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7007c83f-62ff-42a7-9fed-4c8e3007d8c4',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'École / Vie scolaire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '70210a15-63ad-4cd9-8e84-0bced400ee45',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Maghreb',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '708e9723-5d92-4d25-b715-3441f8a8abe3',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Politique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '74a89f8f-fbdd-4fe2-8d5e-f6bfbeb57e43',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'toutazimute',
    'description' => 'La collection Touzazimute est un espace d’expression sous forme de cahier réservé aux illustrateurs où la parole est à l’image ! Pour un lectorat de tout âge.',
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
    'name' => 'Animaux / Bestiaires',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '768475b6-27ee-4591-ba75-f2405a8de24e',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
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
    'name' => 'Sorcellerie / Magie / Monstres',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '79324df8-d40c-4155-ac6f-d3a623233b6c',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'jardin',
    'description' => 'Comment pratiquer le jardinage en respectant le plus possible la nature et la biodiversité : cette question sous-tend l’ensemble des publications du catalogue des Éditions du Rouergue autour du titre fondateur qu’est Le Jardin naturel de Jean-Marie Lespinasse.',
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
    'name' => 'Dès 5 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7da51729-20aa-4824-971b-d9ac90f71e9a',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 6 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7ecc3180-e1e2-4217-89cb-7d28dd7cf2ee',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'albums dès 6 ans',
    'description' => 'Les albums du rouergue jeunesse proposent des parcours inventifs, à travers les mots et les images. Pour un art du récit toujours renouvelé.',
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
    'description' => 'Une société plus respectueuse de l’environnement se pense et se construit à travers l’espace de partage que sont les livres.',
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
    'description' => 'Voyager, oui, mais à ski à travers une Auvergne boréale, à vélo en un tour du monde époustouflant, ou bien vers les terres centrales de la France qui sont si belles qu’on ne les quitterait pour rien au monde. Les beaux-livres des Éditions du Rouergue doivent à de grands photographes de repousser l’horizon.',
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
    'name' => 'Amérique du Sud',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '827202f9-890a-4950-8536-8b0ba4a1a4ef',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Première guerre mondiale',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8303d7b3-2ab8-4606-8815-88d9f966d1ae',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'santé',
    'description' => 'Protéger sa santé par l’alimentation, c’est un peu notre dada, au Rouergue ! Une histoire qui a commencé en 1993 par la publication d’un livre précurseur de Mian Shen Zhu, Siavoch Darakchan et Michel Angles : Savoir manger pour savoir vivre (épuisé). Depuis, le Rouergue n’a cessé d’accueillir des livres de bon goût et de bonne santé.',
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
    'name' => 'Littérature francophone poche',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '878a1b82-4661-4060-a920-609cc076fd41',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'objets littéraires',
    'description' => 'Quand le texte rencontre l’objet artistique, cela donne une collection précieuse où l’art n’est jamais loin.',
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
    'description' => 'Cette collection regroupe des romans dédiés à l’imaginaire (SF, fantasy, dystopie, horreur, etc.) pour repousser les frontières du réel. À destination des ados et jeunes adultes.',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '8c1782e1-88a6-4aac-87d7-4d29ed483c9b',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Préhistoire / Protohistoire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8c32ba67-d9aa-4c26-ae60-e4b7e7b45095',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'rouergue en poche',
    'description' => 'Description de l\'univers…',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '8f6cfb5a-e21d-4afe-9b75-389addf70654',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'c27add62-baf4-45de-b445-27d7fef13a4f',
    ),
  );
  $terms[] = array(
    'name' => 'Littoral / Milieux marins',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '90375b91-c75a-4d64-a312-442e4303edd0',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
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
    'name' => 'Europe',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9065f1da-0012-4673-844d-00e699b60b2c',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'régions de France',
    'description' => 'Nées provinciales, les Éditions du Rouergue aiment regarder au-delà de leurs frontières. Leurs livres voyagent à travers les régions de France en y cherchant la singularité du vécu, la noblesse des patrimoines, les mouvements de l’Histoire. Elles ont consacré quelques-unes de leurs plus belles excursions aux Cévennes voisines, terres amies auxquelles elles ont consacré de nombreux ouvrages.',
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
    'name' => 'Secrets de famille',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '93ef8164-16bf-4214-9684-b2fa6d7a0c9f',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Disparition / Enlèvement',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '94de2131-c875-4bd4-8621-b99a28180671',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'doado',
    'description' => 'Une collection libre pour les ados et jeunes adultes, du récit quotidien au grand roman d’aventures, pour s’ouvrir au monde et aux autres, sans concession.',
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
    'name' => 'Sexualité',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9543f1bd-0d41-418d-9eba-8c191ee13805',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Adolescent',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '95fac3a5-c484-4faf-adeb-1de35d23f93a',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Archéologie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '96199295-0968-478b-a250-df7adbb0fae9',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Paris / Région parisienne',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '96cf58cd-ce46-42b1-baba-cbf6a2fbd7f4',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Peur / Danger',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '988611cb-360d-4be9-8414-9b9e1c6334f0',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Photographie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '98fbf375-76e7-4d29-a7ec-393a8f686dfc',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Afrique / Moyen-Orient',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9cce42f3-4272-4191-bd70-87a678b4f79b',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Tout public',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9d149109-e6b1-43b5-942e-be477ab0deb5',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'art',
    'description' => 'L’art, c’est celui des premiers hommes, avec Art pariétal, grottes ornées du Quercy de Michel Lorblanchet, synthèse de quarante années de recherches. C’est la puissante et mystérieuse expression de l’art néolitique avec Statues-Menhirs, l’ouvrage collectif dirigé par Annie Philippon. Mais c’est aussi Pierre Soulages, immense artiste né en Rouergue, œuvrant à Conques. Du plus loin au plus contemporain, une collection de livres choisis.',
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
    'name' => 'Jalousie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9f040e94-b368-41d3-98e7-5fdb37e45ee4',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Ecologie / Développement durable',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9f3d21de-df6a-40ff-803d-4aa818c1ebaf',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'société',
    'description' => 'La société se regarde par le prisme de beaux-livres tels Braguettes où Colette Gouvion jette un regard malicieux sur une pièce de vêtement on ne peut plus stratégique à travers les plus belles peintures et les plus célèbres des photographies, ou encore La Femme et le travesti dans lequel Chantal Aubry questionne la condition des femmes à travers la présence du travesti dans le spectacle vivant.',
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
    'name' => 'Rêve / Imaginaire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a3a095c3-5c4e-461f-88a9-b4051340dbdf',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Littérature',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a4cf796f-a039-438a-818b-4229360edfcc',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 11 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a69aac9a-e195-4230-ae33-92e6864a7fb2',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'A préciser',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a81bce0e-fbdd-4714-ab7a-cb4ca4918aea',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Art & Histoire',
    'description' => 'En 1991, les Éditions du Rouergue publiaient Voyage en cathédrale, Sainte-Cécile d’Albi, leur premier livre d’art, avec des photographies d’Alain Willaume et un texte de Robert Dulau. L’histoire, le patrimoine, l’art sont des domaines qui n’ont pas cessé d’inspirer de beaux-livres, sous la signature d’érudits et de chercheurs, avec des ouvrages de référence comme Conques de Marie Renoue, le livre majeur sur l’abbatiale et les vitraux de Pierre Soulages, au catalogue depuis 1997.',
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
    'name' => 'Bébé / Naissance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a9b5f7e7-b277-451a-9a77-d70dbe3b330f',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Relation frère/sœur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ab224193-76a8-45af-b360-38fe7027b462',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'la brune',
    'description' => 'Une collection de romans francophones, ouverte aux tonalités littéraires les plus diverses. Auteurs confirmés et jeunes talents pour des lecteurs curieux et exigeants. ',
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
    'name' => 'Apprentissage de la lecture',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ac84db61-7721-409a-b55f-82b5705c4fb9',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Art du paysage',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'addf9302-2095-4191-8198-b13d5d0d84d1',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'nature',
    'description' => 'La nature est un livre infini ouvert à notre curiosité. Depuis leur fondation, les Éditions du Rouergue publient des ouvrages qui explorent les mille et une formes que prennent les créatures vivantes et les savoirs que les êtres humains en ont acquis.',
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
    'name' => 'Interprète',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'af377b53-89da-4546-829d-34ce3687999b',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Jeux / Jouets',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'afb0042a-a43e-4469-b0d6-77d830df60a1',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Mode',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'afd18cc1-3cbd-428e-a6a2-f9b57e990caa',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Agent',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b1e52843-20b4-4b96-80d4-8fcc0b04b17b',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Graphiste',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b2337426-9839-4ced-a862-44d894bcf5b8',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Sciences',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b26a4b97-5311-4963-b680-25b2e876e566',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Travail / Argent / Chômage',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b3819e2c-60ea-4395-bf5b-56d4c4858b56',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'dacodac',
    'description' => 'De vrais romans ok pour les 9/12 ans dans tous les genres, du polar aux aventures du quotidien. ',
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
    'name' => 'Mer / Rivières / Étangs',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b514ee10-9094-4103-89f2-6a593b50b263',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Relation enfant/personne âgée',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b85a531c-ceb8-47ea-93cb-18ce1839e878',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Droit des enfants',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b8d578d2-ad8a-450b-bcfd-6b6d8a10322c',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Esclavage / Colonialisme',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ba7b5798-98c6-4448-90cc-a1d1480ad729',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 3 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bbcf6eb0-8814-48fb-8da0-6190f869d262',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Illustrateur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bbdba370-f28e-47d0-a233-f63cc9da407d',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Guerre',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bcece325-e288-452d-992c-f6a81bbe704e',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Vins',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bd91e30e-dacb-4992-9ab3-0293e42c6a0a',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 12 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bda547c5-3586-4a24-bc75-d47931e32914',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 15 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bdc0566c-c5fe-437f-980d-92efa74819eb',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Cinéma',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bf86e61e-76ec-4907-8525-98a129a90021',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Littérature',
    'description' => 'Le département Littérature au Rouergue est vaste. Il s’étend de collection de littérature générale au domaine du polar, jusqu’aux romans de société.',
    'format' => 'plain_text',
    'weight' => 57,
    'uuid' => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 4 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c08421ca-ac85-45cd-9aef-c211a0d94ec1',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Dès 7 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c0cccd47-6e40-44c0-9d64-0bb33562d29f',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Traducteur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c143a5d7-398b-4d37-86db-d3eef1c67132',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'romans',
    'description' => 'Quand la littérature raconte des histoires, elle s’ancre dans des lieux parfois sublimes, parfois tragiques, elle apprend des grands moments historiques, elle suit le destin des hommes. Cette riche collection née à la fin des années 1980 ne cesse d’accueillir de nouvelles voix et de faire entendre les changements du monde.',
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
    'name' => 'Sommeil',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c3bd33c9-a3cf-4770-afcb-cb9a6f7344e5',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Espagne',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c4f85ac4-10d8-491b-a96e-d59eaab7ab68',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'albums dès 2 ans',
    'description' => 'Les albums du rouergue jeunesse proposent des parcours inventifs, à travers les mots et les images. Pour un art du récit toujours renouvelé.',
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
    'description' => 'Dans le domaine œnologique, le Rouergue fit une entrée fracassante en 1994 avec la publication du livre de Guy Renvoisé, Le Monde du vin, art ou bluff (épuisé), qui dénonçait les dérives du système des AOC. Depuis, le Rouergue a publié des ouvrages d’ampélographie (Cépages du Sud-Ouest de Guy Lavignac, 2001, épuisé), des guides (Vins et vignerons du Sud-Ouest de Paul Strang, 2008, épuisé), des témoignages (Dans les vignes de Catherine Bernard) et même un livre de cuisine (Recettes de ma vigne de Catherine Bernard et Anne-Sophie Thérond).',
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
    'name' => 'Corps humain / Hygiène / Santé',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c9edcc9a-dfb3-4b7e-8192-1af5b01395b6',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Arts plastiques et sculpture',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cc7d2b57-e355-4e11-902b-85228feed4c0',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Numérique',
    'description' => 'Certains romans sont disponibles en format numérique, ainsi que certaines applications dérivées des albums. Vous pouvez vous les procurer sur les plateformes de téléchargement.',
    'format' => 'plain_text',
    'weight' => 67,
    'uuid' => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'la brune',
    'description' => 'Une collection de romans francophones, ouverte aux tonalités littéraires les plus diverses. Auteurs confirmés et jeunes talents pour des lecteurs curieux et exigeants. ',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'ce61d6fc-faa2-47f8-a6e9-976257d809d8',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Grandir',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd3098837-7072-44c0-8beb-c0e0b0c98607',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Peinture',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd3a5dc42-02a2-4315-a8c1-18d9adcb51fb',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Préfacier',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd57b7363-990e-4100-a1a0-64aff27eb532',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Identité / Origine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd696dac7-7228-420c-b469-6620d1ad46aa',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Religion et spiritualité',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd740908a-c4dc-4e4b-93d3-760bbf3eba68',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Conflit enfant / parents',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd7ade982-11f3-4b34-8fc1-b3bace842447',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Corse',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd7f2e2d1-e4fd-4ab7-bf7c-8b7fad743348',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'témoignages',
    'description' => 'Témoins, militants, acteurs de l’histoire font entendre leurs voix dans un ensemble de livres, illustrés ou non, avec un tropisme marqué pour le monde rural.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'd8f5d9a9-3965-44cf-a713-96533e493197',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    ),
  );
  $terms[] = array(
    'name' => 'Apprentissage des langues étrangères',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dafdbd74-0613-4706-b6fd-05e1d9bfc40f',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Botanique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dd5d1e9a-f381-4ce3-a60a-2c7d932f4029',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Humour',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dddc3ba8-cbe9-4792-b296-a8b7b7377784',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Art  / Jeunesse',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'deb43eb9-cd5c-4963-883f-35862b75aed0',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Nature et environnement',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dec8640d-2454-45fb-8662-1a1dd488ffe8',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Temps / Saison / Météo',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'df34e62d-ff21-4209-8766-725ca65d1860',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Relation fille/garçon',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'df6f4677-3656-4167-a7c8-2e18cc7e50b0',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'romans graphiques',
    'description' => 'Des livres qui expérimentent de nouvelles formes de récits dans la rencontre du texte et de l’image, pour les explorateurs de tout âge.',
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
    'name' => 'Art contemporain',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e0ee3a1c-4c01-475a-a240-523188867513',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Benjamin',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e16b08cc-eb58-417f-bb8c-a21b672e578f',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Fugue',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e19162a7-b80c-44e2-acd8-82da14bd0bf1',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
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
    'name' => 'Dès 8 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e39efb3c-fe14-4215-9c88-fd8dc4d9e201',
    'vocabulary_machine_name' => 'readership',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'boomerang',
    'description' => 'Deux histoires recto-verso à lire dans un sens ou dans l’autre, qui se font écho sur un même sujet. ',
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
    'name' => 'Révolte',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e7bde67f-0f02-459d-9fe8-45dd508f2e33',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Auteur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e99d342e-3705-4064-bb1b-fb9b7612b581',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Musique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e9e1bd4f-98ee-4478-b873-7b1f33c7e77d',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Exil / Immigration',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ea238d51-6e90-47c1-98a9-dd5dbee33560',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Théâtre Jeunesse',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ea334487-bd9b-410e-87e7-4e38ee65c560',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Arbre / Forêt',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ec49aa14-1311-44ed-b449-cfb10aaf6b6d',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Linguistique / Onomastique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ed89641e-a32a-49b5-b30a-a6db071203f6',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Philosophie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ee46b914-fb80-4866-a3ea-9f8e706ac006',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Seconde guerre mondiale',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ef561dca-65fa-41ce-a13c-1fb956e680cd',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Handicap / Maladie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'efd72c45-3016-42aa-a0da-3564da6a88c4',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
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
    'description' => 'Au fil des années, les Éditions du Rouergue ont construit leur singularité dans le domaine de la gastronomie. Dès 1991, avec la publication du Livre de Michel Bras (épuisé) qui a marqué l’édition culinaire, les Éditions du Rouergue ont créé des livres autour du travail de grands chefs tels que Michel Bras, Olivier Roellinger puis Thierry Marx, Jean-Luc Rabanel ou Michel Troisgros. Outre cette littérature gastronomique, elles s’intéressent aux patrimoines culinaires des régions de France et au rapport essentiel avec les producteurs.',
    'format' => 'plain_text',
    'weight' => 62,
    'uuid' => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'témoignages',
    'description' => 'Témoins, militants, acteurs de l’histoire font entendre leurs voix dans un ensemble de livres, illustrés ou non, avec un tropisme marqué pour le monde rural.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'f4654d87-9e93-4505-b1b2-01d4b537edfe',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
    'parent' => array(
      0 => 'c27add62-baf4-45de-b445-27d7fef13a4f',
    ),
  );
  $terms[] = array(
    'name' => 'Cuisine / Alimentation',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f572afa1-2e06-439a-ae5e-46e4527fc422',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Colère / Désobéissance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f5730b75-7b2a-4600-bc92-01be2b5689bd',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Eau',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f6f65d73-6cdb-4fe7-b684-bd06acac62e6',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Héritier',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fa4db17a-c6b6-4935-afb0-bd53bbea4b2b',
    'vocabulary_machine_name' => 'functions',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'doado',
    'description' => 'Une collection libre pour les ados et jeunes adultes, du récit quotidien au grand roman d’aventures, pour s’ouvrir au monde et aux autres, sans concession.',
    'format' => 'plain_text',
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
    'description' => 'Doado, Doado noir et épik, des collections de romans coups de poing, tendres, quelque fois hilarants. Écrits par une communauté d’auteurs de talent.',
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
    'description' => 'Les Éditions du Rouergue ont développé un catalogue important dédié à la nature et au jardin, alliant réflexion, prospective et pratique. Régulièrement récompensé par des prix spécialisés, le catalogue nature & jardin des éditions du Rouergue est fort de nombreux livres devenus des incontournables, qui dessinent une ligne engagée, résolument à l’avant-garde des connaissances et des comportements. Avec la volonté de porter à la connaissance de chacun les savoirs et les solutions pour un développement plus respectueux de la vie.',
    'format' => 'plain_text',
    'weight' => 61,
    'uuid' => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    'vocabulary_machine_name' => 'universe',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Philosophie / Sagesse',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fe37a702-4e89-4604-8c66-8e3552f02c9a',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Violence / Délinquance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fed1d1a4-5fcf-4c66-9483-5650fb7121cc',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Solidarité / Tolérance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ff99bae8-803d-412e-8ead-7a2656bdf765',
    'vocabulary_machine_name' => 'themes',
    'metatags' => array(),
  );
  return $terms;
}
