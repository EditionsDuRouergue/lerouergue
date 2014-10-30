<?php
/**
 * @file
 * feature_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agenda_event';
  $context->description = '';
  $context->tag = 'Layout';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-events-agenda_map_block' => array(
          'module' => 'views',
          'delta' => 'events-agenda_map_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-events-agenda_block' => array(
          'module' => 'views',
          'delta' => 'events-agenda_block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  $export['agenda_event'] = $context;

  return $export;
}
