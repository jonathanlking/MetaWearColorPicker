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
@property (strong, nonatomic) IBOutletCollection(UISlider) NSArray *sliders;
- (IBAction)sliderValueChanged:(UISlider *)sender;
@property (strong, nonatomic) MBLMetaWear *device;
@property (strong, nonatomic) NSDate *whenColorLastChanged;
@property (strong, nonatomic) NSTimer *setLEDColorTimer;
- (void)connectToDevice;
- (void)enableSliders:(BOOL)enable;
- (void)setLEDColor:(UIColor *)color;
@property (strong, nonatomic) UIColor *color;
// This is what the light will look like
@property (strong, nonatomic) UIColor *calibratedColor;
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    // Disable the sliders at the start
    [self enableSliders:NO];
    // Set a nice gray color
    self.color = [UIColor grayColor];
    // Search for + connect to a device
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
#warning As darker and lighter colors are inherently relative and there is only one LED, you cannot 'see' a lightness, only a hue and brightness.
    // Update the background of the color view to the current color
    self.colorView.backgroundColor = color;
    // Update the text in the color label
    float components[4];
    [color getRed:&components[0] green:&components[1] blue:&components[2] alpha:&components[3]];
    self.colorLabel.text = [NSString stringWithFormat:@"(%.f, %.f, %.f)", components[0]*255, components[1]*255, components[2]*255];
    // Update the color of the LED, if connected
    if (self.device)
    {
#warning If you are dissapointed in it not being smooth, read this comment.
        // As this method is called for every value change, this may be called hundreds of times in a second, which results in lots of flashing as the LED is called every time. To get around this, a timer is used and the value must stay the same for a short amount of time, before the new color is ent over to the LED. Ideally the colour would be sent over at regular intervals and the device would interpolate the LED color, resulting in a smooth transition.
#warning You can play around with this value, between 0.1 and 0.2 work well
        static float timeDelay = 0.1;
        
        if (ABS([self.whenColorLastChanged timeIntervalSinceNow]) < timeDelay) [self.setLEDColorTimer invalidate];
        
        self.setLEDColorTimer = [NSTimer scheduledTimerWithTimeInterval:timeDelay target:self selector:@selector(setLEDColor:) userInfo:color repeats:NO];
    }
    
    // Set now as when the color last changed
    self.whenColorLastChanged = [NSDate date];
}

- (void)setLEDColor:(NSTimer *)timer
{
    [self.device.led setLEDColor:(UIColor *)[timer userInfo] withIntensity:1.0];
}

- (void)enableSliders:(BOOL)enable
{
    for (UISlider *slider in self.sliders) {
        slider.enabled = enable;
    }
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

#pragma UINavigationBarDelegate

// So that the bar is 64pt
- (UIBarPosition)positionForBar:(id <UIBarPositioning>)bar {
    return UIBarPositionTopAttached;
}

@end
