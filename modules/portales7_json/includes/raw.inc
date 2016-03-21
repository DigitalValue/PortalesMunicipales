<?php
function portales7_json_raw($type, $ids) {
  $max_depth = isset($_GET['max_depth']) && is_numeric($_GET['max_depth'])? $_GET['max_depth'] : 1;
  $cid = 'pm_json:' .  $type. ':' . $ids . ':' . $max_depth;
  $data = '';
  if (!empty($_GET['reset']) || !$cached = cache_get($cid, 'cache_page')) { 
    $entity_ids = array();
    foreach(explode(',', $ids) as $v) {
      if (is_numeric($v)) $entity_ids[] = $v;
    }
    $entities = array();
    portales7_json_entity_load_recursive($type, $entity_ids, $entities, $max_depth);
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

function portales7_json_entity_load_recursive($type, $entity_ids, &$entities, $depth = 1) {
  portales7_json_entity_recurse($type, entity_load($type, $entity_ids), $entities, $depth);
}

function portales7_json_entity_recurse($type, $new_entities, &$entities, $depth = 1) {
  $add = array();
  foreach ($new_entities as $k => $entity) {
    foreach(array('portales7_related') as $field) {
      foreach($entity->{$field}['und'] as $item) {
        if (!empty($item['nid']) && !array_key_exists($item['nid'], $entities)) {
          $add[$item['nid']] = $item['nid'];
        }
      }
    }

    module_load_include('inc', 'portales7_json', 'includes/fc');
    foreach (_portales7_json_get_fields_by_type($type, $entity->type, 'field_collection', !empty($_GET['reset'])) as $field_name => $field) {
      $func = '_portales7_json_raw_process_' . $field_name;
      if (function_exists($func)) {
        call_user_func_array($func, array(&$entity, &$add));
      }
    }

    foreach (_portales7_json_get_fields_by_type($type, $entity->type, 'taxonomy_term_reference', !empty($_GET['reset'])) as $field_name => $field) {
      $processed = array();
      foreach($entity->{$field_name}['und'] as $delta => $v) {
        if (is_array($v)) {
          $processed[] = taxonomy_term_load($v['tid']);
        }
        else {
          $processed[] = taxonomy_term_load($v->tid);
          error_log("$field_name en {$entity->nid} contiene objetos");
        }
      }
      $entity->{$field_name}['und'] = $processed;
    }
    $entities[$k] = $entity;
  }
  if ($depth > 0 && count($add) > 0) portales7_json_entity_recurse($type, entity_load($type, $add), $entities, $depth - 1);
}

function _portales7_json_raw_prefetch() {
  
}
