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
      'weight' => '13',
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
        1 => 'field_subtitle',
      ),
      'left' => array(
        2 => 'field_cover_image',
        3 => 'field_publication_status',
        4 => 'field_release_date',
        5 => 'field_number_pages',
        6 => 'field_price',
        7 => 'field_format',
        8 => 'field_isbn',
        9 => 'field_gencod',
        10 => 'field_barcode',
      ),
      'central' => array(
        11 => 'body',
        12 => 'field_press_quotes',
        13 => 'service_links_displays_group',
        14 => 'field_inner_pages',
      ),
      'right' => array(
        15 => 'field_contributors',
        16 => 'field_themes',
        17 => 'field_readership',
        18 => 'field_bs_button_browse_pdf',
        19 => 'field_num_version_link',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'field_subtitle' => 'top',
      'field_cover_image' => 'left',
      'field_publication_status' => 'left',
      'field_release_date' => 'left',
      'field_number_pages' => 'left',
      'field_price' => 'left',
      'field_format' => 'left',
      'field_isbn' => 'left',
      'field_gencod' => 'left',
      'field_barcode' => 'left',
      'body' => 'central',
      'field_press_quotes' => 'central',
      'service_links_displays_group' => 'central',
      'field_inner_pages' => 'central',
      'field_contributors' => 'right',
      'field_themes' => 'right',
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
    'hide_page_title' => '1',
    'page_option_title' => '',
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
        1 => 'field_pseudonyme',
        2 => 'body',
        3 => 'field_contributor_url',
      ),
    ),
    'fields' => array(
      'field_picture' => 'central',
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
      ),
    ),
    'fields' => array(
      'field_firstname' => 'ds_content',
      'field_lastname' => 'ds_content',
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
