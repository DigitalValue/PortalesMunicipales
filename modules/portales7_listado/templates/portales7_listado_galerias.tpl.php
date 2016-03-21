<div id="portales7_listado-<?php print $row->nid?>" class="portales7_listado-element <?php print $view->name?>-element <?php print $classes?> <?php print $zebra?>">
<?php
  foreach ($fields as $name => $field){
    ?><div class="portales7_listado-<?php print $name?>"><?php print $field->content?></div>
    <?php }
?>
</div>
