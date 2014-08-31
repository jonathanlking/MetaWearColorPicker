//
//  ViewController.m
//  MetaWearColorPicker
//
//  Created by Jonathan King on 31/08/2014.
//  Copyright (c) 2014 Jonathan King. All rights reserved.
//

#import "ViewController.h"
#import <MetaWear/MetaWear.h>

@interface ViewController ()
@property (strong, nonatomic) IBOutlet UILabel *connectionStatusLabel;
@property (strong, nonatomic) IBOutlet UILabel *currentColorLabel;
@property (strong, nonatomic) IBOutlet UIView *colorView;
- (IBAction)sliderValueChanged:(UISlider *)sender;
@property (strong, nonatomic) MBLMetaWear *device;
- (void)connectToDevice;
@property (strong, nonatomic) UIColor *color;
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    [self connectToDevice];
}

- (void)connectToDevice
{
    self.connectionStatusLabel.text = @"Searching for devices";
    
    // Begin scanning for MetaWare boards
    [[MBLMetaWearManager sharedManager] startScanForMetaWearsWithHandler:^(NSArray *array)
    {
        // Hooray! We found a MetaWear board, so stop scanning for more
//        [[MBLMetaWearManager sharedManager] stopScanForMetaWears];
        // Connect to the board we found
        MBLMetaWear *device = [array firstObject];
        [[MBLMetaWearManager sharedManager] connectMetaWear:device withHandler:^(NSError *error)
        {
            if (!error)
            {
                dispatch_async(dispatch_get_main_queue(), ^{
                
                    self.device = device;
                    self.connectionStatusLabel.text = @"Connected";
                });
            }
        }];
    }];
}

- (void)setDevice:(MBLMetaWear *)device {
    
    if (device) [self enableSliders];
}

- (void)enableSliders {
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)sliderValueChanged:(UISlider *)sender {
}
@end
