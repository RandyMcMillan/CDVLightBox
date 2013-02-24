//  Created by Jesse MacFadyen on 10-05-29.
//  Copyright 2010 Nitobi. All rights reserved.
//
//  CDVLightbox Template Created Jan 7 2013
//  Copyright 2013 @RandyMcMillan

//  Created by Randy McMillan on 2/23/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.

#import <UIKit/UIKit.h>

@protocol CDVLightboxDelegate <NSObject>

/*
 *  onChildLocationChanging:newLoc
 *
 *  Discussion:
 *    Invoked when a new page has loaded
 */
- (void)onChildLocationChange:(NSString *)newLoc;
- (void)onOpenInSafari;
- (void)onClose;

@end

@protocol CDVOrientationDelegate <NSObject>

- (NSUInteger)supportedInterfaceOrientations;
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;
- (BOOL)shouldAutorotate;

@end

@interface CDVLightboxViewController : UIViewController <UIWebViewDelegate>{}

@property (nonatomic, strong) IBOutlet UIWebView				*webView;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*closeBtn;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*refreshBtn;
@property (nonatomic, strong) IBOutlet UILabel					*addressLabel;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*backBtn;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*fwdBtn;
@property (nonatomic, strong) IBOutlet UIBarButtonItem			*safariBtn;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView	*spinner;

// unsafe_unretained is equivalent to assign - used to prevent retain cycles in the two properties below
@property (nonatomic, unsafe_unretained) id <CDVLightboxDelegate>	delegate;
@property (nonatomic, unsafe_unretained) id									orientationDelegate;

@property (copy) NSString	*imageURL;
@property (assign) BOOL		isImage;
@property (assign) BOOL		scaleEnabled;

- (CDVLightboxViewController *)initWithScale:(BOOL)enabled;
- (IBAction)onDoneButtonPress:(id)sender;
- (IBAction)onSafariButtonPress:(id)sender;
- (void)loadURL:(NSString *)url;
- (void)closeBrowser;

@end
