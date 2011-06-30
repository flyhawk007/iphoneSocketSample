//
//  iphone_socketViewController.m
//  iphone.socket
//
//  Created by wangjun on 10-12-27.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//
#import "iphone_socketViewController.h"
@implementation iphone_socketViewController
- (void)viewDidLoad {
    [super viewDidLoad];
	asyncSocket = [[AsyncSocket alloc] initWithDelegate:self];
	NSError *err = nil;
	if(![asyncSocket connectToHost:@"192.168.0.113" onPort:25001 error:&err])
	{
		NSLog(@"Error: %@", err);
	}
}
- (void)onSocket:(AsyncSocket *)sock didConnectToHost:(NSString *)host port:(UInt16)port
{
	NSLog(@"onSocket:%p didConnectToHost:%@ port:%hu", sock, host, port);
	[sock readDataWithTimeout:1 tag:0];
}
-(void) onSocket:(AsyncSocket *)sock didReadData:(NSData *)data withTag:(long)tag
{
	NSString* aStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
	NSLog(@"===%@",aStr);
	[aStr release];
	NSData* aData= [@"<xml>我喜欢你<xml>" dataUsingEncoding: NSUTF8StringEncoding];
	[sock writeData:aData withTimeout:-1 tag:1];
	[sock readDataWithTimeout:1 tag:0];
}
- (void)onSocket:(AsyncSocket *)sock didSecure:(BOOL)flag
{
		NSLog(@"onSocket:%p didSecure:YES", sock);
}
- (void)onSocket:(AsyncSocket *)sock willDisconnectWithError:(NSError *)err
{
	NSLog(@"onSocket:%p willDisconnectWithError:%@", sock, err);
}
- (void)onSocketDidDisconnect:(AsyncSocket *)sock
{
	//断开连接了
	NSLog(@"onSocketDidDisconnect:%p", sock);
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}
- (void)viewDidUnload {
	asyncSocket=nil;
}
- (void)dealloc {
	[asyncSocket release];
    [super dealloc];
}
@end
