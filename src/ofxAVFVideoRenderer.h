

//
//  ofxAVFVideoRenderer.h
//  AVFoundationTest
//
//  Created by Sam Kronick on 5/31/13.
//
//


#import <Cocoa/Cocoa.h>
#import <Quartz/Quartz.h>
#import <AVFoundation/AVFoundation.h>
#import <OpenGL/OpenGL.h>

@interface AVFVideoRenderer : NSObject
{
    AVPlayer *player;
    AVPlayerItem *playerItem;
    AVPlayerLayer *playerLayer;
    
    CARenderer *layerRenderer;
    
    CGSize videoSize;
    CMTime videoDuration;
    
    BOOL loading;
    BOOL ready;
    BOOL deallocWhenReady;
    
    BOOL loop;
    BOOL movieIsDone;
    
    float myRate;
}
@property (nonatomic, retain) AVPlayer *player;
@property (nonatomic, retain) AVPlayerItem *playerItem;
@property (nonatomic, retain) AVPlayerLayer *playerLayer;
@property (nonatomic, retain) CARenderer *layerRenderer;
@property (nonatomic, assign) BOOL loop;
@property (nonatomic, assign) BOOL movieIsDone;
@property (nonatomic, assign) float myRate;

- (void) loadFile:(NSString *)filename;
- (void) play;
- (void) stop;
- (void) playerItemDidReachEnd:(NSNotification *) notification;
//- (void) update;
- (BOOL) isReady;
- (BOOL) isLoading;
- (void) render;

- (void)seekStart;

- (CGSize) getVideoSize;
- (CMTime) getVideoDuration;

@end
