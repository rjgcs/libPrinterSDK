//
//  POSCommand.h
//  Printer
//

#import <Foundation/Foundation.h>
#import "POSImageTranster.h"

typedef NS_ENUM(NSInteger, TextWidthRatio){
    TXT_DEFAULTWIDTH = 0, ///< Default width
    TXT_1WIDTH = 1,       ///< Set width ratio to x1
    TXT_2WIDTH = 2,       ///< Set width ratio to x2
    TXT_3WIDTH = 3,       ///< Set width ratio to x3
    TXT_4WIDTH = 4,       ///< Set width ratio to x4
    TXT_5WIDTH = 5,       ///< Set width ratio to x5
    TXT_6WIDTH = 6,       ///< Set width ratio to x6
    TXT_7WIDTH = 7,       ///< Set width ratio to x7
    TXT_8WIDTH = 8        ///< Set width ratio to x8
};

typedef NS_ENUM(NSInteger, TextHeightRatio){
    TXT_DEFAULTHEIGHT = 0, ///< Default height
    TXT_1HEIGHT = 1,       ///< Set height ratio to x1
    TXT_2HEIGHT = 2,       ///< Set height ratio to x2
    TXT_3HEIGHT = 3,       ///< Set height ratio to x3
    TXT_4HEIGHT = 4,       ///< Set height ratio to x4
    TXT_5HEIGHT = 5,       ///< Set height ratio to x5
    TXT_6HEIGHT = 6,       ///< Set height ratio to x6
    TXT_7HEIGHT = 7,       ///< Set height ratio to x7
    TXT_8HEIGHT = 8        ///< Set height ratio to x8
};

typedef NS_ENUM(NSInteger, TextFontAttribute){
    FNT_DEFAULT = 0,   ///< Standard Font A
    FNT_FONTB,         ///< Font B
    FNT_BOLD,          ///< Bold font
    FNT_REVERSE,       ///< Reverse print attribute
    FNT_UNDERLINE,     ///< Underline attribute
    FNT_UNDERLINE2     ///< Bold underline attribute
};

typedef NS_ENUM(NSInteger, POSTextAlignment){
    POS_ALIGNMENT_LEFT,   ///< Left alignment
    POS_ALIGNMENT_CENTER, ///< Center alignment
    POS_ALIGNMENT_RIGHT   ///< Right alignment
};

typedef NS_ENUM(NSInteger, POSBarcodeType) {
    POSBarcodeTypeUPCA = 65, ///< UPC A
    POSBarcodeTypeUPCE = 66, ///< UPCE
    POSBarcodeTypeJAN13_EAN13 = 67, ///< JAN-13 | EAN-13
    POSBarcodeTypeJAN8_EAN8 = 68, ///< JAN-8
    POSBarcodeTypeCode39 = 69, ///< Code 39
    POSBarcodeTypeITF = 70, ///< ITF
    POSBarcodeTypeCodabar = 71, ///< Codabar
    POSBarcodeTypeCode93 = 72, ///< Code 93
    POSBarcodeTypeCode128 = 73 ///< Code 128
};

@interface POSCommand : NSObject

/// MARK: - Basic related APIs

/// Initialize the printer.
+ (NSData *)initializePrinter;

/// Print and feed.
/// @param n length(in inch)to feed.
+ (NSData *)printAndFeed:(int)n;

/// Horizontal positioning.
+ (NSData *)horizontalPosition;

/// Print and wrap.
+ (NSData *)printAndFeedLine;

/// Print and go back to standard mode.
+ (NSData *)printAndBackStandardModel;

/// Print and tab.
+ (NSData *)printAndTabs;

/// Cancel print data in page mode.
+ (NSData *)canclePrintDataByPageModel;

