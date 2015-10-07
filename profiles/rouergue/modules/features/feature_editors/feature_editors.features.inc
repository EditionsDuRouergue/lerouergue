<?php
/**
 * @file
 * feature_editors.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_editors_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
