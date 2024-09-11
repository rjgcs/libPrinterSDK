//
//  POSBLEManager.h
//  Printer
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@protocol POSBLEManagerDelegate <NSObject>
@optional
/// Update the list of found peripherals.
/// @param peripherals The array of found peripherals.
/// @param rssiList The array of RSSI values corresponding to the found peripherals.
- (void)POSbleUpdatePeripheralList:(NSArray *)peripherals RSSIList:(NSArray *)rssiList;

/// Called when a connection to a peripheral is successful.
/// @param peripheral The connected peripheral.
- (void)POSbleConnectPeripheral:(CBPeripheral *)peripheral;

/// Called when a connection to a peripheral fails.
/// @param peripheral The peripheral that failed to connect.
/// @param error The error that occurred during the connection attempt.
- (void)POSbleFailToConnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;

/// Called when a peripheral is disconnected.
/// @param peripheral The disconnected peripheral.
/// @param error The error that occurred during disconnection, if any.
- (void)POSbleDisconnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;

/// Called when data is successfully written to a characteristic.
/// @param character The characteristic that was written to.
/// @param error The error that occurred during the write operation, if any.
- (void)POSbleWriteValueForCharacteristic:(CBCharacteristic *)character error:(NSError *)error;

/// Called when data is received from a characteristic.
/// @param characteristic The characteristic from which data was received.
/// @param error The error that occurred during the receive operation, if any.
- (void)POSbleReceiveValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

/// Called when the state of the BLE central manager is updated.
/// @param state The updated state of the central manager.
- (void)POSbleCentralManagerDidUpdateState:(NSInteger)state;

@end

/// Block type for handling received data from a characteristic.
/// @param characteristic The characteristic from which data was received.
/// @param error The error that occurred during the receive operation, if any.
typedef void (^POSBLEManagerReceiveCallBackBlock)(CBCharacteristic *characteristic, NSError *error);

/// Block type for handling the result of write operations to a characteristic.
/// @param characteristic The characteristic that was written to.
/// @param error The error that occurred during the write operation, if any.
typedef void (^POSBLEManagerWriteCallBackBlock)(CBCharacteristic *characteristic, NSError *error);

/// Block type for handling the status information of the printer.
/// @param status The status data received from the printer.
typedef void (^POSBLEPrinterStatusBlock)(NSData *status);

/// Block type for handling the serial number of the printer.
/// @param sn The serial number of the printer.
typedef void (^POSBLEPrinterSNBlock)(NSString *sn);

/// Block type for handling printer check responses.
/// @param check The check data received from the printer.
typedef void (^POSBLEPrinterCheckBlock)(NSData *check);

@interface POSBLEManager : NSObject

/// Bluetooth name.
@property (nonatomic, copy) NSString *name;

/// Connection status.
@property (nonatomic, assign) BOOL isConnecting;

/// Scanning status.
@property (nonatomic, assign) BOOL isScaning;

/// Peripheral to write to.
@property (nonatomic, strong) CBPeripheral *writePeripheral;

/// Characteristic for writing data.
@property (nonatomic, strong) CBCharacteristic *write_characteristic;

/// Characteristic for reading data.
@property (nonatomic, strong) CBCharacteristic *read_characteristic;

/// Characteristic for notifications.
@property (nonatomic, strong) CBCharacteristic *notify_characteristic;

/// UUID used to filter printers during search.
@property (nonatomic, strong) CBUUID *searchFilterUUID;

/// UUID of the characteristic.
@property (nonatomic, strong) CBUUID *characteristicUUID;

@property (nonatomic, weak) id<POSBLEManagerDelegate> delegate;

@property (nonatomic, copy) POSBLEManagerReceiveCallBackBlock receiveBlock;
@property (nonatomic, copy) POSBLEManagerWriteCallBackBlock writeBlock;
@property (nonatomic, copy) POSBLEPrinterStatusBlock statusBlock;
@property (nonatomic, copy) POSBLEPrinterSNBlock snBlock;
@property (nonatomic, copy) POSBLEPrinterCheckBlock checkBlock;

/// Completion block for write operations.
@property (nonatomic, copy) void (^writeCompletion)(BOOL success, NSUInteger totalBytesSent, NSUInteger currentPackageIndex, NSError *error);

/// Returns the shared instance of the manager.
+ (instancetype)sharedInstance;

/// Removes a specific delegate.
/// @param delegate The delegate to remove.
- (void)removeDelegate:(id<POSBLEManagerDelegate>)delegate;

/// Removes all delegates.
- (void)removeAllDelegates;

/// Starts scanning for Bluetooth peripherals.
/// This method should be triggered after confirming that Bluetooth is enabled and authorized.
/// It is recommended to invoke this method within the delegate callback
/// - (void)POSbleCentralManagerDidUpdateState:(NSInteger)state;
/// when the state indicates that Bluetooth is powered on and authorized for use.
- (void)startScan;

/// Stops scanning for peripherals.
- (void)stopScan;

/// Connects to a specified peripheral.
/// @param peripheral The peripheral to connect to.
- (void)connectDevice:(CBPeripheral *)peripheral;

/// Manually disconnects the root peripheral.
- (void)disconnectRootPeripheral;

/// Sends a command (Write with Response).
/// @param data The data to send.
- (void)writeCommandWithData:(NSData *)data;

/// Sends command data with a receive callback (Write with Response).
/// @param data The data to send.
/// @param receiveBlock The block to execute upon receiving data.
- (void)writeCommandWithData:(NSData *)data receiveCallBack:(POSBLEManagerReceiveCallBackBlock)receiveBlock;

/// Sends command data with a write callback (Write with Response).
/// @param data The data to send.
/// @param writeBlock The block to execute upon completion of the write operation.
- (void)writeCommandWithData:(NSData *)data writeCallBack:(POSBLEManagerWriteCallBackBlock)writeBlock;

/// Sets the Bluetooth name and key.
/// @param btName The Bluetooth name.
/// @param btKey The Bluetooth key.
- (void)setBluetoothNameAndKeyWith:(NSString *)btName btKey:(NSString *)btKey;

/// Checks the connection status of the printer.
/// @return A Boolean indicating whether the printer is connected.
- (BOOL)printerIsConnect;

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
- (void)printerStatus:(POSBLEPrinterStatusBlock)statusBlock;

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
- (void)printerCheck:(int)type checkBlock:(POSBLEPrinterCheckBlock)checkBlock;

/// Queries the printer's serial number.
/// @param snBlock The block to execute with the serial number.
- (void)printerSN:(POSBLEPrinterSNBlock)snBlock;

/// Gets the copyright information.
/// @return A string containing the copyright information.
+ (NSString *)GetCopyRight;

/// Sends data in specified package sizes and reports the progress via a completion handler.
/// @param data The NSData object containing the data to be sent.
/// @param packageSize The size of each data package to be sent, in bytes.
/// @param completion A block to be executed when the sending operation is completed or an error occurs.
///         The block takes the following parameters:
///         - success: A Boolean indicating whether the data was sent successfully.
///         - totalBytesSent: The total number of bytes that have been sent.
///         - currentPackageIndex: The index of the current package being sent.
///         - error: An NSError object that describes the problem, if any.
- (void)sendData:(NSData *)data withPackageSize:(NSUInteger)packageSize completion:(void (^)(BOOL success, NSUInteger totalBytesSent, NSUInteger currentPackageIndex, NSError *error))completion;

/// Sends command data without expecting a response.
/// @param data The data to send.
- (void)writeCommandDataWithoutResponse:(NSData *)data;

@end
