//
//  UIImageTranster.h
//  Printer
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum {
    TSPL_PRINT = 0, ///< TSPL print command
    ZPL_PRINT = 1,  ///< ZPL print command
    CPCL_PRINT = 2, ///< CPCL print command
} PrintCommand;

@interface LabelImageTranster : NSObject

/// Converts an image to data suitable for printing.
/// This method converts a UIImage to NSData based on the specified print command type.
/// @param mImage The image to be converted for printing.
/// @param printType The type of print command to use (TSPL, ZPL, or CPCL).
/// @return NSData representation of the image for the specified print type.
+ (NSData *)dataWithImage:(UIImage *)mImage printType:(PrintCommand)printType;

@end

