//
//  ZPLCommand.h
//  Printer
//
//  Created by apple on 2022/9/20.
//  Copyright © 2022 Admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// Rotation
typedef NS_ENUM(NSInteger, ZPLRotation) {
    ROTATION_0 = 0,
    ROTATION_90,
    ROTATION_180,
    ROTATION_270
};

/// Font
typedef NS_ENUM(NSInteger, ZPLFont) {
    FNT_9_5 = 0,
    FNT_11_7,
    FNT_18_10,
    FNT_42_20,
    FNT_26_13,
    FNT_60_40,
    FNT_34_22,
    FNT_24_24,
    FNT_20_18,
    FNT_28_24,
    FNT_35_31,
    FNT_40_35,
    FNT_48_42,
    FNT_59_53,
    FNT_80_71,
    FNT_15_12
};

/// CodeType
typedef NS_ENUM(NSInteger, ZPLBarCode) {
    CODE_TYPE_11 = 0,
    CODE_TYPE_25,
    CODE_TYPE_39,
    CODE_TYPE_EAN8,
    CODE_TYPE_UPCE,
    CODE_TYPE_93,
    CODE_TYPE_128,
    CODE_TYPE_EAN13,
    CODE_TYPE_CODA,
    CODE_TYPE_MSI,
    CODE_TYPE_PLESSEY,
    CODE_TYPE_UPCEAN,
    CODE_TYPE_UPCA
};

/// HriText
typedef NS_ENUM(NSInteger, ZPLHriText) {
    HRI_TEXT_NONE = 0,
    HRI_TEXT_BELOW,
    HRI_TEXT_ABOVE
};

/// CodePage
typedef NS_ENUM(NSInteger, ZPLCodePage) {
    CODE_PAGE_USA1 = 0,
    CODE_PAGE_USA2 = 1,
    CODE_PAGE_UK = 2,
    CODE_PAGE_NL = 3,
    CODE_PAGE_DK = 4,
    CODE_PAGE_SWEDE = 5,
    CODE_PAGE_GER = 6,
    CODE_PAGE_FR1 = 7,
    CODE_PAGE_FR2 = 8,
    CODE_PAGE_ITA = 9,
    CODE_PAGE_ES = 10,
    CODE_PAGE_JA = 12,
    CODE_PAGE_UTF8 = 28,
    CODE_PAGE_UTF16_BIG = 29,
    CODE_PAGE_UTF16_LITTLE = 30
};

NS_ASSUME_NONNULL_BEGIN

@interface ZPLCommand : NSObject

/// Command start
/// ^XA
/// @return NSData object representing the command
+ (NSData *)XA;

/// Command end
/// ^XZ
/// @return NSData object representing the command
+ (NSData *)XZ;

/// Sets the label width
/// @param width The width of the label
/// @return NSData object representing the command
+ (NSData *)setLabelWidth:(int)width;

/// Sets the label height
/// @param height The height of the label
/// @return NSData object representing the command
+ (NSData *)setLabelHeight:(int)height;

/// Sets the label density
/// @param density The density of the label
/// @return NSData object representing the command
+ (NSData *)setDensity:(int)density;

/// Sets the printing speed
/// @param speed The printing speed (1-14)
/// @return NSData object representing the command
+ (NSData *)setSpeed:(int)speed;

/// Sets the number of copies to print
/// @param count The number of copies
/// @return NSData object representing the command
+ (NSData *)setPageCount:(int)count;

/// Sets a custom font
/// @param fontName The name of the font
/// @param extension The file extension
/// @param alias The alias for the font
/// @param codePage The ZPL code page
/// @return NSData object representing the command
+ (NSData *)setCustomFont:(NSString *)fontName extension:(NSString *)extension alias:(NSString *)alias codePage:(ZPLCodePage)codePage;

/// Sets the string encoding
/// @param encoding The NSStringEncoding to use
+ (void)setStringEncoding:(NSStringEncoding)encoding;

/// Draws text with specified font
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param fontName The ZPLFont to use
/// @param content The text content
/// @return NSData object representing the command
+ (NSData *)drawTextWithx:(int)x y:(int)y fontName:(ZPLFont)fontName content:(NSString *)content;

/// Draws text with specified font and size ratios
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param fontName The ZPLFont to use
/// @param hRatio The height ratio (1, 2, 3...)
/// @param wRatio The width ratio (1, 2, 3...)
/// @param content The text content
/// @return NSData object representing the command
+ (NSData *)drawTextWithx:(int)x y:(int)y fontName:(ZPLFont)fontName hRatio:(int)hRatio wRatio:(int)wRatio content:(NSString *)content;

/// Draws text with specified font, rotation, and size ratios
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param fontName The ZPLFont to use
/// @param rotation The rotation angle
/// @param hRatio The height ratio (1, 2, 3...)
/// @param wRatio The width ratio (1, 2, 3...)
/// @param content The text content
/// @return NSData object representing the command
+ (NSData *)drawTextWithx:(int)x y:(int)y fontName:(ZPLFont)fontName rotation:(ZPLRotation)rotation hRatio:(int)hRatio wRatio:(int)wRatio content:(NSString *)content;

