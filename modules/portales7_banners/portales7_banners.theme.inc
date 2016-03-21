<?php
/**
 * Preprocess function for view results
 */
function portales7_banners_preprocess_portales7_banners_banners(&$variables) {
  $row = $variables['row'];
  $target = $row->field_portales7_banners_target[0]['raw']['value'];
  $options = array('attributes' => array('target' => $target));
  if (!empty($row->field_portales7_banners_url[0]['raw']['value'])){
    $path = $row->field_portales7_banners_url[0]['raw']['value'];
  }
  else if (!empty($row->field_portales7_banners_node[0]['rendered']['#markup'])){
    $path = $row->field_portales7_banners_node[0]['rendered']['#markup']; 
  }
  else {
    $path = url('<front>',array('absolute' => TRUE));
  }
  if (strpos($path, '/') === 0) {
    $options['external'] = TRUE;
  }
  if (!empty($row->field_portales7_banners_image[0]['rendered'])) {
    $element = $row->field_portales7_banners_image[0]['rendered'];
    $element['#path'] = array('path' => $path, 'options' => $options);
    $variables['image'] = theme('image_formatter', $element);
    if (!empty($row->field_portales7_banners_overlay[0]['rendered']['#markup'])) {
      $variables['text'] = '<a href="'. $path . '" target="' . $target . '">' . $row->field_portales7_banners_overlay[0]['rendered']['#markup'] . '</a>';
    }
  }
  else {
    $variables['link'] = l($row->node_title, $path, $options);
  }

  $variables['path'] = $path;
  $variables['id'] = 'banner-node-' . $row->nid;
}


