//
//  iphone_socketAppDelegate.h
//  iphone.socket
//
//  Created by wangjun on 10-12-27.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class iphone_socketViewController;

@interface iphone_socketAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    iphone_socketViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet iphone_socketViewController *viewController;

@end

