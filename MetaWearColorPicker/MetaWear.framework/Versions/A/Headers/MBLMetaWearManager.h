//
//  MBLMetaWearManager.h
//  MetaWear
//
//  Created by Stephen Schiffli on 7/29/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MetaWear/MBLMetaWear.h>
#import <MetaWear/MBLConstants.h>

@interface MBLMetaWearManager : NSObject

/**
 Access the single WetaWearManager object, note you should not create
 one of these objects on your own, only used the sharedManager
 @returns MBLMetaWearManager, Single manager object
 */
+ (instancetype)sharedManager;

/**
 Subscribe to upates to in the internal bluetooth manager state, this is useful
 for displaying errors if the user happens to turn off bluetooth radio in settings
 @param MBLCentralManagerStateHandler handler, Callback to handle each time a new device is found
 @returns none
 */
- (void)startManagerStateUpdatesWithHandler:(MBLCentralManagerStateHandler)handler;

/**
 Begin scanning for MetaWear devices. This will invoke the provided block each time a
 new device shows up and passes an array of all discovered devices to the block.
 This continues until stopScanForMetaWears is called.
 @param MBLArrayHandler handler, Callback to handle each time a new device is found
 @returns none
 */
- (void)startScanForMetaWearsWithHandler:(MBLArrayHandler)handler;
/**
 Begin scanning for MetaWear devices with the option to filter duplicate devices or not.
 This will invoke the provided block each time a new device shows up if filter == YES or
 each time a new advertising packet is found if filter == NO. This continues until 
 stopScanForMetaWears is called.
 @param BOOL duplicates, YES: only callback when a new device is found, NO: callback each time
 @param MBLArrayHandler handler, Callback to handle each time a new device is found
 a new advertising packet is found
 @returns none
 */
- (void)startScanForMetaWearsAllowDuplicates:(BOOL)duplicates handler:(MBLArrayHandler)handler;

/**
 Stop scanning for MetaWear devices, this will release all handlers given to
 startManagerStateUpdatesWithHandler:
 @returns none
 */
- (void)stopScanForMetaWears;

/**
 Connect to the given MetaWear board. Once connection is complete, the provided block 
 will be invoked.  If the NSError pointer provided to the block is not null then the 
 connection failed, otherwise success
 @param MBLMetaWear device, MetaWear device to connect to
 @param MBLErrorHandler handler, Callback once connection is complete
 @returns none
 */
- (void)connectMetaWear:(MBLMetaWear *)device withHandler:(MBLErrorHandler)handler;

/**
 Disconnect from the given MetaWear board.
 @param MBLMetaWear device, MetaWear device to disconnect from
 @param MBLErrorHandler handler, Callback once disconnection is complete
 @returns none
 */
- (void)cancelMetaWearConnection:(MBLMetaWear *)device withHandler:(MBLErrorHandler)handler;

@end
