<?php

/**
 * @file
 * Page stuff for Article entities.
 */

/**
 * Page callback for artwork/add.
 */
function artwork_add_page() {
  $item = menu_get_item();
  $links = system_admin_menu_block($item);

  foreach ($links as $link) {
    $items[] = l($link['title'], $link['href'],
      $item['localized_options']) . ': ' . filter_xss_admin($link['description']);
  }

  return theme('item_list', array('items' => $items));
}

/**
 * Page callback for artwork/add/%artwork_type.
 */
function artwork_add($type) {
  global $user;

  $types = artwork_types();
  $type = isset($type) ? str_replace('-', '_', $type) : NULL;
  if (empty($types[$type])) {
    return MENU_NOT_FOUND;
  }

  $artwork = entity_get_controller('artwork')->create($type);
  drupal_set_title(t('Create @name', array('@name' => $types[$type]->name)), PASS_THROUGH);

  return drupal_get_form($type . '_artwork_form', $artwork);
}
