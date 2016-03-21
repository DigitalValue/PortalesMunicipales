<?php
/**
 * @file
 * auxiliary functions for portales7_aemet module
 */

function _portales7_aemet_get_forecast($ine, $skip_proxy = FALSE) {
  $url = 'http://portalesmunicipales.es/aemet/aemet.php?ine=' . $ine;
  if ($skip_proxy) {
    $url = 'http://www.aemet.es/xml/municipios/localidad_' . $ine . '.xml';
  }
  $doc = new DOMDocument();
  $prediccion = array();
  
  $cid = 'aemet_forecast_' . date('Ymd', $_SERVER['REQUEST_TIME']);
  if (!$skip_proxy && $cache = cache_get($cid, 'cache')) {
    return (array)$cache->data;
  }

  if ($doc->load($url) !== FALSE ) {
    foreach (array('origen', 'elaborado', 'nombre', 'provincia') as $tag) {
      $info[$tag] = _portales7_aemet_process_type2($doc->getElementsByTagName($tag)->item(0));
      if ((count($info[$tag]) == 1) && !empty($info[$tag]['#text'])) {
        $info[$tag] = $info[$tag]['#text'];
      }
    }
    foreach ($doc->getElementsByTagName('dia') as $day) {
      if ($day->hasAttributes()) {
        $date = $day->attributes->getNamedItem('fecha')->value;
        $prediccion[$date] = _portales7_aemet_process_day($date, $day);
      }
    }
    $info['prediccion'] = $prediccion;
    cache_set($cid, $info, 'cache', CACHE_TEMPORARY);
    return $info;
  }
  else {
    drupal_set_message(t('Can\'t retrieve data from @url', array('@url' => $url)), 'error');
  }
}

function _portales7_aemet_process_day($date, $day) {
  $data = NULL;
  foreach ($day->childNodes as $child) {
    $type = $child->nodeName;
    $period = 0;
    if ($child->hasAttributes() && $child->attributes->getNamedItem('periodo')) {
      $period = $child->attributes->getNamedItem('periodo')->value;
    }
    if (function_exists('_portales7_aemet_process_' . $type)) {
      $data[$type][$period] = call_user_func('_portales7_aemet_process_' . $type, $child);
    }
    else {
      $data[$type][$period] = $child->nodeValue;
    }
  }
  $data['date'] = $date;
  return $data;
}

function _portales7_aemet_process_estado_cielo($node) {
  $data = NULL;
  if ($node->hasAttributes() && $node->attributes->getNamedItem('descripcion')) {
    $data[$node->nodeValue] = $node->attributes->getNamedItem('descripcion')->value;
  }
  return $data;
}

function _portales7_aemet_process_type2($node) {
  $data = NULL;
  foreach ($node->childNodes as $child) {
    if ($child->hasAttributes() && $child->attributes->getNamedItem('hora') && ($hour = $child->attributes->getNamedItem('hora')->value)) {
      $data[$child->nodeName][$hour] = $child->nodeValue;
    }
    else {
      $data[$child->nodeName] = $child->nodeValue;
    }
  }
  return $data;
}


function _portales7_aemet_process_viento($node) {
    return _portales7_aemet_process_type2($node);
}

function _portales7_aemet_process_temperatura($node) {
  return _portales7_aemet_process_type2($node);
}

function _portales7_aemet_process_sens_termica($node) {
  return _portales7_aemet_process_type2($node);
}

function _portales7_aemet_process_humedad_relativa($node) {
  return _portales7_aemet_process_type2($node);
}

function _portales7_aemet_check_icon($image_filename) {
  $image_dir = drupal_get_path('module', 'portales7_aemet') . '/images/gif/';
  if (!file_exists($image_dir . $image_filename)) {
    $aemet_dir = 'http://www.aemet.es/imagenes/gif/';
    $path = dirname(__FILE__) . '/images/gif/' . $image_filename;
    watchdog('portales7_aemet', 'Copying @file to @dest', array('@file' => $aemet_dir . $image_filename, '@dest' => $path));
    copy($aemet_dir . $image_filename, $path);
  }
  return base_path() . $image_dir . $image_filename;
}
