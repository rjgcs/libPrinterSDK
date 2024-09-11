//
//  PrinterSDKCodeDefines.h
//  libPrinterSDK
//
//  Created by Apple Mac mini intel on 2024/9/9.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(unsigned char, LabelPrinterStatus) {
    LabelPrinterReady = 0x00,
    LabelPrinterCoverOpened = 0x01,
    LabelPrinterPaperJam = 0x02,
    LabelPrinterCoverOpenedAndPaperJam = 0x03,
    LabelPrinterPaperEnd = 0x04,
    LabelPrinterCoverOpenedAndPaperEnd = 0x05,
    LabelPrinterNoRibbon = 0x08,
    LabelPrinterCoverOpenedAndNoRibbon = 0x09,
    LabelPrinterPause = 0x10,
    LabelPrinterPrinting = 0x20
};

typedef NS_ENUM(unsigned char, POSPrinterStatus) {
    POSPrinterNormal = 0x12,
    POSPrinterCoverOpened = 0x16,
    POSPrinterPaperEnd = 0x32,
    POSPrinterCoverOpenedAndPaperEnd = 0x36,
    POSPrinterFeeding = 0x1A,
    POSPrinterCashBoxOpen = 0x00,
    POSPrinterCashBoxClosed = 0x01
};

typedef NS_ENUM(unsigned char, POSPrinterStatusType) {
    POSPrinterStatusTypePrint = 0x01,
    POSPrinterStatusTypeOffline = 0x02,
    POSPrinterStatusTypeError = 0x03,
    POSPrinterStatusTypePaper = 0x04
};

#pragma mark - TSPL Constants

extern NSString * const kCountryUSA;                     ///< USA
extern NSString * const kCountryCanadianFrench;          ///< Canadian French
extern NSString * const kCountrySpanishLatinAmerica;     ///< Spanish Latin America
extern NSString * const kCountryDutch;                   ///< Dutch
extern NSString * const kCountryBelgian;                 ///< Belgian
extern NSString * const kCountryFranceFrench;            ///< France French
extern NSString * const kCountrySpainSpanish;            ///< Spain Spanish
extern NSString * const kCountryHungarian;               ///< Hungarian
extern NSString * const kCountryYugoslavian;             ///< Yugoslavian
extern NSString * const kCountryItalian;                 ///< Italian
extern NSString * const kCountrySwitzerland;             ///< Switzerland
extern NSString * const kCountrySlovak;                  ///< Slovak
extern NSString * const kCountryUnitedKingdom;           ///< United Kingdom
extern NSString * const kCountryDanish;                  ///< Danish
extern NSString * const kCountrySwedish;                 ///< Swedish
extern NSString * const kCountryNorwegian;               ///< Norwegian
extern NSString * const kCountryPolish;                  ///< Polish
extern NSString * const kCountryGerman;                  ///< German
extern NSString * const kCountryBrazil;                  ///< Brazil
extern NSString * const kCountryEnglishInternational;    ///< English International
extern NSString * const kCountryPortuguese;              ///< Portuguese
extern NSString * const kCountryFinnish;                 ///< Finnish

extern NSString * const kBarcodeTypeCode128;        /// Code 128, switching code subset automatically
extern NSString * const kBarcodeTypeCode128Manual;  /// Code 128, switching code subset manually
extern NSString * const kBarcodeTypeEAN128;         /// EAN128, switching code subset automatically
extern NSString * const kBarcodeTypeInterleaved25;  /// Interleaved 2 of 5
extern NSString * const kBarcodeTypeInterleaved25C; /// Interleaved 2 of 5 with check digit
extern NSString * const kBarcodeTypeCode39;        /// Code 39, switching standard and full ASCII mode automatically
extern NSString * const kBarcodeTypeCode39C;       /// Code 39 with check digit
extern NSString * const kBarcodeTypeCode93;        /// Code 93
extern NSString * const kBarcodeTypeEAN13;         /// EAN 13
extern NSString * const kBarcodeTypeEAN13_2;       /// EAN 13 with 2 digits add-on
extern NSString * const kBarcodeTypeEAN13_5;       /// EAN 13 with 5 digits add-on
extern NSString * const kBarcodeTypeEAN8;          /// EAN 8
extern NSString * const kBarcodeTypeEAN8_2;        /// EAN 8 with 2 digits add-on
extern NSString * const kBarcodeTypeEAN8_5;        /// EAN 8 with 5 digits add-on
extern NSString * const kBarcodeTypeCodabar;       /// Codabar
extern NSString * const kBarcodeTypePostnet;       /// Postnet
extern NSString * const kBarcodeTypeUPCA;          /// UPC-A
extern NSString * const kBarcodeTypeUPCA_2;        /// UPC-A with 2 digits add-on
extern NSString * const kBarcodeTypeUPCA_5;        /// UPC-A with 5 digits add-on
extern NSString * const kBarcodeTypeUPCE;          /// UPC-E
extern NSString * const kBarcodeTypeUPCE_2;        /// UPC-E with 2 digits add-on
extern NSString * const kBarcodeTypeUPCE_5;        /// UPC-E with 5 digits add-on
extern NSString * const kBarcodeTypeCpost;         /// China post
extern NSString * const kBarcodeTypeMSI;           /// MSI
extern NSString * const kBarcodeTypeMSIC;          /// MSI with check digit
extern NSString * const kBarcodeTypePlessey;       /// PLESSEY
extern NSString * const kBarcodeTypeITF14;         /// ITF14
extern NSString * const kBarcodeTypeEAN14;         /// EAN14
extern NSString * const kBarcodeTypeCode11;        /// Code 11
extern NSString * const kBarcodeTypeTelepen;       /// Telepen
extern NSString * const kBarcodeTypeTelepenN;      /// Telepen number
extern NSString * const kBarcodeTypePlanet;        /// Planet
extern NSString * const kBarcodeTypeCode49;        /// Code 49
extern NSString * const kBarcodeTypeDPIIdentcode;  /// Deutsche Post Identcode
extern NSString * const kBarcodeTypeDPILeitcode;   /// Deutsche Post Leitcode

extern NSString * const kQRCodeModeAuto;   /// Auto-generate QR Code
extern NSString * const kQRCodeModeManual; /// Manually generate QR Code

extern NSString * const kECCLevelL; /// Error Correction Level L (7%)
extern NSString * const kECCLevelM; /// Error Correction Level M (15%)
extern NSString * const kEECLevelQ; /// Error Correction Level Q (25%)
extern NSString * const kEECLevelH; /// Error Correction Level H (30%)

extern NSString * const kFNT_8_12;  ///< 8 x 12 Alphanumeric Font
extern NSString * const kFNT_12_20; ///< 12 x 20 Alphanumeric Font
extern NSString * const kFNT_16_24; ///< 16 x 24 Alphanumeric Font
extern NSString * const kFNT_24_32; ///< 24 x 32 Alphanumeric Font
extern NSString * const kFNT_32_48; ///< 32 x 48 Alphanumeric Font
extern NSString * const kFNT_14_19; ///< 14 x 19 OCR-B Alphanumeric Font
extern NSString * const kFNT_14_25; ///< 14 x 25 OCR-A Alphanumeric Font
extern NSString * const kFNT_21_27; ///< 21 x 27 OCR-B Alphanumeric Font
extern NSString * const kFNT_SIMPLIFIED_CHINESE; ///< Simplified Chinese 24x24 Font (GB Code)
extern NSString * const kFNT_TRADITIONAL_CHINESE; ///< Traditional Chinese 24x24 Font (Big Five Code)
extern NSString * const kFNT_KOREAN; ///< Korean 24x24 Font (KS Code)