/// Draws text with a custom font
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param customFontName The name of the custom font
/// @param hSize The height size multiplier
/// @param wSize The width size multiplier
/// @param content The text content
/// @return NSData object representing the command
+ (NSData *)drawTextWithx:(int)x y:(int)y customFontName:(NSString *)customFontName hSize:(int)hSize wSize:(int)wSize content:(NSString *)content;

/// Draws text with a custom font and rotation
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param customFontName The name of the custom font
/// @param rotation The rotation angle
/// @param hSize The height size multiplier
/// @param wSize The width size multiplier
/// @param content The text content
/// @return NSData object representing the command
+ (NSData *)drawTextWithx:(int)x y:(int)y customFontName:(NSString *)customFontName rotation:(ZPLRotation)rotation hSize:(int)hSize wSize:(int)wSize content:(NSString *)content;

/// Draws text with default font (FNT_26_13)
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param content The text content
/// @return NSData object representing the command
+ (NSData *)drawTextWithx:(int)x y:(int)y content:(NSString *)content;

/// Draws a barcode
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param codeType The type of barcode to draw
/// @param text The content of the barcode
/// @return NSData object representing the command
+ (NSData *)drawBarcodeWithx:(int)x y:(int)y codeType:(ZPLBarCode)codeType text:(NSString *)text;

/// Draws a barcode with specified height
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param codeType The type of barcode to draw
/// @param height The height of the barcode
/// @param text The content of the barcode
/// @return NSData object representing the command
+ (NSData *)drawBarcodeWithx:(int)x y:(int)y codeType:(ZPLBarCode)codeType height:(int)height text:(NSString *)text;

/// Draws a barcode with orientation and other parameters
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param orientation The orientation of the barcode
/// @param width The width of the barcode modules (1-10)
/// @param height The height of the barcode
/// @param hriText The HRI text position
/// @param text The content of the barcode
/// @return NSData object representing the command
+ (NSData *)drawBarcodeWithx:(int)x y:(int)y orientation:(ZPLRotation)orientation codeType:(ZPLBarCode)codeType width:(int)width height:(int)height hriText:(ZPLHriText)hriText text:(NSString *)text;

/// Draws a QR code
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param factor The magnification factor (1-10)
/// @param text The content of the QR code
/// @return NSData object representing the command
+ (NSData *)drawQRCodeWithx:(int)x y:(int)y factor:(int)factor text:(NSString *)text;

/// Draws an image
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param image The UIImage to draw
/// @return NSData object representing the command
+ (NSData *)drawImageWithx:(int)x y:(int)y image:(UIImage *)image;

/// Draws an image with specified width and height ratios
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param wRatio The width ratio (1-10)
/// @param hRatio The height ratio (1-10)
/// @param image The UIImage to draw
/// @return NSData object representing the command
+ (NSData *)drawImageWithx:(int)x y:(int)y wRatio:(int)wRatio hRatio:(int)hRatio image:(UIImage *)image;

/// Prints a reverse color label
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param width The width of the label
/// @param height The height of the label
/// @param radius The corner radius (0-8)
/// @return NSData object representing the command
+ (NSData *)drawReverseColorWithx:(int)x y:(int)y width:(int)width height:(int)height radius:(int)radius;

/// Draws a rectangle
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param width The width of the rectangle
/// @param height The height of the rectangle
/// @param thickness The thickness of the rectangle lines
/// @return NSData object representing the command
+ (NSData *)drawBoxWithx:(int)x y:(int)y width:(int)width height:(int)height thickness:(int)thickness;

/// Draws a rectangle with rounded corners
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param width The width of the rectangle
/// @param height The height of the rectangle
/// @param thickness The thickness of the rectangle lines
/// @param radius The corner radius (0-8)
/// @return NSData object representing the command
+ (NSData *)drawBoxWithx:(int)x y:(int)y width:(int)width height:(int)height thickness:(int)thickness radius:(int)radius;

/// Sets the print direction
/// @param n YES for normal, NO for reverse (default: YES)
/// @return NSData object representing the command
+ (NSData *)direction:(BOOL)n;

/// Prints a graphic from stored images
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param source The source device for the stored image (R, E, B, A)
/// @param name The name of the stored image (1-8 alphanumeric characters)
/// @param xMagnification The x-axis magnification factor (1-10)
/// @param yMagnification The y-axis magnification factor (1-10)
/// @return NSData object representing the command
+ (NSData *)printGraphic:(int)x
                      y:(int)y
                 source:(NSString *)source
                   name:(NSString *)name
          xMagnification:(int)xMagnification
          yMagnification:(int)yMagnification;

/// Downloads a graphic to a specified source
/// @param source The source device for the stored image (R, E, B, A)
/// @param name The name of the stored image (1-8 alphanumeric characters)
/// @param image The UIImage to download
/// @return NSData object representing the command
+ (NSData *)downloadGraphic:(NSString *)source name:(NSString *)name image:(UIImage *)image;

/// Deletes a downloaded graphic
/// @param source The source device for the stored image (R, E, B, A)
/// @param name The name of the stored image (1-8 alphanumeric characters)
/// @return NSData object representing the command
+ (NSData *)deleteDownloadGraphic:(NSString *)source name:(NSString *)name;

@end


NS_ASSUME_NONNULL_END
