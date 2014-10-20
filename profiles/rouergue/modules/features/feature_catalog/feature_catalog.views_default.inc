<?php
/**
 * @file
 * feature_catalog.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_catalog_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'authors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Auteurs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_firstname' => 'field_firstname',
    'field_lastname' => 'field_lastname',
  );
  /* Relation: Entity Reference : Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_contributor_field_collection_item']['id'] = 'reverse_field_contributor_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_contributor_field_collection_item']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_contributor_field_collection_item']['field'] = 'reverse_field_contributor_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_contributor_field_collection_item']['label'] = 'FC Contributeur';
  /* Relation: Field collection item : Fonction (field_contributor_function) */
  $handler->display->display_options['relationships']['field_contributor_function_tid']['id'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['table'] = 'field_data_field_contributor_function';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['field'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['relationship'] = 'reverse_field_contributor_field_collection_item';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['label'] = 'Fonction';
  /* Champ: Contenu : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Prénom */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Nom */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Photo */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = '';
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'article-cover-min',
    'image_link' => 'content',
  );
  /* Champ: Image field caption : Photo (caption) */
  $handler->display->display_options['fields']['caption']['id'] = 'caption';
  $handler->display->display_options['fields']['caption']['table'] = 'field_picture_field_image_field_caption';
  $handler->display->display_options['fields']['caption']['field'] = 'caption';
  $handler->display->display_options['fields']['caption']['label'] = '';
  $handler->display->display_options['fields']['caption']['element_label_colon'] = FALSE;
  /* Champ: Prénom Nom */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Prénom Nom';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_firstname] [field_lastname]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Critère de tri: Contenu : Nom (field_lastname) */
  $handler->display->display_options['sorts']['field_lastname_value']['id'] = 'field_lastname_value';
  $handler->display->display_options['sorts']['field_lastname_value']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['sorts']['field_lastname_value']['field'] = 'field_lastname_value';
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'contributor' => 'contributor',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Critère de filtrage: Terme de taxonomie : Nom */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_contributor_function_tid';
  $handler->display->display_options['filters']['name']['value'] = 'auteur';

  /* Display: Auteurs */
  $handler = $view->new_display('page_with_page_title', 'Auteurs', 'authors');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Entity Reference : Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_contributor_field_collection_item']['id'] = 'reverse_field_contributor_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_contributor_field_collection_item']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_contributor_field_collection_item']['field'] = 'reverse_field_contributor_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_contributor_field_collection_item']['label'] = 'FC Contributeur';
  $handler->display->display_options['relationships']['reverse_field_contributor_field_collection_item']['required'] = TRUE;
  /* Relation: Field collection item : Fonction (field_contributor_function) */
  $handler->display->display_options['relationships']['field_contributor_function_tid']['id'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['table'] = 'field_data_field_contributor_function';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['field'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['relationship'] = 'reverse_field_contributor_field_collection_item';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['label'] = 'Fonction';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Prénom */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Nom */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Photo */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = '';
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'article-cover-min',
    'image_link' => 'content',
  );
  /* Champ: Image field caption : Photo (caption) */
  $handler->display->display_options['fields']['caption']['id'] = 'caption';
  $handler->display->display_options['fields']['caption']['table'] = 'field_picture_field_image_field_caption';
  $handler->display->display_options['fields']['caption']['field'] = 'caption';
  $handler->display->display_options['fields']['caption']['label'] = '';
  $handler->display->display_options['fields']['caption']['element_label_colon'] = FALSE;
  /* Champ: Prénom Nom */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Prénom Nom';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_firstname] [field_lastname]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Nom (field_lastname) */
  $handler->display->display_options['arguments']['field_lastname_value']['id'] = 'field_lastname_value';
  $handler->display->display_options['arguments']['field_lastname_value']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['arguments']['field_lastname_value']['field'] = 'field_lastname_value';
  $handler->display->display_options['arguments']['field_lastname_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_lastname_value']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['field_lastname_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_lastname_value']['default_argument_options']['argument'] = 'a';
  $handler->display->display_options['arguments']['field_lastname_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_lastname_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_lastname_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_lastname_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_lastname_value']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['field_lastname_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_lastname_value']['limit'] = '1';
  $handler->display->display_options['arguments']['field_lastname_value']['case'] = 'upper';
  $handler->display->display_options['arguments']['field_lastname_value']['path_case'] = 'lower';
  $handler->display->display_options['path'] = 'auteurs';

  /* Display: Fichier attaché */
  $handler = $view->new_display('attachment', 'Fichier attaché', 'alpha_pager');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_firstname' => 'field_firstname',
    'field_lastname' => 'field_lastname',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Nom */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lastname']['group_columns'] = array(
    'value' => 'value',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Nom (field_lastname) */
  $handler->display->display_options['arguments']['field_lastname_value']['id'] = 'field_lastname_value';
  $handler->display->display_options['arguments']['field_lastname_value']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['arguments']['field_lastname_value']['field'] = 'field_lastname_value';
  $handler->display->display_options['arguments']['field_lastname_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_lastname_value']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['field_lastname_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_lastname_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_lastname_value']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['field_lastname_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_lastname_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_lastname_value']['summary_options']['inline'] = TRUE;
  $handler->display->display_options['arguments']['field_lastname_value']['summary_options']['separator'] = ' | ';
  $handler->display->display_options['arguments']['field_lastname_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_lastname_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_lastname_value']['limit'] = '1';
  $handler->display->display_options['arguments']['field_lastname_value']['case'] = 'upper';
  $handler->display->display_options['arguments']['field_lastname_value']['path_case'] = 'lower';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'contributor' => 'contributor',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['displays'] = array(
    'authors' => 'authors',
    'default' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $translatables['authors'] = array(
    t('Master'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('FC Contributeur'),
    t('Fonction'),
    t('[field_firstname] [field_lastname]'),
    t('Auteurs'),
    t('Tout'),
    t('Fichier attaché'),
  );
  $export['authors'] = $view;

  $view = new view();
  $view->name = 'catalog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Catalogue';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Comportement en l'absence de résultats: Global : Messages */
  $handler->display->display_options['empty']['messages']['id'] = 'messages';
  $handler->display->display_options['empty']['messages']['table'] = 'views';
  $handler->display->display_options['empty']['messages']['field'] = 'messages';
  /* Relation: Contenu : Termes de taxonomie du nœud */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  /* Champ: Contenu : Couverture */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => 'article-cover-min',
    'image_link' => 'content',
  );
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Champ: Contenu : Contributeurs */
  $handler->display->display_options['fields']['field_contributors']['id'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['fields']['field_contributors']['field'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['label'] = '';
  $handler->display->display_options['fields']['field_contributors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributors']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['field_contributors']['settings'] = array(
    'name' => 'fc_contributors',
    'display_id' => 'author',
    'add' => 'Ajouter',
  );
  $handler->display->display_options['fields']['field_contributors']['delta_offset'] = '0';
  /* Critère de tri: Contenu : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Critère de filtrage: Terme de taxonomie : Nom */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'term_node_tid';

  /* Display: Catalogue */
  $handler = $view->new_display('page_with_page_title', 'Catalogue', 'page_with_page_title_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'list';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_release_date|field_release_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'list';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global : Résumé des résultats */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total titres';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Contenu : Date de parution (field_release_date) */
  $handler->display->display_options['sorts']['field_release_date_value']['id'] = 'field_release_date_value';
  $handler->display->display_options['sorts']['field_release_date_value']['table'] = 'field_data_field_release_date';
  $handler->display->display_options['sorts']['field_release_date_value']['field'] = 'field_release_date_value';
  $handler->display->display_options['sorts']['field_release_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Critère de filtrage: Contenu : Date de parution (field_release_date) */
  $handler->display->display_options['filters']['field_release_date_value']['id'] = 'field_release_date_value';
  $handler->display->display_options['filters']['field_release_date_value']['table'] = 'field_data_field_release_date';
  $handler->display->display_options['filters']['field_release_date_value']['field'] = 'field_release_date_value';
  $handler->display->display_options['filters']['field_release_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_release_date_value']['default_date'] = '3 months ago';
  $handler->display->display_options['path'] = 'catalogue';

  /* Display: Livres auteur */
  $handler = $view->new_display('block', 'Livres auteur', 'author_books');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'author_books';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'author_books';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Contenu : Contributeurs (field_contributors) */
  $handler->display->display_options['relationships']['field_contributors_value']['id'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributors_value']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['relationships']['field_contributors_value']['field'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributors_value']['label'] = 'Contributeurs';
  $handler->display->display_options['relationships']['field_contributors_value']['delta'] = '-1';
  /* Relation: Entity Reference : Referenced Entity */
  $handler->display->display_options['relationships']['field_contributor_target_id']['id'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['relationships']['field_contributor_target_id']['field'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['relationship'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributor_target_id']['label'] = 'Contributor';
  /* Relation: Field collection item : Fonction (field_contributor_function) */
  $handler->display->display_options['relationships']['field_contributor_function_tid']['id'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['table'] = 'field_data_field_contributor_function';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['field'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['relationship'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['label'] = 'Fonction';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Couverture */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => 'article-cover-min',
    'image_link' => 'content',
  );
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Contributor ID (field_contributor_id) */
  $handler->display->display_options['arguments']['field_contributor_id_value']['id'] = 'field_contributor_id_value';
  $handler->display->display_options['arguments']['field_contributor_id_value']['table'] = 'field_data_field_contributor_id';
  $handler->display->display_options['arguments']['field_contributor_id_value']['field'] = 'field_contributor_id_value';
  $handler->display->display_options['arguments']['field_contributor_id_value']['relationship'] = 'field_contributor_target_id';
  $handler->display->display_options['arguments']['field_contributor_id_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_contributor_id_value']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['field_contributor_id_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_contributor_id_value']['default_argument_options']['code'] = '$query = db_select(\'field_data_field_contributor_id\',\'cid\');
$query->addField(\'cid\',\'field_contributor_id_value\');
$query->condition(\'cid.entity_id\', arg(1));
return $query->execute()->fetchField();';
  $handler->display->display_options['arguments']['field_contributor_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_contributor_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_contributor_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Critère de filtrage: Terme de taxonomie : Nom */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_contributor_function_tid';
  $handler->display->display_options['filters']['name']['value'] = 'auteur';

  /* Display: Classement avancé */
  $handler = $view->new_display('page_with_page_title', 'Classement avancé', 'catalog_multi');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Options avancées',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
    'field_universe_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_release_date_value_1' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_release_date_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_themes_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_readership_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'list';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_release_date|field_release_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'list';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global : Résumé des résultats */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total titres';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Contenu : Contributeurs (field_contributors) */
  $handler->display->display_options['relationships']['field_contributors_value']['id'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributors_value']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['relationships']['field_contributors_value']['field'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributors_value']['label'] = 'Contributeurs';
  $handler->display->display_options['relationships']['field_contributors_value']['delta'] = '0';
  /* Relation: Entity Reference : Referenced Entity */
  $handler->display->display_options['relationships']['field_contributor_target_id']['id'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['relationships']['field_contributor_target_id']['field'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['relationship'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributor_target_id']['label'] = 'Contributeur';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Couverture */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => 'article-cover-min',
    'image_link' => 'content',
  );
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Champ: Contenu : Contributeurs */
  $handler->display->display_options['fields']['field_contributors']['id'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['fields']['field_contributors']['field'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['label'] = '';
  $handler->display->display_options['fields']['field_contributors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributors']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['field_contributors']['settings'] = array(
    'name' => 'fc_contributors',
    'display_id' => 'author',
    'add' => 'Ajouter',
  );
  $handler->display->display_options['fields']['field_contributors']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Contenu : Date de parution (field_release_date) */
  $handler->display->display_options['sorts']['field_release_date_value']['id'] = 'field_release_date_value';
  $handler->display->display_options['sorts']['field_release_date_value']['table'] = 'field_data_field_release_date';
  $handler->display->display_options['sorts']['field_release_date_value']['field'] = 'field_release_date_value';
  $handler->display->display_options['sorts']['field_release_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_release_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_release_date_value']['expose']['label'] = 'Date de parution';
  /* Critère de tri: Contenu : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Titre';
  /* Critère de tri: Contenu : Nom (field_lastname) */
  $handler->display->display_options['sorts']['field_lastname_value']['id'] = 'field_lastname_value';
  $handler->display->display_options['sorts']['field_lastname_value']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['sorts']['field_lastname_value']['field'] = 'field_lastname_value';
  $handler->display->display_options['sorts']['field_lastname_value']['relationship'] = 'field_contributor_target_id';
  $handler->display->display_options['sorts']['field_lastname_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_lastname_value']['expose']['label'] = 'Auteur';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Critère de filtrage: Contenu : Univers (field_universe) */
  $handler->display->display_options['filters']['field_universe_tid']['id'] = 'field_universe_tid';
  $handler->display->display_options['filters']['field_universe_tid']['table'] = 'field_data_field_universe';
  $handler->display->display_options['filters']['field_universe_tid']['field'] = 'field_universe_tid';
  $handler->display->display_options['filters']['field_universe_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_universe_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_universe_tid']['expose']['operator_id'] = 'field_universe_tid_op';
  $handler->display->display_options['filters']['field_universe_tid']['expose']['label'] = 'Univers';
  $handler->display->display_options['filters']['field_universe_tid']['expose']['operator'] = 'field_universe_tid_op';
  $handler->display->display_options['filters']['field_universe_tid']['expose']['identifier'] = 'field_universe_tid';
  $handler->display->display_options['filters']['field_universe_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7178059 => 0,
    231346920 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_universe_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_universe_tid']['vocabulary'] = 'universe';
  $handler->display->display_options['filters']['field_universe_tid']['hierarchy'] = 1;
  /* Critère de filtrage: Contenu : Date de parution (field_release_date) */
  $handler->display->display_options['filters']['field_release_date_value']['id'] = 'field_release_date_value';
  $handler->display->display_options['filters']['field_release_date_value']['table'] = 'field_data_field_release_date';
  $handler->display->display_options['filters']['field_release_date_value']['field'] = 'field_release_date_value';
  $handler->display->display_options['filters']['field_release_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_release_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_release_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_release_date_value']['expose']['operator_id'] = 'field_release_date_value_op';
  $handler->display->display_options['filters']['field_release_date_value']['expose']['label'] = 'à partir de';
  $handler->display->display_options['filters']['field_release_date_value']['expose']['description'] = '(mm/aaaa)';
  $handler->display->display_options['filters']['field_release_date_value']['expose']['operator'] = 'field_release_date_value_op';
  $handler->display->display_options['filters']['field_release_date_value']['expose']['identifier'] = 'field_release_date_value';
  $handler->display->display_options['filters']['field_release_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7178059 => 0,
    231346920 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_release_date_value']['group_info']['label'] = 'Date de parution (field_release_date)';
  $handler->display->display_options['filters']['field_release_date_value']['group_info']['identifier'] = 'field_release_date_value';
  $handler->display->display_options['filters']['field_release_date_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_release_date_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_release_date_value']['granularity'] = 'month';
  $handler->display->display_options['filters']['field_release_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_release_date_value']['year_range'] = '-10:+1';
  /* Critère de filtrage: Contenu : Date de parution (field_release_date) */
  $handler->display->display_options['filters']['field_release_date_value_1']['id'] = 'field_release_date_value_1';
  $handler->display->display_options['filters']['field_release_date_value_1']['table'] = 'field_data_field_release_date';
  $handler->display->display_options['filters']['field_release_date_value_1']['field'] = 'field_release_date_value';
  $handler->display->display_options['filters']['field_release_date_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_release_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_release_date_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_release_date_value_1']['expose']['operator_id'] = 'field_release_date_value_1_op';
  $handler->display->display_options['filters']['field_release_date_value_1']['expose']['label'] = 'jusqu\'à';
  $handler->display->display_options['filters']['field_release_date_value_1']['expose']['description'] = '(format : mm/aaaa)';
  $handler->display->display_options['filters']['field_release_date_value_1']['expose']['operator'] = 'field_release_date_value_1_op';
  $handler->display->display_options['filters']['field_release_date_value_1']['expose']['identifier'] = 'field_release_date_value_1';
  $handler->display->display_options['filters']['field_release_date_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7178059 => 0,
    231346920 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_release_date_value_1']['granularity'] = 'month';
  $handler->display->display_options['filters']['field_release_date_value_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_release_date_value_1']['year_range'] = '-10:+1';
  /* Critère de filtrage: Contenu : Thèmes (field_themes) */
  $handler->display->display_options['filters']['field_themes_tid']['id'] = 'field_themes_tid';
  $handler->display->display_options['filters']['field_themes_tid']['table'] = 'field_data_field_themes';
  $handler->display->display_options['filters']['field_themes_tid']['field'] = 'field_themes_tid';
  $handler->display->display_options['filters']['field_themes_tid']['value'] = '';
  $handler->display->display_options['filters']['field_themes_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_themes_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_themes_tid']['expose']['operator_id'] = 'field_themes_tid_op';
  $handler->display->display_options['filters']['field_themes_tid']['expose']['label'] = 'Thème';
  $handler->display->display_options['filters']['field_themes_tid']['expose']['description'] = 'Saisir les premières lettre du terme recherché';
  $handler->display->display_options['filters']['field_themes_tid']['expose']['operator'] = 'field_themes_tid_op';
  $handler->display->display_options['filters']['field_themes_tid']['expose']['identifier'] = 'field_themes_tid';
  $handler->display->display_options['filters']['field_themes_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7178059 => 0,
    231346920 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_themes_tid']['vocabulary'] = 'themes';
  /* Critère de filtrage: Contenu : Lectorat (field_readership) */
  $handler->display->display_options['filters']['field_readership_tid']['id'] = 'field_readership_tid';
  $handler->display->display_options['filters']['field_readership_tid']['table'] = 'field_data_field_readership';
  $handler->display->display_options['filters']['field_readership_tid']['field'] = 'field_readership_tid';
  $handler->display->display_options['filters']['field_readership_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_readership_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_readership_tid']['expose']['operator_id'] = 'field_readership_tid_op';
  $handler->display->display_options['filters']['field_readership_tid']['expose']['label'] = 'Lectorat';
  $handler->display->display_options['filters']['field_readership_tid']['expose']['description'] = 'Garder la touche CTRL appuyée pour sélectionner plusieurs valeurs.';
  $handler->display->display_options['filters']['field_readership_tid']['expose']['operator'] = 'field_readership_tid_op';
  $handler->display->display_options['filters']['field_readership_tid']['expose']['identifier'] = 'field_readership_tid';
  $handler->display->display_options['filters']['field_readership_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_readership_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7178059 => 0,
    231346920 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_readership_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_readership_tid']['vocabulary'] = 'readership';
  $handler->display->display_options['filters']['field_readership_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'catalogue/multi-criteres';

  /* Display: Liste nouveautés */
  $handler = $view->new_display('page_with_page_title', 'Liste nouveautés', 'catalog_new_books_page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global : Résumé des résultats */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total titres';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Contenu : Contributeurs (field_contributors) */
  $handler->display->display_options['relationships']['field_contributors_value']['id'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributors_value']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['relationships']['field_contributors_value']['field'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributors_value']['label'] = 'Contributeurs';
  $handler->display->display_options['relationships']['field_contributors_value']['delta'] = '-1';
  /* Relation: Entity Reference : Referenced Entity */
  $handler->display->display_options['relationships']['field_contributor_target_id']['id'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['relationships']['field_contributor_target_id']['field'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['relationship'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributor_target_id']['label'] = 'Contributeur';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Couverture */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => 'article-cover-min',
    'image_link' => 'content',
  );
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Champ: Contenu : Prénom */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['relationship'] = 'field_contributor_target_id';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Nom */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['relationship'] = 'field_contributor_target_id';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Champ: Nodequeue : Add/remove links */
  $handler->display->display_options['fields']['nodequeue_links']['id'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['table'] = 'node';
  $handler->display->display_options['fields']['nodequeue_links']['field'] = 'nodequeue_links';
  $handler->display->display_options['fields']['nodequeue_links']['label'] = '';
  $handler->display->display_options['fields']['nodequeue_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Contenu : Date de parution (field_release_date) */
  $handler->display->display_options['sorts']['field_release_date_value']['id'] = 'field_release_date_value';
  $handler->display->display_options['sorts']['field_release_date_value']['table'] = 'field_data_field_release_date';
  $handler->display->display_options['sorts']['field_release_date_value']['field'] = 'field_release_date_value';
  $handler->display->display_options['sorts']['field_release_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Critère de filtrage: Contenu : Date de parution (field_release_date) */
  $handler->display->display_options['filters']['field_release_date_value']['id'] = 'field_release_date_value';
  $handler->display->display_options['filters']['field_release_date_value']['table'] = 'field_data_field_release_date';
  $handler->display->display_options['filters']['field_release_date_value']['field'] = 'field_release_date_value';
  $handler->display->display_options['filters']['field_release_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_release_date_value']['default_date'] = '3 months ago';
  $handler->display->display_options['path'] = 'catalogue/liste-nouveautes';

  /* Display: Bloc nouveautés */
  $handler = $view->new_display('block', 'Bloc nouveautés', 'catalog_new_books_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nouveautés';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_carousel_plugin_style';
  $handler->display->display_options['style_options']['interval'] = 'false';
  $handler->display->display_options['style_options']['navigation'] = 1;
  $handler->display->display_options['style_options']['indicators'] = 1;
  $handler->display->display_options['style_options']['pause'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nodequeue : Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['label'] = 'Bloc nouveautés';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['queues'] = array(
    'new_books' => 'new_books',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Contenu : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Critère de tri: Nodequeue : Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Critère de filtrage: Nodequeue : In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  $translatables['catalog'] = array(
    t('Master'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('terme'),
    t('Catalogue'),
    t('@total titres'),
    t('Livres auteur'),
    t('Contributeurs'),
    t('Contributor'),
    t('Fonction'),
    t('Tout'),
    t('Classement avancé'),
    t('Select any filter and click on Apply to see results'),
    t('Contributeur'),
    t('Date de parution'),
    t('Titre'),
    t('Auteur'),
    t('Univers'),
    t('à partir de'),
    t('(mm/aaaa)'),
    t('Date de parution (field_release_date)'),
    t('jusqu\'à'),
    t('(format : mm/aaaa)'),
    t('Thème'),
    t('Saisir les premières lettre du terme recherché'),
    t('Lectorat'),
    t('Garder la touche CTRL appuyée pour sélectionner plusieurs valeurs.'),
    t('Liste nouveautés'),
    t('Bloc nouveautés'),
    t('Nouveautés'),
  );
  $export['catalog'] = $view;

  $view = new view();
  $view->name = 'fc_contributors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'FC-Contributeurs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relation: Field collection item : Fonction (field_contributor_function) */
  $handler->display->display_options['relationships']['field_contributor_function_tid']['id'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['table'] = 'field_data_field_contributor_function';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['field'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['label'] = 'Fonction du contributeur';
  /* Relation: Entity Reference : Referenced Entity */
  $handler->display->display_options['relationships']['field_contributor_target_id']['id'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['relationships']['field_contributor_target_id']['field'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['label'] = 'Contributeur';
  /* Champ: Field collection item : Contributor */
  $handler->display->display_options['fields']['field_contributor']['id'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['fields']['field_contributor']['field'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['label'] = '';
  $handler->display->display_options['fields']['field_contributor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_contributor']['settings'] = array(
    'view_mode' => 'on_book_list',
    'links' => 0,
  );
  /* Critère de tri: Contenu : Contributor ID (field_contributor_id) */
  $handler->display->display_options['sorts']['field_contributor_id_value']['id'] = 'field_contributor_id_value';
  $handler->display->display_options['sorts']['field_contributor_id_value']['table'] = 'field_data_field_contributor_id';
  $handler->display->display_options['sorts']['field_contributor_id_value']['field'] = 'field_contributor_id_value';
  $handler->display->display_options['sorts']['field_contributor_id_value']['relationship'] = 'field_contributor_target_id';
  /* Filtre contextuel: Field collection item : Identifiant de Field collection item */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['item_id']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['item_id']['break_phrase'] = TRUE;
  /* Critère de filtrage: Terme de taxonomie : Nom */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_contributor_function_tid';
  $handler->display->display_options['filters']['name']['value'] = 'auteur';
  $handler->display->display_options['filters']['name']['group'] = 1;

  /* Display: Auteur liste livres */
  $handler = $view->new_display('block', 'Auteur liste livres', 'author');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Field collection item : Contributor */
  $handler->display->display_options['fields']['field_contributor']['id'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['fields']['field_contributor']['field'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['label'] = '';
  $handler->display->display_options['fields']['field_contributor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_contributor']['settings'] = array(
    'view_mode' => 'on_book_list',
    'links' => 0,
  );

  /* Display: Contributeurs fiche livre */
  $handler = $view->new_display('block', 'Contributeurs fiche livre', 'book_contributors');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_contributor_function',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_firstname' => 'field_firstname',
    'field_lastname' => 'field_lastname',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_contributor_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Champ: Field collection item : Fonction */
  $handler->display->display_options['fields']['field_contributor_function']['id'] = 'field_contributor_function';
  $handler->display->display_options['fields']['field_contributor_function']['table'] = 'field_data_field_contributor_function';
  $handler->display->display_options['fields']['field_contributor_function']['field'] = 'field_contributor_function';
  $handler->display->display_options['fields']['field_contributor_function']['label'] = '';
  $handler->display->display_options['fields']['field_contributor_function']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_contributor_function']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributor_function']['type'] = 'taxonomy_term_reference_plain';
  /* Champ: Contenu : Prénom */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['relationship'] = 'field_contributor_target_id';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Nom */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['relationship'] = 'field_contributor_target_id';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Champ: Prénom Nom */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Prénom Nom';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_firstname] [field_lastname]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $translatables['fc_contributors'] = array(
    t('Master'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Fonction du contributeur'),
    t('Contributeur'),
    t('Tout'),
    t('Auteur liste livres'),
    t('Contributeurs fiche livre'),
    t('[field_firstname] [field_lastname]'),
  );
  $export['fc_contributors'] = $view;

  $view = new view();
  $view->name = 'first_level_universes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Univers premier niveau';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relation: Terme de taxonomie : Terme parent */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Champ: Terme de taxonomie : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Critère de filtrage: Vocabulaire de taxonomie : Nom système */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'universe' => 'universe',
  );
  /* Critère de filtrage: Terme de taxonomie : Identifiant (ID) du terme */
  $handler->display->display_options['filters']['tid_raw']['id'] = 'tid_raw';
  $handler->display->display_options['filters']['tid_raw']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid_raw']['field'] = 'tid_raw';
  $handler->display->display_options['filters']['tid_raw']['relationship'] = 'parent';
  $handler->display->display_options['filters']['tid_raw']['operator'] = 'empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['first_level_universes'] = array(
    t('Master'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Parent'),
    t('Block'),
  );
  $export['first_level_universes'] = $view;

  $view = new view();
  $view->name = 'themes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Thèmes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Thèmes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Lettre */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['ui_name'] = 'Lettre';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '1';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Champ: Terme de taxonomie : Nom */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = TRUE;
  /* Critère de filtrage: Vocabulaire de taxonomie : Nom système */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'themes' => 'themes',
  );

  /* Display: Page (with Page Title) */
  $handler = $view->new_display('page_with_page_title', 'Page (with Page Title)', 'page_with_page_title_1');
  $handler->display->display_options['path'] = 'catalogue/themes';
  $translatables['themes'] = array(
    t('Master'),
    t('Thèmes'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Page (with Page Title)'),
  );
  $export['themes'] = $view;

  $view = new view();
  $view->name = 'universes';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Univers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendant';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descendant';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Options avancées',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Entête: Global : Résumé des résultats */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total livres';
  /* Relation: Contenu : Contributeurs (field_contributors) */
  $handler->display->display_options['relationships']['field_contributors_value']['id'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributors_value']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['relationships']['field_contributors_value']['field'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributors_value']['label'] = 'FC Contributeurs';
  $handler->display->display_options['relationships']['field_contributors_value']['delta'] = '0';
  /* Relation: Field collection item : Fonction (field_contributor_function) */
  $handler->display->display_options['relationships']['field_contributor_function_tid']['id'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['table'] = 'field_data_field_contributor_function';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['field'] = 'field_contributor_function_tid';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['relationship'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributor_function_tid']['label'] = 'Fonction';
  /* Relation: Entity Reference : Referenced Entity */
  $handler->display->display_options['relationships']['field_contributor_target_id']['id'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['relationships']['field_contributor_target_id']['field'] = 'field_contributor_target_id';
  $handler->display->display_options['relationships']['field_contributor_target_id']['relationship'] = 'field_contributors_value';
  $handler->display->display_options['relationships']['field_contributor_target_id']['label'] = 'Contributeur';
  /* Champ: Contenu : Couverture */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Contributeurs */
  $handler->display->display_options['fields']['field_contributors']['id'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['fields']['field_contributors']['field'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['label'] = '';
  $handler->display->display_options['fields']['field_contributors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributors']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['field_contributors']['settings'] = array(
    'name' => 'fc_contributors',
    'display_id' => 'author',
    'add' => 'Ajouter',
  );
  $handler->display->display_options['fields']['field_contributors']['delta_offset'] = '0';
  /* Champ: Contenu : Contributeurs */
  $handler->display->display_options['fields']['field_contributors_1']['id'] = 'field_contributors_1';
  $handler->display->display_options['fields']['field_contributors_1']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['fields']['field_contributors_1']['field'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_contributors_1']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_contributors_1']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_contributors_1']['delta_offset'] = '0';
  /* Champ: Field collection item : Contributor */
  $handler->display->display_options['fields']['field_contributor']['id'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['fields']['field_contributor']['field'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['relationship'] = 'field_contributors_value';
  $handler->display->display_options['fields']['field_contributor']['label'] = '';
  $handler->display->display_options['fields']['field_contributor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributor']['settings'] = array(
    'link' => 0,
  );
  /* Champ: Field collection item : Fonction */
  $handler->display->display_options['fields']['field_contributor_function']['id'] = 'field_contributor_function';
  $handler->display->display_options['fields']['field_contributor_function']['table'] = 'field_data_field_contributor_function';
  $handler->display->display_options['fields']['field_contributor_function']['field'] = 'field_contributor_function';
  $handler->display->display_options['fields']['field_contributor_function']['relationship'] = 'field_contributors_value';
  $handler->display->display_options['fields']['field_contributor_function']['label'] = '';
  $handler->display->display_options['fields']['field_contributor_function']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributor_function']['type'] = 'taxonomy_term_reference_plain';
  /* Critère de tri: Contenu : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Titre';
  /* Critère de tri: Contenu : Nom (field_lastname) */
  $handler->display->display_options['sorts']['field_lastname_value']['id'] = 'field_lastname_value';
  $handler->display->display_options['sorts']['field_lastname_value']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['sorts']['field_lastname_value']['field'] = 'field_lastname_value';
  $handler->display->display_options['sorts']['field_lastname_value']['relationship'] = 'field_contributor_target_id';
  $handler->display->display_options['sorts']['field_lastname_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_lastname_value']['expose']['label'] = 'Auteur';
  /* Critère de tri: Contenu : Date de parution (field_release_date) */
  $handler->display->display_options['sorts']['field_release_date_value']['id'] = 'field_release_date_value';
  $handler->display->display_options['sorts']['field_release_date_value']['table'] = 'field_data_field_release_date';
  $handler->display->display_options['sorts']['field_release_date_value']['field'] = 'field_release_date_value';
  $handler->display->display_options['sorts']['field_release_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_release_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_release_date_value']['expose']['label'] = 'Date de parution';
  /* Filtre contextuel: Contenu : Possède l'identifiant de terme de taxonomie (avec profondeur) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '2';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Filtre contextuel: Contenu : Possède l'identifiant du terme de taxonomie avec modification de profondeur */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title'] = 'Tout';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Critère de filtrage: Contenu : Publié ou admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Critère de filtrage: Terme de taxonomie : Nom */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_contributor_function_tid';
  $handler->display->display_options['filters']['name']['value'] = 'auteur';

  /* Display: Liste livres */
  $handler = $view->new_display('page', 'Liste livres', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'list';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|title';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'list';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Couverture */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Contributeurs */
  $handler->display->display_options['fields']['field_contributors']['id'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['fields']['field_contributors']['field'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['label'] = '';
  $handler->display->display_options['fields']['field_contributors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributors']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['field_contributors']['settings'] = array(
    'name' => 'fc_contributors',
    'display_id' => 'author',
    'add' => 'Ajouter',
  );
  $handler->display->display_options['fields']['field_contributors']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Liste livres (backup) */
  $handler = $view->new_display('page', 'Liste livres (backup)', 'page_1');
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Liste livres (copie) */
  $handler = $view->new_display('page', 'Liste livres (copie)', 'page_2');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Couverture */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Contributeurs */
  $handler->display->display_options['fields']['field_contributors']['id'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['fields']['field_contributors']['field'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['label'] = '';
  $handler->display->display_options['fields']['field_contributors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contributors']['type'] = 'field_collection_views_view';
  $handler->display->display_options['fields']['field_contributors']['settings'] = array(
    'name' => 'fc_contributors',
    'display_id' => 'author',
    'add' => 'Ajouter',
  );
  $handler->display->display_options['fields']['field_contributors']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'taxonomy/term/%';
  $translatables['universes'] = array(
    t('Master'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Ascendant'),
    t('Descendant'),
    t('Select any filter and click on Apply to see results'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('@total livres'),
    t('FC Contributeurs'),
    t('Fonction'),
    t('Contributeur'),
    t('Contributeurs'),
    t('Titre'),
    t('Auteur'),
    t('Date de parution'),
    t('Tout'),
    t('%1'),
    t('Liste livres'),
    t('Feed'),
    t('Liste livres (backup)'),
    t('Liste livres (copie)'),
  );
  $export['universes'] = $view;

  return $export;
}
