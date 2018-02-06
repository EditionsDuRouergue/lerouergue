<?php

function resave_nodes_drush_command() {
  $items  = array();
  $items['resave-nodes'] = array(
    'callback'    => 'resave_nodes_setup_batch',
    'description' => dt('Resave Nodes'),
    'arguments'   => array(
      'start'     => "Optional: Starting node ID (default: 1)",
      'limit'     => "Optional: Limit the number of nodes to process (default: 1 000 000)",
      'bundle'    => "Optional: Limit the action to a specific node type (entity bndle)",
    ),
  );

  return $items;
}
 
function resave_nodes_drush_help($section) {
  switch ($section) {
    case 'drush:resave-nodes':
    return dt("Re-saves the nodes in the database");
  }
}
