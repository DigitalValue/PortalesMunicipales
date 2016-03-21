<?php
function portales7_node_taxonomy_fields() {
  return array(
    'portales7_term_image' => array(
      'type' => 'image',
      'cardinality' => 1,
      'entity_types' => array('taxonomy_term'),
    ),
    'portales7_term_synonyms' => array(
      'settings' => array(
        'max_length' => 255,
      ),
      'type' => 'text',
      'cardinality' => -1,
    ),
  );
}

function portales7_node_taxonomy_instances() {
  $instances = array(
    'event_types' => array(
      'portales7_term_image' => array(
        'label'       => 'Term image',
        'required'    => FALSE,
        'widget' => array(
          'type'    => 'image_image',
          'weight'  => 1,
          'settings' => array('filefield_sources' => array(
              'filefield_sources' => array(
                'imce' => 'imce',
                'upload' => 0,
              ),
              'source_imce' => array('imce_mode' => 1),
              'source_reference' => array('autocomplete' => 0),
            ),
          ),
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'image',
            'weight' => 0,
            'settings' => array (
                    'image_style' => '',
                    'image_link' => '',
                ),
            'module' => 'image',
          ),
        ),
        'settings' => array(
          'file_directory' => 'imagenes/taxonomia/[current-date:custom:Ym]',
          'file_extensions' => 'png jpg jpeg gif tiff',
          'max_filesize' => '32MB',
          'alt_field' => 1,
          'title_field' => 1,
          'epsacrop' => array(
            'styles' => dvtoolbox_epsacrop_styles(portales7_image_default_styles()),
          ),
        ),
      ),
      'portales7_term_synonyms' => array(
        'label' => 'synonyms',
        'widget' => array(
          'weight' => 31,
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => 60,
          ),
        ),
        'settings' => array(
          'text_processing' => 0,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'text_default',
            'settings' => array(),
            'module' => 'text',
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
      ),
    ),
  );
  $instances['type']['portales7_term_synonyms'] = $instances['event_types']['portales7_term_synonyms'];
  $instances['category']['portales7_term_synonyms'] = $instances['event_types']['portales7_term_synonyms'];
  return $instances;
}

function portales7_node_default_taxonomy_vocabularies() {
  
  return array(
  'type' => (object) array(
    'vid' => 0,
    'name' => 'type',
    'machine_name' => 'type',
    'description' => 'A vocabulary for Portales 7 node content types',
    'hierarchy' => 0,
    'module' => 'portales7_node',
    'i18n_mode' => 1,
  ),
  'banners' => (object) array(
    'vid' => 0,
    'name' => 'Banners',
    'machine_name' => 'banners',
    'description' => 'A vocabulary for Portales 7 banner groups',
    'hierarchy' => 0,
    'module' => 'portales7_node',
  ),
  'calendar' => (object) array(
    'vid' => 0,
    'name' => 'Calendar',
    'machine_name' => 'calendar',
    'description' => 'A vocabulary for Portales 7 event calendars',
    'hierarchy' => 0,
    'module' => 'portales7_node',
  ),
  'category' => (object) array(
    'vid' => 0,
    'name' => 'Category',
    'machine_name' => 'category',
    'description' => 'A vocabulary for Portales 7 categories',
    'hierarchy' => 0,
    'module' => 'portales7_node',
    'i18n_mode' => 1,
  ),
  'families' => (object) array(
    'vid' => 0,
    'name' => 'Families',
    'machine_name' => 'families',
    'description' => 'A vocabulary for Portales 7 families',
    'hierarchy' => 0,
    'module' => 'portales7_node',
    'i18n_mode' => 1,
  ),
  'event_types' => (object) array(
    'vid' => 0,
    'name' => 'Event types',
    'machine_name' => 'event_types',
    'description' => 'A vocabulary for Portales 7 event types',
    'hierarchy' => 0,
    'module' => 'portales7_node',
    'i18n_mode' => 1,
  ),
  'sections' => (object) array(
    'vid' => 0,
    'name' => 'Sections',
    'machine_name' => 'sections',
    'description' => 'A vocabulary for Portales 7 sections',
    'hierarchy' => 0,
    'module' => 'portales7_node',
    'i18n_mode' => 1,
  ),
  );
}

function portales7_node_default_taxonomy_terms() {
  return array( 
    'type' => array(
      0 => array('page', 'report', 'event', 'link', 'notification', 'navigation', 'slideshow', 'archive'),
    ),
    'banners' => array(
      0 => array('right-col', 'left-col', 'footer', 'content', 'Administracion', 'Escaparate', 'Redes sociales', 'minibanners'),
    ),
    'calendar' => array(
      0 => array('General'),
    ),
    'category' => array(
      0 => array('Gallery', 'BIM', 'Display', 'Sections'),
      'Sections' => array('City council', 'Town', 'Directory', 'Turism', 'Press room', 'Self service'),
    ),
    'event_types' => array(
      0 => array("Movies", "Theatre", "Concerts", "Exhibitions", "Expositions", "Holidays", "Sport", "Food", "Health", "Conferences", "Espectacles", "Contest", "Tours",
      "Festivals", "Activities for children", "Fairs and Congresses", "Bullfighting", "Municipal")
    ),
  );
}

