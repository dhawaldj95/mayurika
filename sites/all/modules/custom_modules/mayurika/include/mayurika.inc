<?php

function inno_get_content_page(){
  return "Hello";	
}

function inno_get_content_page_access(){
  return TRUE;
}

function mayurika_get_saree_access() {
	return TRUE;
}

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
  
  return $result;
}