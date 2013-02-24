/* MIT licensed */
// (c) 2010 Jesse MacFadyen, Nitobi
//
//  CDVLightbox Template Created Jan 7 2013
//  Copyright 2013 @RandyMcMillan

//  Created by Randy McMillan on 2/23/13.  
//  Copyright __MyCompanyName__ 2013. All rights reserved.

(function() {

var cordovaRef = window.PhoneGap || window.Cordova || window.cordova; // old to new fallbacks

function CDVLightbox() {
    // Does nothing
}

// Callback when the location of the page changes
// called from native
CDVLightbox._onLocationChange = function(newLoc)
{
    window.plugins.CDVLightbox.onLocationChange(newLoc);
};

// Callback when the user chooses the 'Done' button
// called from native
CDVLightbox._onClose = function()
{
    window.plugins.CDVLightbox.onClose();
};

// Callback when the user chooses the 'open in Safari' button
// called from native
CDVLightbox._onOpenExternal = function()
{
    window.plugins.CDVLightbox.onOpenExternal();
};

// Pages loaded into the CDVLightbox can execute callback scripts, so be careful to
// check location, and make sure it is a location you trust.
// Warning ... don't exec arbitrary code, it's risky and could fuck up your app.
// called from native
CDVLightbox._onJSCallback = function(js,loc)
{
    // Not Implemented
    //window.plugins.CDVLightbox.onJSCallback(js,loc);
};

/* The interface that you will use to access functionality */

// Show a webpage, will result in a callback to onLocationChange
CDVLightbox.prototype.showWebPage = function(loc)
{
    cordovaRef.exec("CDVLightbox.showWebPage", loc);
};

// close the browser, will NOT result in close callback
CDVLightbox.prototype.close = function()
{
    cordovaRef.exec("CDVLightbox.close");
};

// Not Implemented
CDVLightbox.prototype.jsExec = function(jsString)
{
    // Not Implemented!!
    //PhoneGap.exec("CDVLightbox.jsExec",jsString);
};

// Note: this plugin does NOT install itself, call this method some time after deviceready to install it
// it will be returned, and also available globally from window.plugins.childBrowser
CDVLightbox.install = function()
{
    if(!window.plugins) {
        window.plugins = {};
    }
        if ( ! window.plugins.CDVLightbox ) {
        window.plugins.CDVLightbox = new CDVLightbox();
    }

};


if (cordovaRef && cordovaRef.addConstructor) {
    cordovaRef.addConstructor(CDVLightbox.install);
} else {
    console.log("CDVLightbox Cordova Plugin could not be installed.");
    return null;
}


})();
