//
//  MBLMetaWear.h
//  MetaWear
//
//  Created by Stephen Schiffli on 7/29/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <MetaWear/MBLConstants.h>

@class MBLTemperature;
@class MBLAccelerometer;
@class MBLLED;
@class MBLMechanicalSwitch;
@class MBLGPIO;
@class MBLHapticBuzzer;
@class MBLiBeacon;
@class MBLNeopixel;

@interface MBLMetaWear : NSObject <CBPeripheralDelegate>

/**
 Query the current RSSI
 */
- (void)readRSSIWithHandler:(MBLNumberHandler)handler;
/**
 Query the percent remaining battery life, returns int between 0-100
 */
- (void)readBatteryLifeWithHandler:(MBLNumberHandler)handler;
/**
 Query information about the device
 */
- (void)readDeviceInfoWithHandler:(MBLDeviceInfoHandler)handler;

/**
 Perform a software reset of the device
 */
- (void)resetDevice;

/**
 See if this device is running the most up to date firmware
 */
- (void)checkForFirmwareUpdateWithHandler:(MBLBoolHandler)handler;
/**
 Updates the device to the latest firmware.  Executes the progressHandler
 periodically with the progress (0.0 - 1.0), progressHandler will get called
 with 1.0 before handler is called.  handler will be passed a nil NSError* if
 update was successful and non-nil NSError* otherwise.
 @param MBLErrorHandler handler, Callback once update is complete
 @param MBLFloatHandler progressHandler, Periodically called while firmware upload is in progress
 @returns none
 */
- (void)updateFirmwareWithHandler:(MBLErrorHandler)handler
                  progressHandler:(MBLFloatHandler)progressHandler;


/** 
 Pointer the underlying CoreBluetooth object 
 */
@property (nonatomic, strong, readonly) CBPeripheral *peripheral;
/** 
 Stored value of signal strength at discovery time 
 */
@property (nonatomic, strong) NSNumber *discoveryTimeRSSI;

// *** Sensors ***
@property (nonatomic, strong, readonly) MBLMechanicalSwitch *mechanicalSwitch;
@property (nonatomic, strong, readonly) MBLLED *led;
@property (nonatomic, strong, readonly) MBLTemperature *temperature;
@property (nonatomic, strong, readonly) MBLAccelerometer *accelerometer;
@property (nonatomic, strong, readonly) MBLGPIO *gpio;
@property (nonatomic, strong, readonly) MBLHapticBuzzer *hapticBuzzer;
@property (nonatomic, strong, readonly) MBLiBeacon *iBeacon;
@property (nonatomic, strong, readonly) MBLNeopixel *neopixel;

@end
