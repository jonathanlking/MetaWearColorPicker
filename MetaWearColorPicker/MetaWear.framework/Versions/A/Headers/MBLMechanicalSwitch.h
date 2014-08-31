//
//  MBLMechanicalSwitch.h
//  MetaWear
//
//  Created by Stephen Schiffli on 8/1/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MetaWear/MBLConstants.h>
#import <MetaWear/MBLModule.h>

@interface MBLMechanicalSwitch : MBLModule

/**
 Perform a single read of the switch state, then handler will be
 passed a YES for depressed and NO for released
 @param MBLSwitchStateHandler handler, will be called once switch value is read
 @returns none
 */
- (void)readSwitchStateWithHandler:(MBLSwitchStateHandler)handler;

/**
 Start receiving updates when the mechanical switch state changes.  The provided
 blocked will be invoked each time a state change occurs.  Call stopSwitchUpdates:
 to release the block and stop recieving notifications
 @param MBLSwitchStateHandler handler, will be called once switch value is read
 @returns none
 */
- (void)startSwitchUpdatesWithHandler:(MBLSwitchStateHandler)handler;
/**
 Stop receiving switch state updates.
 will stop being called
 @param none
 @returns none
 */
- (void)stopSwitchUpdates;

@end
