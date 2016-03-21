<?php
function portales7_importnodes_form($form_state) {
  $form = array();
  $form['info'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>' . t('This will create some nodes to start up a website') . '</h2>',
  );
  /*$form['nodes'] = array(
    '#type' => 'textarea',
    '#title' => t('Code'),
    '#default_value' => '',
  );*/
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );
  return $form;
}

function portales7_importnodes_form_submit($form, $form_state) {
  module_load_include('batch.inc','dvimport');
  $config = &drupal_static('dvimport_get_export_config');
  $config->file_directory_path = '//////';
  $data = array();
  $context = array();

  // DATOS COMUNES
  $data['nid'] = 0;
  $data['status'] = 1;
  $data['language'] = 'und'; //ca en es
  $data['field_usefirstimage'][0]['value'] = TRUE;
  $data['body'] = 'este es el cuerpo de la noticia este es el cuerpo de la noticia este es el cuerpo de la noticia este es el cuerpo de la noticia este es el cuerpo de la noticia este es el cuerpo de la noticia';

  
  $info = array();
  
  //DATOS COMUNES NOTICIA
  $field_type = dvtoolbox_get_taxonomy_term_by_name('report', 'type', 0, FALSE)->tid;
  // NOTICIA 1
  $info[] = array(
    'title' => 'Premios II concurso de narrativa corta',
    'teaser' => 'Los ganadores del concurso podrán disfrutar de 2 vales de 50 euros cada uno para canjear por compras',
    'field_image' => array(array('filepath'=>'public://portales7-recursos/imagenes/ejemplos/imagen_noticia1.jpg')),
    'field_type' => $field_type,
  );
  // NOTICIA 2
  $info[] = array(
    'title' => 'Alcantir presenta su nueva App Municipal',
    'teaser' => 'La aplicación fue presentada ayer: Los ciudadanos podrán enviar incidencias y consultas desde su móvil',
    'field_image' => array(array('filepath'=>'public://portales7-recursos/imagenes/ejemplos/imagen_noticia3.jpg')), 
    'field_type' => $field_type,
  );
  // NOTICIA 3
  $info[] = array(
    'title' => 'Más de 1500 participantes en la IV Media Maratón',
    'teaser' => 'La carrera se celebrará por cuarto año consecutivo gracias al Club Deportivo Alcantir, el Ayuntamiento y las marcas.',
    'field_image' => array(array('filepath'=>'public://portales7-recursos/imagenes/ejemplos/imagen_noticia2.jpg')), 
    'field_type' => $field_type,
  );
  // NOTICIA 4
  $info[] = array(
    'title' => 'El nuevo Gobierno de Alcantir ya está en marcha',
    'teaser' => 'Los 4 tenientes de alcalde serán Gerardo Martínez, Alicia Sanz, Jaume Martí y Lola de Maria',
    'field_image' => array(array('filepath'=>'public://portales7-recursos/imagenes/ejemplos/imagen_noticia4.jpg')), 
    'field_type' => $field_type,
  );

  // DATOS COMUNES EVENTOS
  //$data->portales7_newsdate'][0] = array(
  //        'value' => date(),
  //        'timezone' => drupal_get_user_timezone());
  
  //$entity->portales7_noticedate['und'][0] = array(
  //            'value' => $entity->created,
  //            'value2' => $entity->created + 864000,
  //            'timezone' => drupal_get_user_timezone());
  
  // el resto de imágenes las añadiríamos al array
  
  //$file['data']['alt']
  //$data['field_banner'] =array();
  
  //$file['data']['title'])) $imported['title']
  //$data['field_event_date']
  //$data['field_type'] = dvtoolbox_get_taxonomy_term_by_name('event', 'type', 0, FALSE);
    
  $field_type = dvtoolbox_get_taxonomy_term_by_name('event', 'type', 0, FALSE)->tid;
  $field_event_date = array(
    'value' => $entity->created,
    'value2' => $entity->created + 31536000, // un año
    'timezone' => drupal_get_user_timezone(),
  );
  
  // EVENTO 1
  $info[] = array(
    'title' => 'Primera Feria del Outlet de Alcantir 205',
    'teaser' => 'Los proximos 12,13 y 14 de diciembre se celebrará la feria organizada por los comerciantes locales',
    'field_image' => array(array('filepath'=>'public://portales7-recursos/imagenes/ejemplos/imagen_agenda1.jpg')),
    'field_type' => $field_type,
    'field_event_date' => $field_event_date,
  );
  // EVENTO 2
  $info[] = array(
    'title' => 'The Hotel. Un espectáculo de 5 estrellas',
    'teaser' => 'Llega al Auditorio municipal de Alcantir "The Hotel", entradas disponibles en ticketMaster',
    'field_image' => array(array('filepath'=>'public://portales7-recursos/imagenes/ejemplos/imagen_agenda2.jpg')),
    'field_type' => $field_type,
    'field_event_date' => $field_event_date,
  );
  // EVENTO 3
  $info[] = array(
    'title' => 'Taller de verano para los más pequeños',
    'teaser' => 'Ven en familia a disfrutar de los talleres que hemos preparado para los más pequeños',
    'field_image' => array(array('filepath'=>'public://portales7-recursos/imagenes/ejemplos/imagen_agenda3.jpg')),
    'field_type' => $field_type,
    'field_event_date' => $field_event_date,
  );
  // EVENTO 4
  $info[] = array(
    'title' => 'Concierto de Andrew Bird. Diciembre 2015',
    'teaser' => 'El de Illinois repasará su último disco "Echolocations Canyon". El día 29 a las 21:30 en el Auditorio.',
    'field_image' => array(array('filepath'=>'public://portales7-recursos/imagenes/ejemplos/imagen_agenda4.jpg')),
    'field_type' => $field_type,
    'field_event_date' => $field_event_date,
  );

  $field_type = dvtoolbox_get_taxonomy_term_by_name('notification', 'type', 0, FALSE)->tid;

  //AVISO 1
  $info[] = array(
    'title' => 'Aviso corte de agua durante 24 Horas',
    'teaser' => 'El ayuntamiento informa que debido a una incidencia en el alcantarillado, se cortara el agua de los vecinos durante el tiempo que duren las reparaciones un maximo de 24 horas.',
    'field_type' => $field_type,
    'field_image' => '',
  );

  //AVISO 2
  $info[] = array(
    'title' => 'Abierto el plazo de pago de impuestos',
    'teaser' => 'Se abre el periodo de pago voluntario de impuestos municipales todas las mañanas de 8:00 a 14:00', 
    'field_type' => $field_type,
    'field_image' => '',
  );

  $field_type = dvtoolbox_get_taxonomy_term_by_name('page', 'type', 0, FALSE)->tid;

  //PAGINA 1
  $info[] = array(
    'title' => 'Saludo de la Alcaldesa',
    'teaser' => 'Como alcaldesa quiero darte la bienvenida al espacio web municipal. Un espacio que debe convertirse en la herramienta clave que facilite la comunicación entre la administración y vecinos.', 
    'field_type' => $field_type,
    'field_image' => '',
  );

  //PAGINA 2
  $info[] = array(
    'title' => 'Medio Ambiente',
    'teaser' => 'Desde Alcantir nos preocupamos por el medio ambiente prestando los siguientes servicios: Recogida de pilas usadas, control y gestión de la calidad del aire, registro especial de alarmas e instalaciones de telecontrol ', 
    'field_type' => $field_type,
    'field_image' => '',
  );

  //PAGINA 3
  $info[] = array(
    'title' => 'Fiestas',
    'teaser' => 'En pleno verano, durante el segundo fin de semana de  agosto, Alcantir rinde honores al patrón de la Vila. Fiesta muy querida y enraizada, se celebran diversos actos, donde destaca la ‘L´Entrà’, donde tropas moras y cristianas desfilan mostrando sus trajes, entre boatos e impresionante música.', 
    'field_type' => $field_type,
    'field_image' => '',
  );

  
  foreach ($info as $v) {
    $data = array_merge($data, $v);
    $node = _dvimport_batch_create_article($data, $context);
    if (!empty($data['teaser'])) $node->portales7_teaser['und'][0]['value'] = strip_tags($data['teaser']);
    $node->portales7_type['und'] = array(array('tid' => $v['field_type']));
    node_save($node);
    if ($node->nid) {
      drupal_set_message(t('Created node !title (%nid) !edit', array('!title' => l($node->title, 'node/' . $node->nid), '%nid' => $node->nid, '!edit' => l(t('edit'), 'node/' . $node->nid . '/edit'))), 'status');
    }
    else {
      drupal_set_message(t("Can't save node %title", array('%title' => $data['title'])), 'error');
    }
  }

  

}
