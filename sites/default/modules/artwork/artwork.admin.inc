<?php


/**
 * Page callback for admin/structure/artworks.
 *
 * @see artwork_menu()
 */
function artwork_overview_types() {
  foreach (artwork_types() as $type => $info) {
    $type_url_str = str_replace('_', '-', $type);
    $label = t('View @type', array('@type' => $info->name));
    $items[] = l($label, 'admin/structure/artworks/manage/' . $type_url_str);
  }

  return theme('item_list', array('items' => $items));
}

/**
 * Title callback for admin/structure/artworks/manage/%artwork_type.
 *
 * @see artwork_menu()
 */
function artwork_type_page_title($type) {
  return t('Manage @type', array('@type' => $type->name));
}

/**
 * Page callback for admin/structure/artworks/manage/%artwork_type.
 *
 * @see artwork_menu()
 */
function artwork_information($artwork_type) {
  return $artwork_type->name . ': ' . $artwork_type->description;
}
