<?php
function _portales7_majordomo_add_subscriber($email, $list = 'default') {
  $now = $_SERVER['REQUEST_TIME'];
  $passwd = substr(md5($now),0,8);
  $activation_code = substr(md5($now), 15, 16);
  
  $edit = array(
    'email' => $email,
    'pass' => $passwd,
    'active' => 0,
    'created' => $now,
    'updated' => $now,
    'activation_code' => $activation_code,
    
  );    
  $sid = db_insert('subscriptions')
    ->fields(array(
      'email' => $email,
      'pass' => $passwd,
      'active' => 0,
      'created' => $now,
      'updated' => $now,
      'activation_code' => $activation_code,
    ))
    ->execute();
  
  $site_name = variable_get('site_name','');
  $language = language_default();
    
  global $base_url;
  
  #$insert = array('sid' => $sid, 'ruta' => $cod_activacion);
  #drupal_write_record('suscripciones_activacion', $insert);
  
  
  $substitutions = array(
    '!site_name' => $site_name,
    '!email' => $email,
    '!password' => $passwd,
    '!activation_link' => $base_url.'/portales7/activate-subscription/'.$activation_code,
  );
    
  if(!empty($email)){
    $message = array(
        'id' => 'portales7_majordomo-activation',
        'to' => $email,
        'subject' => _portales7_majordomo_default_text('portales7_majordomo_subscription_subject', $substitutions),
        'body' =>array(_portales7_majordomo_default_text('portales7_majordomo_subscription_body', $substitutions)),
        'headers' => array(
          'MIME-Version' => '1.0', 
          'Content-Type' => 'text/plain; charset=UTF-8; format=flowed; delsp=yes', 
          'Content-Transfer-Encoding' => '8Bit', 
          'X-Mailer' => 'Portales 7 for Drupal',
        ),
    );
    
    
    if(module_exists('smtp')){
      $from = variable_get('smtp_from', '');
    }else{
      $from = variable_get('site_email', '');
    }
    
    $message['from'] = $from;
    
    $system = drupal_mail_system('portales7_majordomo', 'subscribe');
    $message = $system->format($message);
    
    if ($system->mail($message)) {
      // Success.
      drupal_set_message(t('An activation message has been sent to @email. If you don\'t receive it in a few minutes, check your SPAM folder.', array('@email' => $email)), 'status');
    }
    else {
      // Failure.
      drupal_set_message(t('Can\'t send message. Check logs'));
    }
  
    #drupal_mail('portales7_majordomo', 'subscribe', $message['to'], $language, $message, $message['from'], TRUE);
    
  }
  
  $form_state['redirect'] = 'suscripciones/login';
  return TRUE;
}

function _portales7_majordomo_email_validate($element, &$form_state){
  if(!valid_email_address($element['#value'])){
    form_error($element, t('Enter a valid email address.'));
  }
}

function _portales7_majordomo_password_validate($element, &$form_state){
  if(empty($element['#value'])){
    $form_state['values']['portales7_majordomo_password'] = variable_get('portales7_majordomo_password', '');
  }
}


function _portales7_majordomo_default_text($key, $variables = array()){
  if ($admin_setting = variable_get($key, FALSE)) {
      return strtr($admin_setting, $variables);
  }else{
    switch ($key) {
      case 'portales7_majordomo_subscription_subject':
        return t('!site_name subscription', $variables);
      case 'portales7_majordomo_subscription_body':
        return t("Welcome to the Email Service at !site_name.\nYour account has been created successfully.\n\nThe account details are:\nEmail: !email \nPassword: !password \n\nTo activate your account, please follow this link: \n!activation_link\n\nIf the link does not work, copy and paste this address in your browser.", $variables);
      case 'portales7_majordomo_password_remind_subject':
        return t('Password reminder for !site_name', $variables);
      case 'portales7_majordomo_password_remind_body':
        return t("Your subscription passwrod has been reset on !site_name:\nEmail: !email\nPassword: !password", $variables);
    }
  }
}

function _portales7_majordomo_activate_subscription($activation_code) {
  $affected = db_update('subscriptions')
    ->fields(array(
      'active' => 1, 
    ))
    ->condition('activation_code', $activation_code, '=')
    ->execute();
  if (($subscription = db_query('SELECT * FROM {subscriptions} WHERE activation_code = :actcode', array(':actcode' => $activation_code))->fetchObject()) !== FALSE){
    if ($subscription->active) {
      _portales7_majordomo_send_subscription_email($subscription->email);
      return $subscription->email;
    }
    else {
    	drupal_set_message(t('Your subscription can\'t be activated at this moment. Please try again later.'));
      return FALSE;
    }
  }
  else {
   drupal_set_message(t('Invalid activation link. Please, subscribe again.'), 'error');
	 return FALSE;
  }
}

function _portales7_majordomo_send_subscription_email($email){
$lista = variable_get('portales7_majordomo_list_name','');
$majordomo = variable_get('portales7_majordomo_majordomo','');
$majordomo_passwd = variable_get('portales7_majordomo_majordomo_password', '');
$body = <<< EOD
approve $majordomo_passwd \
subscribe lista \
$email
EOD;

  $message = array(
      'id' => 'portales7_majordomo-subscribe',
      'to' => $majordomo,
      'bcc' => 'juanjo@digitalvalue.es',
      'subject' => 'Subscribe to list',
      'body' =>array($body),
      'headers' => array(
        'MIME-Version' => '1.0', 
        'Content-Type' => 'text/plain; charset=UTF-8; format=flowed; delsp=yes', 
        'Content-Transfer-Encoding' => '8Bit', 
        'X-Mailer' => 'Portales 7 for Drupal',
        'Reply-To' => 'juanjo@digitalvalue.es',
        'BCC' => 'juanjo@digitalvalue.es',
      ),
  );
  
  $from = sprintf("%s <%s>", variable_get('site_name'), variable_get('site_email'));
   
  $message['from'] = $from;
  
  $system = drupal_mail_system('portales7_majordomo', 'subscribe');
  $message = $system->format($message);
  //dsm($message,__FUNCTION__);
  if ($system->mail($message)) {
    // Success.
    return TRUE;
  }
  else {
    // Failure.
    drupal_set_message(t('Can\'t send activation message. Check logs'));
    return FALSE;
  }
}
