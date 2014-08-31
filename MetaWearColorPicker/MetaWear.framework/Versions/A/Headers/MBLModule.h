//
//  MBLModule.h
//  MetaWear
//
//  Created by Stephen Schiffli on 8/1/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MetaWear/MBLMetaWear.h>

@interface MBLModule : NSObject

- (instancetype)initWithModuleId:(uint8_t)moduleId andDevice:(MBLMetaWear *)device;

- (void)readRegister:(uint8_t)registerId withHandler:(MBLDataHandler)handler;
- (void)readRegister:(uint8_t)registerId parameters:(NSData *)parameters withHandler:(MBLDataHandler)handler;

- (void)writeRegister:(uint8_t)registerId parameters:(NSData *)parameters withHandler:(MBLErrorHandler)handler;

- (void)startNotificationsForRegister:(uint8_t)registerId withHandler:(MBLDataHandler)handler;
- (void)stopNotificationsForRegister:(uint8_t)registerId withHandler:(MBLErrorHandler)handler;

@end
