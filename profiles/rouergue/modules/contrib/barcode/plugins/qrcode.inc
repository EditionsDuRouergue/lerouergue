<?php

/**
 * @file
 * Barcode plugin
 * QR Code: get the QR code from Google Graphic API
 */
function barcode_qrcode_barcode($barnumber, $settings) {
  if (empty($settings->filename_no_format)) {
    header("Content-type: image/". $settings->format);
  }

  $h = $settings->height;
  $name = md5($barnumber);
  $content = urlencode($barnumber);
  $url = 'http://chart.apis.google.com/chart?chs=' . $h . 'x' . $h . '&cht=qr&chl=' . $content;
  $img = $settings->default_path .'/'. $name . $settings->encode .'.'. $settings->format; 
  
	//  file_put_contents($img, file_get_contents($url));

	/**Added by H. **/
	$headers = array(
  "Expect:",
  // more headers here
	); 
	$curl_handle=curl_init();
	curl_setopt($curl_handle, CURLOPT_URL, $url);
	curl_setopt($curl_handle, CURLOPT_CONNECTTIMEOUT, 2);
	curl_setopt($curl_handle, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($curl_handle, CURLOPT_USERAGENT, 'Drupal');
	curl_setopt($curl_handle, CURLOPT_HTTPHEADER, $headers); 
	$query = curl_exec($curl_handle);
	curl_close($curl_handle);

  file_put_contents($img, $query);
}

function barcode_qrcode_max_length($encoding) {
  return 8192;
}
