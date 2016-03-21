<?php
/**
 * @file
 * Theme functions for Portales7 AEMET module
 */
function template_preprocess_aemet_day(&$variables, $theme = 'aemet_day') {
  _portales7_aemet_day_low($variables);
}

function template_preprocess_aemet_widget(&$variables, $hook) {
  drupal_add_css(drupal_get_path('module', 'portales7_aemet') . '/portales7-aemet.css');
  $conf = $variables['conf'];
  $day_info_table = array();
  foreach ($variables['prediccion'] as $date => $forecast) {
    //$day_info[$date] = theme('aemet_day', $forecast);
    $day_info_table[format_date(strtotime($date), 'custom', "D d")] = theme('aemet_day_array', array('forecast' => $forecast, 'conf' => $conf));
    if (count($day_info_table) == $variables['conf']['days']) break;
  }
  if ($variables['conf']['show_variables']) {
    $day_info_table = array_merge(array('' => _portales7_aemet_variables($conf['options'])), $day_info_table);
  }
  foreach ($day_info_table as $date => $info) {
    foreach ($info as $k => $v) {
      $day_info_table_t[$k][$date] = $v;
    }
  }
  $variables['forecast_table'] = theme('table', array('header' => array_keys($day_info_table), 'rows' => $day_info_table_t));
  $variables['elaborado'] = strtotime($variables['elaborado']);
  $variables['origen'] = 'Agencia Estatal de Meteorología - AEMET. Gobierno de España http://www.aemet.es ';
}

function theme_portales7_aemet_day_array(&$variables) {
  _portales7_aemet_day_low($variables['forecast']);
  $result = array();
  foreach ($variables['conf']['options'] as $k => $v) {
    if ($v) $result[$k] = sprintf("<div class=\"aemet-%s\">%s</div>", $k, $variables['forecast'][$k]);
  }
  return $result;
}
function _portales7_aemet_day_low(&$variables) {
  module_load_include('inc', 'portales7_aemet', 'portales7_aemet.util');
  if (date('H') < 12) {
    $period = '00-12';
  }
  else {
    $period = '12-24';
  }
  if (empty($variables['estado_cielo'][$period])) {
    $period = 0;
  }
  $estado_cielo = $variables['estado_cielo'][$period];
  $url = _portales7_aemet_check_icon(sprintf("estado_cielo/%s.gif", key($estado_cielo)));
  $variables['estado_cielo'] = sprintf('<img src="%s" alt="%s" title="%s"/>', $url, current($estado_cielo), current($estado_cielo));

  $temp = $variables['temperatura'][0];
  $variables['temperatura'] = sprintf('<span class="aemet-tmax">%s&deg;</span>/<span class="aemet-tmin">%s&deg;</span>', $temp['maxima'], $temp['minima']);
  $sen_term = $variables['sens_termica'][0];
  $variables['sens_termica'] = sprintf('<span class="aemet-sens_tmax">%s&deg;</span>/<span class="aemet-sens_tmin">%s&deg;</span>', $sen_term['maxima'], $sen_term['minima']);

  $viento = $variables['viento'][$period];
  $url = _portales7_aemet_check_icon(sprintf('iconos_viento/%s.gif', $viento['direccion']));
  $variables['viento'] = sprintf('<img src="%s" alt="%s" title="%s"/> %s', $url, $viento['direccion'], $viento['direccion'], $viento['velocidad']);

  $hum = $variables['humedad_relativa'][0];
  $variables['humedad_relativa'] = sprintf('<span class="aemet-hmax">%s</span>/<span class="aemet-hmin">%s</span>', $hum['maxima'], $hum['minima']);

  $racha = $variables['racha_max'][$period];
  $variables['racha_max'] = sprintf('<span class="aemet-rachamax">%s</span>', $racha);

  $uv = $variables['uv_max'][0];
  $variables['uv_max'] = sprintf('<span class="aemet-uvmax">%s</span>', $uv);

  $prec = $variables['prob_precipitacion'][$period];
  $variables['prob_precipitacion'] = sprintf('<span class="aemet-prob_pre">%s</span>', $prec);

}

function theme_aemet_variables($variables) {
  dsm($variables, __FUNCTION__);
}

function _portales7_aemet_variables($options) {
  $variables = array(
    'estado_cielo' => t('Sky'),
    'temperatura' => t('Temp. (max/min)'),
    'prob_precipitacion' => t('Rain prob. (%)'),
    'sens_termica' => t('Termal sensation'),
    'viento' => t('Wind'),
    'humedad_relativa' => t('Humidity (max/min)'),
    'racha_max' => t('Wind burst'),
    'uv_max' => t('UV Index'),
  );

  foreach ($variables as $k => $v) {
    if (empty($options[$k])) {
      unset($variables[$k]);
    }
  }
  return $variables;
}
