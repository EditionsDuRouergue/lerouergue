<?php
/**
 * @file
 * feature_contextes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_contextes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
