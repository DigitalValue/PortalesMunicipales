<?php
 /* 
 *//**
 * Variables used in this file
 * $date1 - Start date of the event
 * $hour1 - Start hour of the event
 * $date2 - End date of the event
 * $hour2 - End hour of the event
 * $calendar_links - Calendar terms
 * $calendar - Transliterated name of the calendar
 * $nid - Node nid for the current record
 * $main_image - Main image field of current node
 * $teaser - Teaser field of current node
 * $title - Title of the current node
 */
?>
<div id="portales7_listado_agenda-<?php print $nid?>" class="portales7_listado-element portales7_listado_agenda-element <?php print $calendar?> <?php print $classes?> <?php print $zebra?>">
  <?php if (!empty($event_type)) {?>
    <div class="portales7_listado-portales7_event_type"><?php print $event_type?></div>
  <?php } ?>
  <div class="portales7_listado-portales7_eventdate">
  <div class="startdate"><?php print $date1?></div><div class="starthour"><?php print $hour1?></div>
  <?php if (!$view->pane_conf['hide_end_date'] && (!empty($date2) || !empty($hour2))) {
   ?><div class="eventdate-separator"><?php print t('to')?></div>
   <?php if (!empty($date2)) {
     ?><div class="enddate"><?php print $date2?></div><?php
   }
   if (!empty($hour2)) {
     ?><div class="endhour"><?php print $hour2?></div><?php
   }
  }?>
  </div>
  <?php if (!empty($main_image)): ?>
  <div class="portales7_listado-portales7_main_image"><?php print $main_image?></div>
  <?php endif; ?>
  <?php if (!empty($title)): ?>
  <div class="portales7_listado-title"><?php print $title?></div>
  <?php endif; ?>
  <?php if (!empty($teaser)): ?>
    <div class="portales7_listado-teaser"><?php print $teaser?></div>
  <?php endif; ?>
  <?php if (!empty($calendar_links)) {?>
    <div class="portales7_listado-portales7_calendar"><?php print $calendar_links?></div>
  <?php } ?>
</div>
