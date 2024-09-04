//
//  TSCCommand.h
//  Printer
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM (NSUInteger, AutoResponse) {
    OFF     = 0, ///< Disable auto response status function
    ON      = 1, ///< Enable auto response status function, returns once after printing each label
    BATCH   = 2  ///< Enable auto response status function, returns once after all printing is complete
};

@interface TSCCommand : NSObject

/// Defines the label width and length in millimeters.
/// Sets the width and length of the label paper (unit: millimeters)
/// @param m Label width
/// @param n Label length
/// @return Data command
+ (NSData *)sizeBymmWithWidth:(double)m andHeight:(double)n;

/// Defines the label width and length in inches.
/// Sets the width and length of the label paper (unit: inches)
/// @param m Label width
/// @param n Label length
/// @return Data command
+ (NSData *)sizeByinchWithWidth:(double)m andHeight:(double)n;

/// Defines the label width and height in dots.
/// Sets the width and height of the label paper (unit: dots)
/// @param m Label width
/// @param n Label height
/// @return Data command
+ (NSData *)sizeBydotWithWidth:(int)m andHeight:(int)n;

/// Defines the gap distance between two labels vertically.
/// Sets the vertical gap distance between labels (unit: millimeters)
/// @param m Gap distance between two labels
/// @param n Offset distance of the gap
/// @return Data command
+ (NSData *)gapBymmWithWidth:(double)m andHeight:(double)n;

/// Defines the gap distance between two labels vertically.
/// Sets the vertical gap distance between labels (unit: inches)
/// @param m Gap distance between two labels
/// @param n Offset distance of the gap
/// @return Data command
+ (NSData *)gapByinchWithWidth:(double)m andHeight:(double)n;

/// Defines the gap distance between two labels vertically.
/// Sets the vertical gap distance between labels (unit: dots)
/// @param m Gap distance between two labels
/// @param n Offset distance of the gap
/// @return Data command
+ (NSData *)gapBydotWithWidth:(int)m andHeight:(int)n;

/// Feeds the paper through the gap sensor to determine the paper and gap sizes.
/// Measures the size of the paper and gap using the gap sensor (unit: dots)
/// @param x Paper length in dots
/// @param y Gap length in dots
/// @return Data command
+ (NSData *)gapDetectWithX:(int)x andY:(int)y;

/// Feeds the paper through the gap sensor to determine the paper and gap sizes.
/// Feeds the paper to determine the size of the paper and gap
/// @return Data command
+ (NSData *)gapDetect;

/// Feeds the paper through the black mark sensor to determine the paper and black mark size.
/// Feeds the paper to determine the size of the paper and black mark (unit: dots)
/// @param x Paper length in dots
/// @param y Black mark length in dots
/// @return Data command
+ (NSData *)blinedDetectWithX:(int)x andY:(int)y;

/// Feeds the paper through the gap/black mark sensor to determine the paper and gap/black mark size.
/// Feeds the paper to determine the size of the paper and gap/black mark (unit: dots)
/// @param x Paper length in dots
/// @param y Gap/Black mark length in dots
/// @return Data command
+ (NSData *)autoDetectWithX:(int)x andY:(int)y;

/// Sets the height of the black line and the extra label feeding length.
/// Sets the height of the black line and the additional feeding length for each label (unit: inches)
/// @param m Height of black line in millimeters
/// @param n Extra label feeding length
/// @return Data command
+ (NSData *)blineByinchWithM:(double)m andN:(double)n;

/// Sets the height of the black line and the user-defined extra label feeding length for each feed action.
/// Sets the height and offset position of the black mark (unit: millimeters)
/// @param m Height of black line in inches
/// @param n Extra label feeding length
/// @return Data command
+ (NSData *)blineBymmWithM:(double)m andN:(double)n;

/// Sets the height of the black line and the user-defined extra label feeding length for each feed action.
/// Sets the height and offset position of the black mark (unit: dots)
/// @param m Height of black line in dots
/// @param n Extra label feeding length
/// @return Data command
+ (NSData *)blineBydotWithM:(int)m andN:(int)n;

/// Sets the position of the label under the peel-off mode.
/// Sets the stopping position of each label in peel-off mode (unit: inches)
/// @param m Offset distance (in inches)
/// @return Data command
+ (NSData *)offSetByinchWithM:(double)m;

