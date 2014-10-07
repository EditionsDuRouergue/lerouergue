(function ($) {
  Drupal.behaviors.UniversesNavigation =  {
    attach: function(context, settings) {
  	  $('#block-menu-menu-universe ul').removeClass('nav');
    }
  };
})(jQuery);