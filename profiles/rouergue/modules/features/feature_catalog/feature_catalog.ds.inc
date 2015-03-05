<?php
/**
 * @file
 * feature_catalog.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function feature_catalog_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|author_books';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'author_books';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|article|author_books'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|block';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'block';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => '',
        'class' => '',
      ),
    ),
  );
  $export['node|article|block'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'authors' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:9:{s:5:"label";s:5:"title";s:9:"formatter";s:27:"field_collection_views_view";s:11:"delta_limit";s:1:"0";s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";i:0;s:18:"formatter_settings";a:3:{s:3:"add";s:0:"";s:4:"name";s:15:"fc_contributors";s:10:"display_id";s:24:"book_contributors_author";}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:23:"node:field_contributors";}',
        'load_terms' => 0,
      ),
    ),
    'illustrators' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:9:{s:5:"label";s:5:"title";s:9:"formatter";s:27:"field_collection_views_view";s:11:"delta_limit";s:1:"0";s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";i:0;s:18:"formatter_settings";a:3:{s:3:"add";s:0:"";s:4:"name";s:15:"fc_contributors";s:10:"display_id";s:29:"book_contributors_illustrator";}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:23:"node:field_contributors";}',
        'load_terms' => 0,
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
      ),
    ),
    'service_links_displays_group' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'sld_group_image_and_text',
    ),
  );
  $export['node|article|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|article|list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|contributor|on_article_page';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'contributor';
  $ds_fieldsetting->view_mode = 'on_article_page';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => '',
        'class' => '',
      ),
    ),
  );
  $export['node|contributor|on_article_page'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function feature_catalog_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'authors';
  $ds_field->label = 'Auteur(s)';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'article|full';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Ex. : h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['authors'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'illustrators';
  $ds_field->label = 'Illustrateur(s)';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'article|full';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Ex. : h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['illustrators'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_catalog_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|author_books';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'author_books';
  $ds_layout->layout = 'bootstrap_12_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_publication_status',
        1 => 'title',
      ),
      'central' => array(
        2 => 'field_cover_image',
      ),
    ),
    'fields' => array(
      'field_publication_status' => 'top',
      'title' => 'top',
      'field_cover_image' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'top' => array(
        'infosWrapper' => 'infosWrapper',
      ),
      'central' => array(
        'couvWrapper' => 'couvWrapper',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|author_books'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|block';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'block';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_cover_image',
        1 => 'field_publication_status',
        2 => 'title',
        3 => 'field_contributors',
      ),
    ),
    'fields' => array(
      'field_cover_image' => 'ds_content',
      'field_publication_status' => 'ds_content',
      'title' => 'ds_content',
      'field_contributors' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|block'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_4_5_3';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'title',
        3 => 'field_subtitle',
      ),
      'central' => array(
        1 => 'authors',
        2 => 'illustrators',
        11 => 'body',
        14 => 'field_press_quotes',
        15 => 'service_links_displays_group',
        16 => 'field_inner_pages',
      ),
      'left' => array(
        4 => 'group_couv_wrapper',
        5 => 'field_publication_status',
        6 => 'field_cover_image',
        7 => 'group_infos_article',
        8 => 'field_release_date',
        9 => 'field_barcode',
        10 => 'field_number_pages',
        12 => 'field_price',
        13 => 'field_format',
        17 => 'field_isbn',
        20 => 'field_gencod',
      ),
      'right' => array(
        18 => 'field_contributors',
        19 => 'field_themes',
        21 => 'field_readership',
        22 => 'field_bs_button_browse_pdf',
        23 => 'field_num_version_link',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'authors' => 'central',
      'illustrators' => 'central',
      'field_subtitle' => 'top',
      'group_couv_wrapper' => 'left',
      'field_publication_status' => 'left',
      'field_cover_image' => 'left',
      'group_infos_article' => 'left',
      'field_release_date' => 'left',
      'field_barcode' => 'left',
      'field_number_pages' => 'left',
      'body' => 'central',
      'field_price' => 'left',
      'field_format' => 'left',
      'field_press_quotes' => 'central',
      'service_links_displays_group' => 'central',
      'field_inner_pages' => 'central',
      'field_isbn' => 'left',
      'field_contributors' => 'right',
      'field_themes' => 'right',
      'field_gencod' => 'left',
      'field_readership' => 'right',
      'field_bs_button_browse_pdf' => 'right',
      'field_num_version_link' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'list';
  $ds_layout->layout = 'bootstrap_12_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_publication_status',
        1 => 'title',
        2 => 'field_contributors',
      ),
      'central' => array(
        3 => 'field_cover_image',
      ),
    ),
    'fields' => array(
      'field_publication_status' => 'top',
      'title' => 'top',
      'field_contributors' => 'top',
      'field_cover_image' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'top' => array(
        'infosWrapper' => 'infosWrapper',
      ),
      'central' => array(
        'couvWrapper' => 'couvWrapper',
      ),
    ),
    'wrappers' => array(
      'top' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contributor|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contributor';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_picture',
        1 => 'field_firstname',
        2 => 'field_lastname',
        3 => 'field_pseudonyme',
        4 => 'body',
        5 => 'field_contributor_url',
      ),
    ),
    'fields' => array(
      'field_picture' => 'central',
      'field_firstname' => 'central',
      'field_lastname' => 'central',
      'field_pseudonyme' => 'central',
      'body' => 'central',
      'field_contributor_url' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|contributor|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contributor|on_article_page';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contributor';
  $ds_layout->view_mode = 'on_article_page';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|contributor|on_article_page'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contributor|on_book_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contributor';
  $ds_layout->view_mode = 'on_book_list';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_firstname',
        1 => 'field_lastname',
        2 => 'field_pseudonyme',
      ),
    ),
    'fields' => array(
      'field_firstname' => 'ds_content',
      'field_lastname' => 'ds_content',
      'field_pseudonyme' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|contributor|on_book_list'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function feature_catalog_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'author_books';
  $ds_view_mode->label = 'Livres auteur';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['author_books'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'on_article_page';
  $ds_view_mode->label = 'Sur page livre';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
    'node' => 'node',
  );
  $export['on_article_page'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'on_book_list';
  $ds_view_mode->label = 'Sur liste livres';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
    'node' => 'node',
  );
  $export['on_book_list'] = $ds_view_mode;

  return $export;
}
