<?php

/**
 * @file
 * Tag1quo drush commands.
 */

/**
 * Implements hook_drush_command().
 */
function tag1quo_drush_command() {
  $items = array();

  $items['send-heartbeat'] = array(
    'description' => "Send heartbeat to Tag1 Quo server.",
    'examples' => array(
      'drush send-heartbeat' => 'Send heartbeat to Tag1 Quo server',
    ),
    'aliases' => array('ph', 'phone-home'),
  );

  return $items;
}

/**
 * Implementation of drush send-heartbeat
 */
function drush_tag1quo_send_heartbeat() {
  $result = tag1quo_send_report();
  if (empty($result->error)) {
    drupal_set_message('Module status reported to Tag1 Quo.');
  } else {
      drupal_set_message('Failed to send heartbeat - see logs for details.');
  }
}