/// Sets the position of the label under the peel-off mode.
/// Sets the stopping position of each label in peel-off mode (unit: millimeters)
/// @param m Offset distance (in millimeters)
/// @return Data command
+ (NSData *)offSetBymmWithM:(double)m;

/// Sets the position of the label under the peel-off mode.
/// Sets the stopping position of each label in peel-off mode (unit: dots)
/// @param m Offset distance (in dots)
/// @return Data command
+ (NSData *)offSetBydotWithM:(int)m;

/// Defines the print speed.
/// Sets the feeding speed (unit: inches/second)
/// @param n Printing speed in inches per second
/// @return Data command
+ (NSData *)speed:(double)n;

/// Sets the printing darkness.
/// Sets the printing density
/// @param n Specifies the lightest/darkest level
/// @return Data command
+ (NSData *)density:(int)n;

/// Defines the printout direction and mirror image. This will be stored in the printer memory.
/// Defines the direction of paper output during printing
/// @param n 0 or 1, please refer to the illustrations below.
/// @return Data command
+ (NSData *)direction:(int)n;

/// Defines the reference point of the label. The reference (origin) point varies with the print direction.
/// Defines the reference coordinates for the label
/// @param x Horizontal coordinate (in dots)
/// @param y Vertical coordinate (in dots)
/// @return Data command
+ (NSData *)referenceWithX:(int)x andY:(int)y;

/// Moves the label's vertical position.
/// Moves the vertical position of the label
/// @param n The maximum value is 1 inch. For 200 dpi printers, this range is -203 to 203; for 300 dpi printers, the range is -300 to 300. This unit is dots.
/// @return Data command
+ (NSData *)shift:(int)n;

/// Orients the keyboard for use in different countries via defining special characters on the KP-200 series portable LCD keyboard (option).
/// Used to select international character set
/// @param countryCoding The keyboard for use in different countries via defining special characters
/// @return Data command
+ (NSData *)country:(NSString *)countryCoding;

/// Orients the keyboard for use in different countries via defining special characters on the KP-200 series portable LCD keyboard (option).
/// Specifies character encoding
/// @param str The name of codepage
/// @return Data command
+ (NSData *)codePage:(NSString *)str;

/// Clears the image buffer.
/// Clears the image buffer
/// @return Data command
+ (NSData *)cls;

/// Feeds label with the specified length. The length is specified by dots.
/// Controls the feeding distance, unit: dot
/// @param n The length label feeds
/// @return Data command
+ (NSData *)feed:(int)n;

/// Feeds the label in reverse. The length is specified by dots.
/// Feeds the label in reverse, unit: dot
/// @param n The length label feeds in reverse
/// @return Data command
+ (NSData *)backFeed:(int)n;

/// Feeds label to the beginning of the next label.
/// @return Data command
+ (NSData *)formFeed;

/// This command will feed the label until the sensor has determined the origin.
/// @return Data command
+ (NSData *)home;

/// This command prints the label format currently stored in the image buffer.
/// Prints the label format currently stored in the image buffer
/// @param m Specifies how many sets of labels will be printed
/// @param n Specifies how many copies should be printed for each particular label set
/// @return Data command
+ (NSData *)printWithM:(int)m andN:(int)n;

/// This command prints the label format currently stored in the image buffer.
/// Prints the label format currently stored in the image buffer
/// @param m Specifies how many sets of labels will be printed
/// @return Data command
+ (NSData *)print:(int)m;

/// This command controls the sound frequency of the beeper. There are 10 levels of sounds.
/// Controls the beeper sound frequency
/// @param level Sound level: 0-9
/// @param interval Sound interval: 1-4095
/// @return Data command
+ (NSData *)soundWithLevel:(int)level andInterval:(int)interval;

/// This command activates the cutter to immediately cut the labels without back feeding the label.
/// @return Data command
+ (NSData *)cut;

/// This command is used to stop feeding paper while feeding paper wrong.
/// Stops feeding paper when feeding error occurs
/// @param n The limit length of wrong (in inch)
/// @return Data command
+ (NSData *)limitFeedByinch:(double)n;

/// This command is used to stop feeding paper while feeding paper wrong.
/// Stops feeding paper when feeding error occurs
/// @param n The limit length of wrong (in mm)
/// @return Data command
+ (NSData *)limitFeedBymm:(double)n;

