<?php
print('<div id="banner-node-' . $row->nid . '">');
$path = !empty($row->field_portales7_link) ?  $row->field_portales7_link[0]['raw']['value'] : 'node/' . $row->nid;
$options = array('attributes' => array('target' => ''));
if (preg_match('@://@', $path)) {
  $options['attributes']['target'] == '_blank';
}
if (!empty($row->field_portales7_banner_image[0]['rendered'])) {
  $element = $row->field_portales7_banner_image[0]['rendered'];
  $element['#path'] = array('path' => $path, 'options' => $options);
  print(theme('image_formatter', $element));
}
else {
  print l($row->node_title, $path, $options);
}
?>
</div>
