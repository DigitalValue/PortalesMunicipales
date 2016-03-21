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
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => 0,
        'settings' => array(),
        'module' => 'text',
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
  'portales7_r_node' => array(
    'label' => 'Related article',
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
          'label_singular' => 'node',
          'label_plural' => 'nodes',
        ),
      ),
    ),
    'settings' => array(),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'entityreference_label',
        'weight' => 2,
        'settings' => array(
          'link' => 1,
        ),
        'module' => 'entityreference',
      ),
    ),
    'required' => 0,
    'description' => '',
    'default_value' => array(),
  ),
  'portales7_fc_formatter' => array(
    'label' => 'Formatter',
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
        'type' => 'hidden',
        'weight' => 4,
        'settings' => array(),
      ),
    ),
    'required' => 0,
    'description' => '',
    'default_value' => NULL,
  ),
);
