<?php
/**
 * @file
 * Template file for a day forecast
 */
?>
<div class="<?php print join(" ",$classes_array);?>">
  <div class="aemet-date"><?php print format_date(strtotime($date),'custom',"d-m");?></div>
  <div class="aemet-sky"><?php print $estado_cielo;?></div>
  <div class="aemet-temp"><?php print $temperatura;?></div>
  <div class="aemet-wind"><?php print $viento;?></div>
  <div class="aemet-hum"><?php print $humedad_relativa;?></div>
</div>
