<?php
function portales7_json_processed($type, $ids) {
  $max_depth = empty($_GET['max_depth']) && is_numeric($_GET['max_depth'])? 1 : $_GET['max_depth'];
  $cid = $type. ':' . $ids . ':' . $max_depth . ':processed';
  $data = '';
  if (!empty($_GET['reset']) || !$cached = cache_get($cid, 'cache_page')) { 
    $entity_ids = array();
    foreach(explode(',', $ids) as $v) {
      if (is_numeric($v)) $entity_ids[] = $v;
    }
    $entities = array();
    portales7_json_entity_load_recursive_processed($type, $entity_ids, $entities, $max_depth);
    $data = json_encode($entities, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT);
    cache_set($cid, $data, 'cache_page', CACHE_PERMANENT);
    drupal_add_http_header('X-Cached', 'FALSE');
  }
  else {
    drupal_add_http_header('X-Cached', 'TRUE');
    $data =  $cached->data;
  }
  drupal_add_http_header('Content-Type', 'application/json');
  drupal_add_http_header('X-Portales-API','version=' . PORTALES7_API_VERSION);
  echo $data;
}

function portales7_json_entity_load_recursive_processed($type, $entity_ids, &$entities, $depth = 1) {
  $new_entities = entity_load($type, $entity_ids);
  $add = array();
  foreach ($new_entities as $k => $entity) {
    foreach(array('portales7_related', 'portales7_related_entity') as $field) {
      foreach($entity->{$field}['und'] as $item) {
        if (!empty($item['nid']) && !array_key_exists($item['nid'], $entities)) {
          $add[$item['nid']] = $item['nid'];
        }
      } 
    }
    $entities[$k] = _portales7_json_get_node($entity);
  }
  if ($depth > 0 && count($add) > 0) portales7_json_entity_load_recursive_processed($type, $add, $entities, $depth - 1);
}
