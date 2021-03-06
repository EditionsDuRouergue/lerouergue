<?php
/**
 * @file
 * feature_catalog.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_catalog_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_article';
  $strongarm->value = 0;
  $export['comment_anonymous_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_contributor';
  $strongarm->value = 0;
  $export['comment_anonymous_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_article';
  $strongarm->value = '1';
  $export['comment_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_contributor';
  $strongarm->value = '1';
  $export['comment_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_article';
  $strongarm->value = 1;
  $export['comment_default_mode_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_contributor';
  $strongarm->value = 1;
  $export['comment_default_mode_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_article';
  $strongarm->value = '50';
  $export['comment_default_per_page_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_contributor';
  $strongarm->value = '50';
  $export['comment_default_per_page_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_article';
  $strongarm->value = 1;
  $export['comment_form_location_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_contributor';
  $strongarm->value = 1;
  $export['comment_form_location_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_article';
  $strongarm->value = '1';
  $export['comment_preview_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_contributor';
  $strongarm->value = '1';
  $export['comment_preview_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_article';
  $strongarm->value = 1;
  $export['comment_subject_field_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_contributor';
  $strongarm->value = 1;
  $export['comment_subject_field_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_release_date';
  $strongarm->value = 'F Y';
  $export['date_format_release_date'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__article';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'block' => array(
        'custom_settings' => FALSE,
      ),
      'list' => array(
        'custom_settings' => TRUE,
      ),
      'on_article_page' => array(
        'custom_settings' => FALSE,
      ),
      'on_book_list' => array(
        'custom_settings' => FALSE,
      ),
      'author_books' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'carousel' => array(
        'custom_settings' => FALSE,
      ),
      'map_block' => array(
        'custom_settings' => FALSE,
      ),
      'in_news_block' => array(
        'custom_settings' => TRUE,
      ),
      'livre_couv_li_e' => array(
        'custom_settings' => TRUE,
      ),
      'workshop_page_list' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '28',
        ),
        'title' => array(
          'weight' => '4',
        ),
        'path' => array(
          'weight' => '27',
        ),
        'redirect' => array(
          'weight' => '26',
        ),
      ),
      'display' => array(
        'publication_status' => array(
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'author_books' => NULL,
          'in_news_block' => NULL,
          'livre_couv_li_e' => NULL,
        ),
        'field_publication_status' => array(
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '99',
            'visible' => TRUE,
          ),
          'list' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'block' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'author_books' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'in_news_block' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'livre_couv_li_e' => array(
            'weight' => '36',
            'visible' => FALSE,
          ),
        ),
        'field_bs_button_browse_pdf' => array(
          'full' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'list' => array(
            'weight' => '35',
            'visible' => FALSE,
          ),
          'author_books' => array(
            'weight' => '35',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '101',
            'visible' => TRUE,
          ),
          'in_news_block' => array(
            'weight' => '36',
            'visible' => FALSE,
          ),
          'livre_couv_li_e' => array(
            'weight' => '37',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__contributor';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'block' => array(
        'custom_settings' => FALSE,
      ),
      'list' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'on_article_page' => array(
        'custom_settings' => TRUE,
      ),
      'on_book_list' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'livre_couv_li_e' => array(
        'custom_settings' => FALSE,
      ),
      'author_books' => array(
        'custom_settings' => FALSE,
      ),
      'in_news_block' => array(
        'custom_settings' => FALSE,
      ),
      'carousel' => array(
        'custom_settings' => FALSE,
      ),
      'map_block' => array(
        'custom_settings' => FALSE,
      ),
      'workshop_page_list' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '15',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '13',
        ),
        'redirect' => array(
          'weight' => '14',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_article';
  $strongarm->value = '0';
  $export['language_content_type_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_contributor';
  $strongarm->value = '0';
  $export['language_content_type_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_article';
  $strongarm->value = array();
  $export['menu_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_contributor';
  $strongarm->value = array();
  $export['menu_options_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_contributor';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_article';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_contributor';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_article';
  $strongarm->value = '1';
  $export['node_preview_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_contributor';
  $strongarm->value = '1';
  $export['node_preview_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_article';
  $strongarm->value = 0;
  $export['node_submitted_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_contributor';
  $strongarm->value = 0;
  $export['node_submitted_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_article_pattern';
  $strongarm->value = 'catalogue/[node:title]';
  $export['pathauto_node_article_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_contributor_pattern';
  $strongarm->value = 'auteurs/[node:title]';
  $export['pathauto_node_contributor_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_functions_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_functions_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_readership_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_readership_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_themes_pattern';
  $strongarm->value = 'catalogue/[term:vocabulary]/[term:name]';
  $export['pathauto_taxonomy_term_themes_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_display_descendants_universe';
  $strongarm->value = 0;
  $export['taxonomy_menu_display_descendants_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_display_num_universe';
  $strongarm->value = 0;
  $export['taxonomy_menu_display_num_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_end_all_universe';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_end_all_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_expanded_universe';
  $strongarm->value = 1;
  $export['taxonomy_menu_expanded_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_flat_universe';
  $strongarm->value = 0;
  $export['taxonomy_menu_flat_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_hide_empty_terms_universe';
  $strongarm->value = 0;
  $export['taxonomy_menu_hide_empty_terms_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_path_universe';
  $strongarm->value = 'taxonomy_menu_path_default';
  $export['taxonomy_menu_path_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_rebuild_universe';
  $strongarm->value = 1;
  $export['taxonomy_menu_rebuild_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_sync_universe';
  $strongarm->value = 1;
  $export['taxonomy_menu_sync_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_term_item_description_universe';
  $strongarm->value = 0;
  $export['taxonomy_menu_term_item_description_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_trails_node_article';
  $strongarm->value = array(
    'selection_method' => 'first',
    'only_without_menu' => 0,
    'set_breadcrumb' => '0',
    'term_path' => 'default',
    'term_path_patterns' => array(),
    'instances' => array(
      'field_universe' => 'field_universe',
    ),
    'paths_ui' => '',
    'trail_per_menu' => 0,
  );
  $export['taxonomy_menu_trails_node_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_vocab_menu_universe';
  $strongarm->value = 'menu-universe';
  $export['taxonomy_menu_vocab_menu_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_vocab_parent_universe';
  $strongarm->value = '0';
  $export['taxonomy_menu_vocab_parent_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_item_description_universe';
  $strongarm->value = 0;
  $export['taxonomy_menu_voc_item_description_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_item_universe';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_voc_item_universe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_name_universe';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_voc_name_universe'] = $strongarm;

  return $export;
}
