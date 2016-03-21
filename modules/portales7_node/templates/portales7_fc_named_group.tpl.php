<?php
if (!isset($fc_formatter)) $fc_formatter = '';
if (!isset($fc_classes)) $fc_classes = array();
if (!empty($fc_items)) { ?>
<div class="portales7-fc-<?php print $fc_formatter;?> <?php print(join(' ', $fc_classes));?>">
<div class="portales7_fc_name"><?php print $fc_name;?></div>
<?php if (!empty($fc_description)): ?>
<div class="portales7_fc_description"><?php print_r($fc_description); ?></div>
<?php endif; ?>
<div class="portales7_fc_content">
  <?php print($fc_items);?>
</div>
</div>
<?php } ?>