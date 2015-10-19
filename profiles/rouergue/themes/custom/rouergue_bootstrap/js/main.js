(function ($) {
	Drupal.behaviors.main =  {
		attach: function(context, settings) {

			$('.field-name-body img').removeAttr('style');
			$('.field-name-body img').addClass('img-responsive');

			$('.infosWrapper').hide();
			
			$('.couvWrapper').mouseenter(function() {
				$(this).children('.infosWrapper').slideDown('fast')
			});

			$('.couvWrapper').mouseleave(function() {
				$(this).children('.infosWrapper').slideUp('slow')
			});

			$('.node-event.view-mode-list').matchHeight('options');
			$('.group-event-details .field-name-title p').matchHeight('options');
			$('.group-event-details .field-name-body p').matchHeight('options');
			//$('.view-news .view-mode-teaser_home .field-name-title h3, .view-news .view-mode-teaser .field-name-title h3').matchHeight('options');

   }
 };
})(jQuery);