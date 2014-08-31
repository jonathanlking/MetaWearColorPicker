//
//  MBLNeopixel.h
//  MetaWear
//
//  Created by Stephen Schiffli on 8/12/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <MetaWear/MBLConstants.h>
#import <MetaWear/MBLModule.h>

@interface MBLNeopixel : MBLModule

/**
 Initialize the Neopixel thread.
 @param uint8_t index, strand index
 @param uint8_t color, color order and speed
 @param uint8_t pin, I/O pin
 @param uint8_t length, strand length
 @returns none
 */
- (void)initializeStrandAtIndex:(uint8_t)index withColor:(uint8_t)color pin:(uint8_t)pin andLength:(uint8_t)length;

/**
 Hold Neopixel strand.
 @param uint8_t index, strand index
 @param BOOL enable, hold enable
 @returns none
 */
- (void)holdStrandAtIndex:(uint8_t)index withEnable:(BOOL)enable;

/**
 Clear Neopixel strand.
 @param uint8_t start, start index
 @param uint8_t end, stop index
 @returns none
 */
- (void)clearStrandwithStartIndex:(uint8_t)start endIndex:(uint8_t)end;

/**
 Set Pixel at strand index.
 @param uint8_t index, strand index
 @param uint8_t red, TODO
 @param uint8_t green, TODO
 @param uint8_t blue, TODO
 @returns none
 */
- (void)setPixelAtIndex:(uint8_t)index withRed:(uint8_t)red Green:(uint8_t)green andBlue:(uint8_t)blue;

/**
 Rotate strand at index.
 @param uint8_t index, strand index
 @param uint8_t flag, increment flag
 @param uint8_t repeat, rotate repeat
 @param uint16_t delay, delay in ms
 @returns none
 */
- (void)rotateStrandAtIndex:(uint8_t)index withIncFlag:(uint8_t)flag rotateRepeat:(uint8_t)repeat andDelay:(uint16_t)delay;

/**
 Deinitialize strand at index.
 @param uint8_t index, strand index
 @returns none
 */
- (void)deinitializeStrandAtIndex:(uint8_t)index;

@end
