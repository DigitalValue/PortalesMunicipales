<?php
function _portales7_json_raw_process_portales7_related_entity(&$entity, &$add) {
  if (empty($entity->portales7_related_entity['und'])) return;
  $fcis = dvtoolbox_load_fc_entities($entity->portales7_related_entity['und']);
  foreach ($fcis as $re) {
    foreach ($re->portales7_re_entities['und'] as &$item) {
      $add[$item['target_id']] = $item['target_id'];
    }
  }
  $entity->portales7_related_entity['und'] = array_values($fcis);
}

function _portales7_json_raw_process_portales7_related_article(&$entity, &$add) {
  if (empty($entity->portales7_related_article['und'])) return;
  $fcis = dvtoolbox_load_fc_entities($entity->portales7_related_article['und']);
  foreach ($fcis as $re) {
    foreach ($re->portales7_r_node['und'] as &$item) {
      $add[$item['target_id']] = $item['target_id'];
      //$item['nid'] = $item['target_id'];
    }
  }
  $entity->portales7_related_article['und'] = array_values($fcis);
}

function _portales7_json_raw_process_portales7_media(&$entity, &$add) {
  if (empty($entity->portales7_media['und'])) return;
  $fcis = dvtoolbox_load_fc_entities($entity->portales7_media['und']);
  foreach ($fcis as $re) {
    foreach ($re->portales7_video_url['und'] as &$item) {
      $item['video_data'] = unserialize($item['video_data']);
    }
  }
  $entity->portales7_media['und'] = array_values($fcis);
}

function _portales7_json_raw_process_portales7_main_media(&$entity, &$add) {
  if (empty($entity->portales7_main_media['und'])) return;
  $fcis = dvtoolbox_load_fc_entities($entity->portales7_main_media['und']);
  foreach ($fcis as &$re) {
    foreach ($re->portales7_video_url['und'] as &$item) {
      $item['video_data'] = unserialize($item['video_data']);
    }
  }
  $entity->portales7_main_media['und'] = array_values($fcis);
}

function _portales7_json_raw_process_portales7_entity_opening_hours(&$entity, &$add) {
  if (empty($entity->portales7_entity_opening_hours['und'])) return;
  $fcis = dvtoolbox_load_fc_entities($entity->portales7_entity_opening_hours['und']);
  $entity->portales7_entity_opening_hours['und'] = array_values($fcis);
}

function _portales7_json_raw_process_portales7_entity_people(&$entity, &$add) {
  if (empty($entity->portales7_entity_people['und'])) return;
  $fcis = dvtoolbox_load_fc_entities($entity->portales7_entity_people['und']);
  $entity->portales7_entity_people['und'] = array_values($fcis);
}

function _portales7_json_process_portales7_entity_people($items = array()) {
  if (empty($items)) return NULL;
  $res = array();
  $fcis = dvtoolbox_load_fc_entities($items);
  foreach ($fcis as $fci) {
    $row = array('name' => '', 'function' => '', 'free_text' => '', 'email' => array(), 'telephone' => '', 'image' => '');
    if (!empty($fci->portales7_entity_p_name['und'][0])) {
      $row['name'] = $fci->portales7_entity_p_name['und'][0]['value'];
    }
    if (!empty($fci->portales7_entity_p_function['und'][0])) {
      $row['function'] = $fci->portales7_entity_p_function['und'][0]['value'];
    }
    if (!empty($fci->portales7_entity_p_free_text['und'][0])) {
      $row['free_text'] = $fci->portales7_entity_p_free_text['und'][0]['value'];
    }
    if (!empty($fci->portales7_entity_p_telephone['und'][0])) {
      $row['telephone'] = $fci->portales7_entity_p_telephone['und'][0]['value'];
    }
    if (!empty($fci->portales7_entity_p_image['und'][0])) {
      $row['image'] = _portales7_json_process_image($fci->portales7_entity_p_image['und'][0]);
    }
    if (!empty($fci->portales7_entity_p_email['und'])) {
      foreach ($fci->portales7_entity_p_email['und'] as $email) {;
        $row['email'][] = $email['value'];
      }
    }

    $res[] = $row;
  }
  return $res;
}

function _portales7_json_process_portales7_entity_opening_hours($items = array()) {
  if (empty($items)) return NULL;
  $res = array();
  $fcis = dvtoolbox_load_fc_entities($items);
  foreach ($fcis as $fci) {
    $row = array('condition' => '', 'detail' => '');
    if (!empty($fci->portales7_entity_oh_condition['und'][0])) {
      $row['condition'] = $fci->portales7_entity_oh_condition['und'][0]['value'];
    }
    if (!empty($fci->portales7_entity_oh_detail['und'][0])) {
      $row['detail'] = $fci->portales7_entity_oh_detail['und'][0]['value'];
    }
    $res[] = $row;
  }
  return $res;
}

