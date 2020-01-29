<?php
/**
 * @file
 * Administrative form include for the Resave Nodes module.
 *
 * This file has the breakout of the main function that does the node
 * resaving.  This was moved out of the resave_nodes.module file for better
 * organization.
 */


/**
 * Form builder.  Create and display the Resave Nodes config settings form.
 */
function resave_nodes_form($form, &$form_state) {
  $content_types  = array();
  // $product_types  = array();
  $validate_types = array();
  $everything     = entity_get_info();
  foreach ($everything as $type => $data) {
    if ((array_key_exists('bundles', $data)) && (!empty($data['bundles']))) {
      if ($type == 'node') {
        foreach ($data['bundles'] as $type_key => $type_data) {
          $content_types[$type_key] = $type_data['label'];
          $validate_types[]         = $type_key;
        }
      // } elseif ($type == 'commerce_product') {
      //   foreach ($data['bundles'] as $type_key => $type_data) {
      //     $product_types[$type_key] = $type_data['label'];
      //     $validate_types[]         = $type_key;
      //   }
      }
    }
  }
  variable_set('resave_nodes_validate_types', $validate_types);

  $resave_nodes_selected_types         = variable_get('resave_nodes_selected_types', array());
  // $resave_nodes_selected_product_types = variable_get('resave_nodes_selected_product_types', array());
  $resave_nodes_all_nodes              = variable_get('resave_nodes_all_nodes');
  $resave_nodes_scheduling             = variable_get('resave_nodes_use_cron');
  $resave_nodes_last_run               = variable_get('resave_nodes_last_run');

  $form['content'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Content Selection'),
    '#collapsible' => FALSE,
    '#collapsed'   => FALSE,
    '#description' => t('Select content/product types you would like
      periodically saved.  If you\'d like to resave nodes now, save the
      configuration first and then click \'Resave Nodes Now.\''),
  );

  if (!empty($content_types)) {
    $form['content']['content_types'] = array(
      '#title'       => t('Content Types'),
      '#type'        => 'checkboxes',
      '#options'     => $content_types,
    );
    if (isset($resave_nodes_selected_types)) {
      $form['content']['content_types']['#default_value'] = $resave_nodes_selected_types;
    }
  }
  // if (!empty($product_types)) {
  //   $form['content']['product_types'] = array(
  //     '#title'       => t('Commerce Product Types'),
  //     '#type'        => 'checkboxes',
  //     '#options'     => $product_types,
  //   );
  //   if (isset($resave_nodes_selected_types)) {
  //     $form['content']['product_types']['#default_value'] = $resave_nodes_selected_product_types;
  //   }
  // }

  $form['content']['resave_all_nodes'] = array(
    '#title'         => t('Resave All Nodes'),
    '#type'          => 'checkboxes',
    '#options'       => array(
    'resave_all_nodes' => t('Resave all nodes of the selected content types
      regardless of creation/change time.'),
    ),
    '#description' => t('By default, Resave Nodes will only resave nodes
      that have been created/changed since the last time it ran.  Selecting
      this option will cause all nodes of the selected content/product types to
      be resaved regardless of their creation/change times.'),
  );
  if (isset($resave_nodes_all_nodes)) {
    $form['content']['resave_all_nodes']['#default_value'] = $resave_nodes_all_nodes;
  }

  $form['scheduling'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Scheduling'),
    '#collapsible' => FALSE,
    '#collapsed'   => FALSE,
  );

  $form['scheduling']['description'] = array(
    '#type' => 'item',
    '#description' => t('Last run completed: @time',
      array(
        '@time' => format_date($resave_nodes_last_run),
      )
    ),
  );

  $form['scheduling']['use_cron'] = array(
    '#title'    => t('Resave nodes using...'),
    '#type'     => 'radios',
    '#required' => TRUE,
    '#options'  => array(
      'run_with_cron'      => t('Drupal Cron'),
      'run_with_scheduler' => t('Unix-style Cron'),
    ),
    '#default_value' => $resave_nodes_scheduling,
  );

  $form['scheduling']['unix_cron'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Unix-style Cron Configuration'),
    '#description' => t('Use standard Unix-style cron to configure when and how
      often nodes are resaved.  These settings take effect only if "Unix-style
      cron" is selected above.  This feature relies on the Job Scheduler module,
      and, in turn, the Job Scheduler module relies on Drupal\'s cron.  This
      means that the minimum time interval available to this module is dictated
      by the time interval configured for this installation\'s cron.  Because
      the smallest potential interval is 1 hour, this module\'s available
      smallest potential interval is also 1 hour.'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
  );

  // Next comes a long section where we pull the defaults for the unix-style
  // crontab settings and then fill in the appropriate fields.
  $resave_nodes_unix_cron_min       = variable_get('resave_nodes_unix_cron_min');
  $resave_nodes_unix_cron_hour      = variable_get('resave_nodes_unix_cron_hour');
  $resave_nodes_unix_cron_day_month = variable_get('resave_nodes_unix_cron_day_month');
  $resave_nodes_unix_cron_month     = variable_get('resave_nodes_unix_cron_month');
  $resave_nodes_unix_cron_day_week  = variable_get('resave_nodes_unix_cron_day_week');

  $form['scheduling']['unix_cron']['min'] = array(
      '#type'          => 'item',
      '#title'         => t('Minutes'),
      '#description'   => t('The minimum possible time interval for either cron
        option is 1 hour (as dictated by Drupal\'s cron\'s minimum time
        interval).  Thus, minute-based resolution is not available.  This field
        has been hardcoded to run as "*".'),
  );

  $form['scheduling']['unix_cron']['hour'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Hour'),
    '#description'   => t('Enter a specific hour between 0 and 23, "*" for every
      hour, or comma separate multiple hours (e.g. "0,6,12,18" for every 6
      hours).'),
    '#size'          => 20,
    '#maxlength'     => 20,
    '#default_value' => $resave_nodes_unix_cron_hour,
  );

  $form['scheduling']['unix_cron']['day_month'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Day of the Month'),
    '#description'   => t('Enter a specific day between 1 and 31, "*" for every
      day of the month, or comma separate multiple days of the month (e.g.
      "1,10,20" for the 1st, 10th, and 20th day of the month).'),
    '#size'          => 20,
    '#maxlength'     => 20,
    '#default_value' => $resave_nodes_unix_cron_day_month,
  );

  $form['scheduling']['unix_cron']['month'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Month'),
    '#description'   => t('Enter a specific month between 1 and 12, "*" for
      every month, or comma separate multiple months (e.g. "1,6,11" for January,
      June, and November).'),
    '#size'          => 20,
    '#maxlength'     => 20,
    '#default_value' => $resave_nodes_unix_cron_month,
  );

  $form['scheduling']['unix_cron']['day_week'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Day of the week'),
    '#description'   => t('Enter a specific day of the week between 0 and 6, "*"
      for every day of the week, or comma/dash separate multiple days (e.g.
      "1-5" for Monday through Friday).'),
    '#size'          => 20,
    '#maxlength'     => 20,
    '#default_value' => $resave_nodes_unix_cron_day_week,
  );

  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => 'Save Configuration',
  );

  $form['run_now'] = array(
    '#type'     => 'submit',
    '#value'    => t('Resave Nodes Now'),
    '#validate' => array('resave_nodes_form_validate'),
    '#submit'   => array('resave_nodes_do_that_thing'),
  );

  return $form;
}


/**
 * Form builder.  Validate values passed in the form.
 */
function resave_nodes_form_validate($form, &$form_state) {
  $resave_nodes_validate_types = variable_get('resave_nodes_validate_types');

  // Validate the content types that are getting passed in.
  foreach ($form_state['values']['content_types'] as $name => $value) {
    if (($name == $value) || ($value == 0)) {
      // Good to go
    } else {
      form_set_error('content_types', 'Illegal content type.');
    }
    $valid_content_type = FALSE;
    foreach ($resave_nodes_validate_types as $valid_name) {
      if ($name == $valid_name) {
        $valid_content_type = TRUE;
        break;
      }
    }
    if ($valid_content_type) {
      break;
    } else {
      form_set_error('content_types', 'Illegal content type.');
    }
  }

  // // Validate the product types that are getting passed in.
  // foreach ($form_state['values']['product_types'] as $name => $value) {
  //   if (($name == $value) || ($value == 0)) {
  //     // Good to go
  //   } else {
  //     form_set_error('product_types', 'Illegal product type.');
  //   }
  //   $valid_product_type = FALSE;
  //   foreach ($resave_nodes_validate_types as $valid_name) {
  //     if ($name == $valid_name) {
  //       $valid_product_type = TRUE;
  //       break;
  //     }
  //   }
  //   if ($valid_product_type) {
  //     break;
  //   } else {
  //     form_set_error('product_types', 'Illegal product type.');
  //   }
  // }

  // Verify if the 'resave_all_nodes' field has proper data.
  if (($form_state['values']['resave_all_nodes']['resave_all_nodes'] == 'resave_all_nodes') || ($form_state['values']['resave_all_nodes']['resave_all_nodes'] == 0)) {
    // Everything's cool.
  } else {
    form_set_error('resave_all_nodes', 'Invalid input for \'Resave All Nodes\' field.');
  }

  // Verify if the 'use_cron' field has proper data.
  if (($form_state['values']['use_cron'] == 'run_with_cron') || ($form_state['values']['use_cron'] == 'run_with_scheduler')) {
    // Everything's cool.
  } else {
    form_set_error('use_cron', 'Invalid input for \'Resave nodes using...\' field.');
  }

  // Verify if the Unix time fields have proper data.
  foreach (array('hour', 'day_month', 'month', 'day_week') as $key => $time_field) {
    $elements = explode(",", $form_state['values'][$time_field]);
    foreach ($elements as $sub_key => $time_field_value) {
      if ($time_field_value == '*') {
        // Everything's cool.
      } elseif (intval($time_field_value) >= 0) {
        // Everything's cool.
      }
    }
  }
}


/**
 * Form builder.  Save the selected content types.
 */
function resave_nodes_form_submit($form, &$form_state) {
  variable_set('resave_nodes_selected_types', $form_state['values']['content_types']);
  // variable_set('resave_nodes_selected_product_types', $form_state['values']['product_types']);
  variable_set('resave_nodes_all_nodes', $form_state['values']['resave_all_nodes']);
  variable_set('resave_nodes_use_cron', $form_state['values']['use_cron']);

  variable_set('resave_nodes_unix_cron_min', '*');
  variable_set('resave_nodes_unix_cron_hour', $form_state['values']['hour']);
  variable_set('resave_nodes_unix_cron_day_month', $form_state['values']['day_month']);
  variable_set('resave_nodes_unix_cron_month', $form_state['values']['month']);
  variable_set('resave_nodes_unix_cron_day_week', $form_state['values']['day_week']);

  // Create the job data structure to either schedule or delete the job.
  $hard_coded_minutes = variable_get('resave_nodes_unix_cron_min');
  $crontab            = $hard_coded_minutes . ' ' . $form_state['values']['hour'] . ' ' .
    $form_state['values']['day_month'] . ' ' . $form_state['values']['month'] . ' ' .
    $form_state['values']['day_week'];

  $job = array(
    'type'     => 'resave_nodes',
    'id'       => variable_get('resave_nodes_unix_cron_job_id'),
    'periodic' => TRUE,
    'crontab'  => $crontab,
  );

  // This is where we schedule a new job.
  if ($form_state['values']['use_cron'] == 'run_with_scheduler') {
    JobScheduler::get('resave_nodes_do_that_thing')->set($job);

  // This is where we remove from an old job from the scheduler.
  } elseif ($form_state['values']['use_cron'] == 'run_with_cron') {
    JobScheduler::get('resave_nodes_do_that_thing')->remove($job);
  }

  drupal_set_message(t('The configuration has been saved.'));

  $config['content_types']          = $form_state['values']['content_types'];
  $config['resave_all_nodes']       = $form_state['values']['resave_all_nodes'];
  $config['resave_nodes_last_run']  = variable_get('resave_nodes_last_run');
  $config['use_cron']               = $form_state['values']['use_cron'];

  if ($form_state['values']['use_cron'] == 'run_with_scheduler') {
    $config['job_scheduler_settings'] = $job;
    $config['unix_cron_settings']     = array(
      'min'       => $hard_coded_minutes,
      'hour'      => $form_state['values']['hour'],
      'day_month' => $form_state['values']['day_month'],
      'month'     => $form_state['values']['month'],
      'day_week'  => $form_state['values']['day_week'],
    );
  }

  watchdog(
    'resave_nodes',
    'Configuration has been updated: <pre>@config</pre>',
    array(
      '@config'  => print_r($config, TRUE),
    ),
    WATCHDOG_INFO
  );
}
