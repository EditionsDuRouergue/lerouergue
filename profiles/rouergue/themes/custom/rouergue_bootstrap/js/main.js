(function ($) {
	Drupal.behaviors.main =  {
		attach: function(context, settings) {

			$('.infosWrapper').hide();
			
			$('.couvWrapper').mouseenter(function() {
				$(this).children('.infosWrapper').slideDown('fast')
			});

			$('.couvWrapper').mouseleave(function() {
				$(this).children('.infosWrapper').slideUp('slow')
			});


   }
 };
})(jQuery);