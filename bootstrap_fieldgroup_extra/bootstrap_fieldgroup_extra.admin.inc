<?php 

function bootstrap_fieldgroup_extra_admin_form($form, &$form_state) {
  
  $transliteration_disabled = true;
  if (module_exists('transliteration')) {
    $transliteration_disabled = false;
  }
  
  $form['bootstrap_fieldgroup_id_transl'] = array(
    '#type' => 'checkbox',
    '#title' => t('Transliterate fieldgroup ID'),
    '#description' => t('Transliterate Bootstrap fieldgroup tab ID with transliterate module. Transliteration module must be enabled to use this functionality.'),
    '#disabled' => $transliteration_disabled,
    '#default_value' => variable_get('bootstrap_fieldgroup_transl'),
  );
  
  $form['bootstrap_fieldgroup_history'] = array(
    '#type' => 'checkbox',
    '#title' => t('Turn on Bootstrap fieldgroup tabs history'),
    '#description' => t('Add Bootstrap fieldgroup tabs history.'),
    '#default_value' => variable_get('bootstrap_fieldgroup_history'),
  );
  
  $form['#submit'][] = 'bootstrap_fieldgroup_extra_admin_form_submit';
  
  return system_settings_form($form);
}

function bootstrap_fieldgroup_extra_admin_form_submit($form, &$form_state) {
  //$form_state['values']['bootstrap_fieldgroup_id_transl']
  //$form_state['values']['bootstrap_fieldgroup_history']
  if ($form_state['values']['bootstrap_fieldgroup_id_transl']) {
    drupal_set_message(t('Transliterate Bootstrap fieldgroup ID turned on.'));
    variable_set('bootstrap_fieldgroup_transl', TRUE);
  } else if (variable_get('bootstrap_fieldgroup_transl') && 
             !$form_state['values']['bootstrap_fieldgroup_id_transl']) {
    drupal_set_message(t('Transliterate Bootstrap fieldgroup ID turned off.'));
    variable_set('bootstrap_fieldgroup_transl', FALSE);
  }
    
  if ($form_state['values']['bootstrap_fieldgroup_history']) {
    drupal_set_message(t('Bootstrap fieldgroup history turned on.'));
    variable_set('bootstrap_fieldgroup_history', TRUE);
  } else if (variable_get('bootstrap_fieldgroup_history') && 
             !$form_state['values']['bootstrap_fieldgroup_history']) {
    drupal_set_message(t('Bootstrap fieldgroup history turned off.'));
    variable_set('bootstrap_fieldgroup_history', FALSE);
  }
}