//
//  PrinterProfile.h
//  PrinterSDK
//
//  Created by Apple Mac mini intel on 2023/9/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PrinterProfile : NSObject

/// The name of the printer
@property (nonatomic, readonly) NSString *printerName;

/// A description of the printer
@property (nonatomic, readonly) NSString *printerDesc;

/// Sets the MAC address of the printer
/// @param mac The MAC address as NSData
- (void)setMAC:(NSData *)mac;

/// Sets the IP address of the printer
/// @param ip The IP address as NSData
- (void)setIP:(NSData *)ip;

/// Sets the subnet mask of the printer
/// @param mask The subnet mask as NSData
- (void)setMask:(NSData *)mask;

/// Sets the gateway address of the printer
/// @param gw The gateway address as NSData
- (void)setGateway:(NSData *)gw;

/// Enables or disables DHCP for the printer
/// @param dhcp A character indicating the DHCP status (1 for enabled, 0 for disabled)
- (void)setDHCP:(char)dhcp;

/// Retrieves the IP address as a string
/// @return The IP address as a NSString
- (NSString *)getIPString;

/// Retrieves the subnet mask as a string
/// @return The subnet mask as a NSString
- (NSString *)getMaskString;

/// Retrieves the gateway address as a string
/// @return The gateway address as a NSString
- (NSString *)getGatewayString;

/// Retrieves the DHCP status
/// @return The DHCP status as a character
- (char)getDHCP;

/// Retrieves the MAC address as an array of bytes
/// @return A pointer to the MAC address byte array
- (Byte *)getMACArray;

@end


NS_ASSUME_NONNULL_END
