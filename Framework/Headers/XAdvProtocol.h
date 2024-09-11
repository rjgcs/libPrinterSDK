//
//  XAdvProtocol.h
//  PrinterSDK
//
//  Created by max on 2024/5/19.
//

#import <Foundation/Foundation.h>
/// Define a block type named XTestBlock, with a parameter of type NSString and a void return type
typedef void (^XTestBlock)(NSString *code);
/// Define a protocol named XAdvProtocol, which inherits from the NSObject protocol
@protocol XAdvProtocol <NSObject>
/// The protocol declares the printerTest: method, which takes an XTestBlock type parameter named codeBlock
- (void)printerTest:(XTestBlock)codeBlock;

@end
