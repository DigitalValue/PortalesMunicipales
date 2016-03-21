<?php
function _dvtoolbox_fakeupdate_160104_1() {
  $code = substr(__FUNCTION__, 22);
  if (!variable_get('fakeupdate-' . $code, FALSE)) {
    require(drupal_realpath(drupal_get_path('module', 'portales7_profile')) . '/portales7_profile.permissions.inc');
    dvtoolbox_grant_permissions($permissions);
    drupal_set_message(t('Code @code executed', array('@code' => __FUNCTION__)), 'status');
    variable_set('fakeupdate-' . $code, TRUE);
    return "fakeupdate-" . $code;
  }
  else {
    drupal_set_message(t('Code @code already executed', array('@code' => __FUNCTION__)), 'status');
  }
}
