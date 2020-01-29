<?php
/**
 * @file
 * General functions include for the Resave Nodes module.
 *
 * This file has the breakout of the main function that does the node
 * resaving.  This was moved out of the resave_nodes.module file for better
 * organization.
 */


function resave_nodes_do_that_thing($form, &$form_state) {
  $resave_nodes_last_run               = variable_get('resave_nodes_last_run');
  $resave_nodes_selected_content_types = variable_get('resave_nodes_selected_types', array());
  // $resave_nodes_selected_product_types = variable_get('resave_nodes_selected_product_types', array());
  $resave_nodes_all_nodes              = variable_get('resave_nodes_all_nodes');

  $batch = FALSE;
  if ((isset($form_state['clicked_button']['#value'])) && ($form_state['clicked_button']['#value'] == 'Resave Nodes Now')) {
    $batch = TRUE;
  }

  // $merged_types = array_merge($resave_nodes_selected_content_types, $resave_nodes_selected_product_types);

  $start_time = time();
  $operations = array();

  $total_num_nodes_saved = 0;
  // if (!empty($merged_types)) {
  //   foreach ($merged_types as $type => $value) {
  if (!empty($resave_nodes_selected_content_types)) {
    foreach ($resave_nodes_selected_content_types as $type => $value) {
      if ($type === $value) {
        // Check the node table first.
        // Default action: resave only recently created/changed.
        if ($resave_nodes_all_nodes['resave_all_nodes'] == '0') {
          $query = db_query('SELECT nid FROM {node} WHERE changed >= :last_cron_run AND type = :content_type',
            array(
              ":last_cron_run" => $resave_nodes_last_run,
              ":content_type"  => $value,
            )
          );
        // Resave everything for specified content type.
        } else {
          $query = db_query('SELECT nid FROM {node} WHERE type = :content_type',
            array(
              ":content_type"  => $value,
            )
          );
        }
        $num_nodes_saved = 0;
        foreach ($query as $result) {
          if ($batch) {
            $operations[] = array(
              'resave_nodes_save_it',
              array($result->nid, 'node', TRUE),
            );
          } else {
            $num_nodes_saved       += resave_nodes_save_it($result->nid, 'node', $batch);
            $total_num_nodes_saved += $num_nodes_saved;
          }
        }

        // // Repeat the process for the commerce_product table (if installed).
        // if ((module_exists('commerce_product')) && ($num_nodes_saved == 0)) {
        //   if ($resave_nodes_all_nodes['resave_all_nodes'] == '0') {
        //     $query = db_query('SELECT product_id FROM {commerce_product} WHERE changed >= :last_cron_run AND type = :content_type',
        //       array(
        //         ":last_cron_run" => $resave_nodes_last_run,
        //         ":content_type"  => $value,
        //       )
        //     );
        //   // Resave everything for specified product type.
        //   } else {
        //     $query = db_query('SELECT product_id FROM {commerce_product} WHERE type = :content_type',
        //       array(
        //         ":content_type"  => $value,
        //       )
        //     );
        //   }
        //   $num_nodes_saved = 0;
        //   foreach ($query as $result) {
        //     if ($batch) {
        //       $operations[] = array(
        //         'resave_nodes_save_it',
        //         array($result->product_id, 'commerce_product', TRUE),
        //       );
        //     } else {
        //       $num_nodes_saved       += resave_nodes_save_it($result->product_id, 'commerce_product', $batch);
        //       $total_num_nodes_saved += $num_nodes_saved;
        //     }
        //   }
        // }
      }
    }
  }

  if ($batch) {
    $batch_job = array(
      'operations'    => $operations,
      'finished'      => 'resave_nodes_batch_finished',
      'title'         => t('Resaving content.'),
      'error_message' => t('Something broke!'),
    );
    if (empty($batch_job)) {
      drupal_set_message(t('There is no content to resave.'), 'status');
    }
    else {
      batch_set($batch_job);
    }
    return $batch_job;

  } else {
    $time_delta = time() - $start_time;
    watchdog(
      'resave_nodes',
      'Finished updating @num new/changed nodes. Runtime was @time seconds',
      array(
        '@num'  => print_r($total_num_nodes_saved, TRUE),
        '@time' => print_r($time_delta, TRUE),
      ),
      WATCHDOG_INFO
    );
    variable_set('resave_nodes_last_run', $start_time + $time_delta);

    return array(
      'number_updated' => $total_num_nodes_saved,
      'run_time'       => $time_delta,
    );
  }
}

function resave_nodes_save_it($id, $bundle_type, $batch = FALSE, &$context = array()) {
  $num_saved = 0;
  $title     = '';
  $type      = '';

  if ((!empty($id)) && (!empty($bundle_type))) {
    try {
      if ($bundle_type == 'node') {
        $node  = node_load($id);
        $title = $node->title;
        $type  = $node->type;
        node_save($node);
      // } elseif ($bundle_type == 'commerce_product') {
      //   $product = commerce_product_load($id);
      //   $title = $product->title;
      //   $type  = $product->type;
      //   commerce_product_save($product);
      }
      $num_saved++;

      if ($batch) {
        $context['results'][] = t('Resaved node "@res" of @content type "@ctype".', array(
          '@res'     => $title,
          '@content' => $bundle_type,
          '@ctype'   => $type,
        ));
      } else {
        watchdog(
          'resave_nodes',
          'Resaved node "@res" of @content type "@ctype"',
          array(
            '@res'     => print_r($title, TRUE),
            '@content' => print_r($bundle_type, TRUE),
            '@ctype'   => print_r($type, TRUE),
          ),
          WATCHDOG_INFO
        );
      }
    } catch (Exception $e) {
      watchdog_exception($bundle_type, $e);
      throw $e;
    }
  }

  return $num_saved;
}

function resave_nodes_batch_finished($success, $results, $operations) {
  if ($success) {
    $nodes    = 0;
    $products = 0;
    foreach ($results as $res) {
      if (strpos($res, 'of node type') !== false) {
        $nodes++;
      } else {
        $products++;
      }
    }
    // drupal_set_message(t('Resaved @nodes nodes and @products products for @total total resaved content.',
    drupal_set_message(t('Resaved @nodes nodes.',
      array(
        '@nodes'    => $nodes,
        // '@products' => $products,
        // '@total'    => count($results),
      )
    ));
    watchdog(
      'resave_nodes',
      // 'Resaved @nodes nodes and @products products for @total total resaved content: <pre>@results</pre>',
      'Resaved @nodes nodes : <pre>@results</pre>',
      array(
        '@nodes'    => $nodes,
        // '@products' => $products,
        // '@total'    => count($results),
        '@results'  => print_r($results, TRUE),
      ),
      WATCHDOG_INFO
    );

  } else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(
      t('An error occurred while while resaving @operation with arguments : @args',
        array(
          '@operation' => $error_operation[0],
          '@args'      => print_r($error_operation[0], TRUE),
        )
      )
    );
  }
}
