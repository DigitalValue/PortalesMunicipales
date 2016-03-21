<?php
$fields = array(
  'portales7_entity_contact' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => -1,
  ),
  'portales7_entity_email' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => -1,
  ),
  'portales7_entity_extra' => array(
    'type' => 'text_long',
    'cardinality' => -1,
  ),
  'portales7_entity_fax' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_entity_logo' => array(
    'settings' => array(
      'uri_scheme' => 'public',
      'default_image' => 0,
    ),
    'type' => 'image',
    'cardinality' => 1,
  ),
  'portales7_entity_postaladdress' => array(
    'type' => 'addressfield',
    'cardinality' => -1,
  ),
  'portales7_entity_telephone' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => -1,
  ),
  'portales7_entity_web' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => -1,
  ),
  'portales7_entity_geofield' => array(
    'settings' => array(
      'backend' => 'default',
      'srid' => 4326,
    ),
    'type' => 'geofield',
    'cardinality' => -1,
  ),
  'portales7_entity_opening_hours' => array(
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'type' => 'field_collection',
    'cardinality' => -1,
  ),
  'title_field' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_entity_facebook' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_entity_twitter' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_entity_other' => array(
    'settings' => array(
      'max_length' => 4096,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_entity_booking' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
);
