//
//  WIFIConnecter.h
//  PrinterSDK
//
//  Created by Apple Mac mini intel on 2023/9/1.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PrinterProfile.h"

@class WIFIConnecter;
@class PrinterProfile;

@protocol WIFIConnecterDelegate <NSObject>
@optional
/// Called when the connection to the host is successful
/// @param ip The IP address of the connected host
/// @param port The port number of the connected host
/// @param mac The MAC address of the connected device
- (void)wifiPOSConnectedToHost:(NSString *)ip port:(UInt16)port mac:(NSString *)mac;

/// Called when there is an error during disconnection
/// @param error The error encountered during disconnection
/// @param mac The MAC address of the device
/// @param ip The IP address of the device
- (void)wifiPOSDisconnectWithError:(NSError *)error mac:(NSString *)mac ip:(NSString *)ip;

/// Called when data is successfully sent
/// @param tag A unique identifier for the operation
/// @param mac The MAC address of the device
/// @param ip The IP address of the device
- (void)wifiPOSWriteValueWithTag:(long)tag mac:(NSString *)mac ip:(NSString *)ip;

/// Called when data is received from the printer
/// @param data The data received from the printer
/// @param mac The MAC address of the device
/// @param ip The IP address of the device
- (void)wifiPOSReceiveValueForData:(NSData *)data mac:(NSString *)mac ip:(NSString *)ip;

@end

/// Block called when data is received
typedef void (^WIFIConnecterReceiveBlock)(NSData *data);

/// Block called when data is written
typedef void (^WIFIConnecterWriteBlock)(BOOL success, NSError *error);

/// Block called for printer status updates
typedef void (^POSWiFiPrinterStatusBlock)(NSData *status);

/// Block called for printer serial number retrieval
typedef void (^POSWiFiPrinterSNBlock)(NSString *sn);

@interface WIFIConnecter : NSObject

/// Host IP address
@property (nonatomic, copy) NSString *deviceIP;

/// Port number
@property (nonatomic, assign) UInt16 port;

/// MAC address
@property (nonatomic, copy) NSString *deviceMac;

/// Delegate for connection events
@property (nonatomic, weak) id<WIFIConnecterDelegate> delegate;

/// Block for receiving data
@property (nonatomic, copy) WIFIConnecterReceiveBlock receiveBlock;

/// Block for writing data
@property (nonatomic, copy) WIFIConnecterWriteBlock writeBlock;

/// Block for printer status updates
@property (nonatomic, copy) POSWiFiPrinterStatusBlock statusBlock;

/// Block for retrieving printer serial number
@property (nonatomic, copy) POSWiFiPrinterSNBlock snBlock;

/// Connected printer profile
@property (nonatomic, strong) PrinterProfile *connectedPrinter;

/// Removes a specific delegate
/// @param delegate The delegate to be removed
- (void)removeDelegate:(id<WIFIConnecterDelegate>)delegate;

/// Removes all delegates
- (void)removeAllDelegates;

/// Disconnects from the printer
- (void)disconnect;

/// Sends a command to the printer
/// @param data The data to be sent as a command
- (void)writeCommandWithData:(NSData *)data;

/// Sends a command to the printer with a receive callback
/// @param data The data to be sent as a command
/// @param receiveBlock Block to be called upon receiving data
- (void)writeCommandWithData:(NSData *)data receiveCallBack:(WIFIConnecterReceiveBlock)receiveBlock;

/// Sends a command to the printer with a write callback
/// @param data The data to be sent as a command
/// @param writeBlock Block to be called upon completion of the write operation
- (void)writeCommandWithData:(NSData *)data writeCallBack:(WIFIConnecterWriteBlock)writeBlock;

/// Sends a command to the printer with subpackaging and a write callback
/// @param data The data to be sent as a command
/// @param subpackageLength Length of each subpackage
/// @param writeBlock Block to be called upon completion of the write operation
- (void)writeCommandWithData:(NSData *)data subpackageLength:(int)subpackageLength writeCallBack:(WIFIConnecterWriteBlock)writeBlock;

/// Checks the connection status of the printer
/// @return YES if connected, NO otherwise
- (BOOL)printerCheckWithMac;

/// Retrieves the printer status
/// @param statusBlock Block to be called with the printer status
- (void)printerStatus:(POSWiFiPrinterStatusBlock)statusBlock;

/// Retrieves the printer serial number
/// @param snBlock Block to be called with the printer serial number
- (void)printerSNWithSnBlock:(POSWiFiPrinterSNBlock)snBlock;

/// Connects to the printer using the host address
/// @param hostStr The host address as a string
/// @param port The port number to connect to
- (void)connectWithHost:(NSString *)hostStr port:(UInt16)port;

/// Connects to the printer using its MAC address
/// @param mac The MAC address of the printer
- (void)connectWithMac:(NSString *)mac;

/// Connects to the printer using a device profile
/// @param device The PrinterProfile object representing the printer
- (void)connectWithDevice:(PrinterProfile *)device;

/// Retrieves the label printer status
/// @param statusBlock Block to be called with the label printer status
- (void)labelPrinterStatus:(POSWiFiPrinterStatusBlock)statusBlock;

@end


