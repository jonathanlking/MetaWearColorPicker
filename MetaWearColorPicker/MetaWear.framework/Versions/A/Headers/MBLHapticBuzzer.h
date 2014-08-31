//
//  MBLHapticBuzzer.h
//  MetaWear
//
//  Created by Stephen Schiffli on 8/2/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MetaWear/MBLConstants.h>
#import <MetaWear/MBLModule.h>

@interface MBLHapticBuzzer : MBLModule

/**
 Turn on Haptic Driver.
 @param uint8_t dcycle, Duty cycle (0-248), relative strength of buzz
 @param uint16_t pwidth, Duration of buzz in mSec
 @param MBLVoidHandler completion, callback when the buzz is complete
 @returns none
 */
- (void)startHapticWithDutyCycle:(uint8_t)dcycle pulseWidth:(uint16_t)pwidth completion:(MBLVoidHandler)completion;

/**
 Turn on Buzzer Driver.
 @param uint16_t pwidth, Duration of buzz in mSec
 @param MBLVoidHandler completion, callback when the buzz is complete
 @returns none
 */
- (void)startBuzzerWithPulseWidth:(uint16_t)pwidth completion:(MBLVoidHandler)completion;

@end
