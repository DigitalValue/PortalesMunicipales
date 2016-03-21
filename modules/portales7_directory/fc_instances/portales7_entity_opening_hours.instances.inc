<?php
$instances = array(
  'portales7_entity_oh_condition' => array(
    'label' => 'Condition',
    'widget' => array(
      'weight' => 1,
      'type' => 'text_textfield',
      'settings' => array(
        'size' => 60,
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
        'weight' => 0,
        'settings' => array(),
        'module' => 'text',
      ),
    ),
    'required' => FALSE,
    'description' => '',
  ),
  'portales7_entity_oh_detail' => array(
    'label' => 'Detail',
    'widget' => array(
      'weight' => 2,
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
);
