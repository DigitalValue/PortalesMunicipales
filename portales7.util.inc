<?php
function portales7_get_taxonomy_term_by_name($name, $vocabulary, $create = TRUE, $ptid = 0) {
  if (empty($name)) return FALSE;
  $v = taxonomy_vocabulary_machine_name_load($vocabulary);
  if (!$v->vid) return FALSE;
  $query = new EntityFieldQuery;
  $result = $query
  ->entityCondition('entity_type', 'taxonomy_term')
  ->propertyCondition('name', $name)
  ->propertyCondition('vid', $v->vid)
  ->execute();
  
  
  
  if ($result) {
    $term = array_shift($result['taxonomy_term']);
    $term = taxonomy_term_load($term->tid);
  }
  elseif ($create) {
    $term = new stdClass();
    $term->name = $name;
    $term->vid = $v->vid;
    $term->parent = $ptid;
    $term->description = '';
    taxonomy_term_save($term);
  } 
  else 
    return FALSE;
  
  return $term;
}

function portales7_taxonomy_term_select($vocname) {
  $options = array( '0' => '--' . t('None') . '--');
  $options_source = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load($vocname)->vid);

  foreach($options_source as $item ) {
    $key = $item->tid;
    $value = $item->name;
    $options[$key] = $value;
  }

  return $options;
}


function _portales7_listado_content_types($strict = FALSE) {
  $voc = taxonomy_vocabulary_machine_name_load('type');
  $terms = taxonomy_get_tree($voc->vid);
  $options = array();
  if (!$strict) {
    $options['-2'] = t('From panel arguments');
    $options['-1'] = t('Any');
  }
  foreach ($terms as $t) {
    $options[$t->tid] = $t->name;
  }
  return $options;
}

function _portales7_listado_content_type_names($strict = FALSE) {
  $voc = taxonomy_vocabulary_machine_name_load('type');
  $terms = taxonomy_get_tree($voc->vid);
  $options = array();
  if (!$strict) {
    $options['-2'] = t('From panel arguments');
    $options['-1'] = t('Any');
  }
  foreach ($terms as $t) {
    $options[$t->name] = $t->name;
  }
  return $options;
}

function _portales7_get_date_format_select() {
  $date_formats = array();
  $formats = system_get_date_formats();
  foreach ($formats as $type => $data) {
    foreach ($data as $format => $variant){
      $date_formats[$format] = $type . ': ' . format_date($_SERVER['REQUEST_TIME'], $type, $format);
    }
  }
  return $date_formats;
}
