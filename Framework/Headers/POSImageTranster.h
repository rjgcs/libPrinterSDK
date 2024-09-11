//
//  POSImageTranster.h
//  Printer
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface POSImageTranster : NSObject

typedef enum {
    Dithering = 0, ///< bitmap binary method
    Threshold      ///< bitmap dithering
} BmpType;

typedef enum {
    RasterNolmorWH = 0,  ///< print raster bitmap: normal
    RasterDoubleWidth,   ///< double width
    RasterDoubleHeight,  ///< double height
    RasterDoubleWH       ///< double width height
} PrintRasterType;

/// Prints raster bitmap data.
/// @param mIamge The image to be printed.
/// @param bmptype The bitmap type to use for printing.
/// @param type The raster print type to use.
/// @return NSData representing the raster image data.
+ (NSData *)rasterImagedata:(UIImage *)mIamge andType:(BmpType)bmptype andPrintRasterType:(PrintRasterType)type;

/// Compresses and prints bitmap data.
/// @param mIamge The image to be compressed and printed.
/// @param bmptype The bitmap type to use for compression.
/// @param type The raster print type to use.
/// @return NSData representing the compressed image data.
+ (NSData *)compressionImagedata:(UIImage *)mIamge andType:(BmpType)bmptype andPrintRasterType:(PrintRasterType)type;

@end

