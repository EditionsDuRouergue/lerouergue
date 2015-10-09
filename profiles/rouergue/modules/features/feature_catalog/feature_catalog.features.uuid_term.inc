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
    'description' => '<p>La collection Rouergue noir est née de la publication des romans de Peter May, dont toute l’œuvre est traduite en français aux Éditions du Rouergue. Elle accueille principalement des auteurs français et anglo-saxons.</p>
',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '0007e2ce-750f-4ef6-a648-3b465add8036',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '63ed8920-edfe-4b4e-ae83-6cafb9fd9673',
    ),
  );
  $terms[] = array(
    'name' => '12x12',
    'description' => '<p>Une collection d’imagiers cartonnés à quatre côtés égaux et au format 12 cm x 12 cm, destinée aux jeunes lecteurs (à partir de 2 ans). Des petits albums carrés réalisés par de grands illustrateurs, pour les plus petites mains et les plus neuves curiosités.</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '01014525-94b0-414e-acd9-7ccc6eda4dc7',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => 'c536a140-ecd1-4080-9e71-eb2977f5e55f',
    ),
  );
  $terms[] = array(
    'name' => 'Société',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0117d89d-ddf0-4800-8eb4-96b6151751cf',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Préfacier',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '021288ac-6bcc-484b-a58c-e436d45da7db',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Romans Jeunesse',
    'description' => 'Zig zag, dacodac, tic tac, boomerang, doado, épik : des mots imagés pour des collections en mouvement qui grandissent avec l’imaginaire des lecteurs, depuis l’âge de 6 ans jusqu’aux jeunes adultes.',
    'format' => 'plain_text',
    'weight' => 64,
    'uuid' => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'Littoral / Milieux marins',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '03b53486-bb60-428f-bc58-2d0ad23228c2',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Cadet',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '09250186-03c2-458f-83f5-cd76dc30baed',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'dacodac',
    'description' => 'De vrais romans ok pour les 9/12 ans dans tous les genres, du polar aux aventures du quotidien. ',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '0af3c4aa-630d-48a0-98ca-51752eba0778',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Mer / Rivières / Étangs',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0c581827-2982-4836-82f7-c6c24d304a7d',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Littérature',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0df55a81-27ca-40d3-b652-f309970b58cf',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Bretagne',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0f18fb31-8477-4b86-9177-f7ca51718f86',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Corse',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '11469051-8474-43db-97e2-31691b15d7ac',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Narrateur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '12e96f34-98c9-4eda-9297-bff61b6efffd',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'romans',
    'description' => 'Quand la littérature raconte des histoires, elle s’ancre dans des lieux parfois sublimes, parfois tragiques, elle apprend des grands moments historiques, elle suit le destin des hommes. Cette riche collection née à la fin des années 1980 ne cesse d’accueillir de nouvelles voix et de faire entendre les changements du monde.',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '13c26811-5ade-4018-b8bb-5642b42fc1da',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Mensonge',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '13c345e6-bd9c-4b54-b2ea-dca75bfd9de3',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Erotique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1431056e-24fe-460f-8f26-e419e9b3f3a8',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Fugue',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '14d39ee5-a835-4d72-98b7-c81ee524072f',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 4 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1618e4dd-5f02-4aa7-b853-4640690aa99b',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Art  / Jeunesse',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '175dd0c7-4372-4089-bf84-4bfa208499ab',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'à la petite semaine',
    'description' => '<p>Sous la forme d’un cahier d’école, Rachel Corenblit au texte et Cécile Bonbon aux images tirent des leçons des matières scolaires pour les appliquer au quotidien. Des petits romans graphiques pour les 8/11 ans.</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '1875786a-6d12-4e8b-8786-a7dcc77cd95d',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '7f31083c-7346-459e-9ec5-f44936788c0e',
    ),
  );
  $terms[] = array(
    'name' => 'Adulte',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '18ff6474-5097-4a00-8587-b6ab817f5e86',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Musique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1a8df3e3-2d6d-4c42-8a9a-8c2a56e00ab9',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Relation frère/sœur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1bb65d4e-7ff6-444a-a300-db3f0725a4a3',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Exil / Immigration',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1c81e58a-7e0f-4f72-b08f-6971a4fbb825',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'La brune',
    'description' => 'Une collection de romans francophones, ouverte aux tonalités littéraires les plus diverses. Auteurs confirmés et jeunes talents pour des lecteurs curieux et exigeants. ',
    'format' => 'plain_text',
    'weight' => 58,
    'uuid' => '1cc5d1ae-4297-4a31-bc83-ec57da26f285',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'Impressionnisme',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1faa3c58-8b83-41bc-828a-9c94e3447e72',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Japon',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '205592ae-44f7-45b7-869e-342900ff893c',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Nature et environnement',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '21841b20-ba55-43ef-94ba-31c04815fa3b',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Photographe',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '218fdf55-b0e8-44d8-a2ca-211508db8fa8',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Albums Jeunesse',
    'description' => 'Les albums du rouergue jeunesse proposent des parcours inventifs, à travers les mots et les images. Pour un art du récit toujours renouvelé.',
    'format' => 'plain_text',
    'weight' => 65,
    'uuid' => '21b526e8-954a-4878-a43a-7fcdc8955938',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'Traducteur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '21d179d1-c74b-46c8-967e-f90ad32c5686',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'tic tac',
    'description' => 'Destinés aux lecteurs en herbe, ces recueils d’histoires courtes et drôles, teintées d’absurde, très délicatement illustrées en noir et blanc, permettent de renouer avec le rituel de la lecture du soir, seul ou en famille !',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '238c7664-3155-4a75-8d18-ee167c39fa2c',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '6113be70-821f-44af-989e-c72d4135d2d1',
    ),
  );
  $terms[] = array(
    'name' => 'Mort / Deuil',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '252c19bd-bf28-44d8-8385-2626496e413c',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Australie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '268f9cd7-b0a5-40af-87ce-8f04511fce25',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'polars',
    'description' => 'La collection Rouergue noir est née de la publication des romans de Peter May, dont toute l’œuvre est traduite en français aux Éditions du Rouergue. Elle accueille principalement des auteurs français et anglo-saxons.',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '2796300b-4322-4e79-8dcf-f3d7447c31dd',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Fêtes',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '27db68ef-d657-4395-aab6-13d63ba4f512',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Sciences',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '284bf083-54b0-4e98-b4bb-d3f653d52fd4',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'bâti',
    'description' => 'Comment allier construction et écologie ? Matériaux naturels, couvertures végétales ou recyclage de l’eau, oui la nature peut être dans l’habitation.',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '287736de-2aeb-48bd-a91d-5510b786ccaf',
    'vocabulary_machine_name' => 'universe',
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
  );
  $terms[] = array(
    'name' => 'Afrique / Moyen-Orient',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '293dd905-99ce-4244-a7be-2a449e4c66f7',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'doado noir',
    'description' => 'Pour les ados qui aiment se promener dans les zones d’ombre, polars, thrillers, romans noirs et explorations de la réalité sociale.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '2a73fe7d-1781-42b7-8127-dd7a268d6bdd',
    'vocabulary_machine_name' => 'universe',
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
    'parent' => array(
      0 => 'a82a3692-1790-4ef9-a0bb-15bb01fa5029',
    ),
  );
  $terms[] = array(
    'name' => 'Cuisine / Alimentation',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2e4b1e8f-36be-4e9c-b750-baaec24787b2',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Puberté / Sexualité',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '31624619-704a-45c4-bacc-ae81f2924661',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'à la petite semaine',
    'description' => 'Sous la forme d’un cahier d’école, Rachel Corenblit au texte et Cécile Bonbon aux images tirent des leçons des matières scolaires pour les appliquer au quotidien. Des petits romans graphiques pour les 8/11 ans.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3178b576-6073-4472-81ef-4c5c8edf9fb6',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'f023f562-dc45-4a75-906e-de7dec903fc2',
    ),
  );
  $terms[] = array(
    'name' => 'rouergue en poche',
    'description' => '<p>De grands romans à petits prix.</p>
',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => '322aa47f-7585-4688-b4ee-08e83eca5d28',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    ),
  );
  $terms[] = array(
    'name' => 'Sociologie et ethnologie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3468e65c-485a-4b04-9c92-ea3e7485ebfc',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 14 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '37b5f379-b817-4d30-b4d5-3bba3564971f',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Animaux / Bestiaires',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '39949188-528c-485f-b065-c1ead20fd095',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Littérature francophone poche',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3a52f151-c184-43b3-aa9b-a324c2bec154',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Démocratie / Dictature',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3d1dfcfe-dd40-4d2b-9b8c-9931b7c83b89',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Littérature policière poche',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3df27238-ed22-47e4-8f13-036ea0aa7ece',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'cuisine',
    'description' => '« La cuisine, c’est beaucoup plus que des recettes », professait le regretté Alain Chapel. Au Rouergue, nous en sommes convaincus. La cuisine ce sont des traditions, transmises depuis la naissance de l’humanité, ce sont des hommes et des femmes qui produisent avec soin fruits et légumes, élèvent sans brutalité de beaux animaux, ce sont des gestes à apprendre et à approfondir. La cuisine c’est un fil de saveurs et d’apprentissages auquel nous accrochons, chaque année, de nouveaux livres.',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '3ec4f92d-32c1-45c6-a0b7-be9ea50872cc',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    ),
  );
  $terms[] = array(
    'name' => 'Polars / Livres d’enquête',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3ec9f71f-e0ee-491b-aca9-8cda834925fb',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Amérique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3ee53a6d-1513-4b1d-a40d-d7623efe0c38',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Sommeil',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3f5e31e5-cb34-41e4-85db-2eb3ab608fa8',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'doado noir',
    'description' => 'Pour les ados qui aiment se promener dans les zones d’ombre, polars, thrillers, romans noirs et explorations de la réalité sociale.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '4269d4f5-45c0-4629-abab-b5d15e824200',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Dès 3 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '42b281ff-88b5-49b0-8433-c461919729ab',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Graphisme & Illustrations',
    'description' => 'Lorsque les illustrations, les images s’invitent dans le livre pour les plus grands.',
    'format' => 'plain_text',
    'weight' => 66,
    'uuid' => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'botanique',
    'description' => 'Connaître les plantes, c’est aussi faire la part belle et protéger la biodiversité. Les Éditions du Rouergue publient un ensemble d’ouvrages de référence sous la signature de botanistes éminents.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '48169487-b368-480b-83a4-46ddb4205188',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    ),
  );
  $terms[] = array(
    'name' => 'Cirque / Mime',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4873ab52-0eb2-4e70-8be4-cc4e61c57bdc',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Botanique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '495d55a4-a329-47d3-8d2f-a55238fda2df',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Apprentissage de la lecture',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4a4c1e3b-df55-402f-b24b-adfb86ca7c12',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 2 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4c0f3fab-2bfd-4bcc-a1ae-25e1eb802b45',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Politique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4cdfd6d6-486a-4287-857e-ca9707aebaa5',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Solidarité / Tolérance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4e97eb51-0c19-464f-aff8-c1e7c77442fe',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Révolte',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4f10f083-7c9e-481e-8db2-39b8e071b6d2',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Auteur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '518e22e3-de98-48a1-bfc2-1ec5dfd3b2bb',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Première guerre mondiale',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '52a612a0-9940-4045-95df-999578fc847e',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Santé / Médecine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '536a0373-43ab-4601-b8b7-011a33650edb',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'essais',
    'description' => 'Quand les acteurs de la littérature jeunesse interrogent leur propre histoire et leur parcours.',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '53c9815b-ac19-4b74-8abb-a727270582bd',
    'vocabulary_machine_name' => 'universe',
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
    'parent' => array(
      0 => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    ),
  );
  $terms[] = array(
    'name' => 'Musicien',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '55878cd1-0cdd-48d0-9345-78c13bd2e575',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Auteur représenté',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '57a231d5-9a12-402b-b0a3-622596dfc450',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'l\'estive',
    'description' => '<p>Quand la littérature raconte des histoires, elle s’ancre dans des lieux parfois sublimes, parfois tragiques, elle apprend des grands moments historiques, elle suit le destin des hommes. Cette riche collection née à la fin des années 1980 ne cesse d’accueillir de nouvelles voix et de faire entendre les changements du monde.</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '58df9ecd-f479-4da4-ae71-da888aaaecd4',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => 'c27add62-baf4-45de-b445-27d7fef13a4f',
    ),
  );
  $terms[] = array(
    'name' => 'Eau',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5a05001f-0840-40e4-84e2-0cee8ab64bfe',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Ecologie / Développement durable',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5a346939-7367-46fb-8bc3-0f95c933e499',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Amour',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5a9cb9be-d36d-4d4b-a038-9492dbc3118b',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Aventure',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5acc2cc8-21cb-459c-a460-5ff75e086993',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Postfacier',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5b18d22c-f395-4741-916a-962db9c594f3',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Agriculture',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5b45b118-b27d-4ae7-a4e4-04b849743cf2',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Adolescent',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5b480e91-602e-4981-9ad0-af097a728d87',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'aveyron',
    'description' => 'Les Éditions du Rouergue portent le nom de la région où elles ont vu le jour, celui de l’ancienne province du Rouergue devenue à la Révolution le département de l’Aveyron. Nées à Rodez, les Éditions du Rouergue ont largement développé des publications autour de l’histoire et du patrimoine régionaux.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '5c231e18-ad97-4038-b7e1-a1da158dc904',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    ),
  );
  $terms[] = array(
    'name' => 'l\'estive',
    'description' => '<p>Quand la littérature raconte des histoires, elle s’ancre dans des lieux parfois sublimes, parfois tragiques, elle apprend des grands moments historiques, elle suit le destin des hommes. Cette riche collection née à la fin des années 1980 ne cesse d’accueillir de nouvelles voix et de faire entendre les changements du monde.</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '5d89969d-47af-4c0d-a22b-589fb6ea57a2',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    ),
  );
  $terms[] = array(
    'name' => 'Temps / Saison / Météo',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5de4fddd-f80e-42e2-83a7-cdbfbacfb333',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Sorcellerie / Magie / Monstres',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5df50c12-9703-4c3b-8069-91f2c240d01b',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 12 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5e0f82a4-bfc4-40ac-b789-01bbcbfb9034',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Epik (Fantasy)',
    'description' => 'Cette collection regroupe des romans dédiés à l’imaginaire (SF, fantasy, dystopie, horreur, etc.) pour repousser les frontières du réel. À destination des ados et jeunes adultes.',
    'format' => 'plain_text',
    'weight' => 63,
    'uuid' => '5ea55aec-1f9b-4ff9-a577-2ff4e9076370',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'romans dès 6 ans',
    'description' => '<p>Destinés aux lecteurs en herbe, ces recueils d’histoires courtes et drôles, teintées d’absurde, très délicatement illustrées en noir et blanc, permettent de renouer avec le rituel de la lecture du soir, seul ou en famille !</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6113be70-821f-44af-989e-c72d4135d2d1',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'Illustrateur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6264a170-23a0-4bf9-844f-61dfef39c8b8',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'assassins sans visage',
    'description' => '<p>Des comédies policières imaginées par Peter May, le plus français des écrivains écossais.</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6332356c-9e6d-4c86-b14f-c39fbd7352e1',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
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
    'parent' => array(
      0 => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    ),
  );
  $terms[] = array(
    'name' => 'zig zag',
    'description' => 'Une collection de romans à partir de 8 ans qui propose un parcours de lecture entre texte et images, dans des histoires du quotidien souvent pleines d’humour.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '652fe62a-ec9a-43b9-8443-9c44f9ebb44d',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'f023f562-dc45-4a75-906e-de7dec903fc2',
    ),
  );
  $terms[] = array(
    'name' => 'Agent',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '66026127-aace-458d-8463-1ca6d0707309',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Science fiction Fantasy',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '694e228a-4d85-4253-ae73-9eed1eda095f',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'École / Vie scolaire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '69fdd69e-76d0-4af2-a6f6-81cc4dc1a46d',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Coloriste',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6cbbe013-094e-4433-9c2a-875ff0da6fac',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'romans',
    'description' => 'Quand la littérature raconte des histoires, elle s’ancre dans des lieux parfois sublimes, parfois tragiques, elle apprend des grands moments historiques, elle suit le destin des hommes. Cette riche collection née à la fin des années 1980 ne cesse d’accueillir de nouvelles voix et de faire entendre les changements du monde.',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    ),
  );
  $terms[] = array(
    'name' => 'albums dès 4 ans',
    'description' => 'Les albums du rouergue jeunesse proposent des parcours inventifs, à travers les mots et les images. Pour un art du récit toujours renouvelé.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '6f0d710e-3dd0-466b-9eb8-661c179170a9',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '21b526e8-954a-4878-a43a-7fcdc8955938',
    ),
  );
  $terms[] = array(
    'name' => 'Art contemporain',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6fa20e90-9a1b-439b-8a6f-45be426dbdb7',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 5 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '71202de2-c250-4618-84dc-c3b87f71a94d',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Théâtre Jeunesse',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '73e589bb-255e-49b0-a7a2-1cf2bd3b93c6',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'toutazimute',
    'description' => 'La collection Touzazimute est un espace d’expression sous forme de cahier réservé aux illustrateurs où la parole est à l’image ! Pour un lectorat de tout âge.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '75291089-f665-47fc-96c5-eba17480b851',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    ),
  );
  $terms[] = array(
    'name' => 'Benjamin',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '755df11c-e6aa-409e-b397-4bf5e431a5f2',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Saisons',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7641233a-c4dc-451a-ba9a-b68c323e5cb8',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Apprentissage des langues étrangères',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '779bcfd3-2dd7-43c7-9ef3-0293880acc75',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Géologie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '77c9c7be-3a0c-4450-a74c-fdbf3862e60c',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'romans dès 7 ans',
    'description' => '<p>Deux histoires recto-verso à lire dans un sens ou dans l’autre, qui se font écho sur un même sujet.</p>
',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '781eb291-8dd2-49db-9042-7fcb77aa5bdd',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'Expressions',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7a539d5b-2742-4520-95fc-a2cf2a698352',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Histoire de l\'art',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7a7b8b96-b7d5-4082-82b3-96bcb4945229',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Région Sud Ouest',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7aa03333-0c15-460e-9e42-73eeb9071101',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'jardin',
    'description' => 'Comment pratiquer le jardinage en respectant le plus possible la nature et la biodiversité : cette question sous-tend l’ensemble des publications du catalogue des Éditions du Rouergue autour du titre fondateur qu’est Le Jardin naturel de Jean-Marie Lespinasse.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '7bf1968c-cf26-4fe6-a839-f70abf339851',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    ),
  );
  $terms[] = array(
    'name' => 'Asie / Océanie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7c1542ed-cb6e-4010-888b-959a663944e1',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Grandir',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7c2ca4f0-2523-45e0-b56a-f9a38726a66c',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Archéologie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7cfcc63c-c6d5-46a8-98dc-bf39ff7207d8',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Philosophie / Sagesse',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7d882773-9342-43eb-8416-41b89b174237',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'albums dès 6 ans',
    'description' => 'Les albums du rouergue jeunesse proposent des parcours inventifs, à travers les mots et les images. Pour un art du récit toujours renouvelé.',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '7f31083c-7346-459e-9ec5-f44936788c0e',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '21b526e8-954a-4878-a43a-7fcdc8955938',
    ),
  );
  $terms[] = array(
    'name' => 'Dès 6 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7f7dc8e8-06c9-4d66-a64a-0e3bbf4950f8',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Famille recomposée',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '80b223b7-3303-4e29-854a-392a358ba6ea',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Corée',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '80ba0746-c50f-4d40-bbd1-be952d506efb',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'écologie',
    'description' => 'Une société plus respectueuse de l’environnement se pense et se construit à travers l’espace de partage que sont les livres.',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '80df7f9b-4f8b-47eb-89c7-2da7ff929d20',
    'vocabulary_machine_name' => 'universe',
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
    'parent' => array(
      0 => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    ),
  );
  $terms[] = array(
    'name' => 'Sexualité',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '81790aaf-8130-48c3-ad69-13f0ae301f55',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'A préciser',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '82aa9a48-e718-49eb-a59b-f37566e9531c',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Corps humain / Hygiène / Santé',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '83ca3443-c839-4874-bc38-e26e30a0057a',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'santé',
    'description' => 'Protéger sa santé par l’alimentation, c’est un peu notre dada, au Rouergue ! Une histoire qui a commencé en 1993 par la publication d’un livre précurseur de Mian Shen Zhu, Siavoch Darakchan et Michel Angles : Savoir manger pour savoir vivre (épuisé). Depuis, le Rouergue n’a cessé d’accueillir des livres de bon goût et de bonne santé.',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '85b490bb-bfae-46e2-9a1f-130057789068',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    ),
  );
  $terms[] = array(
    'name' => 'Peinture',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '85ce8e1d-ba56-4a10-821a-d8cdff937dad',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Relation enfant/personne âgée',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '88668639-9b77-40eb-9d11-ed3b9ae5efc0',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'objets littéraires',
    'description' => 'Quand le texte rencontre l’objet artistique, cela donne une collection précieuse où l’art n’est jamais loin.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '88728848-477d-401c-8d67-287baaaad668',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    ),
  );
  $terms[] = array(
    'name' => 'Travail / Argent / Chômage',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '88d11f9f-9c20-434f-b93a-a527f5fd6b09',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Philosophie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8b154a2e-45df-4d0c-b682-b82167a1b263',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Echecs',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8bcd5492-e75e-4035-a29a-3642d6cfe587',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Arts plastiques et sculpture',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8bd875b6-0162-4d50-8fa0-3d5614bfc0ae',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'epik',
    'description' => 'Cette collection regroupe des romans dédiés à l’imaginaire (SF, fantasy, dystopie, horreur, etc.) pour repousser les frontières du réel. À destination des ados et jeunes adultes.',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '8c1782e1-88a6-4aac-87d7-4d29ed483c9b',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Colère / Désobéissance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8e1b30f1-456b-4138-af72-b02337e5dccc',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 7 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8e62c0b6-8410-4b16-a9c0-5e6819b5a2ce',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Rêve / Imaginaire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8edd7384-c2d4-4018-854c-198d3c583e81',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'rouergue en poche',
    'description' => '<p>De grands romans à petits prix.</p>
',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => '8f6cfb5a-e21d-4afe-9b75-389addf70654',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => 'c27add62-baf4-45de-b445-27d7fef13a4f',
    ),
  );
  $terms[] = array(
    'name' => 'Scénariste',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '902838c8-84aa-4af5-b74b-1601fb884533',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'comptines en continu',
    'description' => '<p>Voici une série de comptines illustrées : dans chacune, une variation sur un animal. Des livres adaptés aux tout-petits dans lesquels le dessin de Frédérique Bertrand est volontairement classique et le texte d’Olivier Douzou simple et plein d’humour. On y joue sur les mots et les images pour les premiers plaisirs du langage et des sonorités.</p>
',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '904edf51-1d02-40a7-bfc4-54004970a09a',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => 'c536a140-ecd1-4080-9e71-eb2977f5e55f',
    ),
  );
  $terms[] = array(
    'name' => 'Jeux / Jouets',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '904fcd15-4a6e-4349-8f53-a7efbca8d948',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'régions de France',
    'description' => 'Nées provinciales, les Éditions du Rouergue aiment regarder au-delà de leurs frontières. Leurs livres voyagent à travers les régions de France en y cherchant la singularité du vécu, la noblesse des patrimoines, les mouvements de l’Histoire. Elles ont consacré quelques-unes de leurs plus belles excursions aux Cévennes voisines, terres amies auxquelles elles ont consacré de nombreux ouvrages.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '92100609-a178-4183-8c5f-e091e442c265',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '28a7aacd-6429-4630-abe0-9f8fa916748e',
    ),
  );
  $terms[] = array(
    'name' => 'Habitat / Ville / Déménagement',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '921c3fcf-23a1-4737-b012-c249c5730aeb',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Parcs et jardins',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '92b2c751-c1ab-45ec-992b-c487493acc2a',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 9 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '94d228ff-d3e1-4c9a-a306-75c87153a9a6',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'doado',
    'description' => 'Une collection libre pour les ados et jeunes adultes, du récit quotidien au grand roman d’aventures, pour s’ouvrir au monde et aux autres, sans concession.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '950d4168-1130-460f-902e-46a961b7ad69',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'fbfacf65-522b-4683-80d6-d17681e3e425',
    ),
  );
  $terms[] = array(
    'name' => 'Relation fille/garçon',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '95e99ab2-5b2d-4d05-b003-00631b32a15c',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Arbre / Forêt',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9ac82f35-5d38-437d-82e5-d54d4f543bde',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Amitiés',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9c27c9fc-1051-4eb7-8110-ec45d69caca2',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Médias / Journalisme',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9d029020-f1a3-448b-b92b-484a9b037f53',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Jalousie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9dd80756-dd49-4c1d-af3b-4e464279b176',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'art',
    'description' => 'L’art, c’est celui des premiers hommes, avec Art pariétal, grottes ornées du Quercy de Michel Lorblanchet, synthèse de quarante années de recherches. C’est la puissante et mystérieuse expression de l’art néolitique avec Statues-Menhirs, l’ouvrage collectif dirigé par Annie Philippon. Mais c’est aussi Pierre Soulages, immense artiste né en Rouergue, œuvrant à Conques. Du plus loin au plus contemporain, une collection de livres choisis.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9e65659d-3259-480c-a3f6-5fb69acef58a',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'a82a3692-1790-4ef9-a0bb-15bb01fa5029',
    ),
  );
  $terms[] = array(
    'name' => 'Dès 8 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9e8cf99d-2771-4111-b862-7614bfc077cc',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Amérique du Sud',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9fde6657-3c85-45ff-86e3-34194f23b831',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Potager et jardinage',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a0db2569-24f1-4934-ae1c-abd88633162d',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Interprète',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a1e805cd-a5b4-443c-97a7-aaee71caaba7',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Voyages',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a2f1e31a-db91-4c4b-bbfb-e3f205c4ff5a',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'société',
    'description' => 'La société se regarde par le prisme de beaux-livres tels Braguettes où Colette Gouvion jette un regard malicieux sur une pièce de vêtement on ne peut plus stratégique à travers les plus belles peintures et les plus célèbres des photographies, ou encore La Femme et le travesti dans lequel Chantal Aubry questionne la condition des femmes à travers la présence du travesti dans le spectacle vivant.',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'a34c3c50-a9d8-4c67-81d3-b64581938481',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'a82a3692-1790-4ef9-a0bb-15bb01fa5029',
    ),
  );
  $terms[] = array(
    'name' => 'Maghreb',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a4b59c46-b625-4e04-aae8-12c5fa2ff469',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Esclavage / Colonialisme',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a5d709a2-9d0d-4a00-80c2-40dc76cbea88',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Voyages / Vacances',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a5da272b-e925-4b0e-93c4-03b3f55556cd',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Identité / Origine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a814dbee-5f2b-4cd0-bf5c-0884403f3d5f',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Art & Histoire',
    'description' => 'En 1991, les Éditions du Rouergue publiaient Voyage en cathédrale, Sainte-Cécile d’Albi, leur premier livre d’art, avec des photographies d’Alain Willaume et un texte de Robert Dulau. L’histoire, le patrimoine, l’art sont des domaines qui n’ont pas cessé d’inspirer de beaux-livres, sous la signature d’érudits et de chercheurs, avec des ouvrages de référence comme Conques de Marie Renoue, le livre majeur sur l’abbatiale et les vitraux de Pierre Soulages, au catalogue depuis 1997.',
    'format' => 'plain_text',
    'weight' => 59,
    'uuid' => 'a82a3692-1790-4ef9-a0bb-15bb01fa5029',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'romans dès 9 ans',
    'description' => '<p>De vrais romans ok pour les 9/12 ans dans tous les genres, du polar aux aventures du quotidien.</p>
',
    'format' => 'full_html',
    'weight' => 3,
    'uuid' => 'a85c3603-43ad-41a9-97ae-3973ac55ac98',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'la brune',
    'description' => 'Une collection de romans francophones, ouverte aux tonalités littéraires les plus diverses. Auteurs confirmés et jeunes talents pour des lecteurs curieux et exigeants. ',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'aba0e77d-4004-47d1-83aa-0dcc982091ba',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    ),
  );
  $terms[] = array(
    'name' => 'Bébé / Naissance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ac49768f-c6e5-4286-a846-9e1fa9390022',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Préhistoire / Protohistoire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ad1af789-e6f6-4e22-8b8f-dfbe7444f956',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Directeur d\'ouvrage',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ad3ef1ff-bc5a-4080-b28a-3d10f470bee9',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Héritier',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'adc40b6f-e74e-4b1e-9a3d-19b3bf677899',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'nature',
    'description' => 'La nature est un livre infini ouvert à notre curiosité. Depuis leur fondation, les Éditions du Rouergue publient des ouvrages qui explorent les mille et une formes que prennent les créatures vivantes et les savoirs que les êtres humains en ont acquis.',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'ae01c103-055b-41e3-a1e1-3e5c6a9aa320',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    ),
  );
  $terms[] = array(
    'name' => 'Vins',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ae024a43-8735-45fa-8692-809334d379f8',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Chine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b19f87a9-b297-4ead-a1b3-0e958fdee80e',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'dacodac',
    'description' => 'De vrais romans ok pour les 9/12 ans dans tous les genres, du polar aux aventures du quotidien. ',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b4bb6966-c17a-401e-a705-907a9e42b69b',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'a85c3603-43ad-41a9-97ae-3973ac55ac98',
    ),
  );
  $terms[] = array(
    'name' => 'Montagne',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b6cff08a-c931-4f24-9b26-c5494e06b847',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Cinéma',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b7cdbd0c-2dee-4cca-ab5e-9a9b6b2ba250',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Arts du spectacle',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b8327ee2-62e6-45a3-bf9c-0a32894245d2',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 15 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b9e87d0d-f1e3-49f7-bc96-af2a3e300840',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Réalisateur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ba7776f2-5a41-4f28-b0ae-cf0591a96f7a',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Editeur',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ba964f94-d638-4f18-9de6-9f189d057910',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Racisme / Différence',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bd407f6f-cbbd-47c0-9a48-aa4c24c8ad88',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Tout public',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bd842c39-a1e6-472d-a3b8-3f0988c388f9',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Conflit enfant / parents',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bee938ac-5c04-4c5b-aa41-1e91a12d9909',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 9 mois',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bf3c514b-82f3-4ec3-8e0c-21fce7219cf3',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Littérature',
    'description' => 'Le département Littérature au Rouergue est vaste. Il s’étend de collection de littérature générale au domaine du polar, jusqu’aux romans de société.',
    'format' => 'plain_text',
    'weight' => 57,
    'uuid' => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'romans',
    'description' => 'Quand la littérature raconte des histoires, elle s’ancre dans des lieux parfois sublimes, parfois tragiques, elle apprend des grands moments historiques, elle suit le destin des hommes. Cette riche collection née à la fin des années 1980 ne cesse d’accueillir de nouvelles voix et de faire entendre les changements du monde.',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'c27add62-baf4-45de-b445-27d7fef13a4f',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'bff581ca-2883-4ec8-9e83-917be1285f49',
    ),
  );
  $terms[] = array(
    'name' => 'Assistant(e)',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c4f9ce1e-c462-4dda-9356-0d60504f4836',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'albums dès 2 ans',
    'description' => 'Les albums du rouergue jeunesse proposent des parcours inventifs, à travers les mots et les images. Pour un art du récit toujours renouvelé.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c536a140-ecd1-4080-9e71-eb2977f5e55f',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '21b526e8-954a-4878-a43a-7fcdc8955938',
    ),
  );
  $terms[] = array(
    'name' => 'Art du paysage',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c5a87a08-2109-4433-bbdd-f8ba4ca70f92',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Violence / Délinquance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c6528d8e-5a1f-461a-b92d-fd3cd784aab0',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'vins',
    'description' => 'Dans le domaine œnologique, le Rouergue fit une entrée fracassante en 1994 avec la publication du livre de Guy Renvoisé, Le Monde du vin, art ou bluff (épuisé), qui dénonçait les dérives du système des AOC. Depuis, le Rouergue a publié des ouvrages d’ampélographie (Cépages du Sud-Ouest de Guy Lavignac, 2001, épuisé), des guides (Vins et vignerons du Sud-Ouest de Paul Strang, 2008, épuisé), des témoignages (Dans les vignes de Catherine Bernard) et même un livre de cuisine (Recettes de ma vigne de Catherine Bernard et Anne-Sophie Thérond).',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c838c944-79ea-4767-be9b-f66f87756c86',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    ),
  );
  $terms[] = array(
    'name' => 'Algérie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c9534ae7-c02a-492b-a811-23a116601350',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Liberté',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cafe4a38-7b7f-48c0-b2e3-077dd4eb9b3b',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Numérique',
    'description' => 'Certains romans sont disponibles en format numérique, ainsi que certaines applications dérivées des albums. Vous pouvez vous les procurer sur les plateformes de téléchargement.',
    'format' => 'plain_text',
    'weight' => 67,
    'uuid' => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'la brune',
    'description' => 'Une collection de romans francophones, ouverte aux tonalités littéraires les plus diverses. Auteurs confirmés et jeunes talents pour des lecteurs curieux et exigeants. ',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'ce61d6fc-faa2-47f8-a6e9-976257d809d8',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'cdf5215e-8b85-4f0c-9f68-9ee517392c16',
    ),
  );
  $terms[] = array(
    'name' => 'Paris / Région parisienne',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cefb7bef-aab6-457c-86c7-3a9f91003aee',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Guerre',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd01fbdc8-7705-49bc-a329-f0a5f3dc846f',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Disparition / Enlèvement',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd5fa5d5d-4d6e-4507-8ca6-8b54a84d762a',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Patrimoine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd62afd74-3585-457e-aba4-db296992367f',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 10 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd70438f0-f056-457a-9a49-9956a5760a6a',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Histoire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd8114947-e79e-44db-939f-151f3a6e930b',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Petite enfance',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd81bcc5c-8466-4dcc-9a80-067762ad1dca',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Handicap / Maladie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd81ed916-a7da-469c-9b99-816ebe336dc4',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'témoignages',
    'description' => 'Témoins, militants, acteurs de l’histoire font entendre leurs voix dans un ensemble de livres, illustrés ou non, avec un tropisme marqué pour le monde rural.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'd8f5d9a9-3965-44cf-a713-96533e493197',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '6d8d9942-6f62-48cb-8469-9bcee5ca29aa',
    ),
  );
  $terms[] = array(
    'name' => 'Directeur de collection',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd998e336-646d-41c1-9c98-97cfdbcf0de9',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Sport',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dafbc2a8-53d5-43a4-8ac5-1991f76da552',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Dès 11 ans',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dc4f812c-ed69-4eb5-ab7d-fa153d317756',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Architecture et urbanisme',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'de78f073-bba7-4ae2-a77b-ca5f68f68e97',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Humour',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e05bad1c-590d-4f50-991d-45201b9e0d4b',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'romans graphiques',
    'description' => 'Des livres qui expérimentent de nouvelles formes de récits dans la rencontre du texte et de l’image, pour les explorateurs de tout âge.',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'e0e69acb-e53c-41af-bcbb-085df9bd1cf9',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    ),
  );
  $terms[] = array(
    'name' => 'Droit des enfants',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e21fa666-396c-48bf-b746-c0f4c60a4f06',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'catalogues d\'exposition',
    'description' => '<p>Publier c’est accompagner et garder par le souvenir le beau moment d’une exposition. En collaboration avec différents musées, à Paris et en province, le Rouergue publie des catalogues d’exposition.</p>
',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => 'e2c94656-1a56-402b-a016-81e7455633d2',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '4509ebf0-0dac-496e-b968-96e7f4b9d248',
    ),
  );
  $terms[] = array(
    'name' => 'Plasticien',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e3066fbd-3d21-4f16-be25-a03a7f6e7804',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Etats - Unis',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e410ce85-d1ef-4324-9143-2cf5f7fc195c',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'boomerang',
    'description' => 'Deux histoires recto-verso à lire dans un sens ou dans l’autre, qui se font écho sur un même sujet. ',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e6aea4fd-4293-40c5-beab-f90ddae63def',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => '781eb291-8dd2-49db-9042-7fcb77aa5bdd',
    ),
  );
  $terms[] = array(
    'name' => 'Histoire Poche',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e70c5a57-622b-4b50-aa7f-dddf73cf7631',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Histoire moderne et contemporaine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e7669bf0-7ae3-44ff-a386-756dbf8ebbc6',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Linguistique / Onomastique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e84e2b67-1c4f-4069-b999-19a305af52e8',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Adoption',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ea8f4f97-45af-4f6d-9f30-ce7a6891e727',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Peur / Danger',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ec47aca1-87e9-4d18-995d-e9c862b388ce',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Photographie',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ec58078d-b271-479a-a01b-8499e00ba7e4',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Secrets de famille',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'eea7a946-2878-4e40-9855-7d7689aab57c',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'romans dès 8 ans',
    'description' => '<p>Une collection de romans à partir de 8 ans qui propose un parcours de lecture entre texte et images, dans des histoires du quotidien souvent pleines d’humour.</p>
',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => 'f023f562-dc45-4a75-906e-de7dec903fc2',
    'vocabulary_machine_name' => 'universe',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'Contraires',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f1ec9b60-8bd6-4f08-9241-50aef3681cae',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Religion et spiritualité',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f2a0a47d-b969-4ba5-a585-cf0dff13c76c',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Europe',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f2a1da78-b608-42e9-a083-f9814ed8368b',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Gastronomie',
    'description' => 'Au fil des années, les Éditions du Rouergue ont construit leur singularité dans le domaine de la gastronomie. Dès 1991, avec la publication du Livre de Michel Bras (épuisé) qui a marqué l’édition culinaire, les Éditions du Rouergue ont créé des livres autour du travail de grands chefs tels que Michel Bras, Olivier Roellinger puis Thierry Marx, Jean-Luc Rabanel ou Michel Troisgros. Outre cette littérature gastronomique, elles s’intéressent aux patrimoines culinaires des régions de France et au rapport essentiel avec les producteurs.',
    'format' => 'plain_text',
    'weight' => 62,
    'uuid' => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'Cuisine',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f3f960e2-d644-4d21-bd54-b0b9da40b573',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Mode',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f40142a7-8adc-4408-9877-96b81f7cde9d',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'témoignages',
    'description' => 'Témoins, militants, acteurs de l’histoire font entendre leurs voix dans un ensemble de livres, illustrés ou non, avec un tropisme marqué pour le monde rural.',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'f4654d87-9e93-4505-b1b2-01d4b537edfe',
    'vocabulary_machine_name' => 'universe',
    'parent' => array(
      0 => 'c27add62-baf4-45de-b445-27d7fef13a4f',
    ),
  );
  $terms[] = array(
    'name' => 'Espagne',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f470aeda-086f-40ad-ac4a-17f60099c616',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Fantastique',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f90c45a9-921e-4fae-aa8d-9a8c1905114a',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'doado',
    'description' => 'Une collection libre pour les ados et jeunes adultes, du récit quotidien au grand roman d’aventures, pour s’ouvrir au monde et aux autres, sans concession.',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'faaf7a44-b11c-478a-b05f-e2ca1892f5b7',
    'vocabulary_machine_name' => 'universe',
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
    'parent' => array(
      0 => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    ),
  );
  $terms[] = array(
    'name' => 'Universitaire',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fc88be55-1a09-4f7d-a195-0fe917ac8c7f',
    'vocabulary_machine_name' => 'readership',
  );
  $terms[] = array(
    'name' => 'Seconde guerre mondiale',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fcb71cd9-9307-403b-924b-7f3b96808fcb',
    'vocabulary_machine_name' => 'themes',
  );
  $terms[] = array(
    'name' => 'Nature & Jardin',
    'description' => 'Les Éditions du Rouergue ont développé un catalogue important dédié à la nature et au jardin, alliant réflexion, prospective et pratique. Régulièrement récompensé par des prix spécialisés, le catalogue nature & jardin des éditions du Rouergue est fort de nombreux livres devenus des incontournables, qui dessinent une ligne engagée, résolument à l’avant-garde des connaissances et des comportements. Avec la volonté de porter à la connaissance de chacun les savoirs et les solutions pour un développement plus respectueux de la vie.',
    'format' => 'plain_text',
    'weight' => 61,
    'uuid' => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    'vocabulary_machine_name' => 'universe',
  );
  $terms[] = array(
    'name' => 'Graphiste',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fe682e55-aad5-4690-99b9-84ee6d51228b',
    'vocabulary_machine_name' => 'functions',
  );
  $terms[] = array(
    'name' => 'Justice / Injustice',
    'description' => NULL,
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ff6417da-f6b1-4485-912c-c8f43547bcf1',
    'vocabulary_machine_name' => 'themes',
  );
  return $terms;
}
