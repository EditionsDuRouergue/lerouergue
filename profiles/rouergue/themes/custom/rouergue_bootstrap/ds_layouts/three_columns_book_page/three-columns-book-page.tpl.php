<?php
/**
 * @file
 * Display Suite Three columns book page template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 * - $layout_wrapper: wrapper surrounding the layout.
 *
 * Regions:
 *
 * - $left: Rendered content for the "Left" region.
 * - $left_classes: String of classes that can be used to style the "Left" region.
 *
 * - $middle: Rendered content for the "Middle" region.
 * - $middle_classes: String of classes that can be used to style the "Middle" region.
 *
 * - $right: Rendered content for the "Right" region.
 * - $right_classes: String of classes that can be used to style the "Right" region.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes;?> clearfix">

  <!-- Needed to activate contextual links -->
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <<?php print $left_wrapper; ?> class="ds-left<?php print $left_classes; ?>">
      <?php print $left; ?>
    </<?php print $left_wrapper; ?>>

    <<?php print $middle_wrapper; ?> class="ds-middle<?php print $middle_classes; ?>">
      <?php print $middle; ?>
    </<?php print $middle_wrapper; ?>>

    <<?php print $right_wrapper; ?> class="ds-right<?php print $right_classes; ?>">
      <?php print $right; ?>
    </<?php print $right_wrapper; ?>>

</<?php print $layout_wrapper ?>>

<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
