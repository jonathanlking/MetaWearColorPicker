//
//  MBLiBeacon.h
//  MetaWear
//
//  Created by Stephen Schiffli on 8/3/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <MetaWear/MBLConstants.h>
#import <MetaWear/MBLModule.h>

@interface MBLiBeacon : MBLModule

/**
 The iBeacon UUID being broadcast, the default is the MetaWear Service UUID
 */
@property (nonatomic, strong) CBUUID *uuid;
/**
 The iBeacon major value being broadcast, the default is 0x0000
 */
@property (nonatomic) uint16_t major;
/**
 The iBeacon minor value being broadcast, the default is 0x0000
 */
@property (nonatomic) uint16_t minor;

/**
 Calibrated RX power, default is -55 dBm
 */
@property (nonatomic) uint8_t powerRX;
/**
 TX power, default is 0 dBm
 */
@property (nonatomic) uint8_t powerTX;
/**
 Advertisement frequency in ms, default is 500 ms
 */
@property (nonatomic) uint16_t frequency;

/**
 Change iBeacon state to on or off. Please set any configuration properties
 before calling this method, setting properties after this call will have
 no effect until setBeaconOn: is called again.
 @param BOOL on, YES turns iBeacon on, NO, turns iBeacon off
 @returns none
 */
- (void)setBeaconOn:(BOOL)on;

@end
