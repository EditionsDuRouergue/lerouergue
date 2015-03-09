<?php
/**
 * @file
 * feature_books.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function feature_books_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 1,
  'title' => 'Présentation de la maison',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '2ca7e71e-58d6-4399-9cd0-99d2d76e1707',
  'type' => 'book',
  'language' => 'fr',
  'created' => 1415118263,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '452785c2-7d43-40e3-a2c5-7cd3bd120589',
  'revision_uid' => 1,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Préface</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>Préface</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'book' => array(
    'mlid' => 760,
    'nid' => 2949,
    'bid' => 2949,
    'menu_name' => 'book-toc-2949',
    'plid' => 0,
    'link_path' => 'node/2949',
    'router_path' => 'node/%',
    'link_title' => 'Présentation de la maison',
    'options' => array(),
    'module' => 'book',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'depth' => 1,
    'customized' => 0,
    'p1' => 760,
    'p2' => 0,
    'p3' => 0,
    'p4' => 0,
    'p5' => 0,
    'p6' => 0,
    'p7' => 0,
    'p8' => 0,
    'p9' => 0,
    'updated' => 0,
    'uuid' => NULL,
    'href' => 'node/2949',
    'title' => 'Présentation de la maison',
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'superadmin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2014-11-04 17:24:23 +0100',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Espace Pro',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '80a166e4-ffd8-498b-b756-59e3db9560ab',
  'type' => 'book',
  'language' => 'fr',
  'created' => 1415119148,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'd7536d51-dacf-496d-ac6d-02d3c7ca69f9',
  'revision_uid' => 1,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Préface</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>Préface</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'book' => array(
    'mlid' => 765,
    'nid' => 2953,
    'bid' => 2953,
    'menu_name' => 'book-toc-2953',
    'plid' => 0,
    'link_path' => 'node/2953',
    'router_path' => 'node/%',
    'link_title' => 'Espace Pro',
    'options' => array(),
    'module' => 'book',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'depth' => 1,
    'customized' => 0,
    'p1' => 765,
    'p2' => 0,
    'p3' => 0,
    'p4' => 0,
    'p5' => 0,
    'p6' => 0,
    'p7' => 0,
    'p8' => 0,
    'p9' => 0,
    'updated' => 0,
    'uuid' => NULL,
    'href' => 'node/2953',
    'title' => 'Espace Pro',
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 1,
  'comment_count' => 0,
  'name' => 'superadmin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2014-11-04 17:39:08 +0100',
);
  return $nodes;
}
