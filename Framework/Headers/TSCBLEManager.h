//
//  TSCBLEManager.h
//  Printer
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@protocol TSCBLEManagerDelegate <NSObject>
@optional

/// Updates the list of found peripherals
/// @param peripherals An array of discovered peripherals
/// @param rssiList An array of RSSI values corresponding to the peripherals
- (void)TSCbleUpdatePeripheralList:(NSArray *)peripherals RSSIList:(NSArray *)rssiList;

/// Called when the connection to a peripheral is successful
/// @param peripheral The connected CBPeripheral instance
- (void)TSCbleConnectPeripheral:(CBPeripheral *)peripheral;

/// Called when the connection to a peripheral fails
/// @param peripheral The CBPeripheral instance that failed to connect
/// @param error An NSError object describing the connection failure
- (void)TSCbleFailToConnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;

/// Called when a peripheral is disconnected
/// @param peripheral The disconnected CBPeripheral instance
/// @param error An NSError object describing the disconnection, if any
- (void)TSCbleDisconnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;

/// Called when data is successfully sent to a characteristic
/// @param characteristic The CBCharacteristic that was written to
/// @param error An NSError object describing any error that occurred during the write operation
- (void)TSCbleWriteValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

/// Called when data is received from a characteristic
/// @param characteristic The CBCharacteristic from which data was received
/// @param error An NSError object describing any error that occurred during the receive operation
- (void)TSCbleReceiveValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

/// Called when the BLE central manager's state is updated
/// @param state The new state of the central manager
- (void)TSCbleCentralManagerDidUpdateState:(NSInteger)state;

@end

/// Block called upon receiving data
typedef void (^TSCBLEManagerReceiveCallBackBlock)(CBCharacteristic *characteristic, NSError *error);

/// Block called upon writing data
typedef void (^TSCBLEManagerWriteCallBackBlock)(CBCharacteristic *characteristic, NSError *error);

/// Block called for printer status updates
typedef void (^TSCBLEPrinterStatusBlock)(NSData *status);

/// Block called for retrieving printer serial number
typedef void (^TSCBLEPrinterSNBlock)(NSString *sn);

@interface TSCBLEManager : NSObject

/// The Bluetooth name of the device
@property (nonatomic, copy) NSString *name;

/// Indicates whether the manager is currently connecting to a peripheral
@property (nonatomic, assign) BOOL isConnecting;

/// Indicates whether the manager is currently scanning for peripherals
@property (nonatomic, assign) BOOL isScaning;

/// The peripheral used for writing data
@property (nonatomic, strong) CBPeripheral *writePeripheral;

/// The characteristic used for writing data
@property (nonatomic, strong) CBCharacteristic *write_characteristic;

/// The characteristic used for reading data
@property (nonatomic, strong) CBCharacteristic *read_characteristic;

/// The characteristic used for notifications
@property (nonatomic, strong) CBCharacteristic *notify_characteristic;

/// The UUID used to filter the search for printers
@property (nonatomic, strong) CBUUID *searchFilterUUID;

/// The UUID of the characteristic
@property (nonatomic, strong) CBUUID *characteristicUUID;

/// The delegate to receive updates from the BLE manager
@property (nonatomic, weak) id<TSCBLEManagerDelegate> delegate;

/// Block called when data is received
@property (nonatomic, copy) TSCBLEManagerReceiveCallBackBlock receiveBlock;

/// Block called when data is written
@property (nonatomic, copy) TSCBLEManagerWriteCallBackBlock writeBlock;

/// Block called for printer status updates
@property (nonatomic, copy) TSCBLEPrinterStatusBlock statusBlock;

/// Block called for retrieving printer serial number
@property (nonatomic, copy) TSCBLEPrinterSNBlock snBlock;

/// Block called for state updates
@property (nonatomic, copy) TSCBLEPrinterStatusBlock stateBlock;

