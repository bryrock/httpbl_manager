<?php
/**
 * @file
 * Views exposure for http:BL Manager.
 *
 * @author Bryan Lewellen (bryrock)
 * @link http://drupal.org/project/httpbl
 * @link http://httpbl.org/
 *
 */

/**
 * Implements hook_views_data().
 */
function httpbl_manager_views_data() {
}

/**
 * Implements hook_views_data_alter(&$data).
 */
function httpbl_manager_views_data_alter(&$data) {
  //dpm($data, '$data');
  //dpm($data['httpbl'], '$data httpbl');
  //dpm($data['entity_httpbl'], '$data entity_httpbl');
  
  // Grab the defaults for the new columns that Views API makes.
  $data['httpbl']['httpbl_id'] = $data['entity_httpbl']['httpbl_id'];
  $data['httpbl']['type'] = $data['entity_httpbl']['type'];
  $data['httpbl']['language'] = $data['entity_httpbl']['language'];
  $data['httpbl']['domain'] = $data['entity_httpbl']['domain'];
  $data['httpbl']['uid'] = $data['entity_httpbl']['uid'];
  $data['httpbl']['created'] = $data['entity_httpbl']['created'];
  $data['httpbl']['modified'] = $data['entity_httpbl']['modified'];

  // Alter as needed.

  // Define this as a base field.
  $data['httpbl']['table']['base']['field'] = 'httpbl_id';

  $data['httpbl']['hostname']['title'] = t('Host IP');
  $data['httpbl']['httpbl_id']['title'] = t('http:bl ID');
  $data['httpbl']['httpbl_id']['help'] = t('The unique ID of the managed host ip.');
  $data['httpbl']['httpbl_id']['field']['handler'] = 'views_handler_field_numeric';
  $data['httpbl']['status']['help'] = t('Indicates White (0), Black (1) or Grey (2) listed.');
  $data['httpbl']['type']['field']['handler'] = 'views_handler_field';
  $data['httpbl']['language']['field']['handler'] = 'views_handler_field';
  $data['httpbl']['domain']['field']['handler'] = 'views_handler_field';
  $data['httpbl']['uid']['field']['handler'] = 'views_handler_field_user';
  $data['httpbl']['created']['field']['handler'] = 'views_handler_field_date';
  $data['httpbl']['modified']['field']['handler'] = 'views_handler_field_date';

}
