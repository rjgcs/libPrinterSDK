//
//  POSWIFIManager.h
//  Printer
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PrinterProfile.h"

@class POSWIFIManager;
@protocol POSWIFIManagerDelegate <NSObject>
@optional
/// Called when connected successfully.
/// @param host The host address.
/// @param port The port number.
- (void)POSwifiConnectedToHost:(NSString *)host port:(UInt16)port;

/// Called when there is a disconnect error.
/// @param error The error that occurred during disconnection.
- (void)POSwifiDisconnectWithError:(NSError *)error;

/// Called when data is sent successfully.
/// @param tag The tag associated with the sent data.
- (void)POSwifiWriteValueWithTag:(long)tag;

/// Called when printer data is received.
/// @param data The received data.
- (void)POSwifiReceiveValueForData:(NSData *)data;
@end

/// Block type for handling received data from the printer.
/// @param data The data received from the printer.
typedef void (^POSWIFIManagerReceiveBlock)(NSData *data);

/// Block type for handling the result of write operations to the printer.
/// @param success Indicates whether the write operation was successful.
/// @param error The error that occurred, if any.
typedef void (^POSWIFIManagerWriteBlock)(BOOL success, NSError *error);

/// Block type for handling the status information of the printer.
/// @param status The status data received from the printer.
typedef void (^POSWiFiPrinterStatusBlock)(NSData *status);

/// Block type for handling the serial number of the printer.
/// @param sn The serial number of the printer.
typedef void (^POSWiFiPrinterSNBlock)(NSString *sn);

/// Block type for handling printer check responses.
/// @param check The check data received from the printer.
typedef void (^POSWiFiPrinterCheckBlock)(NSData *check);

@class PrinterProfile;

/// Block type for handling found printer information.
/// @param foundPrinter The profile of the printer that was found.
typedef void (^POSWiFiManagerFoundPrinterBlock)(PrinterProfile *foundPrinter);

@interface POSWIFIManager : NSObject

/// Host address.
@property (nonatomic, copy) NSString *hostStr;

/// Port number.
@property (nonatomic, assign) UInt16 port;

/// Connection status.
@property (nonatomic, assign) BOOL isConnect;

/// Delegate for handling Wi-Fi manager events.
@property (nonatomic, weak) id<POSWIFIManagerDelegate> delegate;

/// Block to handle received data from the printer.
@property (nonatomic, copy) POSWIFIManagerReceiveBlock receiveBlock;

/// Block to handle the result of write operations to the printer.
@property (nonatomic, copy) POSWIFIManagerWriteBlock writeBlock;

/// Block to execute when a printer is found.
@property (nonatomic, copy) POSWiFiManagerFoundPrinterBlock foundPrinterBlock;

/// Block to handle the printer's status information.
@property (nonatomic, copy) POSWiFiPrinterStatusBlock statusBlock;

/// Block to handle the printer's serial number.
@property (nonatomic, copy) POSWiFiPrinterSNBlock snBlock;

/// Block to handle printer check responses.
@property (nonatomic, copy) POSWiFiPrinterCheckBlock checkBlock;

/// The profile of the currently connected printer.
@property (nonatomic, strong) PrinterProfile *connectedPrinter;

/// Returns the shared instance of the manager.
+ (instancetype)sharedInstance;

/// Removes a specific delegate.
/// @param delegate The delegate to remove.
- (void)removeDelegate:(id<POSWIFIManagerDelegate>)delegate;

/// Removes all delegates.
- (void)removeAllDelegates;

/// Connects to the printer at the specified host and port.
/// @param hostStr The host address.
/// @param port The port number.
- (void)connectWithHost:(NSString *)hostStr port:(UInt16)port;

/// Disconnects from the printer.
- (void)disconnect;

/// Writes a command to the printer.
/// @param data The data to send.
- (void)writeCommandWithData:(NSData *)data;

