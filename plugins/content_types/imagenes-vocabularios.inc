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
  'title' => t('Image Vocabulary'),
  'content_types' => 'image_vocabulary',
  // 'single' means not to be subtyped.
  'single' => TRUE,
  // Name of a function which will render the block.
  'render callback' => 'portales7_image_vocabulary_render',
  'edit form' => 'portales7_image_vocabulary_edit_form',

  // Icon goes in the directory with the content type.
  'icon' => 'icon_portales7.png',
  'category' => t('Portales 7'),
  'admin info' => 'portales7_imagenes_vocabulario_content_type_admin_info',
  'admin title' => 'portales7_imagenes_vocabulario_content_type_admin_title',
  'defaults' => array('type' => '', 'possible_image_styles' => '', 'url' => ''),

  // presents a block which is used in the preview of the data.
  // Pn Panels this is the preview pane shown on the panels building page.
);

function portales7_imagenes_vocabulario_content_type_admin_title($subtype, $conf, $context = NULL) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  $output = t('Image Vocabulary');
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
function portales7_imagenes_vocabulario_content_type_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();
  $pane->title = portales7_imagenes_vocabulario_content_type_admin_title($subtype, $conf, $context);
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
function portales7_image_vocabulary_render($subtype, $conf, $panel_args, $context) {
  $pane=new stdClass();
  $df = NULL;
  if ($df = array_pop($panel_args)) {
    if (!strtotime($df)) {
      array_push($panel_args, $df);
      $df = NULL;
    }
  }
  $vocabulary = taxonomy_vocabulary_machine_name_load($conf['type']);
  $terms = taxonomy_get_tree($vocabulary->vid);
  foreach($terms as $tax){
     $term = taxonomy_term_load($tax ->tid);      
     $img['item'] = $term ->portales7_term_image['und'][0];    
     $img['image_style'] = $conf['possible_image_styles'];
     $img['item']['title'] = $term ->name;
     $img['item']['alt'] = $term ->name;
     $term_image = theme('image_formatter', $img);
     $output[] = '<div class="' . transliteration_clean_filename($term->name, '-') . ' termino-' . $conf['type'] . '"/>' . l ($term_image, $conf['url'] . '/' . $term->name . ($df ? '/' . $df : ''), array('attributes' => array('title' => $term->name),'html' => TRUE)) . '</div >';
     
  }

  // Don't forget to check this data if it's untrusted.
  // The title actually used in rendering.
  $pane->title = "Image termes";
  $pane->content = theme('item_list', array('items' => $output));
  return $pane;
}

/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function portales7_image_vocabulary_edit_form($form, &$form_state) {
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


  $image_styles = image_style_options();
  $image_styles[''] = t('Left blank for original size');
  $styles = array();
  $styles['header'] = array(t('token'), t('field'));
  $styles['rows'] = array();
  foreach ($image_styles as $token => $description) {
    $styles['rows'][] = array($token, $description);
  }
  $form['possible_image_styles'] = array(
    '#type' => 'select',
    '#title' => t('Available image styles'),
    '#description' => t('Possible styles for image fields'),
    '#options' => image_style_options(),
    '#default_value' => $conf['possible_image_styles'],
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

function portales7_image_vocabulary_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
