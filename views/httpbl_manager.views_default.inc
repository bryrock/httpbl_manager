<?php

/**
 * @file
 * VBO Views for http:BL Manager.
 *
 * VBO management for entities created from http:BL cache table. 
 *
 * @author Bryan Lewellen (bryrock)
 * @link http://drupal.org/project/httpbl
 * @link http://httpbl.org/
 *
 */
 
function httpbl_manager_views_default_views() {
  $view = new view();
  $view->name = 'http_bl_manager';
  $view->description = 'VBO management for entities created from http:BL cache table.';
  $view->tag = 'http:BL';
  $view->base_table = 'httpbl';
  $view->human_name = 'http:BL Manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'http:BL Manager';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'admin httpbl manager ips';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'httpbl_id' => 'httpbl_id',
    'hostname' => 'hostname',
    'status' => 'status',
    'expire' => 'expire',
    'created' => 'created',
    'modified' => 'modified',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'httpbl_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hostname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expire' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'modified' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = 'These are all OR filters.';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Field: Bulk operations: HttpBL */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'httpbl';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operation';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::httpbl_manager_notation_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Notes',
    ),
    'action::httpbl_manager_change_expiry_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Extend Expiry',
    ),
    'action::httpbl_manager_change_listing_status_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'White / Grey or Blacklisting (use with caution!)',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete a managed IP',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_queue_operations_item_delete_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => 'buns',
      ),
    ),
    'action::views_queue_operations_item_release_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: HttpBL: Host IP */
  $handler->display->display_options['fields']['hostname']['id'] = 'hostname';
  $handler->display->display_options['fields']['hostname']['table'] = 'httpbl';
  $handler->display->display_options['fields']['hostname']['field'] = 'hostname';
  /* Field: HttpBL: Domain */
  $handler->display->display_options['fields']['domain']['id'] = 'domain';
  $handler->display->display_options['fields']['domain']['table'] = 'httpbl';
  $handler->display->display_options['fields']['domain']['field'] = 'domain';
  $handler->display->display_options['fields']['domain']['label'] = 'Domain / Notes';
  /* Field: HttpBL: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'httpbl';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['separator'] = '';
  /* Field: HttpBL: Expires */
  $handler->display->display_options['fields']['expire']['id'] = 'expire';
  $handler->display->display_options['fields']['expire']['table'] = 'httpbl';
  $handler->display->display_options['fields']['expire']['field'] = 'expire';
  $handler->display->display_options['fields']['expire']['date_format'] = 'medium';
  $handler->display->display_options['fields']['expire']['second_date_format'] = 'long';
  /* Field: HttpBL: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'httpbl';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['empty'] = '(http:BL)';
  $handler->display->display_options['fields']['uid']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = FALSE;
  /* Field: HttpBL: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'httpbl';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['empty'] = '(from honeypot.org)';
  $handler->display->display_options['fields']['created']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: HttpBL: Modified */
  $handler->display->display_options['fields']['modified']['id'] = 'modified';
  $handler->display->display_options['fields']['modified']['table'] = 'httpbl';
  $handler->display->display_options['fields']['modified']['field'] = 'modified';
  $handler->display->display_options['fields']['modified']['empty'] = '(from honeypot.org)';
  $handler->display->display_options['fields']['modified']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['modified']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['modified']['date_format'] = 'short';
  $handler->display->display_options['fields']['modified']['second_date_format'] = 'long';
  /* Field: HttpBL: http:bl ID */
  $handler->display->display_options['fields']['httpbl_id']['id'] = 'httpbl_id';
  $handler->display->display_options['fields']['httpbl_id']['table'] = 'httpbl';
  $handler->display->display_options['fields']['httpbl_id']['field'] = 'httpbl_id';
  $handler->display->display_options['fields']['httpbl_id']['label'] = 'Httpbl ID';
  $handler->display->display_options['fields']['httpbl_id']['separator'] = '';
  /* Field: HttpBL: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'httpbl';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['exclude'] = TRUE;
  /* Field: HttpBL: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'httpbl';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );
  /* Filter criterion: HttpBL: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'httpbl';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Whitelisted',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Greylisted',
      'operator' => '=',
      'value' => array(
        'value' => '2',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => 'Blacklisted',
      'operator' => '=',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: HttpBL: Host IP */
  $handler->display->display_options['filters']['hostname']['id'] = 'hostname';
  $handler->display->display_options['filters']['hostname']['table'] = 'httpbl';
  $handler->display->display_options['filters']['hostname']['field'] = 'hostname';
  $handler->display->display_options['filters']['hostname']['group'] = 1;
  $handler->display->display_options['filters']['hostname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hostname']['expose']['operator_id'] = 'hostname_op';
  $handler->display->display_options['filters']['hostname']['expose']['label'] = 'Host IP';
  $handler->display->display_options['filters']['hostname']['expose']['operator'] = 'hostname_op';
  $handler->display->display_options['filters']['hostname']['expose']['identifier'] = 'hostname';
  $handler->display->display_options['filters']['hostname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['hostname']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['hostname']['group_info']['label'] = 'Host IP';
  $handler->display->display_options['filters']['hostname']['group_info']['identifier'] = 'hostname';
  $handler->display->display_options['filters']['hostname']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Localhost',
      'operator' => '=',
      'value' => '127.0.0.1',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: HttpBL: Host IP */
  $handler->display->display_options['filters']['hostname_1']['id'] = 'hostname_1';
  $handler->display->display_options['filters']['hostname_1']['table'] = 'httpbl';
  $handler->display->display_options['filters']['hostname_1']['field'] = 'hostname';
  $handler->display->display_options['filters']['hostname_1']['group'] = 1;
  $handler->display->display_options['filters']['hostname_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hostname_1']['expose']['operator_id'] = 'hostname_1_op';
  $handler->display->display_options['filters']['hostname_1']['expose']['label'] = 'This IP';
  $handler->display->display_options['filters']['hostname_1']['expose']['description'] = 'Search a specific ip';
  $handler->display->display_options['filters']['hostname_1']['expose']['operator'] = 'hostname_1_op';
  $handler->display->display_options['filters']['hostname_1']['expose']['identifier'] = 'hostname_1';
  $handler->display->display_options['filters']['hostname_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: HttpBL: Expires */
  $handler->display->display_options['filters']['expire']['id'] = 'expire';
  $handler->display->display_options['filters']['expire']['table'] = 'httpbl';
  $handler->display->display_options['filters']['expire']['field'] = 'expire';
  $handler->display->display_options['filters']['expire']['group'] = 1;
  $handler->display->display_options['filters']['expire']['exposed'] = TRUE;
  $handler->display->display_options['filters']['expire']['expose']['operator_id'] = 'expire_op';
  $handler->display->display_options['filters']['expire']['expose']['label'] = 'Expires';
  $handler->display->display_options['filters']['expire']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['expire']['expose']['operator_label'] = 'mm-dd-yyyy';
  $handler->display->display_options['filters']['expire']['expose']['operator'] = 'expire_op';
  $handler->display->display_options['filters']['expire']['expose']['identifier'] = 'expire';
  $handler->display->display_options['filters']['expire']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/config/people/httpbl-manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'http:BL Manager';
  $handler->display->display_options['menu']['description'] = 'Manage IPs cached by http:BL.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'httpbl';
  $handler->display->display_options['tab_options']['weight'] = '0';

  $views[$view->name] = $view;
  return $views;
}
