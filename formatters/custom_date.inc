<?php
$formatter = array(
  'name' => 'custom_date',
  'info' => array(
    'label' => t('Portales 7 Custom Date'),
    'field types' => array('date', 'datetime', 'datestamp'),
    'description' => t('Show the date in divs'),
    'settings' => array(
      'class_title' => '',
    ),
  ),
);


function custom_date_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $settings = $instance['display'][$view_mode]['settings'];
  $element['class_title'] = array(
    '#type' => 'textfield',
    '#title' => t('class'),
    '#description' => t('Class for the div element'),
    '#default_value' => $settings['class_title'],
  );
  return $element;
}

function custom_date_settings_summary($field, $instance, $view_mode) {
   return t('Show the date in divs');
}

function _custom_date_sort($a, $b) {
  if ($a['value'] == $b['value']) {
    return ($a['value2'] - $b['value2']);
  }
  return ($a['value'] - $b['value']);
}

function custom_date_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $printed = &drupal_static(__FUNCTION__);
  $settings = $display['settings'];
  $output = '';
  usort($items, '_custom_date_sort');
  foreach ($items as $delta => $item){
    if (isset($printed[$entity->nid][$delta])) continue;
    if (preg_match('@/([0-9]{4}\-[0-9]{2}\-[0-9]{2})$@',$_GET['q'], $res) && ($t = strtotime($res[1]))) {
      if ($item['value2'] < $t) continue;
    }
    elseif (($item['value2'] < REQUEST_TIME) && isset($entity->view)) continue;
    $printed[$entity->nid][$delta] = TRUE;
    $fecha = $item['value'];
    $dias = format_date($fecha, 'custom', 'l');
    $dia = format_date($fecha, 'custom', 'j');
    $mes = format_date($fecha, 'custom', 'F');
    $anyo = format_date($fecha, 'custom', 'Y');
    $hora = format_date($fecha, 'custom', 'G');
    $minu = format_date($fecha, 'custom', 'i');
    $val1 ='<div class="pm-fecha-fecha ' . $settings['class_title'] . '"><div class="pm-fecha-dias">' . $dias .  '</div><div class="pm-fecha-dia">' .  $dia . '</div><div class="pm-fecha-mes">' . $mes . '</div><div class="pm-fecha-anyo">' . $anyo . '</div></div><div class="pm-fecha-horas"><div class="pm-fecha-hora">' . $hora . '</div><div class="pm-fecha-minu">' . $minu . '</div></div>';
    $compara1 = format_date($fecha, 'custom', 'jmY');
    $hoy = date('jmY', time());
     if($hoy == $compara1)
      {
      $val1 ='<div class="pm-fecha-fecha"><div class="pm-fecha-hoy">' . t('Today') .  '</div><div class="pm-fecha-dia">' .  $dia . '</div><div class="pm-fecha-mes">' . $mes . '</div><div class="pm-fecha-anyo">' . $anyo . '</div></div><div class="pm-fecha-horas"><div class="pm-fecha-hora">' . $hora . '</div><div class="pm-fecha-minu">' . $minu . '</div></div>';
      }
     
   if ( !empty ($item['value2'])){
    $fecha2 = $item['value2'];
    $dias2 = format_date($fecha2, 'custom', 'l');
    $dia2 = format_date($fecha2, 'custom', 'j');
    $mes2 = format_date($fecha2, 'custom', 'F');
    $anyo2 = format_date($fecha2, 'custom', 'Y');
    $hora2 = format_date($fecha2, 'custom', 'G');
    $minu2 = format_date($fecha2, 'custom', 'i');
      $compara1 = format_date($fecha, 'custom', 'jmY');
      $compara2 = format_date($fecha2, 'custom', 'jmY');
      if ($hoy < $compara1) $clase = 'futuro';
      if ($hoy > $compara2) $clase = 'pasado';
      if ($hoy >= $compara1 && $hoy <= $compara2){ $clase = 'presente';}
      if ( $compara1 != $compara2){
           if($hoy == $compara2)
            {
                $val1 = '<div class="pm-fecha compuesta ' . $clase . '"><div class="pm-fecha-desde pm-fecha-grupo"><div class="pm-fecha-from">' . t('From') . '</div>' . $val1 . '</div><div class="pm-fecha-separador"></div><div class="pm-fecha-hasta pm-fecha-grupo"><div class="pm-fecha-a">' . t('to') . '</div><div class="pm-fecha-fecha"><div class="pm-fecha-hoy">' . t('Today') .  '</div><div class="pm-fecha-dia">' .  $dia2 . '</div><div class="pm-fecha-mes">' . $mes2 . '</div><div class="pm-fecha-anyo">' . $anyo2 . '</div></div><div class="pm-fecha-horas"><div class="pm-fecha-hora">' . $hora2 . '</div><div class="pm-fecha-minu">' . $minu2 . '</div></div></div></div>';
      }   
          else{
        $val1 = '<div class="pm-fecha compuesta ' . $clase . '"><div class="pm-fecha-desde pm-fecha-grupo"><div class="pm-fecha-from">' . t('From') . '</div>' . $val1 . '</div><div class="pm-fecha-separador"></div><div class="pm-fecha-hasta pm-fecha-grupo"><div class="pm-fecha-a">' . t('to') . '</div><div class="pm-fecha-fecha"><div class="pm-fecha-dias">' . $dias2 .  '</div><div class="pm-fecha-dia">' .  $dia2 . '</div><div class="pm-fecha-mes">' . $mes2 . '</div><div class="pm-fecha-anyo">' . $anyo2 . '</div></div><div class="pm-fecha-horas"><div class="pm-fecha-hora">' . $hora2 . '</div><div class="pm-fecha-minu">' . $minu2 . '</div></div></div></div>';
        }
       }
      else{
          $val1 = '<div class="pm-fecha simple ' . $clase . '"><div class="pm-fecha-desde pm-fecha-grupo">' . $val1 . '</div></div>';
          } 
    }
    $output[] = array('#markup' => $val1);
    break;
  }
return $output;
}
