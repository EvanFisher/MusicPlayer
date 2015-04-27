//
//  APAudioPlayer.h
//  APAudioPlayer
//
//  Created by Sergii Kryvoblotskyi on 5/20/14.
//  Copyright (c) 2014 Alterplay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol APAudioPlayerDelegate;
@interface APAudioPlayer : NSObject

@property (nonatomic, weak) id <APAudioPlayerDelegate> delegate;

/*
Play. Existing channel will be released
 */
- (BOOL)playItemWithURL:(NSURL *)url;

/*
 Player interactions
 */
- (void)pause;
- (void)resume;
- (void)stop;
- (BOOL)isPlaying;

- (void)setGain:(float)value forCenterFrequency:(float)center;

/*
 Player values
 */
- (NSTimeInterval)duration;

@property (nonatomic, assign) CGFloat volume;
@property (nonatomic, assign) NSTimeInterval currentTime;
@property (nonatomic, assign) BOOL hasPlayItem;

@end

@protocol APAudioPlayerDelegate <NSObject>
@optional

/*
 Will be called when track is over
 */

- (void)playerDidFinishPlaying:(APAudioPlayer *)player;

/*
 Will be called when interruption occured.
 For ex. phone call.
 Basically you should call - (void)pause in this case.
 */

- (void)playerBeginInterruption:(APAudioPlayer *)player;

/*
 Will be called when interruption ended.
 For ex. phone call ended.
 It's up to you to decide to call - (void)resume or not.
 */

- (void)playerEndInterruption:(APAudioPlayer *)player shouldResume:(BOOL)should;

@end