function _portales7_node_default_synonyms() {
  $synonyms['report'] = array('noticia', 'noticias', 'noticies', 'news', 'notícia');
  $synonyms['event'] = array('evento', 'eventos', 'events', 'esdeveniment', 'esdeveniments');
  $synonyms['Gallery'] = array('galeria', 'galerias', 'galeries', 'galleries');
  $synonyms['page'] = array('pagina', 'paginas','pagines', 'pages', 'pàgina');
  $synonyms['link'] = array('enlace', 'enlaces', 'enllaços', 'enllaç', 'links');
  $synonyms['notification'] = array('aviso', 'avisos', 'avis', 'avís', 'notifications', 'avissos');
  $synonyms['navigation'] = array('navegacion', 'navegació', 'navegacio');
  $synonyms['slideshow'] = array('carrusel');
  $synonyms['people'] = array('persona', 'personas', 'persones', 'gente', 'gent');
  $synonyms['building'] = array('edificio', 'edificios', 'edifici', 'edificis', 'buildings');
  $synonyms['mobile'] = array('movil', 'moviles', 'móvil', 'móviles', 'mòbil', 'mòbils', 'mobil', 'mobils');
  $synonyms['archive'] = array('archivo', 'archivos', 'arxiu', 'arxius');
  $synonyms['City council'] = array('ayuntamiento', 'ajuntament');
  $synonyms['Town'] = array('pueblo', 'poble');
  $synonyms['Directory'] = array('directorio', 'directori');
  $synonyms['Turism'] = array('turismo', 'turisme');
  $synonyms['Press room'] = array('sala de prensa', 'sala de premsa');
  $synonyms['Self service'] = array('teletramitacion', 'teletramitacio', 'teleadministracion', 'teletramitacion', 'teletramitació', 'teletramitaciò');
  $synonyms['Movies'] = array('cine', 'cinema');
  $synonyms['Theatre'] = array('teatre');
  $synonyms['Concerts'] = array('conciertos');
  $synonyms['Exhibitions'] = array('exhibiciones', 'exhibicions');
  $synonyms['Expositions'] = array('exposicions', 'exposicions');
  $synonyms['Holidays'] = array('fiestas', 'festes');
  $synonyms['Sport'] = array('deporte', 'deportes', 'deport', 'deports', 'esport', 'esports');
  $synonyms['Food'] = array('gastronomia');
  $synonyms['Health'] = array('salud', 'salut');
  $synonyms['Conferences'] = array('conferencias', 'conferencies');
  $synonyms['Espectacles'] = array('espectaculos', 'espectaculs');
  $synonyms['Contest'] = array('concurso', 'concurs');
  $synonyms['Tours'] = array('visitas', 'visites');
  $synonyms['Festivals'] = array('festivales');
  $synonyms['Activities for children'] = array('actividades para niños', 'activitats per a xiquets');
  $synonyms['Fairs and Congresses'] = array('ferias y congresos', 'fires i congressos');
  $synonyms['Bullfighting'] = array('toros', 'bous');
  $synonyms['Display'] = array('escaparate', 'escaparates', 'escaparat', 'escaparats', 'displays');
  return $synonyms;
}

function _portales7_node_create_vocabularies(){
  module_load_include('field.inc', 'dvtoolbox');
  
  foreach (portales7_node_default_taxonomy_vocabularies() as $voc) {
    if (!taxonomy_vocabulary_machine_name_load($voc->machine_name)) {
      taxonomy_vocabulary_save($voc);
    }
  }

  dvtoolbox_field_create_fields(portales7_node_taxonomy_fields());
  dvtoolbox_field_create_instances('taxonomy_term', portales7_node_taxonomy_instances());
  
  foreach (portales7_node_taxonomy_instances() as $name => $fields) {
    if (isset($fields['portales7_term_synonyms'])) {
      $voc = taxonomy_vocabulary_machine_name_load($name);
      $instance = field_info_instance('taxonomy_term', 'portales7_term_synonyms', $voc->machine_name);
      $settings = array(
        'instance_id' => $instance['id'],
        'behavior' => 'synonyms',
        'settings' => array(),
      );
      synonyms_behavior_settings_save($settings);
      $settings['behavior'] = 'search';
      synonyms_behavior_settings_save($settings);
    }
  }
  $tt = get_t();
  $synonyms = _portales7_node_default_synonyms();
  foreach (portales7_node_default_taxonomy_terms() as $voc => $terms){
    foreach ($terms as $parent => $childs) {
      if (!is_numeric($parent)) {
        $pt = dvtoolbox_get_taxonomy_term_by_name($parent, $voc, TRUE, 0);
        $parent = $pt->tid;
      }
      foreach ($childs as $t) {
        $term = dvtoolbox_get_taxonomy_term_by_name($t, $voc, TRUE, $parent);
        if (!empty($synonyms[$t])) {
          if (empty($term->portales7_term_synonyms['und'])) $term->portales7_term_synonyms['und'] = array();
          foreach ($synonyms[$t] as $syn) {
            $term->portales7_term_synonyms['und'][] = array('value' => $syn);
          }
          taxonomy_term_save($term);
          if (empty($_GET['profile'])) drupal_set_message($tt('Added @synonyms as synonyms for @term', array('@synonyms' => join(', ', $synonyms[$t]), '@term' => $term->name)), 'status');
        }
      }
    }
  }
}

