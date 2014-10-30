<?php
/**
 * @file
 * feature_events.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function feature_events_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Dédicace',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '8c9ae363-be21-4cdf-a8ca-9882444cb008',
    'vocabulary_machine_name' => 'event_types',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Salon',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '96293ffc-91ae-4f78-af55-495fabedace9',
    'vocabulary_machine_name' => 'event_types',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Rencontre',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'a7fc62b5-3466-441e-86e7-86ee3db1d7a4',
    'vocabulary_machine_name' => 'event_types',
    'metatags' => array(),
  );
  return $terms;
}
