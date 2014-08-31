//
//  MBLAccelerometerData.h
//  MetaWear
//
//  Created by Stephen Schiffli on 7/29/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MBLAccelerometerData : NSObject

/**
 Time since data collection began
 */
@property (nonatomic, readonly) NSTimeInterval intervalSinceCaptureBegan;
/**
 Acceleration along each axis in G's
 */
@property (nonatomic, readonly) double x, y, z;

@end