/// This command is used to stop feeding paper while feeding paper wrong.
/// Stops feeding paper when feeding error occurs
/// @param n The limit length of wrong (in dots)
/// @return Data command
+ (NSData *)limitFeedBydot:(int)n;

/// At this command, the printer will print out the printer information.
/// @return Data command
+ (NSData *)selfTest;

/// At this command, the printer will print out the printer information.
/// @param page The type of printer information
/// @return Data command
+ (NSData *)selfTest:(NSString *)page;

/// Let the printer wait until the process of commands (before EOJ) is complete, then go on to the next command.
/// @return Data command
+ (NSData *)eoj;

/// Let the printer wait a specific period of time, then go on to the next command.
/// @param ms Print delay in milliseconds
/// @return Data command
+ (NSData *)delay:(int)ms;

/// This command can show the image, which is in the printer's image buffer, on the LCD panel.
/// @param str IMAGE: Show the image in printer's image buffer on LCD panel
///            OFF: Disable this function
/// @return Data command
+ (NSData *)display:(NSString *)str;

/// This command can restore printer settings to defaults.
/// @return Data command
+ (NSData *)initialPrinter;

/// This command draws a bar on the label format.
/// @param x The upper left corner x-coordinate (in dots)
/// @param y The upper left corner y-coordinate (in dots)
/// @param w Bar width (in dots)
/// @param h Bar height (in dots)
/// @return Data command
+ (NSData *)barWithX:(int)x andY:(int)y andWidth:(int)w andHeight:(int)h;

/// This command prints 1D barcodes.
/// Draws a 1D barcode
/// @param x Specify the x-coordinate
/// @param y Specify the y-coordinate
/// @param codetype Type of barcode
/// @param height Height of barcode
/// @param readable HRI readable, 0-3
/// @param rotation Graphic rotation, 0-90-180-270
/// @param narrow Space in unit
/// @param wide Width of unit
/// @param content Barcode's content
/// @param strEnCoding Barcode's content's encoding
/// @return Data command
+ (NSData *)barcodeWithX:(int)x
                   andY:(int)y
            andCodeType:(NSString *)codetype
              andHeight:(int)height
       andHunabReadable:(int)readable
            andRotation:(int)rotation
              andNarrow:(int)narrow
                andWide:(int)wide
             andContent:(NSString *)content
          usStrEnCoding:(NSStringEncoding)strEnCoding;

/// This command draws bitmap images.
/// Draws a bitmap image
/// @param x Specify the x-coordinate
/// @param y Specify the y-coordinate
/// @param mode Graphic modes listed below:
///             0: OVERWRITE
///             1: OR
///             2: XOR
/// @param image The graphic you want to print
/// @return Data command
+ (NSData *)bitmapWithX:(int)x
                  andY:(int)y
               andMode:(int)mode
              andImage:(UIImage *)image;

/// This command draws rectangles on the label.
/// Draws a rectangle
/// @param x Specify x-coordinate of upper left corner (in dots)
/// @param y Specify y-coordinate of upper left corner (in dots)
/// @param x_end Specify x-coordinate of lower right corner (in dots)
/// @param y_end Specify y-coordinate of lower right corner (in dots)
/// @param thickness Specify the round corner, default is 0
/// @return Data command
+ (NSData *)boxWithX:(int)x
                andY:(int)y
             andEndX:(int)x_end
             andEndY:(int)y_end
        andThickness:(int)thickness;

/// This command draws an ellipse on the label.
/// Draws an ellipse
/// @param x Specify x-coordinate of upper left corner (in dots)
/// @param y Specify y-coordinate of upper left corner (in dots)
/// @param width Specify the width of the ellipse (in dots)
/// @param height Specify the height of the ellipse (in dots)
/// @param thickness Specify the thickness
/// @return Data command
+ (NSData *)ellipseWithX:(int)x
                    andY:(int)y
                andWidth:(int)width
               andHeight:(int)height
            andThickness:(int)thickness;

/// This command draws CODEBLOCK F mode barcode.
/// Draws CODEBLOCK F mode barcode
/// @param x Specify the x-coordinate
/// @param y Specify the y-coordinate
/// @param rotation Rotate rotation degrees clockwise
/// @param content Content of codablock barcode
/// @return Data command
+ (NSData *)codaBlockFModeWithX:(int)x
                           andY:(int)y
                    andRotation:(int)rotation
                     andContent:(NSString *)content;