/// Transfer real-time status.
/// @param n 1<=n<=4.
///
/// | Enum Value                      | Description             | Hex Value |
/// |----------------------------------|-------------------------|-----------|
/// | POSPrinterStatusTypePrint        | Print status            | 0x01      |
/// | POSPrinterStatusTypeOffline      | Offline status          | 0x02      |
/// | POSPrinterStatusTypeError        | Error status            | 0x03      |
/// | POSPrinterStatusTypePaper        | Paper transmission status | 0x04      |
///
+ (NSData *)sendRealTimeStatus:(int)n;

/// Real-time request to printer.
/// @param n 1<=n<=2.
+ (NSData *)requestRealTimeForPrint:(int)n;

/// Generate cash box pulses in real time.
/// @param m  m=0, or 1;
/// @param t  1<=t<=8.
+ (NSData *)openCashBoxRealTimeWithM:(int)m andT:(int)t;

/// Printing in page mode.
/// This command is only valid in page mode.
+ (NSData *)printUnderPageModel;

/// Select printer.
/// @param n 0 or 1.
+ (NSData *)selectPrinter:(int)n;

/// Select an alignment.
/// @param n The alignment value, which can be one of the following:
///
/// | Value                  | Description    |
/// |------------------------|----------------|
/// | POS_ALIGNMENT_LEFT      | Left alignment |
/// | POS_ALIGNMENT_CENTER    | Center alignment |
/// | POS_ALIGNMENT_RIGHT     | Right alignment |
///
/// @return Data for selecting alignment.
+ (NSData *)selectAlignment:(int)n;

/// Print and advance paper n lines.
/// @param n 0~255.
/// @return Data for printing and advancing paper n lines.
+ (NSData *)printAndFeedForwardWhitN:(int)n;

/// To select or cancel upside-down printing.
/// @param n Last decision. 1: select, 0: cancel.
/// @return Data for selecting or canceling upside-down printing.
+ (NSData *)selectOrCancleConvertPrintModel:(int)n;


/// MARK: - Set related APIs

/// Set absolute print position.
/// @param nL  range 0~255, the lower byte of te distance from the beginning of the line.
/// @param nH  range 0~255, the higher byte of the distance from the beginning of the line.
+ (NSData *)setAbsolutePrintPositionWithNL:(int)nL andNH:(int)nH;

/// Set default line spacing.
+ (NSData *)setDefultLineSpace;

/// Set line spacing.
/// @param n range 0~255.
+ (NSData *)setDefultLineSpace:(int)n;

/// Set the horizontal tab position.
/// @param data array of tab positions (k<=32), Tab distance=character width*k.
+ (NSData *)setHorizontalTabsPosition:(NSData *)data;

/// Set density.
/// @param density 1 - 8
/// @return Data for setting density.
+ (NSData *)setDensity:(int)density;

/// Set DIP.
/// @param string DIP string.
/// @return Data for setting DIP.
+ (NSData *)setDIPSettingsWithString:(NSString *)string;

/// Set beeper.
/// @param onSwitch Switch for beeper.
/// @return Data for setting beeper.
+ (NSData *)setBeeper:(BOOL)onSwitch;

/// Set beeper count after cutter.
/// @param count Beeper count.
/// @param interval Interval * 50ms.
/// @return Data for setting beeper count after cutter.
+ (NSData *)setCutterAndBeeper:(int)count interval:(int)interval;

/// Set cash box open.
/// @return Data for setting cash box open.
+ (NSData *)setCashBoxOpen;

/// Cancel beeper count after cutter.
/// @return Data for canceling beeper count after cutter.
+ (NSData *)cancelCutterAndBeeper;

/// Select or deselect Rotate 90 degrees clockwise.
/// This command is only valid in page mode.
/// @param n 0 or 48 to cancel, 1 or 49 to select.
+ (NSData *)selectOrCancleCW90:(int)n;

