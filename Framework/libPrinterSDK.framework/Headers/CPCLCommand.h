//
//  CPCLCommand.h
//  Printer
//
//  Created by apple on 2022/9/20.
//  Copyright © 2022 Admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// Rotation
typedef NS_ENUM(NSInteger, CPCLRotation) {
    ROTA_0 = 0,
    ROTA_90,
    ROTA_180,
    ROTA_270
};

/// Font
typedef NS_ENUM(NSInteger, CPCLFont) {
    FNT_0 = 0,
    FNT_1 = 1,
    FNT_2 = 2,
    FNT_3 = 3,
    FNT_4 = 4,
    FNT_5 = 5,
    FNT_6 = 6,
    FNT_7 = 7,
    FNT_24 = 24,
    FNT_55 = 55
};

/// BarCode
typedef NS_ENUM(NSInteger, CPCLBarCode) {
    BC_128 = 0,
    BC_UPCA,
    BC_UPCE,
    BC_EAN13,
    BC_EAN8,
    BC_39,
    BC_93,
    BC_CODABAR
};

/// Bar Code Ratio
typedef NS_ENUM(NSInteger, CPCLBarCodeRatio) {
    BCR_RATIO_0 = 0,
    BCR_RATIO_1 = 1,
    BCR_RATIO_2 = 2,
    BCR_RATIO_3 = 3,
    BCR_RATIO_4 = 4,
    BCR_RATIO_20 = 20,
    BCR_RATIO_21 = 21,
    BCR_RATIO_22 = 22,
    BCR_RATIO_23 = 23,
    BCR_RATIO_24 = 24,
    BCR_RATIO_25 = 25,
    BCR_RATIO_26 = 26,
    BCR_RATIO_27 = 27,
    BCR_RATIO_28 = 28,
    BCR_RATIO_29 = 29,
    BCR_RATIO_30 = 30
};

/// QR Code Mode
typedef NS_ENUM(NSInteger, CPCLQRCodeMode) {
    CODE_MODE_ORG = 1,
    CODE_MODE_ENHANCE = 2
};

/// Alignment
typedef NS_ENUM(NSInteger, CPCLAlignment) {
    ALIGNMENT_LEFT = 0,
    ALIGNMENT_CENTER,
    ALIGNMENT_RIGHT
};

@interface CPCLCommand : NSObject

/// Initializes the label
/// @param height The height of the label
/// @return NSData object representing the command
+ (NSData *)initLabelWithHeight:(int)height;

/// Initializes the label with specified count
/// @param height The height of the label
/// @param count The number of labels
/// @return NSData object representing the command
+ (NSData *)initLabelWithHeight:(int)height count:(int)count;

/// Initializes the label with specified count and offset
/// @param height The height of the label
/// @param count The number of labels
/// @param offsetx The horizontal offset position
/// @return NSData object representing the command
+ (NSData *)initLabelWithHeight:(int)height count:(int)count offsetx:(int)offsetx;

/// Sets the font magnification
/// @param w The width magnification (1-16)
/// @param h The height magnification (1-16)
/// @return NSData object representing the command
+ (NSData *)setmagWithw:(int)w h:(int)h;

/// Sets the alignment of fields (default: left aligned)
/// @param alignment The alignment type
/// @return NSData object representing the command
+ (NSData *)setAlignment:(CPCLAlignment)alignment;

/// Sets the alignment of fields with a specified end point (default: left aligned)
/// @param alignment The alignment type
/// @param end The end point for alignment
/// @return NSData object representing the command
+ (NSData *)setAlignment:(CPCLAlignment)alignment end:(int)end;

/// Sets the printing speed
/// @param level The speed level (0-5)
/// @return NSData object representing the command
+ (NSData *)setSpeedLevel:(int)level;

/// Sets the page width
/// @param width The unit width of the page
/// @return NSData object representing the command
+ (NSData *)setPageWidth:(int)width;

/// Sets the beep duration
/// @param length The duration of the beep, in 1/8 seconds (e.g., 16 means 2 seconds)
/// @return NSData object representing the command
+ (NSData *)setBeepLength:(int)length;

/// Sets the character encoding
/// @param encoding The NSStringEncoding to use
+ (void)setStringEncoding:(NSStringEncoding)encoding;

/// Draws text content
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param content The text content
/// @return NSData object representing the command
+ (NSData *)drawTextWithx:(int)x y:(int)y content:(NSString *)content;

/// Draws text content with specified font
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param font The font type
/// @param content The text content
/// @return NSData object representing the command
+ (NSData *)drawTextWithx:(int)x y:(int)y font:(CPCLFont)font content:(NSString *)content;

