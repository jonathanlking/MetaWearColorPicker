//
//  MBLGPIO.h
//  MetaWear
//
//  Created by Stephen Schiffli on 8/2/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MetaWear/MBLConstants.h>
#import <MetaWear/MBLModule.h>

@interface MBLGPIO : MBLModule

/**
 Set a digital output GPIO Pin to a 1 or 0.
 @param uint8_t pinNumber, number of the pin
 @param BOOL on, YES sets pin to 1, NO clears pin to 0
 @returns none
 */
- (void)setPin:(uint8_t)pinNumber toDigitalValue:(BOOL)on;

/**
 Set input GPIO pin type.
 @param uint8_t pinNumber, number of the pin
 @param uint8_t type, option type (0: pullup, 1: pulldown, 2/else: nopull)
 @returns none
 */
- (void)configurePin:(uint8_t)pinNumber withOptions:(uint8_t)type;

/**
 Read Analog value of GPIO Pin.
 @param uint8_t pinNumber, number of the pin
 @param uint8_t option, option type (0: use internal Vref, 1/else: use supply voltage ratio)
 @returns none
 */
- (void)readAnalogPin:(uint8_t)pinNumber usingOptions:(uint8_t)option withHandler:(MBLDecimalNumberHandler)handler;

/**
 Read Digital value of GPIO Pin.
 @param uint8_t pinNumber, number of the pin
 @returns none
 */
- (void)readDigitalPin:(uint8_t)pinNumber withHander:(MBLBoolHandler)handler;

@end
