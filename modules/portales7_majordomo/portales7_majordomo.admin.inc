<?php
module_load_include('inc', 'portales7_majordomo', 'portales7_majordomo.util');
function portales7_majordomo_admin() {
  $pass = variable_get('portales7_majordomo_majordomo_password');
  $form = array();
  
  $form['portales7_majordomo_majordomo'] = array(
    '#type' => 'textfield',
    '#title' => t('Majordomo address'),
    '#default_value' => variable_get('portales7_majordomo_majordomo', 'majordomo@example.com'),
    '#maxlength' => 255,
    '#required' => TRUE,
    '#element_validate' => array('_portales7_majordomo_email_validate'),
    '#description' => t('Enter the Majordomo Manager email address.'),
  );
  $form['portales7_majordomo_majordomo_password'] = array(
    '#type' => 'password',
    '#title' => t('List manager password.'),
    '#default_value' => $pass,
    '#maxlength' => 60,
    '#required' => empty($pass),
    '#element_validate' => array('_portales7_majordomo_password_validate'),
    '#description' => t('Enter the password for list manager. The user sending emails from this site must be authorized to subscribe users.'),
  );
  $form['portales7_majordomo_list_name'] = array(
    '#type' => 'textfield',
    '#title' => t('List name'),
    '#default_value' => variable_get('portales7_majordomo_list_name', 'my-list'),
    '#maxlength' => 255,
    '#required' => TRUE,
    '#description' => t('Enter the distribution list name.'),
  );
  $form['portales7_majordomo_list_address'] = array(
    '#type' => 'textfield',
    '#title' => t('List address'),
    '#default_value' => variable_get('portales7_majordomo_list_address', 'my-list@example.com'),
    '#maxlength' => 255,
    '#required' => TRUE,
    '#element_validate' => array('_portales7_majordomo_email_validate'),
    '#description' => t('Enter the distribution list address.'),
  );  

  
  $form['email_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Opciones de correo de BandoEmail'),              
    '#collapsible' => FALSE, 
  );
  
  
  $desc = <<< EOD
Customize message for the new subscriber. You can use the following replacements:
<ul><li><em>!site_name</em> Site name (as configured on site informattion)</li>
<li><em>!email</em> Email address subscribed</li>
<li><em>!password</em> Subscriber password</li>
<li><em>!activation_link</em> Activation link for subscription confirmation</li>
</ul>
EOD;
  
  $form['email_options']['portales7_majordomo_new_subscriber'] = array(
    '#type' => 'fieldset',
    '#title' => t('New subscriber account'),              
    '#collapsible' => TRUE,
    '#description' => t($desc),
    '#collapsed' => TRUE,
  );
  
  $form['email_options']['portales7_majordomo_new_subscriber']['portales7_majordomo_subscription_subject'] = array(
    '#type' => 'textfield',
      '#title' => t('Subject'),
    '#default_value' => _portales7_majordomo_default_text('portales7_majordomo_subscription_subject'),
      '#maxlength' => 180,
  );
    
  $form['email_options']['portales7_majordomo_new_subscriber']['portales7_majordomo_subscription_body'] = array(
      '#type' => 'textarea',
      '#title' => t('Body'),
      '#default_value' => _portales7_majordomo_default_text('portales7_majordomo_subscription_body'),
      '#rows' => 10,
  );
  
  
  $form['email_options']['portales7_majordomo_password_remind'] = array(
    '#type' => 'fieldset',
    '#title' => t('Password reminder'),              
    '#collapsible' => TRUE,
    '#description' => t($desc),
    '#collapsed' => TRUE,
  );
  
  $form['email_options']['portales7_majordomo_password_remind']['portales7_majordomo_password_remind_subject'] = array(
    '#type' => 'textfield',
      '#title' => t('Subject'),
      '#default_value' => _portales7_majordomo_default_text('portales7_majordomo_password_remind_subject'),
      '#maxlength' => 180,
  );
  
  $form['email_options']['portales7_majordomo_password_remind']['portales7_majordomo_password_remind_body'] = array(
      '#type' => 'textarea',
      '#title' => t('Body'),
      '#default_value' => _portales7_majordomo_default_text('portales7_majordomo_password_remind_body'),
      '#rows' => 10,
  );
  
  
  
  return system_settings_form($form);
}
