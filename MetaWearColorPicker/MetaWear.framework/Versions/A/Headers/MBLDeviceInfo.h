//
//  MBLDeviceInfo.h
//  MetaWear
//
//  Created by Stephen Schiffli on 8/12/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MBLDeviceInfo : NSObject

@property (nonatomic, strong) NSString *manufacturerName; /**< DeviceInfo Manufacturer Name string */
@property (nonatomic, strong) NSString *serialNumber; /**< DeviceInfo Serial Number string */
@property (nonatomic, strong) NSString *hardwareRevision; /**< DeviceInfo Hardware Revision string */
@property (nonatomic, strong) NSString *firmwareRevision; /**< DeviceInfo Firmware Revision string */

@end
