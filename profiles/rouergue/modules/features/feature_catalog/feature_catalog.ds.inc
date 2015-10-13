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
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
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
      'weight' => '8',
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
      'weight' => '9',
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
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'sld_group_image_and_text',
    ),
  );
  $export['node|article|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|in_news_block';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'in_news_block';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_release_date',
    ),
  );
  $export['node|article|in_news_block'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
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
  $ds_layout->layout = 'rouergue_12_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_publication_status',
        1 => 'field_cover_image',
      ),
      'middle' => array(
        2 => 'title',
      ),
    ),
    'fields' => array(
      'field_publication_status' => 'top',
      'field_cover_image' => 'top',
      'title' => 'middle',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'middle' => 'div',
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
  $ds_layout->layout = 'rouergue_4_5_3';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'title',
        1 => 'field_subtitle',
      ),
      'left' => array(
        2 => 'field_publication_status',
        3 => 'group_couv',
        4 => 'field_cover_image',
        5 => 'field_bs_button_browse_pdf',
        7 => 'field_themes',
        9 => 'field_barcode',
      ),
      'right' => array(
        6 => 'field_release_date',
        8 => 'field_number_pages',
        11 => 'field_format',
        13 => 'field_price',
        15 => 'field_isbn',
        19 => 'field_gencod',
        21 => 'field_contributors',
        22 => 'group_infos_article',
        23 => 'field_readership',
        24 => 'field_num_version_link',
      ),
      'middle' => array(
        10 => 'group_contributors',
        12 => 'authors',
        14 => 'body',
        16 => 'illustrators',
        17 => 'field_press_quotes',
        18 => 'service_links_displays_group',
        20 => 'field_inner_pages',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'field_subtitle' => 'top',
      'field_publication_status' => 'left',
      'group_couv' => 'left',
      'field_cover_image' => 'left',
      'field_bs_button_browse_pdf' => 'left',
      'field_release_date' => 'right',
      'field_themes' => 'left',
      'field_number_pages' => 'right',
      'field_barcode' => 'left',
      'group_contributors' => 'middle',
      'field_format' => 'right',
      'authors' => 'middle',
      'field_price' => 'right',
      'body' => 'middle',
      'field_isbn' => 'right',
      'illustrators' => 'middle',
      'field_press_quotes' => 'middle',
      'service_links_displays_group' => 'middle',
      'field_gencod' => 'right',
      'field_inner_pages' => 'middle',
      'field_contributors' => 'right',
      'group_infos_article' => 'right',
      'field_readership' => 'right',
      'field_num_version_link' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|article|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|in_news_block';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'in_news_block';
  $ds_layout->layout = 'rouergue_12_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_cover_image',
      ),
      'middle' => array(
        1 => 'title',
        2 => 'field_contributors',
        3 => 'post_date',
      ),
    ),
    'fields' => array(
      'field_cover_image' => 'top',
      'title' => 'middle',
      'field_contributors' => 'middle',
      'post_date' => 'middle',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'middle' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|in_news_block'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'list';
  $ds_layout->layout = 'rouergue_12_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_publication_status',
        1 => 'field_cover_image',
      ),
      'middle' => array(
        2 => 'title',
        3 => 'field_contributors',
      ),
    ),
    'fields' => array(
      'field_publication_status' => 'top',
      'field_cover_image' => 'top',
      'title' => 'middle',
      'field_contributors' => 'middle',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'middle' => 'div',
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
  $ds_layout->layout = 'rouergue_4_5_3';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_displayed_name',
      ),
      'left' => array(
        1 => 'field_picture',
        2 => 'field_copyright',
      ),
      'middle' => array(
        3 => 'body',
        4 => 'field_contributor_url',
      ),
    ),
    'fields' => array(
      'field_displayed_name' => 'top',
      'field_picture' => 'left',
      'field_copyright' => 'left',
      'body' => 'middle',
      'field_contributor_url' => 'middle',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|contributor|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contributor|on_article_page';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contributor';
  $ds_layout->view_mode = 'on_article_page';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'regions' => array(
      'central' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'central',
    ),
  );
  $export['node|contributor|on_article_page'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contributor|on_book_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contributor';
  $ds_layout->view_mode = 'on_book_list';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'regions' => array(
      'central' => array(
        0 => 'field_displayed_name',
      ),
    ),
    'fields' => array(
      'field_displayed_name' => 'central',
    ),
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
  $ds_view_mode->view_mode = 'in_news_block';
  $ds_view_mode->label = 'Dans le bloc nouveautés';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['in_news_block'] = $ds_view_mode;

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