/// This command draws a DataMatrix 2D barcode.
/// Draws a DataMatrix 2D barcode
/// @param x Specify x-coordinate of upper left corner (in dots)
/// @param y Specify y-coordinate of upper left corner (in dots)
/// @param width Specify the width of DataMatrix
/// @param height Specify the height of DataMatrix
/// @param content The content of DataMatrix
/// @param strEnCoding Barcode's content's encoding
/// @return Data command
+ (NSData *)dmateixWithX:(int)x
                    andY:(int)y
                andWidth:(int)width
               andHeight:(int)height
              andContent:(NSString *)content
           usStrEnCoding:(NSStringEncoding)strEnCoding;

/// This command clears a specified region in the image buffer.
/// Clears the specified region in the image buffer
/// @param x The x-coordinate of the starting point (in dots)
/// @param y The y-coordinate of the starting point (in dots)
/// @param width The region width in x-axis direction (in dots)
/// @param height The region height in y-axis direction (in dots)
/// @return Data command
+ (NSData *)eraseWithX:(int)x
                  andY:(int)y
              andWidth:(int)width
             andHeight:(int)height;

/// This command defines a PDF417 2D barcode.
/// Draws a PDF417 2D barcode
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param width The width of the PDF417
/// @param height The height of the PDF417
/// @param rotate Rotation angle
/// @param content The content of PDF417
/// @param strEnCoding Barcode's content's encoding
/// @return Data command
+ (NSData *)pdf417WithX:(int)x
                   andY:(int)y
               andWidth:(int)width
              andHeight:(int)height
              andRotate:(int)rotate
             andContent:(NSString *)content
          usStrEnCoding:(NSStringEncoding)strEnCoding;

/// Prints BMP format images.
/// @param x The x-coordinate for printing.
/// @param y The y-coordinate for printing.
/// @param filename The name of the BMP file to print.
/// @param contrast The contrast level for the image.
/// @return Data command
+ (NSData *)pubBmpWithX:(int)x
                   andY:(int)y
            andFileName:(NSString *)filename
            andContrast:(int)contrast;

/// This command prints BMP format images.
/// Prints BMP format images
/// @param x The x-coordinate of the BMP format image
/// @param y The y-coordinate of the BMP format image
/// @param filename The download BMP filename
/// @return Data command
+ (NSData *)putBmpWithX:(int)x
                   andY:(int)y
            andFileName:(NSString *)filename;

/// This command prints PCX format images.
/// Prints PCX format images
/// @param x The x-coordinate of the PCX format image
/// @param y The y-coordinate of the PCX format image
/// @param filename The download PCX filename
/// @return Data command
+ (NSData *)putPcxWithX:(int)x
                   andY:(int)y
            andFileName:(NSString *)filename;

/// This command prints QR code.
/// Prints a QR code
/// @param x The upper left corner x-coordinate of the QR code
/// @param y The upper left corner y-coordinate of the QR code
/// @param ecclevel Error correction recovery level
/// @param cellwidth Width of each cell (1~10)
/// @param mode A or M
/// @param rotation Rotation angle (0, 90, 180, 270)
/// @param content The content of the QR code
/// @param strEnCoding The encoding of content
/// @return Data command
+ (NSData *)qrCodeWithX:(int)x
                   andY:(int)y
            andEccLevel:(NSString *)ecclevel
           andCellWidth:(int)cellwidth
                andMode:(NSString *)mode
            andRotation:(int)rotation
             andContent:(NSString *)content
          usStrEnCoding:(NSStringEncoding)strEnCoding;

/// This command reverses a region in the image buffer.
/// This command inverts the specified region in the image buffer.
/// @param x The x-coordinate of the starting point (in dots)
/// @param y The y-coordinate of the starting point (in dots)
/// @param width The x-axis region width (in dots)
/// @param height The y-axis region height (in dots)
+ (NSData *)reverseWithX:(int)x
                    andY:(int)y
                andWidth:(int)width
               andHeight:(int)height;

/// This command prints text on the label.
/// Prints text on the label.
/// @param x The x-coordinate of the text
/// @param y The y-coordinate of the text
/// @param font Font name
/// @param rotation Rotation angle of the text
/// @param x_mul Horizontal multiplication, up to 10x
/// @param y_mul Vertical multiplication, up to 10x
/// @param content The content of the text string
/// @param strEnCoding The encoding of the content string
+ (NSData *)textWithX:(int)x
                 andY:(int)y
              andFont:(NSString *)font
          andRotation:(int)rotation
             andX_mul:(int)x_mul
             andY_mul:(int)y_mul
           andContent:(NSString *)content
        usStrEnCoding:(NSStringEncoding)strEnCoding;