/// Writes a command to the printer with a receive callback.
/// @param data The data to send.
/// @param receiveBlock The block to execute upon receiving data.
- (void)writeCommandWithData:(NSData *)data receiveCallBack:(POSWIFIManagerReceiveBlock)receiveBlock;

/// Writes a command to the printer with a write callback.
/// @param data The data to send.
/// @param receiveBlock The block to execute upon completion.
- (void)writeCommandWithData:(NSData *)data writeCallBack:(POSWIFIManagerWriteBlock)receiveBlock;

/// Creates a UDP socket.
/// @return YES if the socket was created successfully, NO otherwise.
- (BOOL)createUdpSocket;

/// Closes the UDP socket.
- (void)closeUdpSocket;

/// Searches for printers.
/// @param foundPrinterBlock The block to execute when a printer is found.
- (void)sendFindCmd:(POSWiFiManagerFoundPrinterBlock)foundPrinterBlock;

/// Sets the IP configuration.
/// @param ip The IP address.
/// @param mask The subnet mask.
/// @param gateway The gateway address.
/// @param dhcp Indicates whether to use DHCP.
- (void)setIPConfigWithIP:(NSString *)ip Mask:(NSString *)mask Gateway:(NSString *)gateway DHCP:(BOOL)dhcp;

/// Sets the Wi-Fi configuration.
/// @param ip The IP address.
/// @param mask The subnet mask.
/// @param gateway The gateway address.
/// @param ssid The Wi-Fi SSID.
/// @param password The Wi-Fi password.
/// @param encrypt The encryption type.
- (void)setWiFiConfigWithIP:(NSString *)ip mask:(NSString *)mask gateway:(NSString *)gateway ssid:(NSString *)ssid password:(NSString *)password encrypt:(NSUInteger)encrypt;

/// Checks if the printer is connected.
/// @return YES if connected, NO otherwise.
- (BOOL)printerIsConnect;

/// Retrieves the printer's serial number.
/// @param snBlock The block to execute with the serial number.
- (void)printerSN:(POSWiFiPrinterSNBlock)snBlock;

/// Connects to the printer using its MAC address.
/// @param macStr The MAC address of the printer.
- (void)connectWithMac:(NSString *)macStr;

/// Retrieves the copyright information.
/// @return The copyright string.
+ (NSString *)GetCopyRight;

/// Queries the current printer status (normal/out of paper/open cover, etc.).
/// @param statusBlock The block to execute with the printer status.
///
/// | Enum Value                      | Description                            | Hex Value |
/// |----------------------------------|----------------------------------------|-----------|
/// | POSPrinterNormal                 | Printer is in normal status            | 0x12      |
/// | POSPrinterCoverOpened            | Printer cover is opened                | 0x16      |
/// | POSPrinterPaperEnd               | Printer is out of paper                | 0x32      |
/// | POSPrinterCoverOpenedAndPaperEnd | Cover is opened and printer is out of paper | 0x36  |
/// | POSPrinterFeeding                | Printer is feeding paper               | 0x1A      |
/// | POSPrinterCashBoxOpen            | Cash box is open                       | 0x00      |
/// | POSPrinterCashBoxClosed          | Cash box is closed                     | 0x01      |
- (void)printerStatus:(POSWiFiPrinterStatusBlock)statusBlock;

/// Queries all printer statuses.
/// @param type The type of status to check.
///
/// | Enum Value                      | Description             | Hex Value |
/// |----------------------------------|-------------------------|-----------|
/// | POSPrinterStatusTypePrint        | Print status            | 0x01      |
/// | POSPrinterStatusTypeOffline      | Offline status          | 0x02      |
/// | POSPrinterStatusTypeError        | Error status            | 0x03      |
/// | POSPrinterStatusTypePaper        | Paper transmission status | 0x04      |
///
/// @param checkBlock The block to execute with the check results.
- (void)printerCheck:(int)type checkBlock:(POSWiFiPrinterCheckBlock)checkBlock;

@end

