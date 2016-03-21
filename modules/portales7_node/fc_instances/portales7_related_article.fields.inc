<?php
$fields = array(
  'portales7_fc_name' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_fc_description' => array(
    'type' => 'text_long',
    'cardinality' => 1,
  ),
  'portales7_r_node' => array(
    'settings' => array(
      'target_type' => 'node',
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(
          'portales7_node' => 'portales7_node',
          'webform' => 'webform',
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
      ),
    ),
    'type' => 'entityreference',
    'cardinality' => -1,
  ),
  'portales7_fc_formatter' => array(
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'portales7_fc_formatters',
    ),
    'type' => 'list_text',
    'cardinality' => 1,
  ),
);
