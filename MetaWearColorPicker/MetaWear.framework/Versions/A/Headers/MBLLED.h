//
//  MBLLED.h
//  MetaWear
//
//  Created by Stephen Schiffli on 8/1/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <MetaWear/MBLModule.h>
#import <UIKit/UIKit.h>

typedef enum {
    MBLLEDColorChannelGreen = 0,
    MBLLEDColorChannelRed = 1,
    MBLLEDColorChannelBlue = 2
} MBLLEDColorChannel;

@interface MBLLED : MBLModule

/**
 Display a specific color on the LED
 @param UIColor color, color which the LED should be
 @param CGFloat intensity, scale from 0-1.0 on how bright the LED should
 @returns none
 */
- (void)setLEDColor:(UIColor *)color withIntensity:(CGFloat)intensity;

/**
 Flash a specific color on the LED
 @param UIColor color, color which the LED should be
 @param CGFloat intensity, scale from 0-1.0 on how bright the LED should
 @returns none
 */
- (void)flashLEDColor:(UIColor *)color withIntensity:(CGFloat)intensity;

/**
 Flash a specific color on the LED
 @param UIColor color, color which the LED should be
 @param CGFloat intensity, scale from 0-1.0 on how bright the LED should
 @param int otime, Time in mSec LED spends on
 @param int period, Flash period lenght in mSec
 @returns none
 */
- (void)flashLEDColor:(UIColor *)color withIntensity:(CGFloat)intensity onTime:(uint16_t)otime andPeriod:(uint16_t)period;


#pragma mark - Advanced Settings
// These are typically not needed, see the simpler APIs above

/**
 Program one color channel of the LED, there are 3 total (red, blue, green).
 Each one is programmed individually and then the whole LED is enabled by a
 called to setLEDOn:withOptions:
 @param MBLLEDColorChannel channel, color channel being configured
 @param uint8_t onint, ON Intensity (0-31)
 @param uint8_t ofint, OFF Intensity (0-31)
 @param uint16_t rtime, Time Rise (used for Flash mode only)
 @param uint16_t ftime, Time Fall (used for Flash mode only)
 @param uint16_t otime, Time On
 @param uint16_t period, Time Period
 @param uint16_t offset, Time Offset
 @param uint8_t repeat, Repeat Count (0-254, 255: Forever)
 @returns none
 */
- (void)setLEDModeWithColorChannel:(MBLLEDColorChannel)channel
                       onIntensity:(uint8_t)onint
                      offIntensity:(uint8_t)ofint
                          riseTime:(uint16_t)rtime
                          fallTime:(uint16_t)ftime
                            onTime:(uint16_t)otime
                            period:(uint16_t)period
                            offset:(uint16_t)offset
                       repeatCount:(uint8_t)repeat;

/**
 Change global LED state.
 @param BOOL on, YES turns LED on, NO, turns LED off
 @param uint8_t mode, if on == YES then (0: pause, 1: play), 
 if on == NO then (0: Stop, 1: Stop and reset channels)
 @returns none
 */
- (void)setLEDOn:(BOOL)on withOptions:(uint8_t)mode;

@end
