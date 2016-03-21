<?php
/**
 * Preprocess function for agenda display
 */
function portales7_listado_preprocess_portales7_listado_agenda(&$variables) {
  $nodes = &drupal_static(__FUNCTION__);
  $row = $variables['row'];
  $fields = $variables['fields'];
  $delta = isset($nodes[$row->nid]) ? $nodes[$row->nid] : 0;
  $date1 = date('j-n-y', $row->field_portales7_eventdate[$delta]['raw']['value']);
  $hour1 = date('H:i', $row->field_portales7_eventdate[$delta]['raw']['value']);
  $date2 = date('j-n-y', $row->field_portales7_eventdate[$delta]['raw']['value2']);
  $hour2 = date('H:i', $row->field_portales7_eventdate[$delta]['raw']['value2']);
  if ($date2 == $date1) {
    $date2 = '';
    if ($hour2 == $hour1) $hour2 = '';
  }
  foreach ((array)$row->field_portales7_eventcalendar as $c) {  
    if (function_exists('transliteration_clean_filename')) {
      $calendar[] = 'portales7_eventcalendar-'. str_replace(' ', '_', transliteration_clean_filename($c['raw']['taxonomy_term']->name));
    }
    else {
      $calendar[] = 'portales7_eventcalendar-'. str_replace(' ', '_', $c['raw']['taxonomy_term']->name);
    }
  }
  $variables['hour1'] = $hour1;
  $variables['date1'] = $date1;
  $variables['hour2'] = $hour2;
  $variables['date2'] = $date2;
  $variables['calendar'] = join(' ', $calendar);
  if (!empty($row->field_portales7_main_media[0]['rendered'])) {
    $variables['main_image'] = drupal_render($row->field_portales7_main_media[0]['rendered']);
  }
  $variables['teaser'] = !empty($fields['portales7_teaser']->content) ? $fields['portales7_teaser']->content : '';
  $variables['title'] = l($row->node_title, 'node/' .  $row->nid);
  $variables['calendar_links'] = $fields['portales7_eventcalendar']->content;
  $variables['nid'] = $row->nid;
  foreach ((array)$row->field_portales7_event_type as $type) {
    $types[] = $type['rendered']['#markup'];
  }
  if (!empty($types)) {
    $type = theme('item_list' , array('items' => $types));
    $variables['event_type'] = $type;
  }
  $nodes[$row->nid] = $delta + 1;
}
