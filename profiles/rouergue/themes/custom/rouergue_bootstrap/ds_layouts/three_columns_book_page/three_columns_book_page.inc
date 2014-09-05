<?php

/**
 * @file
 * Display Suite Three columns book page configuration.
 */

function ds_three_columns_book_page() {
  return array(
    'label' => t('Three columns book page'),
    'regions' => array(
      'left' => t('Left'),
      'middle' => t('Middle'),
      'right' => t('Right'),
    ),
    // Uncomment if you want to include a CSS file for this layout (three_columns_book_page.css)
    'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (three_columns_book_page.png)
    'image' => TRUE,
  );
}
