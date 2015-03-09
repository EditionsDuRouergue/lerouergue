<?php 

/**
 * Implements hook_features_export_options().
 */
function features_date_format_features_export_options() {
  $options = array();

  $date_formats = system_get_date_formats('custom');
  if ($date_formats) {
    foreach ($date_formats as $format) {
      $options['date_format_' . $format['dfid']] = t('Date format') . ': '. $format['format'];
    }
  }
  
  return $options;
}

/**
 * Implements hook_features_export().
 */
function features_date_format_features_export($data, &$export, $module_name) {
  $pipe = array();
  $export['dependencies']['features_date_formats'] = 'features_date_formats';
  foreach ($data as $component) {
    $export['features']['features_date_format'][$component] = $component;
    if (!isset($pipe['date_format'])) {
      $pipe['date_format'] = array();
    }
    $pipe['date_format'][] = $component;
  }
  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function features_date_format_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  $code[] = '  $fdf_config = array();';
  $code[] = '';
  foreach ($data as $sys_name) {
    $dfid = intval(str_replace('date_format_', '', $sys_name));
    $format = system_get_date_format($dfid);
    $code[] = '  $fdf_config[] = ' . features_var_export($format, '  ') . ';';
  }
  $code[] = '  return $fdf_config;';
  $code = implode("\n", $code);
  return array('features_date_format_default' => $code);
}

/**
 * Implements hook_features_export_rebuild().
 */
function features_date_format_features_rebuild($module) {
  $formats = module_invoke($module, 'features_date_format_default');
  foreach ($formats as $format) {
    db_merge('date_formats')
      ->key(array(
        'dfid' => $format['dfid']
      ))
      ->fields(array(
        'format' => $format['format'],
        'type' => $format['type'],
        'locked' => $format['locked']
      ))
      ->execute();
  }
}

/**
 * Implements hook_features_revert().
 */
function features_date_format_features_revert($module) {
  features_date_format_features_rebuild($module);
  return TRUE;
}

/**
 * Implements hook_features_export_options().
 */
function features_date_type_features_export_options() {
  $options = array();

  $date_types = system_get_date_types();
  foreach ($date_types as $type) {
    if ($type['locked']) {
      continue;
    }
    $options['date_type_' . $type['type']] = t('Date type') . ': '. $type['type'];
  }

  return $options;
}

/**
 * Implements hook_features_export().
 */
function features_date_type_features_export($data, &$export, $module_name) {
  $pipe = array();
  $export['dependencies']['features_date_types'] = 'features_date_formats';
  foreach ($data as $component) {
    $export['features']['features_date_type'][$component] = $component;
    if (!isset($pipe['date_type'])) {
      $pipe['date_type'] = array();
    }
    $pipe['date_type'][] = $component;
  }
  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function features_date_type_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  $code[] = '  $fdt_config = array();';
  $code[] = '';
  foreach ($data as $sys_name) {
    $type = str_replace('date_type_', '', $sys_name);
    $format = system_get_date_types($type);
    $code[] = '  $fdt_config[] = ' . features_var_export($format, '  ') . ';';
  }
  $code[] = '  return $fdt_config;';
  $code = implode("\n", $code);
  return array('features_date_type_default' => $code);
}

/**
 * Implements hook_features_export_rebuild().
 */
function features_date_type_features_rebuild($module) {
  $types = module_invoke($module, 'features_date_type_default');
  foreach ($types as $type) {
    db_merge('date_format_type')
      ->key(array(
        'type' => $type['type']
      ))
      ->fields(array(
        'title' => $type['title'],
        'locked' => $type['locked']
      ))
      ->execute();
  }
}

/**
 * Implements hook_features_revert().
 */
function features_date_type_features_revert($module) {
  features_date_type_features_rebuild($module);
  return TRUE;
}
