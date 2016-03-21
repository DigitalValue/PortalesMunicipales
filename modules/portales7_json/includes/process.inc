<?php
define('P7JSON_IMAGE_SMALL', 'image-100');
define('P7JSON_IMAGE_MEDIUM', 'image-300');
define('P7JSON_IMAGE_BIG', 'image-900');
define('P7JSON_DATE_FORMAT', 'd/m/Y H:i');

function _portales7_json_get_portales7_node($node) {
  $res = new stdClass();
  $res->url = url('node/' . $node->nid, array('absolute' => TRUE));
  $res->nid = $node->nid;
  $res->type = $node->type;
  $res->uuid = $node->uuid;
  $res->title = check_plain($node->title);
  $res->updated = date(P7JSON_DATE_FORMAT, $node->changed);
  $res->created = date(P7JSON_DATE_FORMAT, $node->created);
  $res->teaser = !empty($node->portales7_teaser['und'][0]['value'])? strip_tags($node->portales7_teaser['und'][0]['value']) : '';
  $res->body = !empty($node->body['und'][0]['value'])? strip_tags($node->body['und']['0']['value']) : '';
  module_load_include('inc', 'portales7_json', 'includes/fc');
  foreach (_portales7_json_get_fields_by_type('node', 'portales7_node', 'field_collection', !empty($_GET['reset'])) as $field_name => $field) {
    $func = '_portales7_json_process_' . $field_name;
    if (function_exists($func) && !empty($node->{$field_name}['und'])) {
      $res->{$field_name} = call_user_func_array($func, array($node->{$field_name}['und']));
    }
  }
  $res->subtype = !empty($node->portales7_type['und']) ? array_map('_portales7_json_process_taxonomy', $node->portales7_type['und']) : array();
  $res->event_type = !empty($node->portales7_event_type['und']) ? array_map('_portales7_json_process_taxonomy', $node->portales7_event_type['und']) : array();
  $res->links = !empty($node->portales7_weblink['und']) ? array_map('_portales7_json_process_link', $node->portales7_weblink['und']) : array();
  $res->event_date = !empty($node->portales7_eventdate['und']) ? array_map('_portales7_json_process_eventdate', $node->portales7_eventdate['und']) : array();
  $res->news_date = !empty($node->portales7_newsdate['und'][0]) ? _portales7_json_process_newsdate($node->portales7_newsdate['und'][0]) : array();
  $res->notice_date = _portales7_json_process_noticedate($node->portales7_noticedate['und'], $node->created);
  return $res;
}

function _portales7_json_get_portales7_entity($node) {
  $res = new stdClass();
  $res->url = url('node/' . $node->nid, array('absolute' => TRUE));
  $res->nid = $node->nid;
  $res->type = 'entidad';
  $res->uuid = $node->uuid;
  $res->title = check_plain($node->title);
  $res->updated = date(P7JSON_DATE_FORMAT, $node->changed);
  $res->created = date(P7JSON_DATE_FORMAT, $node->created);
  $res->teaser = !empty($node->portales7_entity_teaser['und'][0]['value'])? strip_tags($node->portales7_entity_teaser['und'][0]['value']) : '';
  $res->body = !empty($node->body['und'][0]['value'])? strip_tags($node->body['und']['0']['value']) : '';
  $res->subtype = !empty($node->portales7_entity_type['und']) ? array_map('_portales7_json_process_taxonomy', $node->portales7_entity_type['und']) : array();
  $res->category = !empty($node->portales7_entity_families['und']) ? array_map('_portales7_json_process_taxonomy', $node->portales7_entity_families['und']) : array();
  $res->address = !empty($node->portales7_entity_postaladdress['und']) ? $node->portales7_entity_postaladdress['und'] : array();
  $res->twitter =  !empty($node->portales7_entity_twitter['und'][0]['value']) ? $node->portales7_entity_twitter['und'][0]['value'] : '';
  $res->facebook =  !empty($node->portales7_entity_facebook['und'][0]['value']) ? $node->portales7_entity_facebook['und'][0]['value'] : '';
  $res->otro =  !empty($node->portales7_entity_other['und'][0]['value']) ? $node->portales7_entity_other['und'][0]['value'] : '';
  $res->contact = !empty($node->portales7_entity_contact['und']) ? array_map('_portales7_json_get_value', $node->portales7_entity_contact['und']) : array();
  $res->email = !empty($node->portales7_entity_email['und']) ? array_map('_portales7_json_get_value', $node->portales7_entity_email['und']) : array();
  $res->web = !empty($node->portales7_entity_web['und']) ? array_map('_portales7_json_get_value', $node->portales7_entity_web['und']) : array();
  $res->event_date = !empty($node->portales7_eventdate['und']) ? _portales7_json_process_eventdate($node->portales7_eventdate['und']) : array();

  module_load_include('inc', 'portales7_json', 'includes/fc');
  foreach (_portales7_json_get_fields_by_type('node', 'portales7_entity', 'field_collection', !empty($_GET['reset'])) as $field_name => $field) {
    $func = '_portales7_json_process_' . $field_name;
    if (function_exists($func)) {
      $res->{$field_name} = call_user_func_array($func, array($node->{$field_name}['und']));
    }
    else {
      $res->{$field_name} = "no existe $func";
    }
  }


  return $res;
}

