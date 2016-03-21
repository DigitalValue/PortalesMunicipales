<?php
$instances = array(
  'portales7_fc_name' => array(
    'label' => 'Name',
    'widget' => array(
      'weight' => 0,
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
  'portales7_fc_description' => array(
    'label' => 'Description',
    'widget' => array(
      'weight' => 1,
      'type' => 'text_textarea',
      'settings' => array(
        'rows' => 5,
      ),
      'module' => 'text',
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => 1,
        'settings' => array(),
        'module' => 'text',
      ),
    ),
    'required' => FALSE,
    'description' => '',
  ),
  'portales7_re_entities' => array(
    'label' => 'Entities',
    'widget' => array(
      'weight' => 2,
      'type' => 'inline_entity_form',
      'module' => 'inline_entity_form',
      'active' => 1,
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 1,
          'match_operator' => 'CONTAINS',
          'delete_references' => 0,
          'override_labels' => 0,
          'label_singular' => 'nodo',
          'label_plural' => 'nodos',
        ),
      ),
    ),
    'settings' => array(),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'entityreference_label',
        'settings' => array(
          'link' => FALSE,
        ),
        'module' => 'entityreference',
        'weight' => 1,
      ),
    ),
    'required' => 0,
    'description' => '',
  ),
  'portales7_fc_formatter' => array(
    'label' => 'Presentation',
    'widget' => array(
      'weight' => 99,
      'type' => 'options_select',
      'module' => 'options',
      'active' => 1,
      'settings' => array(),
    ),
    'settings' => array(),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'list_default',
        'settings' => array(),
        'module' => 'list',
        'weight' => 2,
      ),
    ),
    'required' => 0,
    'description' => '',
    'default_value' => NULL,
  ),
);
