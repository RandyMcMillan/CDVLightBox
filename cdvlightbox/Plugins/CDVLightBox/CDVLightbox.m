//  Created by Jesse MacFadyen on 10-05-29.
//  Copyright 2010 Nitobi. All rights reserved.
//

#import "CDVLightbox.h"
#import <Cordova/CDVViewController.h>
#import <AVFoundation/AVFoundation.h>

@implementation CDVLightbox

@synthesize CDVLightbox;

- (void)showWebPage:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options	// args: url
{
	/* setting audio session category to "Playback" (since iOS 6) */
	AVAudioSession	*audioSession		= [AVAudioSession sharedInstance];
	NSError			*setCategoryError	= nil;
	BOOL			ok = [audioSession setCategory:AVAudioSessionCategoryPlayback error:&setCategoryError];

	if (!ok) {
		NSLog(@"Error setting AVAudioSessionCategoryPlayback: %@", setCategoryError);
	}

	if (self.CDVLightbox == nil) {
#if __has_feature(objc_arc)
			self.CDVLightbox = [[CDVLightboxViewController alloc] initWithScale:NO];
#else
			self.CDVLightbox = [[[CDVLightboxViewController alloc] initWithScale:NO] autorelease];
#endif
		self.CDVLightbox.delegate			= self;
		self.CDVLightbox.orientationDelegate = self.viewController;
	}

	/* // TODO: Work in progress
	 *   NSString* strOrientations = [ options objectForKey:@"supportedOrientations"];
	 *   NSArray* supportedOrientations = [strOrientations componentsSeparatedByString:@","];
	 */

	[self.viewController presentModalViewController:CDVLightbox animated:YES];

	NSString *url = (NSString *)[arguments objectAtIndex:0];

	[self.CDVLightbox loadURL:url];
}

- (void)getPage:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
	NSString *url = (NSString *)[arguments objectAtIndex:0];

	[self.CDVLightbox loadURL:url];
}

- (void)close:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options	// args: url
{
	[self.CDVLightbox closeBrowser];
}

- (void)onClose
{
	[self.webView stringByEvaluatingJavaScriptFromString:@"window.plugins.CDVLightbox.onClose();"];
}

- (void)onOpenInSafari
{
	[self.webView stringByEvaluatingJavaScriptFromString:@"window.plugins.CDVLightbox.onOpenExternal();"];
}

- (void)onChildLocationChange:(NSString *)newLoc
{
	NSString	*tempLoc	= [NSString stringWithFormat:@"%@", newLoc];
	NSString	*encUrl		= [tempLoc stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];

	NSString *jsCallback = [NSString stringWithFormat:@"window.plugins.CDVLightbox.onLocationChange('%@');", encUrl];

	[self.webView stringByEvaluatingJavaScriptFromString:jsCallback];
}

#if !__has_feature(objc_arc)
	- (void)dealloc
	{
		self.CDVLightbox = nil;

		[super dealloc];
	}

#endif

@end
