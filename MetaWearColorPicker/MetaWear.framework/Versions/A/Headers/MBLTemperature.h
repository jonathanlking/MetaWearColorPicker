//
//  MBLTemperature.h
//  MetaWear
//
//  Created by Stephen Schiffli on 8/1/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MetaWear/MBLConstants.h>
#import <MetaWear/MBLModule.h>

@class MBLMetaWear;

@interface MBLTemperature : MBLModule

/**
 Query the current temperature of the device in degrees C
 */
- (void)readTemperatureWithHandler:(MBLDecimalNumberHandler)handler;

@end