/// This command prints a paragraph on the label.
/// Prints a paragraph on the label.
/// @param x The x-coordinate of the paragraph
/// @param y The y-coordinate of the paragraph
/// @param width The width of the paragraph (in dots)
/// @param height The height of the paragraph (in dots)
/// @param font Font name
/// @param rotation Rotation angle of the paragraph
/// @param x_mul Horizontal multiplication, up to 10x
/// @param y_mul Vertical multiplication, up to 10x
/// @param content The content of the paragraph
/// @param strEnCoding The encoding of the content string
+ (NSData *)blockWithX:(int)x
                  andY:(int)y
              andWidth:(int)width
             andHeight:(int)height
               andFont:(NSString *)font
           andRotation:(int)rotation
              andX_mul:(int)x_mul
              andY_mul:(int)y_mul
             andContent:(NSString *)content
         usStrEnCoding:(NSStringEncoding)strEnCoding;

/// This command obtains the printer status at any time.
/// Retrieves the printer status at any time.
/// @return Data command
+ (NSData *)checkPrinterStatusByPort9100;

/// This command obtains the printer status at any time.
/// Retrieves the printer status at any time.
/// @return Data command
+ (NSData *)checkPrinterStatusByPort4000;

/// Download program file.
/// Downloads a program file.
/// @param filename The filename to download
+ (NSData *)download:(NSString *)filename;

/// Download text file.
/// DOWNLOAD "FILENAME", DATASIZE, CONTENT
/// @param filename The filename to download
/// @param size The size of the data
/// @param content The content of the file
+ (NSData *)download:(NSString *)filename
            andSize:(int)size
          andContent:(NSString *)content;

/// Download text file from a specified path.
/// DOWNLOAD "FILENAME", FILE SIZE, DATA CONTENT
/// @param filename The filename to download
/// @param url The file URL
+ (NSData *)download:(NSString *)filename
            andPath:(NSURL *)url;

/// End of program, to declare the start and the end of BASIC language used in program.
/// Marks the end of the program.
/// @return Data command
+ (NSData *)eop;

/// This command prints out the total memory size, available memory size and file lists in the printer memory.
/// Retrieves the total memory size, available memory size, and file list in the printer memory.
/// @return Data command
+ (NSData *)files;

/// This command deletes a file in the printer memory.
/// Deletes a file from the printer's memory.
/// @param filename The name of the file to be deleted
+ (NSData *)kill:(NSString *)filename;

/// This command moves downloaded files from DRAM to FLASH memory.
/// Moves files from DRAM to FLASH memory.
/// @return Data command
+ (NSData *)move;

/// This command executes a program resident in the printer memory. It is available for TSPL2 printers only.
/// Executes a program stored in the printer's memory.
/// @param filename The name of the program file to be executed
+ (NSData *)run:(NSString *)filename;

/// This command sets the printer to automatically return information.
/// Configures the printer to automatically return information.
/// @param response The type of auto response to set
+ (NSData *)setAutoResponse:(AutoResponse)response;

/// This command draws bitmap images.
/// Draws a bitmap image.
/// @param x The x-coordinate
/// @param y The y-coordinate
/// @param mode Graphic modes listed below:
///             0: OVERWRITE
///             1: OR
///             2: XOR
///             3: OVERWRITE + zlib
///             4: OR + zlib
///             5: XOR + zlib
/// @param image The graphic you want to print
+ (NSData *)zlibBitmapWithX:(int)x
                      andY:(int)y
                   andMode:(int)mode
                  andImage:(UIImage *)image;

/// Sets the feature to feed paper to the tear-off position.
/// Configures whether to feed paper to the tear-off position or stop at the print line.
/// @param isOpen YES: Feed paper to the tear-off position after printing; NO: Stop at the print line after printing
+ (NSData *)setTear:(BOOL)isOpen;

/// Sets the feature to enable/disable the automatic peeler.
/// Configures whether to enable or disable the automatic peeler.
/// @param isOpen YES: Enable the automatic peeler; NO: Disable the automatic peeler
+ (NSData *)setPeel:(BOOL)isOpen;

@end
