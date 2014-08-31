//
//  MBLConstants.h
//  MetaWear
//
//  Created by Stephen Schiffli on 7/30/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
@class MBLAccelerometerData;
@class MBLDeviceInfo;

#pragma mark - Block Typedefs

typedef void (^MBLVoidHandler)();
typedef void (^MBLErrorHandler)(NSError *error);
typedef void (^MBLDataHandler)(NSData *data, NSError *error);
typedef void (^MBLArrayHandler)(NSArray *array);
typedef void (^MBLCentralManagerStateHandler)(CBCentralManagerState state);
typedef void (^MBLPeripheralStateHandler)(CBPeripheralState state);
typedef void (^MBLAccelerometerHandler)(MBLAccelerometerData *acceleration, NSError *error);
typedef void (^MBLDeviceInfoHandler)(MBLDeviceInfo *deviceInfo, NSError *error);
typedef void (^MBLDecimalNumberHandler)(NSDecimalNumber *number, NSError *error);
typedef void (^MBLNumberHandler)(NSNumber *number, NSError *error);
typedef void (^MBLSwitchStateHandler)(BOOL isPressed, NSError *error);
typedef void (^MBLBoolHandler)(BOOL isTrue, NSError *error);
typedef void (^MBLFloatHandler)(float number, NSError *error);

#pragma mark - Errors

extern NSString *const kMBLErrorDomain;

/*! @abstract 100: Unexpected number of bluetooth services */
extern NSInteger const kMBLErrorUnexpectedServices;

/*! @abstract 101: Unexpected number of bluetooth characteristics */
extern NSInteger const kMBLErrorUnexpectedCharacteristics;