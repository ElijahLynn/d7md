<?php

/**
 * @file
 * Artwork controller.
 */

class ArtworkController extends DrupalDefaultEntityController {

  public function create($type = '') {
    return (object) array(
      'aid' => '',
      'type' => $type,
      'title' => '',
    );
  }
}