/// Setting the print area in page mode.
/// @param xL lower byte of the start bit in the x direction.
/// @param xH higher byte of the start bit in the x direction.
/// @param yL lower byte of the start bit in the y direction.
/// @param yH higher byte of the start bit in the y direction.
/// @param dxL lower byte of width in x direction.
/// @param dxH higher byte of width in x direction.
/// @param dyL lower byte of height in y direction.
/// @param dyH higher byte of height in y direction.
+ (NSData *)setPrintAreaUnderPageModelWithxL:(int)xL
                                       andxH:(int)xH
                                       andyL:(int)yL
                                       andyH:(int)yH
                                      anddxL:(int)dxL
                                      anddxH:(int)dxH
                                      anddyL:(int)dyL
                                      anddyH:(int)dyH;

/// Set relative landscape print position.
/// @param nL Lower byte of the set size.
/// @param nH Higher byte of the set size.
/// @return Data for setting relative landscape print position.
+ (NSData *)setRelativeHorizontalPrintPositionWithnL:(int)nL andnH:(int)nH;

/// Set double byte language.
/// @param type 0 - 3
/// @return Data for setting double byte language.
+ (NSData *)setDoubleByteLanguageWithType:(int)type;

/// Set code page.
/// @param page Page number.
/// @return Data for setting code page.
+ (NSData *)setCodePage:(int)page;

/// Turn automatic status return on or off.
/// @param n 0~255, each bit means a different type of status return.
/// @return Data for turning automatic status return on or off.
+ (NSData *)openOrCloseAutoReturnPrintState:(int)n;

/// Set left margin.
/// @param nL Lower byte of the left margin.
/// @param nH Higher byte of the left margin.
/// @return Data for setting left margin.
+ (NSData *)setLeftSpaceWithnL:(int)nL andnH:(int)nH;

/// Set horizontal and vertical movement units.
/// @param x Horizontal movement unit, 0~255.
/// @param y Vertical movement unit, 0~255.
/// @return Data for setting horizontal and vertical movement units.
+ (NSData *)setHorizontalAndVerticalMoveUnitWithX:(int)x andY:(int)y;

/// Set the print area width.
/// @param nL Lower byte of the print area width.
/// @param nH Higher byte of the print area width.
/// @return Data for setting the print area width.
+ (NSData *)setPrintAreaWidthWithnL:(int)nL andnH:(int)nH;

/// Set absolute print position in page mode.
/// @param nL Lower byte of the vertical movement distance.
/// @param nH Higher byte of the vertical movement distance.
/// @return Data for setting absolute print position in page mode.
+ (NSData *)setVertivalRelativePositionUnderPageModelWithNL:(int)nL andNH:(int)nH;

/// Set absolute position in page mode.
/// @param nL Lower byte of the position.
/// @param nH Higher byte of the position.
/// @return Data for setting absolute position in page mode.
+ (NSData *)setAbsolutePositionUnderPageModelWithnL:(int)nL andnH:(int)nH;


/// MARK: - Text related APIs

/// Set character right spacing.
/// @param n  0~255, in dots.
+ (NSData *)setCharRightSpace:(int)n;

/// Select print mode.
/// @param n  0~255, the last digit of n, 0: cancel, 1: select.
+ (NSData *)selectPrintMode:(int)n;

/// Select or cancel user-defined characters.
/// @param n  0~255, the last digit of n, 0: cancel, 1: select.
+ (NSData *)selectOrCancleCustomChar:(int)n;

/// Define user-defined characters.
/// @param m range 0, 1, 32, 33, representing different densities of points.
/// @param nL range 0~255, the lower byte of the character code.
/// @param nH range 0~3, the higher byte of the character code.
/// @param bytes character binary data.
+ (NSData *)defineUserDefinedCharactersWithM:(int)m andNL:(int)nL andNH:(int)nH andBytes:(Byte *)bytes;

/// Select or deselect underline mode.
/// @param n 0 or 48 to cancel; 1 or 49 to select (by 1 dot); 2 or 50 to select (by 2 dots).
+ (NSData *)selectOrCancleUnderLineModel:(int)n;

/// Cancel user-defined characters.
/// Cancel the character with code n in user-defined characters. n range: 32~127.
/// @param n character code to cancel.
+ (NSData *)cancleUserDefinedCharacters:(int)n;

