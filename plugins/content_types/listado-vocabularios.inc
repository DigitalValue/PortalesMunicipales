<?php


/**
 * @file
 * Sample ctools content type that takes advantage of context.
 *
 * This example uses the context it gets (simplecontext) to demo how a
 * ctools content type can access and use context. Note that the simplecontext
 * can be either configured manually into a panel or it can be retrieved via
 * an argument.
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('List Vocabulary'),
  'content_types' => 'list_vocabulary',
  // 'single' means not to be subtyped.
  'single' => TRUE,
  // Name of a function which will render the block.
  'render callback' => 'portales7_list_vocabulary_render',
  'edit form' => 'portales7_list_vocabulary_edit_form',

  // Icon goes in the directory with the content type.
  'icon' => 'icon_portales7.png',
  'category' => t('Portales 7'),
  'admin info' => 'portales7_list_vocabulario_content_type_admin_info',
  'admin title' => 'portales7_list_vocabulario_content_type_admin_title',
  'defaults' => array('type' => '', 'url' => ''),

  // presents a block which is used in the preview of the data.
  // Pn Panels this is the preview pane shown on the panels building page.
);

function portales7_list_vocabulario_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  $output = t('List Vocabulary');
  if ($conf['override_title'] && !empty($conf['override_title_text'])) {
    $output = filter_xss_admin($conf['override_title_text']);
  }
  return $output;
}

/**
 * Callback to provide administrative info (the preview in panels when building
 * a panel).
 *
 * In this case we'll render the content with a dummy argument and
 * a dummy context.
 */
function portales7_list_vocabulario_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_list_vocabulario_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre> ' . t('Options') . ': ' . print_r($conf, 1) . '</pre>';
  return $pane;
}

/**
 * Run-time rendering of the body of the block (content type)
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time
 * @param $args
 * @param $context
 *   Context - in this case we don't have any
 *
 * @return
 *   An object with at least title and content members
 */
function portales7_list_vocabulary_render($subtype, $conf, $args, $context) {
  $pane=new stdClass();
  $vocabulary = taxonomy_vocabulary_machine_name_load($conf['type']);
  $terms = taxonomy_get_tree($vocabulary->vid);
  foreach($terms as $tax){
     $term = taxonomy_term_load($tax ->tid);      
     $output[] = '<div class="' . transliteration_clean_filename($term->name, '-') . ' termino-' . $conf['type'] . '"/>' . l($term->name, $conf['url'] . '/' . $term->name, array('attributes' => array('title' => $term->name ))) . '</div >';
     
  }

  // Don't forget to check this data if it's untrusted.
  // The title actually used in rendering.
  $pane->title = "List termes";
  $pane->content = theme('item_list', array('items' => $output));
  return $pane;
}

/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function portales7_list_vocabulary_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $vocab = taxonomy_get_vocabularies();
  foreach($vocab as $vo){
    $vocab_name[$vo->machine_name] = $vo->name;
  }
  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#description' => t('Taxonomy type to show'),
    '#options' => $vocab_name,
    '#default_value' => $conf['type'],
    );
  
  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('Url'),
    '#description' => t('The url to link the image.'),
    //'#default_value' => $conf['fields'],
    '#default_value' => $conf['url'],
    '#maxlength' => 4096,
  );

  return $form;
}

function portales7_list_vocabulary_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
