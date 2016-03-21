<?php
function portales7_node_push_setup($form_state) {
  $form = array();
  $form['portales7_node_push_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable push notifications'),
    '#default_value' => variable_get('portales7_node_push_enabled', FALSE),
  );
  $form['portales7_node_push_app'] = array(
    '#type' => 'textfield',
    '#title' => t('App ID'),
    '#default_value' => variable_get('portales7_node_push_app', ''),
    '#required' => TRUE,
  );
  $form['portales7_node_push_tag'] = array(
    '#type' => 'textfield',
    '#title' => t('Tag name'),
    '#default_value' => variable_get('portales7_node_push_tag', ''),
    '#description' => t('This identifies the site on multisite apps, left blank if you are using a standalone app.'),
  );
  $form['portales7_node_auth_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Auth token'),
    '#default_value' => variable_get('portales7_node_auth_token', ''),
    '#required' => TRUE,
  );
  $form['portales7_node_push_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Push server'),
    '#default_value' => variable_get('portales7_node_push_url', 'http://push.digitalvalue.es:8090/v1/pushes/push'),
    '#required' => TRUE,
  );
  $form['portales7_node_push_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Prefix'),
    '#description' => t('This text will be prefixed to node title. You can use <em>!date</em> to include current date.'),
    '#default_value' => variable_get('portales7_node_push_prefix', ''),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
