//
//  TSCWIFIManager.h
//  Printer
//

#import <Foundation/Foundation.h>

typedef void(^TSCWIFIManagerReceiveBlock)(NSData *data);
typedef void(^TSCWIFIManagerWriteBlock)(long tag);
typedef void (^TSCWIFIPrinterStatusBlock)(NSData *status);

@class TSCWIFIManager;
@protocol TSCWIFIManagerDelegate <NSObject>
@optional
/// Called when the connection to the host is successful
/// @param host The host address
/// @param port The port number
- (void)TSCwifiConnectedToHost:(NSString *)host port:(UInt16)port;

/// Called when there is an error during disconnection
/// @param error An NSError object describing the disconnection error
- (void)TSCwifiDisconnectWithError:(NSError *)error;

/// Called when data is successfully sent
/// @param tag The tag associated with the sent data
- (void)TSCwifiWriteValueWithTag:(long)tag;

/// Called when printer data is received
/// @param data The received NSData object
- (void)TSCwifiReceiveValueForData:(NSData *)data;
@end

@interface TSCWIFIManager : NSObject

/// The host address for the printer
@property (nonatomic, copy) NSString *hostStr;

/// The port number for the connection
@property (nonatomic, assign) UInt16 port;

/// Indicates whether the manager is currently connected
@property (nonatomic, assign) BOOL isConnect;

/// The delegate to receive updates from the WIFI manager
@property (nonatomic, weak) id<TSCWIFIManagerDelegate> delegate;

/// Block called when data is received
@property (nonatomic, copy) TSCWIFIManagerReceiveBlock receiveBlock;

/// Block called when data is written
@property (nonatomic, copy) TSCWIFIManagerWriteBlock writeBlock;

/// Block called for printer status updates
@property (nonatomic, copy) TSCWIFIPrinterStatusBlock statusBlock;

/// Retrieves the shared instance of TSCWIFIManager
/// @return The shared instance of TSCWIFIManager
+ (instancetype)sharedInstance;

/// Connects to the printer at the specified address
/// @param hostStr The host address of the printer
/// @param port The port number for the connection
- (void)connectWithHost:(NSString *)hostStr port:(UInt16)port;

/// Disconnects from the printer
- (void)disconnect;

/// Writes a command to the printer
/// @param data The NSData object containing the command to be sent
- (void)writeCommandWithData:(NSData *)data;

/// Removes a specific delegate
/// @param delegate The delegate to be removed
- (void)removeDelegate:(id<TSCWIFIManagerDelegate>)delegate;

/// Removes all delegates
- (void)removeAllDelegates;

/// Writes a command to the printer with a receive callback
/// @param data The NSData object containing the command to be sent
/// @param receiveBlock Block to be called upon receiving data
- (void)writeCommandWithData:(NSData *)data receiveCallBack:(TSCWIFIManagerReceiveBlock)receiveBlock;

/// Writes a command to the printer with a write callback
/// @param data The NSData object containing the command to be sent
/// @param writeBlock Block to be called upon completion of the write operation
- (void)writeCommandWithData:(NSData *)data writeCallBack:(TSCWIFIManagerWriteBlock)writeBlock;

/// Retrieves the printer status
/// @param statusBlock Block to be called with the printer status
- (void)printerStatus:(TSCWIFIPrinterStatusBlock)statusBlock;

/// Retrieves the copyright information
/// @return A string containing the copyright information
+ (NSString *)GetCopyRight;

@end