/// Block called upon completion of writing data
@property (nonatomic, copy) void (^writeCompletion)(BOOL success, NSUInteger totalBytesSent, NSUInteger currentPackageIndex, NSError *error);

/// Retrieves the shared instance of TSCBLEManager
/// @return The shared instance of TSCBLEManager
+ (instancetype)sharedInstance;

/// Removes a specific delegate
/// @param delegate The delegate to be removed
- (void)removeDelegate:(id<TSCBLEManagerDelegate>)delegate;

/// Removes all delegates
- (void)removeAllDelegates;

/// Starts scanning for Bluetooth peripherals.
/// This method should be triggered after confirming that Bluetooth is enabled and authorized.
/// It is recommended to invoke this method within the delegate callback
/// - (void)TSCbleCentralManagerDidUpdateState:(NSInteger)state;
/// when the state indicates that Bluetooth is powered on and authorized for use.
- (void)startScan;

/// Stops scanning for peripherals
- (void)stopScan;

/// Connects to a specific peripheral
/// @param peripheral The CBPeripheral instance to connect to
- (void)connectDevice:(CBPeripheral *)peripheral;

/// Disconnects from the currently connected peripheral
- (void)disconnectRootPeripheral;

/// Sends a command with response
/// @param data The data to be sent as a command
- (void)writeCommandWithData:(NSData *)data;

/// Sends a command with a receive callback
/// @param data The data to be sent as a command
/// @param receiveBlock Block to be called upon receiving data
- (void)writeCommandWithData:(NSData *)data receiveCallBack:(TSCBLEManagerReceiveCallBackBlock)receiveBlock;

/// Sends a command with a write callback
/// @param data The data to be sent as a command
/// @param writeBlock Block to be called upon completion of the write operation
- (void)writeCommandWithData:(NSData *)data writeCallBack:(TSCBLEManagerWriteCallBackBlock)writeBlock;

/// Returns the copyright information
/// @return A string containing the copyright information
+ (NSString *)GetCopyRight;

/// Retrieves the printer status
///
/// | Label Printer Status                    | Description                          | Value    |
/// |-----------------------------------------|--------------------------------------|----------|
/// | `LabelPrinterReady`                     | Printer is ready                     | `0x00`   |
/// | `LabelPrinterCoverOpened`               | Cover is opened                      | `0x01`   |
/// | `LabelPrinterPaperJam`                  | Paper jam detected                   | `0x02`   |
/// | `LabelPrinterCoverOpenedAndPaperJam`    | Cover is opened and paper jam         | `0x03`   |
/// | `LabelPrinterPaperEnd`                  | Out of paper                         | `0x04`   |
/// | `LabelPrinterCoverOpenedAndPaperEnd`    | Cover is opened and out of paper      | `0x05`   |
/// | `LabelPrinterNoRibbon`                  | No ribbon detected                   | `0x08`   |
/// | `LabelPrinterCoverOpenedAndNoRibbon`    | Cover is opened and no ribbon         | `0x09`   |
/// | `LabelPrinterPause`                     | Printer is paused                    | `0x10`   |
/// | `LabelPrinterPrinting`                  | Printer is printing                  | `0x20`   |
///
/// @param statusBlock Block to be called with the printer status (see table above)
- (void)printerStatus:(TSCBLEPrinterStatusBlock)statusBlock;

/// Sends data in specified package sizes and reports progress via a completion handler
/// @param data The NSData object containing the data to be sent
/// @param packageSize The size of each data package to be sent, in bytes
/// @param completion A block to be executed when the sending operation is completed or an error occurs
- (void)sendData:(NSData *)data withPackageSize:(NSUInteger)packageSize completion:(void (^)(BOOL success, NSUInteger totalBytesSent, NSUInteger currentPackageIndex, NSError *error))completion;

/// Sends a command without expecting a response
/// @param data The data to be sent as a command
- (void)writeCommandDataWithoutResponse:(NSData *)data;

@end

