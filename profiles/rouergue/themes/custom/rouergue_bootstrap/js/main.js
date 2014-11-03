(function ($) {
	Drupal.behaviors.main =  {
		attach: function(context, settings) {
			$('.field-name-title').hide();
			$('.field-name-field-contributors').hide();

			$('.field-name-field-cover-image').hide();
			$('.field-name-field-cover-image').fadeIn('slow');

			$('.field-name-field-cover-image').mouseenter(function() {
				$(this).parent().children('.field-name-title').fadeIn();
				$(this).parent().children('.field-name-field-contributors').fadeIn();
			});

			$('.field-name-field-cover-image').mouseleave(function() {
				$(this).parent().children('.field-name-title').fadeOut();
				$(this).parent().children('.field-name-field-contributors').fadeOut();
			});


    }
  };
})(jQuery);