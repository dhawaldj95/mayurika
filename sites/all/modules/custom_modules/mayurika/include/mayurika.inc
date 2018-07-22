<?php

/**
 * @return bool
 *
 */
function mayurika_get_saree_access() {
	return TRUE;
}

/**
 * @return mixed
 */
function mayurika_get_saree() {
  $query = db_select('node', 'n');
  $query -> innerJoin('field_data_field_image', 'image', 'n.nid = image.entity_id');
  $query -> innerJoin('field_data_field_brand', 'brand', 'n.nid = brand.entity_id');
  $query -> innerJoin('field_data_field_type', 'type', 'n.nid = type.entity_id');
  $query -> leftJoin('file_managed', 'file', 'file.fid = image.field_image_fid');
  $query -> condition('n.type', 'saree');
  $query -> condition('brand.bundle', 'saree');
  $query -> condition('type.bundle', 'saree');
  $query->addExpression("GROUP_CONCAT( file.uri SEPARATOR ',')", 'uri');
  $query -> fields('file', array('uri'));
  $query -> fields('brand', array('field_brand_value'));
  $query -> fields('type', array('field_type_value'));
  $query->groupBy('n.nid');
  $result = $query -> execute() -> fetchAll();

  if (empty($result)) {
    return $result;
  }

  foreach ($result as $key => $value) {
    $imagesArray = explode(',', $value -> uri);
    foreach ($imagesArray as $key1 => $value1) {
      $urlImageArray[] = file_create_url($value1);
    }
    unset($result[$key] -> uri);
    $result[$key] -> urls = $urlImageArray;
    unset($urlImageArray);
  }

  return $result;
}

/**
 * @return mixed
 */
function mayurika_get_kurti() {
  $query = db_select('node', 'n');
  $query -> innerJoin('field_data_field_image', 'image', 'n.nid = image.entity_id');
  $query -> innerJoin('field_data_field_type', 'type', 'n.nid = type.entity_id');
  $query -> leftJoin('file_managed', 'file', 'file.fid = image.field_image_fid');
  $query -> condition('n.type', 'kurti');
  $query -> condition('type.bundle', 'kurti');
  $query -> addExpression("GROUP_CONCAT( file.uri SEPARATOR ',')", 'uri');
  $query -> fields('file', array('uri'));
  $query -> fields('type', array('field_type_value'));
  $query -> groupBy('n.nid');
  $result = $query -> execute() -> fetchAll();

  if (empty($result)) {
    return $result;
  }

  foreach ($result as $key => $value) {
    $imagesArray = explode(',', $value -> uri);
    foreach ($imagesArray as $key1 => $value1) {
      $urlImageArray[] = file_create_url($value1);
    }
    unset($result[$key] -> uri);
    $result[$key] -> urls = $urlImageArray;
    unset($urlImageArray);
  }

  return $result;
}

/**
 * @return bool
 */
function mayurika_get_kurti_access() {
  return TRUE;
}

/**
 * @return mixed
 */
function mayurika_get_lehenga() {
  $query = db_select('node', 'n');
  $query -> innerJoin('field_data_field_image', 'image', 'n.nid = image.entity_id');
  $query -> leftJoin('file_managed', 'file', 'file.fid = image.field_image_fid');
  $query -> addExpression("GROUP_CONCAT( file.uri SEPARATOR ',')", 'uri');
  $query -> condition('n.type', 'lehenga');
  $query -> fields('file', array('uri'));
  $query -> groupBy('n.nid');
  $result = $query -> execute() -> fetchAll();

  if (empty($result)) {
    return $result;
  }

  foreach ($result as $key => $value) {
    $imagesArray = explode(',', $value -> uri);
    foreach ($imagesArray as $key1 => $value1) {
      $urlImageArray[] = file_create_url($value1);
    }
    unset($result[$key] -> uri);
    $result[$key] -> urls = $urlImageArray;
    unset($urlImageArray);
  }

  return $result;
}

/**
 * @return bool
 */
function mayurika_get_lehenga_access() {
  return TRUE;
}

/**
 * @return mixed
 */
function mayurika_get_banner() {
  $query = db_select('node', 'n');
  $query -> leftJoin('field_data_field_image', 'image', 'n.nid = image.entity_id');
  $query -> leftJoin('field_data_field_description', 'des', 'n.nid = des.entity_id');
  $query -> leftJoin('field_data_field_order', 'order1', 'n.nid = order1.entity_id');
  $query -> innerJoin('file_managed', 'file', 'file.fid = image.field_image_fid');
  $query -> addExpression("GROUP_CONCAT( file.uri SEPARATOR ',')", 'uri');
  $query -> condition('n.type', 'banner');
  $query -> fields('des', array('field_description_value'));
//  $query -> fields('order', array('field_order_value'));
//  $query -> fields('file', array('uri'));
  $query -> orderBy('order1.field_order_value');
  $query -> groupBy('n.nid');
  $result = $query -> execute() -> fetchAll();

  if (empty($result)) {
    return $result;
  }

  foreach ($result as $key => $value) {
    $imagesArray = explode(',', $value -> uri);
    foreach ($imagesArray as $key1 => $value1) {
      $urlImageArray[] = file_create_url($value1);
    }
    unset($result[$key] -> uri);
    $result[$key] -> urls = $urlImageArray;
    unset($urlImageArray);
  }

  return $result;
}

/**
 * @return bool
 */
function mayurika_get_banner_access() {
  return TRUE;
}