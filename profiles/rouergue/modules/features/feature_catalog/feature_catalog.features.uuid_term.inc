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
    'name' => 'Romans Jeunesse',
    'description' => 'Zig zag, dacodac, tic tac, boomerang, doado, épik : des mots imagés pour des collections en mouvement qui grandissent avec l’imaginaire des lecteurs, depuis l’âge de 6 ans jusqu’aux jeunes adultes.',
    'format' => 'plain_text',
    'weight' => 64,
    'uuid' => '02919f7b-735d-4f1a-acc6-0854803e8b56',
    'vocabulary_machine_name' => 'universe',
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
    'name' => 'La brune',
    'description' => 'Une collection de romans francophones, ouverte aux tonalités littéraires les plus diverses. Auteurs confirmés et jeunes talents pour des lecteurs curieux et exigeants. ',
    'format' => 'plain_text',
    'weight' => 58,
    'uuid' => '1cc5d1ae-4297-4a31-bc83-ec57da26f285',
    'vocabulary_machine_name' => 'universe',
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
    'name' => 'Gastronomie',
    'description' => 'Au fil des années, les Éditions du Rouergue ont construit leur singularité dans le domaine de la gastronomie. Dès 1991, avec la publication du Livre de Michel Bras (épuisé) qui a marqué l’édition culinaire, les Éditions du Rouergue ont créé des livres autour du travail de grands chefs tels que Michel Bras, Olivier Roellinger puis Thierry Marx, Jean-Luc Rabanel ou Michel Troisgros. Outre cette littérature gastronomique, elles s’intéressent aux patrimoines culinaires des régions de France et au rapport essentiel avec les producteurs.',
    'format' => 'plain_text',
    'weight' => 62,
    'uuid' => 'f39ea2eb-3cae-4b3b-92b4-3ddb6f326b4c',
    'vocabulary_machine_name' => 'universe',
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
    'name' => 'Nature & Jardin',
    'description' => 'Les Éditions du Rouergue ont développé un catalogue important dédié à la nature et au jardin, alliant réflexion, prospective et pratique. Régulièrement récompensé par des prix spécialisés, le catalogue nature & jardin des éditions du Rouergue est fort de nombreux livres devenus des incontournables, qui dessinent une ligne engagée, résolument à l’avant-garde des connaissances et des comportements. Avec la volonté de porter à la connaissance de chacun les savoirs et les solutions pour un développement plus respectueux de la vie.',
    'format' => 'plain_text',
    'weight' => 61,
    'uuid' => 'fe160545-8a24-4647-9d4a-f3717dec5ef4',
    'vocabulary_machine_name' => 'universe',
  );
  return $terms;
}