/// Draws text content with specified font and rotation
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param rotation The rotation type
/// @param font The font type
/// @param content The text content
/// @return NSData object representing the command
+ (NSData *)drawTextWithx:(int)x y:(int)y rotation:(CPCLRotation)rotation font:(CPCLFont)font content:(NSString *)content;

/// Indicates the printer to switch to the top of the next page after finishing the current page
/// @return NSData object representing the command
+ (NSData *)form;

/// Ends the command and starts printing
/// @return NSData object representing the command
+ (NSData *)print;

/// Draws a barcode
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param codeType The type of barcode
/// @param height The height of the barcode
/// @param content The content of the barcode
/// @return NSData object representing the command
+ (NSData *)drawBarcodeWithx:(int)x y:(int)y codeType:(CPCLBarCode)codeType height:(int)height content:(NSString *)content;

/// Draws a barcode with specified height and ratio
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param codeType The type of barcode
/// @param height The height of the barcode
/// @param ratio The ratio of wide to narrow bars (default: BCR_RATIO_1)
/// @param content The content of the barcode
/// @return NSData object representing the command
+ (NSData *)drawBarcodeWithx:(int)x y:(int)y codeType:(CPCLBarCode)codeType height:(int)height ratio:(CPCLBarCodeRatio)ratio content:(NSString *)content;

/// Draws a vertical barcode
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param codeType The type of barcode
/// @param height The height of the barcode
/// @param content The content of the barcode
/// @return NSData object representing the command
+ (NSData *)drawBarcodeVerticalWithx:(int)x y:(int)y codeType:(CPCLBarCode)codeType height:(int)height content:(NSString *)content;

/// Draws a vertical barcode with specified height and ratio
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param codeType The type of barcode
/// @param height The height of the barcode
/// @param ratio The ratio of wide to narrow bars (default: BCR_RATIO_1)
/// @param content The content of the barcode
/// @return NSData object representing the command
+ (NSData *)drawBarcodeVerticalWithx:(int)x y:(int)y codeType:(CPCLBarCode)codeType height:(int)height ratio:(CPCLBarCodeRatio)ratio content:(NSString *)content;

/// Adds barcode text
/// @param offsetx The unit offset from the barcode to the text
/// @return NSData object representing the command
+ (NSData *)barcodeText:(int)offsetx;

/// Turns off barcode text
/// @return NSData object representing the command
+ (NSData *)barcodeTextOff;

/// Draws a QR code
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param content The content of the QR code
/// @return NSData object representing the command
+ (NSData *)drawQRCodeWithx:(int)x y:(int)y content:(NSString *)content;

/// Draws a QR code with specified parameters
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param codeModel The QR code mode
/// @param cellWidth The size of the cells (1-32, default: 6)
/// @param content The content of the QR code
/// @return NSData object representing the command
+ (NSData *)drawQRCodeWithx:(int)x y:(int)y codeModel:(CPCLQRCodeMode)codeModel cellWidth:(int)cellWidth content:(NSString *)content;

/// Draws an image
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param image The UIImage to draw
/// @return NSData object representing the command
+ (NSData *)drawImageWithx:(int)x y:(int)y image:(UIImage *)image;

/// Draws a rectangle
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param width The width of the rectangle
/// @param height The height of the rectangle
/// @param thickness The thickness of the rectangle lines
/// @return NSData object representing the command
+ (NSData *)drawBoxWithx:(int)x y:(int)y width:(int)width height:(int)height thickness:(int)thickness;

/// Draws a line
/// @param x The starting x-coordinate of the line (in points)
/// @param y The starting y-coordinate of the line (in points)
/// @param xend The ending x-coordinate of the line (in points)
/// @param yend The ending y-coordinate of the line (in points)
/// @param width The width of the line
/// @return NSData object representing the command
+ (NSData *)drawLineWithx:(int)x y:(int)y xend:(int)xend yend:(int)yend width:(int)width;

/// Inverts the colors in the specified area
/// @param x The starting x-coordinate of the inversion area (in points)
/// @param y The starting y-coordinate of the inversion area (in points)
/// @param xend The ending x-coordinate of the inversion area (in points)
/// @param yend The ending y-coordinate of the inversion area (in points)
/// @param width The width of the inversion area (in points)
/// @return NSData object representing the command
+ (NSData *)drawInverseLineWithx:(int)x y:(int)y xend:(int)xend yend:(int)yend width:(int)width;

@end


NS_ASSUME_NONNULL_END
