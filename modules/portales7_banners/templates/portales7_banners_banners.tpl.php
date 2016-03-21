<div id="<?php print $id;?>" class="banner-item">
  <?php if (!empty($image)): ?>
    <div class="banner-image"><?php print $image;?></div>
    <?php if (!empty($text)): ?>
      <div class="banner-grup-text"><?php print $text;?></div>
    <?php endif;
  else: ?>
  <div class="banner-link"><?php print $link;?></div>
  <?php endif; ?>
</div>