/// Select or deselect bold mode.
/// @param n 0~255, the last digit of n, 0 to cancel, 1 to select.
+ (NSData *)selectOrCancleBoldModel:(int)n;

/// Select font.
/// @param n 0, 1, 48, 49.
+ (NSData *)selectFont:(int)n;

/// Select international character set.
/// @param n 0-15, means an international character set.
+ (NSData *)selectInternationCharacterSets:(int)n;

/// Select character size.
/// @param n 0~255, 0-3 for character height, 4-7 for character width.
/// @return Data for selecting character size.
+ (NSData *)selectCharacterSize:(int)n;

/// Set the left and right spacing of Chinese characters.
/// @param n1 Left spacing, 0~255.
/// @param n2 Right spacing, 0~255.
/// @return Data for setting the left and right spacing of Chinese characters.
+ (NSData *)setChineseCharLeftAndRightSpaceWithN1:(int)n1 andN2:(int)n2;

/// Set Chinese character mode.
/// @param n 0~255, different bits define character patterns.
/// @return Data for setting Chinese character mode.
+ (NSData *)setChineseCharacterModel:(int)n;

/// Select Chinese mode.
/// @return Data for selecting Chinese mode.
+ (NSData *)selectChineseCharacterModel;

/// Cancel Chinese mode.
/// @return Data for canceling Chinese mode.
+ (NSData *)CancelChineseCharModel;

/// Select or cancel the double width and double height of Chinese characters.
/// @param n 0~255, the last digit of n, 1: select; 0: cancel.
/// @return Data for selecting or canceling the double width and double height of Chinese characters.
+ (NSData *)selectOrCancelChineseCharDoubleWH:(int)n;

/// Select or cancel Chinese character underline mode.
/// @param n 0~2 or 48~50.
/// @return Data for selecting or canceling Chinese character underline mode.
+ (NSData *)selectOrCancelChineseCharUnderLineModel:(int)n;

/// User-defined Chinese characters.
/// @param c2 C2: A1H<=c2<=FEH.
/// @param bytes Byte array of Chinese character.
/// @return Data for defining user-defined Chinese characters.
+ (NSData *)definedUserDefinedChineseCharWithCPosition:(int)c2 andNsdata:(Byte *)bytes;

/// Select or cancel the black and white reverse print mode.
/// @param n The last digit of n. 1: select, 0: cancel.
/// @return Data for selecting or canceling the black and white reverse print mode.
+ (NSData *)selectOrCancleInvertPrintModel:(int)n;

/// Select character code table.
/// @return Data for selecting character code table.
+ (NSData *)selectCharacterCodePage:(int)n;

/// This method is used to print text in a specific format.
/// @param width The text width ratio, which can be one of the following:
///
/// | Value           | Description           |
/// |-----------------|-----------------------|
/// | TXT_DEFAULTWIDTH| Default width          |
/// | TXT_1WIDTH      | Set width ratio to x1  |
/// | TXT_2WIDTH      | Set width ratio to x2  |
/// | TXT_3WIDTH      | Set width ratio to x3  |
/// | TXT_4WIDTH      | Set width ratio to x4  |
/// | TXT_5WIDTH      | Set width ratio to x5  |
/// | TXT_6WIDTH      | Set width ratio to x6  |
/// | TXT_7WIDTH      | Set width ratio to x7  |
/// | TXT_8WIDTH      | Set width ratio to x8  |
///
/// @param height The text height ratio, which can be one of the following:
///
/// | Value            | Description            |
/// |------------------|------------------------|
/// | TXT_DEFAULTHEIGHT| Default height         |
/// | TXT_1HEIGHT      | Set height ratio to x1 |
/// | TXT_2HEIGHT      | Set height ratio to x2 |
/// | TXT_3HEIGHT      | Set height ratio to x3 |
/// | TXT_4HEIGHT      | Set height ratio to x4 |
/// | TXT_5HEIGHT      | Set height ratio to x5 |
/// | TXT_6HEIGHT      | Set height ratio to x6 |
/// | TXT_7HEIGHT      | Set height ratio to x7 |
/// | TXT_8HEIGHT      | Set height ratio to x8 |
///
/// @return Data for printing text in the specified format.
+ (NSData *)setTextSize:(int)width height:(int)height;

