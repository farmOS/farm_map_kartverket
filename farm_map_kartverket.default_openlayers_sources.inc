<?php
/**
 * @file
 * farm_map_kartverket.default_openlayers_sources.inc
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function farm_map_kartverket_default_openlayers_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'farm_map_kartverket_source_norges_grunnkart';
  $ol_source->name = 'Farm Map Kartverket: Norges Grunnkart';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:InlineJS';
  $ol_source->options = array(
    'url' => 'http://opencache.statkart.no/gatekeeper/gk/gk.open_wmts',
    'wms_layers' => 'matrikkel_bakgrunn',
    'version' => '1.0.0',
    'params' => array(
      'LAYERS' => 'matrikkel_bakgrunn',
      'VERSION' => '1.0.0',
    ),
    'javascript' => '// Code adapted from https://github.com/kartverket/example-clients/blob/master/openlayers3/wmts_mercator.html

//Start: projection & tileGrid definitions
var sProjection = \'EPSG:3857\';
var projection = ol.proj.get(sProjection);
var projectionExtent = projection.getExtent();
var size = ol.extent.getWidth(projectionExtent) / 256;
var resolutions = [],
	matrixIds = [];
for (var z = 0; z < 15; ++z) { //Max 18?
	// generate resolutions and matrixIds arrays for this WMTS
	resolutions[z] = size / Math.pow(2, z);
	matrixIds[z] = sProjection + ":" + z;
}
//End: projection & tileGrid definitions
//start View definitions
var view = new ol.View({
	projection: sProjection,
	center: [1891337, 9772319],
	zoom: 5
});
//End View definitions
//Start: Map definitions
var map = new ol.Map({
	target: \'map\',
	view: view
});
//End: Map definitions
//***********************
var _url = "http://opencache.statkart.no/gatekeeper/gk/gk.open_wmts?";
//Start: source
var source = new ol.source.WMTS({
	url: _url,
	layer: \'norges_grunnkart\',
	matrixSet: \'EPSG:3857\',
	format: \'image/png\',
	projection: projection,
	tileGrid: new ol.tilegrid.WMTS({
		origin: ol.extent.getTopLeft(projectionExtent),
		resolutions: resolutions,
		matrixIds: matrixIds
	}),
	style: \'default\'
});
//End: source',
  );
  $export['farm_map_kartverket_source_norges_grunnkart'] = $ol_source;

  return $export;
}