function _portales7_json_process_link($item) {
  $out = new stdClass();
  $out->title = $item['title'];
  $out->url = $item['url'];
  $out->target = !empty($item['attributes']['target']) ? '_blank' : '_self';
  return $out;
}

function _portales7_json_process_related_entity($item) {
  //$res = entity_load('portales7_related_entity', array($item['value']));
  $res = field_collection_item_load($item['value']);
  $out = new stdClass();
  $out->name = $res->portales7_re_relationship['und'][0]['value'];
  $out->related = !empty($res->portales7_re_entities['und']) ? array_map('_portales7_json_process_related', $res->portales7_re_entities['und']) : array();
  return $out;

}

function _portales7_json_process_related($item) {
  return $item['nid'];
}

function _portales7_json_process_file($file) {
  if (!$file['status']) return NULL;
  $out = new stdClass();
  $out->filemime = $file['filemime'];
  $out->filesize = $file['filesize'];
  $out->url = file_uri_target($file['uri']);
  $out->description = $file['description'];
  $out->abs_url = file_create_url($file['uri']);
  return $out;
}

function _portales7_json_process_image($image) {
  if (!$image['status']) return NULL;
  $out = new stdClass();
  $out->filemime = $image['filemime'];
  $out->filesize = $image['filesize'];
  $out->title = $image['title'];
  $out->alt = $image['alt'];
  $out->url = file_uri_target($image['uri']);
  $out->abs_url = file_create_url($image['uri']);
  return $out;
}

function _portales7_json_get_value($item) {
  return check_plain($item['value']);
}

function _portales7_json_process_taxonomy($term) {
  $t = i18n_taxonomy_localize_terms(taxonomy_term_load($term['tid']));
  return $t->name;
}

function _portales7_json_process_eventdate($item) {
  $res['start'] = date(P7JSON_DATE_FORMAT, $item['value']);
  $res['end'] = !empty($item['value2']) ? date(P7JSON_DATE_FORMAT, $item['value2']) : NULL;
  return $res;
}

function _portales7_json_process_newsdate($item) {
  return date(P7JSON_DATE_FORMAT, $item['value']);
}

function _portales7_json_process_noticedate($items, $start = NULL) {
  if (empty($start)) $start = time();
  $result = array();
  $today = strtotime('0:00 today');
  if (empty($items)) {
    $res = array(
      'start' => date(P7JSON_DATE_FORMAT, $start),
      'end' => date(P7JSON_DATE_FORMAT, strtotime('+15 days', $start)),
    );
    $result[] = $res;
  }
  else {
    foreach ($items as $item) {
      if (!empty($item['value2']) && ($item['value2'] >= $today)) {
        $res = array(
          'start' => date(P7JSON_DATE_FORMAT, $item['value']),
          'end' => date(P7JSON_DATE_FORMAT, $item['value2']),
        );
        $result[] = $res;
      }
    }
  }
  return $result;
}
