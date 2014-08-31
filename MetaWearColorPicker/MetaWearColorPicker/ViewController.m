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
@property (strong, nonatomic) IBOutlet UILabel *colorLabel;
@property (strong, nonatomic) IBOutlet UIView *colorView;
- (IBAction)sliderValueChanged:(UISlider *)sender;
@property (strong, nonatomic) MBLMetaWear *device;
- (void)connectToDevice;
- (void)enableSliders:(BOOL)enable;
@property (strong, nonatomic) UIColor *color;
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.color = [UIColor grayColor];
    [self connectToDevice];
}

- (void)connectToDevice
{
    self.connectionStatusLabel.text = @"Searching for devices";
    
    // Begin scanning for MetaWare boards
    [[MBLMetaWearManager sharedManager] startScanForMetaWearsWithHandler:^(NSArray *array)
    {
        // Hooray! We found a MetaWear board, so stop scanning for more
#warning Calling stopScanForMetaWears does some strange things - like changing self to a CBXpcConnection - therefore not calling it for now.
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

- (void)setDevice:(MBLMetaWear *)device
{
    _device = device;
    // If connected then enable sliders, else disable them
    device ? [self enableSliders:YES] : [self enableSliders:NO];
}

- (void)setColor:(UIColor *)color
{
    _color = color;
    // Update the background of the color view to the current color
    self.colorView.backgroundColor = color;
    // Update the text in the color label
    float components[4];
    [color getRed:&components[0] green:&components[1] blue:&components[2] alpha:&components[3]];
    self.colorLabel.text = [NSString stringWithFormat:@"(%.f, %.f, %.f)", components[0]*255, components[1]*255, components[2]*255];
}

- (void)enableSliders:(BOOL)enable
{
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)sliderValueChanged:(UISlider *)sender
{
    float components[4];
    [self.color getRed:&components[0] green:&components[1] blue:&components[2] alpha:&components[3]];
    components[sender.tag] = sender.value;
    self.color = [UIColor colorWithRed:components[0] green:components[1] blue:components[2] alpha:components[3]];
}
@end
