//
//  POSPrinter.h
//  Printer
//
//  Created by Apple Mac mini intel on 2022/12/7.
//  Copyright © 2022 Admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

typedef NS_ENUM(NSInteger, POSPrinterConnectType) {
    POSPrinterConnectBLE = 0,           ///< Bluetooth
    POSPrinterConnectWiFi = 1           ///< WiFi
};

NS_ASSUME_NONNULL_BEGIN

@interface POSPrinter : NSObject

/// Connect type for the printer.
@property (nonatomic, assign) POSPrinterConnectType connectType;

/// Bluetooth name of the printer.
@property (nonatomic, copy, readwrite) NSString *name;

/// MAC address of the printer.
@property (nonatomic, copy, readwrite) NSString *mac;

/// Unique identifier for the printer.
@property (nonatomic, copy, readwrite) NSString *uuid;

/// RSSI value for the printer's connection.
@property (nonatomic, copy, readwrite) NSNumber *rssi;

/// Peripheral representing the connected printer.
@property (nonatomic, copy, readwrite) CBPeripheral *peripheral;

/// IP address of the printer.
@property (nonatomic, copy, readwrite) NSString *ip;

/// Port number for the printer's connection.
@property (nonatomic, copy, readwrite) NSString *port;

@end


NS_ASSUME_NONNULL_END
