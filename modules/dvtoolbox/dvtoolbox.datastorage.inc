<?php
/**
 * @file
 * This file contains functions to provide datastorage
 * feature
 * @author Juanjo Garcia <juanjo@digitalvalue.es>
 * @author Digital Value, SL <info@digitalvalue.es>
 */

/**
 * Callback function to save data
 */
function dvtoolbox_data_save() {
  global $user;
  $data = base64_encode($_POST['value']);
  $key = check_plain($_POST['name']);
  
  $res = db_merge('dvtoolbox_datastorage')
    ->key(array('uid' => $user->uid, 'name' => $key))
    ->fields(array('value' => $data))
    ->execute();
  drupal_json_output(array('status' => $res));
}

/**
 * Calllback function to retrieve data
 */
function dvtoolbox_data_get() {
  global $user;
  $key = check_plain($_POST['name']);
  if ($data = db_select('dvtoolbox_datastorage', 'ds')
    ->fields('ds', array())
    ->condition('uid', $user->uid)
    ->condition('name', $key)
    ->execute()
    ->fetch(PDO::FETCH_ASSOC)
  ) {
    $data['value'] = base64_decode($data['value']);
    $data['status'] = 1;
    drupal_json_output($data);
  }
  else {
    drupal_json_output(array('status' => 0));
  }
}

function dvtoolbox_data_delete() {
  global $user;
  $key = check_plain($_POST['name']);
  $res = db_delete('dvtoolbox_datastorage')->condition('uid', $user->uid)->condition('name', $key)->execute();
  drupal_json_output(array('res' => $res));
}