/// Prints text with specific formatting options.
/// @param data The content to print.
/// @param alignment The text alignment, which can be one of the following:
///
/// | Value                  | Description     |
/// |------------------------|-----------------|
/// | POS_ALIGNMENT_LEFT      | Left alignment  |
/// | POS_ALIGNMENT_CENTER    | Center alignment|
/// | POS_ALIGNMENT_RIGHT     | Right alignment |
///
/// @param attribute The font attribute, which can be one of the following:
///
/// | Value          | Description                |
/// |----------------|----------------------------|
/// | FNT_DEFAULT     | Standard Font A            |
/// | FNT_FONTB       | Font B                     |
/// | FNT_BOLD        | Bold font                  |
/// | FNT_REVERSE     | Reverse print attribute    |
/// | FNT_UNDERLINE   | Underline attribute        |
/// | FNT_UNDERLINE2  | Bold underline attribute   |
///
/// @param textWid The text width ratio, which can be one of the following:
///
/// | Value           | Description            |
/// |-----------------|------------------------|
/// | TXT_DEFAULTWIDTH| Default width          |
/// | TXT_1WIDTH      | Set width ratio to x1  |
/// | TXT_2WIDTH      | Set width ratio to x2  |
/// | TXT_3WIDTH      | Set width ratio to x3  |
/// | TXT_4WIDTH      | Set width ratio to x4  |
/// | TXT_5WIDTH      | Set width ratio to x5  |
/// | TXT_6WIDTH      | Set width ratio to x6  |
/// | TXT_7WIDTH      | Set width ratio to x7  |
/// | TXT_8WIDTH      | Set width ratio to x8  |
///
/// @param textHei The text height ratio, which can be one of the following:
///
/// | Value            | Description             |
/// |------------------|-------------------------|
/// | TXT_DEFAULTHEIGHT| Default height          |
/// | TXT_1HEIGHT      | Set height ratio to x1  |
/// | TXT_2HEIGHT      | Set height ratio to x2  |
/// | TXT_3HEIGHT      | Set height ratio to x3  |
/// | TXT_4HEIGHT      | Set height ratio to x4  |
/// | TXT_5HEIGHT      | Set height ratio to x5  |
/// | TXT_6HEIGHT      | Set height ratio to x6  |
/// | TXT_7HEIGHT      | Set height ratio to x7  |
/// | TXT_8HEIGHT      | Set height ratio to x8  |
///
/// @return Data for printing text with the specified formatting.
+ (NSData *)printText:(NSString *)data alignment:(int)alignment attribute:(int)attribute textWid:(int)textWid textHei:(int)textHei;

+ (NSData *)printText:(NSString *)data textWid:(int)textWid textHei:(int)textHei;

+ (NSData *)printText:(NSString *)data attribute:(int)attribute;

+ (NSData *)printText:(NSString *)data alignment:(int)alignment;

/// MARK: - QRCode related API

/// QRCODE: Set cell size.
/// @param n 0~16.
/// @return Data for setting cell size for QR code.
+ (NSData *)setQRcodeUnitsize:(int)n;

/// Set error correction level for QR code.
/// @param n Error correction level: L:48 M:49 Q:50 H:51.
/// @return Data for setting error correction level for QR code.
+ (NSData *)setErrorCorrectionLevelForQrcode:(int)n;

/// Transfer data to encoding buffer for QR code.
/// @param str QR code content.
/// @param strEnCoding String encoding.
/// @return Data for transferring data to encoding buffer for QR code.
+ (NSData *)sendDataToStoreAreaWitQrcodeConent:(NSString *)str usEnCoding:(NSStringEncoding)strEnCoding;

