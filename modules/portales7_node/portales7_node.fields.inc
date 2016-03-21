<?php
$fields = array(
  'portales7_inline_banner' => array(
    'settings' => array(
      'target_type' => 'node',
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(
          'portales7_banner' => 'portales7_banner',
        ),
        'sort' => array(
          'type' => 'property',
          'property' => 'title',
          'direction' => 'ASC',
        ),
      ),
    ),
    'type' => 'entityreference',
    'cardinality' => -1,
  ),
  'body' => array(
    'type' => 'text_long',
    'cardinality' => 1,
  ),
  'portales7_type' => array(
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'type',
          'parent' => 0,
        ),
      ),
    ),
    'type' => 'taxonomy_term_reference',
    'cardinality' => -1,
  ),
  'portales7_teaser' => array(
    'type' => 'text_long',
    'cardinality' => 1,
  ),
  'portales7_newsdate' => array(
    'settings' => array(
      'granularity' => array(
        'month' => 'month',
        'year' => 'year',
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'second' => FALSE,
      ),
      'tz_handling' => 'site',
      'timezone_db' => 'UTC',
      'repeat' => FALSE,
      'todate' => FALSE,
      'cache_enabled' => TRUE,
      'cache_count' => 2,
    ),
    'type' => 'datestamp',
    'cardinality' => 1,
  ),
  'portales7_source' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => -1,
  ),
  'portales7_eventdate' => array(
    'settings' => array(
      'granularity' => array(
        'month' => 'month',
        'year' => 'year',
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'second' => FALSE,
      ),
      'tz_handling' => 'site',
      'timezone_db' => 'UTC',
      'repeat' => FALSE,
      'todate' => 'optional',
      'cache_enabled' => TRUE,
      'cache_count' => 2,
    ),
    'type' => 'datestamp',
    'cardinality' => -1,
  ),
  'portales7_eventcalendar' => array(
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar',
          'parent' => 0,
        ),
      ),
    ),
    'type' => 'taxonomy_term_reference',
    'cardinality' => -1,
  ),
  'portales7_category' => array(
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'category',
          'parent' => 0,
        ),
      ),
    ),
    'type' => 'taxonomy_term_reference',
    'cardinality' => -1,
  ),
  'title_field' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_weblink' => array(
    'settings' => array(
      'attributes' => array(
        'target' => 'default',
        'class' => '',
        'rel' => '',
      ),
      'url' => 0,
      'title' => 'optional',
      'title_value' => '',
      'title_maxlength' => 128,
      'enable_tokens' => 1,
      'display' => array(
        'url_cutoff' => 128,
      ),
    ),
    'type' => 'link_field',
    'cardinality' => -1,
  ),
  'portales7_families' => array(
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'families',
          'parent' => 0,
        ),
      ),
    ),
    'type' => 'taxonomy_term_reference',
    'cardinality' => -1,
  ),
  'portales7_event_type' => array(
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'event_types',
          'parent' => 0,
        ),
      ),
    ),
    'type' => 'taxonomy_term_reference',
    'cardinality' => -1,
  ),
  'portales7_event_note' => array(
    'type' => 'text_long',
    'cardinality' => 1,
  ),
  'portales7_section' => array(
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'sections',
          'parent' => 0,
        ),
      ),
    ),
    'type' => 'taxonomy_term_reference',
    'cardinality' => -1,
  ),
  'portales7_pretitle' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_subtitle' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
    'cardinality' => 1,
  ),
  'portales7_related_entity' => array(
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'type' => 'field_collection',
    'cardinality' => -1,
  ),
  'portales7_social' => array(
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'addthis',
    'cardinality' => 1,
  ),
  'portales7_related_article' => array(
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'type' => 'field_collection',
    'cardinality' => -1,
  ),
  'portales7_media' => array(
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'type' => 'field_collection',
    'cardinality' => -1,
  ),
  'portales7_main_media' => array(
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'type' => 'field_collection',
    'cardinality' => 1,
  ),
  'portales7_place' => array(
    'settings' => array(
      'target_type' => 'node',
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(
          'portales7_node' => 'portales7_entity',
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
  'portales7_noticedate' => array(
    'settings' => array(
      'granularity' => array(
        'month' => 'month',
        'year' => 'year',
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'second' => FALSE,
      ),
      'tz_handling' => 'site',
      'timezone_db' => 'UTC',
      'repeat' => FALSE,
      'todate' => 'optional',
      'cache_enabled' => TRUE,
      'cache_count' => 2,
    ),
    'type' => 'datestamp',
    'cardinality' => -1,
  ),
);
