<?php
/**
 * @file
 * Widget's template file
 */
?>
<div class="<?php print join(" ",$classes_array);?>">
<div class="aemet-provincia"><span class="aemet-label"><?php print t('Province:');?></span> <?php print $provincia;?></div>
<div class="aemet-widget-table"><?php print $forecast_table;?></div>
<div style="clear:both"></div>
<div class="aemet-elaborado"><span class="aemet-label"><?php print t('Issued:');?></span><?php print format_date($elaborado, 'medium');?></div>
<div class="aemet-origen"><span class="aemet-label"><?php print t('Source');?>:</span><span class="aemet-source-value"><?php print $origen;?></span></div>
</div>