/// Print the QR code of the encoded cache.
/// @return Data for printing the QR code in the store.
+ (NSData *)printTheQRcodeInStore;

/// Print QR code.
/// @param n 0~16.
/// @param errLevel Error correction level: L:48 M:49 Q:50 H:51.
/// @param code QR code content.
/// @param strEncoding String encoding.
/// @return Data for printing QR code.
+ (NSData *)printQRCode:(int)n level:(int)errLevel code:(NSString *)code useEnCodeing:(NSStringEncoding)strEncoding;

/// Set the number of columns in the data region for PDF417.
/// @param n Number of columns.
/// @return Data for setting the number of columns in the data region for PDF417.
+ (NSData *)setPdf417Columns:(int)n;

/// Set the width of the module for PDF417.
/// @param n Width of the module.
/// @return Data for setting the width of the module for PDF417.
+ (NSData *)setpdf417WidthOfModule:(int)n;

/// Set the row height for PDF417.
/// @param n Row height.
/// @return Data for setting the row height for PDF417.
+ (NSData *)setpdf417RowHeight:(int)n;

/// Store the data in the symbol storage area for PDF417.
/// @param pL Lower byte of the data length.
/// @param pH Higher byte of the data length.
/// @param content Content to store.
/// @param strEnCoding String encoding.
/// @return Data for storing PDF417 data in the symbol storage area.
+ (NSData *)storethepdf417WithpL:(int)pL andpH:(int)pH andContent:(NSString*)content usEnCoding:(NSStringEncoding)strEnCoding;

/// Print the PDF417 symbol data in the symbol storage area.
/// @return Data for printing the PDF417 symbol data in the symbol storage area.
+ (NSData *)printPdf417InStore;

/// MARK: - Barcode related API

/// Select HRI font.
/// @param n 0 or 48 for normal; 1 or 49 for compression.
/// @return Data for selecting HRI font.
+ (NSData *)selectHRIFont:(int)n;

/// Select barcode height.
/// GS h n (0x1D 0x68 n)
/// @param n 1~255, default: 162.
/// @return Data for selecting barcode height.
+ (NSData *)setBarcodeHeight:(int)n;

/// Print barcode.
/// @param m Barcode type, which can be one of the following: 0~6 or 65 ~71
///
/// | Value                  | Barcode Type            |
/// |------------------------|-------------------------|
/// | POSBarcodeTypeUPCA      | UPC A                   |
/// | POSBarcodeTypeUPCE      | UPCE                    |
/// | POSBarcodeTypeJAN13_EAN13 | JAN-13 / EAN-13        |
/// | POSBarcodeTypeJAN8_EAN8 | JAN-8 / EAN-8           |
/// | POSBarcodeTypeCode39    | Code 39                 |
/// | POSBarcodeTypeITF       | ITF                     |
/// | POSBarcodeTypeCodabar   | Codabar                 |
///
/// @param content Barcode content.
/// @param strEncoding String encoding for the barcode content.
/// @return Data for printing barcode.
+ (NSData *)printBarcodeWithM:(int)m andContent:(NSString *)content useEnCodeing:(NSStringEncoding)strEncoding;


/// Print a barcode with specific type and content.
/// @param m Barcode type, which can be one of the following:65 ~73
///
/// | Value                   | Description       |
/// |--------------------------|-------------------|
/// | POSBarcodeTypeUPCA        | UPC A             |
/// | POSBarcodeTypeUPCE        | UPCE              |
/// | POSBarcodeTypeJAN13_EAN13 | JAN-13 | EAN-13   |
/// | POSBarcodeTypeJAN8_EAN8   | JAN-8             |
/// | POSBarcodeTypeCode39      | Code 39           |
/// | POSBarcodeTypeITF         | ITF               |
/// | POSBarcodeTypeCodabar     | Codabar           |
/// | POSBarcodeTypeCode93      | Code 93           |
/// | POSBarcodeTypeCode128     | Code 128          |
///
/// @param n The width of the barcode, ranging from 2 to 6.
/// @param content The content of the barcode.
/// @param strEncoding The string encoding used for the content.
/// @return Data for printing the barcode.
+ (NSData *)printBarcodeWithM:(int)m andN:(int)n andContent:(NSString *)content useEnCodeing:(NSStringEncoding)strEncoding;