function _portales7_json_process_portales7_media($items = array()) {
  if (empty($items)) return NULL;
  $res = array();
  $fcis = dvtoolbox_load_fc_entities($items);
  foreach ($fcis as $id => $fci) {
    $row = array('name' => '', 'images' => array(), 'files' => array(), 'videos' => array(), 'video_url' => array());
    if (!empty($fci->portales7_fc_name['und'][0])) {
        $row['name'] = $fci->portales7_fc_name['und'][0]['value'];
    }
    if (!empty($fci->portales7_images['und'])) {
      foreach ($fci->portales7_images['und'] as $image) {
        $row['images'][] = _portales7_json_process_image($image);
      }
    }
    if (!empty($fci->portales7_files['und'])) {
      foreach ($fci->portales7_files['und'] as $file) {
        $row['files'][] = _portales7_json_process_file($file);
      }
    }
    if (!empty($fci->portales7_videos['und'])) {
      foreach ($fci->portales7_videos['und'] as $video) {
        $row['videos'][] = $video;
      }
    }
    if (!empty($fci->portales7_video_url['und'])) {
      foreach ($fci->portales7_video_url['und'] as $video) {
        $video['video_data'] = unserialize($video['video_data']);
        $row['video_url'][] = $video;
      }
    }
    $res[] = $row;
  }
  return $res;
}

function _portales7_json_process_portales7_main_media($items = array()) {
  if (empty($items)) return NULL;
  $res = array();
  $fcis = dvtoolbox_load_fc_entities($items);
  foreach ($fcis as $id => $fci) {
    if (!empty($_SESSION['DEBUG'])) dpm($fci, __FUNCTION__ . " $id");
    $row = array('name' => '', 'images' => array(), 'files' => array(), 'videos' => array(), 'video_url' => array());
    if (!empty($fci->portales7_mm_image['und'])) {
      foreach ($fci->portales7_mm_image['und'] as $image) {
        $row['images'][] = _portales7_json_process_image($image);
      }
    }
    if (!empty($fci->portales7_mm_video['und'])) {
      foreach ($fci->portales7_mm_video['und'] as $video) {
        $row['videos'][] = $video;
      }
    }
    if (!empty($fci->portales7_mm_video_url['und'])) {
      foreach ($fci->portales7_mm_video_url['und'] as $video) {
        $video['video_data'] = unserialize($video['video_data']);
        $row['video_url'][] = $video;
      }
    }
    $res[] = $row;
  }
  return $res;
}

function _portales7_json_raw_process_field_linea_agendadival(&$entity, &$add) {
  module_load_include('inc', 'portales7_json', 'includes/process');

  if (empty($entity->field_linea_agendadival['und'])) return;
  $fcis = dvtoolbox_load_fc_entities($entity->field_linea_agendadival['und']);

  foreach ($fcis as $fci) {
    $row = array('field_fecha' => array(), 'field_delegacion' => '', 'field_descripcion' => array(), 'field_lugar' => '', 'field_diputado_a' => '');
    if (!empty($fci->field_fecha['und'][0])) {
      $row['field_fecha'] = strtotime($fci->field_fecha['und'][0]['value']);
    }
    if (!empty($fci->field_delegacion['und'][0])) {
      $row['field_delegacion'] = _portales7_json_process_taxonomy($fci->field_delegacion['und'][0]);

    }
    if (!empty($fci->field_descripcion['und'][0])) {
      $row['field_descripcion'] = $fci->field_descripcion['und'][0]['value'];
    }
    if (!empty($fci->field_lugar['und'][0])) {
      $row['field_lugar'] = $fci->field_lugar['und'][0]['value'];
    }
    if (!empty($fci->field_diputado_a['und'][0])) {
      $row['field_diputado_a'] = _portales7_json_process_taxonomy($fci->field_diputado_a['und'][0]);
    }
    $res[] = $row;
  }
  $entity->field_linea_agendadival['und'] = $res;
  return $res;
}

function _portales7_json_process_portales7_related_entity($items = array()) {
  if (empty($items)) return NULL;
  $res = array();
  $fcis = dvtoolbox_load_fc_entities($items);
  foreach ($fcis as $fci) {
    $row = array('name' => '', 'entities' => array(), 'formatter' => '');
    if (!empty($fci->portales7_fc_name['und'][0])) {
      $row['name'] = $fci->portales7_fc_name['und'][0]['value'];
    }
    if (!empty($fci->portales7_fc_formatter['und'][0])) {
      $row['formatter'] = $fci->portales7_fc_formatter['und'][0]['value'];
    }
    if (!empty($fci->portales7_re_entities['und'])) {
      foreach ($fci->portales7_re_entities['und'] as $item) {
        $row['entities'][] = array('nid' => $item['target_id']);
      }
    }
    $res[] = $row;
  }
  return $res;
}

function _portales7_json_process_portales7_related_article($items = array()) {
  if (empty($items)) return NULL;
  $res = array();
  $fcis = dvtoolbox_load_fc_entities($items);
  foreach ($fcis as $fci) {
    $row = array('name' => '', 'entities' => array(), 'formatter' => '');
    if (!empty($fci->portales7_fc_name['und'][0])) {
      $row['name'] = $fci->portales7_fc_name['und'][0]['value'];
    }
    if (!empty($fci->portales7_fc_formatter['und'][0])) {
      $row['formatter'] = $fci->portales7_fc_formatter['und'][0]['value'];
    }
    if (!empty($fci->portales7_r_node['und'])) {
      foreach ($fci->portales7_r_node['und'] as $item) {
        $row['articles'] = array('nid' => $item['target_id']);
      }
    }
    $res[] = $row;
  }
  return $res;
}
