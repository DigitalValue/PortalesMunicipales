<?php
/**
 * @file
 * Provides a content-type plugin to show contents of imagefield field.
 * /

 * /**
* Plugins are described by creating a $plugin array which will be used
* by the system that includes this file.
*/
$plugin = array(
  'title' => t('Advanced slideshow'),
  'description' => t('Provides an slideshow of several nodes.'),
  'single' => TRUE,
  'content_types' => array('portales7_slideshow_advslide_content_type'),
  'render callback' => 'portales7_slideshow_advslide_content_type_render',
  'defaults' => array('type' => '', 'classification' => '', 'image_link' => FALSE, 'image_style' => '', 'inlinetitle' => TRUE, 'effect' => 'blindX', 'speed' => 1000, 'timeout' => 4000, 'showcontrols' => FALSE),
  'edit form' => 'portales7_slideshow_advslide_content_type_edit_form',

// Icon goes in the directory with the content type.
  'icon' => 'icon_slideshow.png',
  'category' => t('Portales 7'),

);
 

// The function name is MODULE_NAME_CT_NAME_content_type_render
function portales7_slideshow_advslide_content_type_render($subtype, $conf, $panel_args, $context) {
  $args = explode(',', $conf['classification']);
  $view_args = json_encode(array('media' => array('formatter' => 'raw', 'settings' => array('image_style' => $conf['image_style']))));
  $view = _portales7_listado_prepare_view($conf['type'], $args, $view_args, 0, 0);
  $view->execute_display('default', $args);
  $elements['items'] = array();
  $elements['conf'] = $conf;
  foreach($view->result as $r) {
    foreach($r->field_portales7_media as $fc_media) {
      $fc_items = entity_load('field_collection_item', array($fc_media['raw']['value']));
      $fc_item = array_shift($fc_items);
      if (!empty($fc_item->portales7_images['und'])) {
        foreach ($fc_item->portales7_images['und'] as $image) {
          $image['nid'] = $r->nid;
          $elements['items'][] = $image;
        }
      }
    }
  }
  $elements['classes'] = array('portales7-slideshow-' . $conf['image_style']);
  $pane = new stdClass();
  $pane->content = theme('portales7_slideshow', $elements);
  return $pane;
}


/**
 * Returns an edit form for the custom type.
 */
// The function name is <code>MODULE_NAME_CT_NAME_content_type_edit_form
function portales7_slideshow_advslide_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $types = dvtoolbox_get_taxonomy_options('type');
  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#description' => t('Article type to show'),
    '#default_value' => $conf['type'],
    '#options' => $types,
    '#required' => TRUE,
  );

  $form['classification'] = array(
    '#type' => 'textfield',
    '#title' => t('Category'),
    '#description' => t('Category to filter out nodes'),
    '#default_value' => $conf['classification'],
    '#required' => TRUE,
  );

  $form['image_link'] = array(
    '#type' => 'checkbox',
    '#title' => t('Link'),
    '#description' => t('Link image to the content'),
    '#return_value' => 'node',
    '#default_value' => $conf['image_link'],
  );
  
  $form['slideshow'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slideshow options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
  );
  
  $image_styles = image_style_options(TRUE);
  $form['slideshow']['image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image style'),
    '#options' => $image_styles,
    '#default_value' => $conf['image_style'],
    '#description' => t('Select the image style to use with images'),
  );
  
  $form['slideshow']['inlinetitle'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show image title'),
    '#description' => t('Show image title'),
    '#return_value' => 1,
    '#default_value' => $conf['inlinetitle'],
  );
  $form['slideshow']['effect'] = array(
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Transition effect'),
    '#description' => t('Choose wich transition effect slideshow will use'),
    '#options' => _portales7_slideshow_available_effects(),
    '#default_value' => $conf['effect'],
  );
  $form['slideshow']['timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('Duration'),
    '#description' => t('How much time, in milliseconds, will be shown every item.'),
    '#default_value' => $conf['timeout'],
    '#required' => TRUE,
  );
  $form['slideshow']['speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Speed'),
    '#description' => t('Duration, in milliseconds, of the transition effect.'),
    '#default_value' => $conf['speed'],
    '#required' => TRUE,
  );
  $form['slideshow']['showcontrols'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show controls'),
    '#description' => t('Show controls at the bottom of the slideshow'),
    '#default_value' => $conf['showcontrols'],
    '#return_value' => 1,
  );

  return $form;

}

function portales7_slideshow_advslide_content_type_edit_form_submit(&$form, &$form_state) {
  // For each part of the form defined in the 'defaults' array set when you
  // defined the content type, copy the value from the form into the array
  // of items to be saved. We don't ever want to use
  // $form_state['conf'] = $form_state['values'] because values contains
  // buttons, form id and other items we don't want stored. CTools will handle
  // the actual form submission.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function portales7_slideshow_advslide_content_type_admin_title($subtype, $conf, $context) {
  if (!empty($conf['admin_title'])) return $conf['admin_title'];
  return t('Advanced slideshow pane');
}

function portales7_slideshow_advslide_content_type_admin_info($subtype, $conf, $context) {
  $pane = new stdClass();
  $pane->title = portales7_slideshow_advslide_content_type_admin_title($subtype, $conf, $context);
  $pane->content = '<pre>' . print_r($conf, 1) . '</pre>';
  return $pane;
}