/// Set barcode width.
/// @param n 2~6, default 3.
/// @return Data for setting barcode width.
+ (NSData *)setBarcodeWidth:(int)n;

/// Select the HRI character print position.
/// @param n 0~3 or 48~51, means the printing position of the characters relative to the barcode.
/// @return Data for selecting the HRI character print position.
+ (NSData *)selectHRICharactersPrintPosition:(int)n;


/// MARK: - Image related APIs

/// Print a raster bitmap with specified mode and bitmap type.
/// @param m Print mode, which can be one of the following:
///
/// | Value               | Description              |
/// |---------------------|--------------------------|
/// | RasterNolmorWH       | Normal                   |
/// | RasterDoubleWidth    | Double width             |
/// | RasterDoubleHeight   | Double height            |
/// | RasterDoubleWH       | Double width and height  |
///
/// @param image The UIImage instance to be printed.
/// @param type Bitmap processing type, which can be one of the following:
///
/// | Value    | Description          |
/// |----------|----------------------|
/// | Dithering| Bitmap binary method |
/// | Threshold| Bitmap dithering     |
///
/// @return Data for printing the raster bitmap.
+ (NSData *)printRasteBmpWithM:(PrintRasterType)m andImage:(UIImage *)image andType:(BmpType)type;

/// Select bitmap mode.
/// @param m range 0, 1, 32, 33, representing different densities of points.
/// @param nL range 0~255, the lower byte of the number of dots.
/// @param nH range 0~3, the higher byte of the number of dots.
/// @param data bitmap data.
+ (NSData *)selectBmpModelWithM:(int)m andnL:(int)nL andnH:(int)nH andNSData:(NSData *)data;

/// Print a compressed raster bitmap with specified mode and bitmap type.
/// @param m Print mode, which can be one of the following:
///
/// | Value              | Description               |
/// |--------------------|---------------------------|
/// | RasterNolmorWH      | Normal                    |
/// | RasterDoubleWidth   | Double width              |
/// | RasterDoubleHeight  | Double height             |
/// | RasterDoubleWH      | Double width and height   |
///
/// @param image The UIImage instance to be printed.
/// @param type Bitmap processing type, which can be one of the following:
///
/// | Value     | Description            |
/// |-----------|------------------------|
/// | Dithering | Bitmap binary method   |
/// | Threshold | Bitmap dithering       |
///
/// @return Data for printing the compressed raster bitmap.
+ (NSData *)compressionPrintBmpWithM:(PrintRasterType)m andImage:(UIImage *)image andType:(BmpType)type;


/// Print bitmap downloaded to flash.
/// @param n Image at n position in flash cache.
/// @param m Print flash bitmap way, 0~3 or 48~51, means normal, double width, double height, double width and height.
/// @return Data for printing bitmap downloaded to flash.
+ (NSData *)printBmpInFLASHWithN:(int)n andM:(int)m;

/// Print download bitmap.
/// @param m Print mode, range: 0~3 or 48~51.
/// @return Data for printing download bitmap.
+ (NSData *)printDownLoadBmp:(int)m;

/// Define a download bitmap with the specified type.
/// @param image The UIImage instance to be downloaded.
/// @param bmptype The bitmap type, which can be one of the following:
///
/// | Value     | Description            |
/// |-----------|------------------------|
/// | Dithering | Bitmap binary method   |
/// | Threshold | Bitmap dithering       |
///
/// @return Data for defining the download bitmap.
+ (NSData *)definedDownLoadBmp:(UIImage *)image byType:(BmpType)bmptype;

/// MARK: - Pattern related APIs

/// Select or cancel dual printing mode.
/// @param n 0~255, the last digit of n, 0 to cancel, 1 to select.
+ (NSData *)selectOrCancleDoublePrintMode:(int)n;

