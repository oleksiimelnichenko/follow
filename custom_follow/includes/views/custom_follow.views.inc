<?php

/**
 * Implements hook_views_data().
 */
function custom_follow_views_data() {

  $data = array();

  $data['custom_follow']['table']['group'] = t('Custom Follow');

  $data['custom_follow']['table']['base'] = array(
    'title' => t('Custom Follow'),
    'help' => t('Contains records we want exposed to Views.'),
  );

  $data['custom_follow']['id_cf'] = array(
    'title' => t('The primary identifier'),
    'help' => t('The primary identifier for a record.'),
    'label' => t('The primary identifier'),
  );

  $data['custom_follow']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['custom_follow']['uid'] = array(
    'title' => t('User'),
    'help' => t('Some example content that references a node.'),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
    ),
  );

  $data['custom_follow']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'follower_uid',
    ),
  );

  $data['custom_follow']['follower_uid'] = array(
    'title' => t('Follower'),
    'help' => t('Some example content that references a node.'),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Follower'),
    ),
  );

  $data['custom_follow']['id_cf'] = array(
    'title' => t('ID'),
    'help' => t('Just a numeric field.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;

}