<?php
/*function portales7_admin() {
  $form = array();
  
  $form['portales7_EL_name'] = array(
    '#type' => 'textfield',
    '#title' => 'Name',
    '#description' => t('City council official name'),
    '#default_value' => variable_get('portales7_EL_name', 'UNCONFIGURED'),
    '#required' => TRUE,
  );
  $form['portales7_EL_address'] = array(
    '#type' => 'textfield',
    '#title' => 'address',
    '#default_value' => variable_get('portales7_EL_address', ''),
    '#required' => TRUE,
  );
  
  $form['portales7_EL_city'] = array(
    '#type' => 'textfield',
    '#title' => 'City',
    '#description' => t('City name'),
    '#default_value' => variable_get('portales7_EL_city', ''),
    '#required' => TRUE,
  );
  $form['portales7_EL_zip'] = array(
    '#type' => 'textfield',
    '#title' => 'ZIP',
    '#description' => t('ZIP code'),
    '#default_value' => variable_get('portales7_EL_zip', ''),
    '#required' => TRUE,
  );
  $form['portales7_EL_cif'] = array(
    '#type' => 'textfield',
    '#title' => 'CIF',
    '#description' => t('City council CIF'),
    '#default_value' => variable_get('portales7_EL_cif', ''),
  );
  
  $form['portales7_EL_signature'] = array(
    '#type' => 'textarea',
    '#title' => 'Signature',
    '#description' => t('The former footer message'),
    '#default_value' => variable_get('portales7_EL_signature'),
  );
  
  return system_settings_form($form);
}
 * */
 
function portales7_logos() {
  $settings = variable_get('theme_portales7_theme_settings', array());
  //dsm($settings);
  $logo = theme_get_setting('logo_path', 'portales7_theme');
  $favicon = theme_get_setting('favicon_path', 'portales7_theme');
  $logo_fid = '';
  $favicon_fid = '';
  $res = db_query('select fid from {file_managed} where uri = :uri', array(':uri' => $logo));
  if ($fid = $res->fetchField(0)) {
    $logo_fid = $fid;
  }
  $res = db_query('select fid from {file_managed} where uri = :uri', array(':uri' => $favicon));
  if ($fid = $res->fetchField(0)) {
    $favicon_fid = $fid;
  }
  $form['site_logo'] = array(
    '#type' => 'managed_file',
    '#title' => t('Site logo'),
    '#default_value' => $logo_fid > 0 ?  $logo_fid : NULL,
    '#description' => t('Currently set to %path', array('%path' => $logo)),
  );
  $form['favicon'] = array(
    '#type' => 'managed_file',
    '#title' => t('Link icon'),
    '#description' => t('Currently set to %path', array('%path' => $favicon)),
    '#default_value' => $favicon_fid > 0 ? $favicon_fid : NULL,
  );
  $form['old_site_logo'] = array(
    '#type' => 'value',
    '#value' => $logo_fid,
  );
  $form['old_favicon'] = array(
    '#type' => 'value',
    '#value' => $favicon_fid,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
  );
  return $form;
}

function portales7_logos_submit($form, &$form_state){
  $changed = FALSE;
  global $user;
  $settings = variable_get('theme_portales7_theme_settings', array());
  if ($form_state['values']['old_site_logo'] != $form_state['values']['site_logo']){
    if ($form_state['values']['site_logo']) {
      $file = file_load($form_state['values']['site_logo']);
      $file->status = FILE_STATUS_PERMANENT;
      if ($file = file_move($file, 'public://')) {
        file_usage_add($file, 'portales7', 'portales7', $user->uid);
        $settings['logo_path'] = $file->uri;
        $changed = TRUE;
      }
      else {
        drupal_set_message(t("Can't reference site logo"), 'error');
      }
    }
    else if ($form_state['values']['site_logo'] === 0){
      drupal_set_message('empty site_logo', 'status');
      $settings['logo_path'] = '';
      $changed = TRUE;
    }
    if ($form_state['values']['old_site_logo'] > 0 && $old_site_logo = file_load($form_state['values']['old_site_logo'])) {
      file_usage_delete($old_site_logo);
      if (db_query('select sum(count) as ctd from {file_usage} where fid = :fid', array(':fid' => $form_state['values']['old_site_logo']))->fetchField(0) === 0) {
        file_delete($old_site_logo);
      }
    }
  }
  
  if ($form_state['values']['old_favicon'] != $form_state['values']['favicon']){
    if ($form_state['values']['favicon']) {
      $file = file_load($form_state['values']['favicon']);
      $file->status = FILE_STATUS_PERMANENT;
      if ($file = file_move($file, 'public://')) {
        file_usage_add($file, 'portales7', 'portales7', $user->uid);
        $settings['favicon_path'] = $file->uri;
        $settings['favicon_mimetype'] = $file->mimetype;
        $changed = TRUE;
      }
      else {
        drupal_set_message(t("Can't reference favicon"), 'error');
      }
    }
    else if($form_state['values']['favicon'] === 0){
      $settings['favicon_path'] = '';
      $changed = TRUE;
    }
    
    if ($form_state['values']['old_favicon'] > 0 && $old_favicon = file_load($form_state['values']['old_favicon'])) {
      file_usage_delete($old_favicon);
      if (db_query('select sum(count) as ctd from {file_usage} where fid = :fid', array(':fid' => $form_state['values']['old_favicon']))->fetchField(0) === 0) {
        file_delete($old_favicon);
      }
    }
  }
  if ($changed) {
    variable_set('theme_portales7_theme_settings', $settings);
  }
}