/// Select page mode.
+ (NSData *)selectPagemode;

/// Select standard mode.
+ (NSData *)selectStabdardMode;

/// Select the print area orientation in page mode.
/// @param n 0<=n<=3 or 48<=n<=51, n specifies the orientation and starting position of the print area.
+ (NSData *)selectPrintDirectionUnderPageMode:(int)n;

/// Select the cut paper mode and cut the paper.
/// @param m 0 or 48 for full cut; 1 or 49 for half cut.
/// @return Data for selecting the cut paper mode and cutting the paper.
+ (NSData *)selectCutPageModelAndCutpage:(int)m;

/// Select the cut paper mode and cut the paper.
/// @param m M=66.
/// @param n Paper feed n, and half cut paper.
/// @return Data for selecting the cut paper mode and cutting the paper.
+ (NSData *)selectCutPageModelAndCutpageWithM:(int)m andN:(int)n;

/// MARK: - Query related APIs

/// Return status.
/// @param n 1, 2, 49, 50; 1 or 49 for returning sensor status, 2 or 50 for returning cash box status.
/// @return Data for returning status.
+ (NSData *)returnState:(int)n;

/// MARK: - Other related APIs

/// Select the printer sensor to output the paper-cut signal.
/// @param n 0~255.
/// @return Data for selecting the printer sensor to output the paper-cut signal.
+ (NSData *)selectPrintTransducerOutPutPageOutSignal:(int)n;

/// Select Printer Sensor - Stop Printing.
/// @param n 0~255.
/// @return Data for selecting Printer Sensor - Stop Printing.
+ (NSData *)selectPrintTransducerStopPrint:(int)n;

/// The printer beeps for a single print.
/// @param n Beeps counts, 1~9.
/// @param t T*50ms means every beep time, 1~9.
/// @return Data for the printer beeping for a single print.
+ (NSData *)printerOrderBuzzingHintWithRes:(int)n andTime:(int)t;

/// The printer beeps and the alarm light flashes.
/// @param m Number of beeps, number of flashes of alarm light, 1~20.
/// @param t (T*50ms)interval, 1~20.
/// @param n 0~3, 0: no beep no flash; 1: beep; 2: flash, 3: beep and flash.
/// @return Data for the printer beeping and the alarm light flashing.
+ (NSData *)printerOrderBuzzingAndWaringLightWithM:(int)m andT:(int)t andN:(int)n;

/// Allow or disallow keystrokes.
/// @param n Last decision. 1: allow, 0: forbid.
/// @return Data for allowing or disallowing keystrokes.
+ (NSData *)allowOrForbidPressButton:(int)n;

/// Generate cash box control pulses.
/// @param t1 0~255.
/// @param t2 0~255.
/// @return Data for generating cash box control pulses.
+ (NSData *)creatCashBoxContorPulseWithM:(int)m andT1:(int)t1 andT2:(int)t2;

/// Execute macro command.
/// @param r Execute counts, 0~255.
/// @param t Execute wait time, 0~255.
/// @param m Execute model, 0 or 1.
/// @return Data for executing macro command.
+ (NSData *)executeMacrodeCommandWithR:(int)r andT:(int)t andM:(int)m;

/// Start or end macro definition.
/// @return Data for starting or ending macro definition.
+ (NSData *)startOrStopMacrodeFinition;

/// Execute printer data hex dump.
/// @return Data for executing printer data hex dump.
+ (NSData *)executePrintDataSavaByTeansformToHex;

/// Define flash bitmaps with the given array of images.
/// @param images An array of UIImage objects representing the bitmaps to be defined.
/// @return NSData object containing the command to define the flash bitmaps.
+ (NSData *)definedFlashBmpWithImage:(NSArray <UIImage *> *)images;

/// Clear all previously defined flash bitmaps.
/// @return NSData object containing the command to clear flash bitmaps.
+ (NSData *)clearFlashBmp;

@end
