//  Created by Jesse MacFadyen on 10-05-29.
//  Copyright 2010 Nitobi. All rights reserved.
//  Copyright 2012, Randy McMillan
//
//  CDVLightbox Template Created Jan 7 2013
//  Copyright 2013 @RandyMcMillan

//  Created by Randy McMillan on 2/23/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.

#import <Cordova/CDVPlugin.h>
#import "CDVLightboxViewController.h"

@interface CDVLightbox : CDVPlugin <CDVLightboxDelegate>{}

@property (nonatomic, strong) CDVLightboxViewController *CDVLightbox;

- (void)showWebPage:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;
- (void)onChildLocationChange:(NSString *)newLoc;

@end
