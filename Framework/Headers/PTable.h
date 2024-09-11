//
//  PTable.h
//  PrinterSDK
//
//  Created by Apple Mac mini intel on 2023/11/27.
//  Copyright © 2023 Admin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents table alignment types
typedef NS_ENUM(NSInteger, TableAlignType) {
    /// All text content aligned to the left
    ALL_LEFT_ALIGN,
    /// All text content aligned to the right
    ALL_RIGHT_ALIGN,
    /// Only the first column text aligned to the left, others aligned to the right
    FIRST_LEFT_ALIGN,
};

/// Represents barcode types
typedef NS_ENUM(NSInteger, BCSBarcodeType) {
    BCS_UPCA,    ///< Universal Product Code (UPC-A)
    BCS_UPCE,    ///< Universal Product Code (UPC-E)
    BCS_EAN13,   ///< European Article Number (EAN-13)
    BCS_EAN8,    ///< European Article Number (EAN-8)
    BCS_Code39,  ///< Code 39
    BCS_ITF,     ///< Interleaved 2 of 5
    BCS_Codabar, ///< Codabar
    BCS_Code93,  ///< Code 93
    BCS_Code128  ///< Code 128
};

/// Represents barcode HRI (Human-Readable Interpretation) text positions
typedef NS_ENUM(NSInteger, BarHriText) {
    BAR_HRI_TEXT_NONE = 0,  ///< No HRI text
    BAR_HRI_TEXT_BELOW,     ///< HRI text below the barcode
    BAR_HRI_TEXT_ABOVE,     ///< HRI text above the barcode
    BAR_HRI_TEXT_BOTH       ///< HRI text both above and below the barcode
};

@interface PTable : NSObject

/// Automatically wraps text if it exceeds the preset character width
/// @param titles Array of titles for the table
/// @param lengths Array of lengths for each title
/// @param align Alignment type for the table
/// @return Data representing the auto-wrapped table
+ (NSData *)addAutoTableH:(NSArray<NSString *> *)titles titleLength:(NSArray<NSNumber *> *)lengths align:(TableAlignType)align;

/// Adds a barcode row
/// @param data Data to be encoded in the barcode
/// @param type Type of the barcode
/// @param hri Position of the HRI text
/// @return Data representing the barcode row
+ (NSData *)addBarcodeRow:(NSString *)data type:(BCSBarcodeType)type hri:(BarHriText)hri;

@end


NS_ASSUME_NONNULL_END
