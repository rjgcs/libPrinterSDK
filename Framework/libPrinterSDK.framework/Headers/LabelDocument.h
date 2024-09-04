//
//  LabelDocument.h
//  Printer
//
//  Created by Apple Mac mini intel on 2023/3/21.
//  Copyright © 2023 Admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

/// Represents document error codes
typedef NS_ENUM(NSInteger, DocErrorCode) {
    /// Operation successful
    DocSuccess = 0,
    /// PDF document reference is null
    CGPDFDocumentRefNULL,
    /// Page number exceeds the limit
    PageNumberExceeds,
};

/// Parsing data callback block
/// @param sourceImages Array of images parsed from the document
/// @param errorCode Error code encountered during document processing
typedef void (^ParsingDataCallBackBlock) (NSMutableArray<UIImage *> *sourceImages, DocErrorCode errorCode);

@interface LabelDocument : NSObject

/// Gets the total number of pages in the current PDF file
/// @param filePath Path to the PDF file
/// @param password Password for the PDF file (optional)
/// @return Total number of pages in the PDF file
+ (int)getPDFPages:(NSString *)filePath pdfPassword:(nullable NSString *)password;

/// Parses the document to retrieve the corresponding image data source collection
/// @param filePath Path to the PDF file
/// @param startPage Starting page number
/// @param endPage Ending page number
/// @param password Password for the PDF file (optional)
/// @param dataBlock Callback block to be executed after parsing is complete
+ (void)parsingDoc:(NSString *)filePath start:(int)startPage end:(int)endPage password:(nullable NSString *)password DataCallBack:(ParsingDataCallBackBlock)dataBlock;

/// Scales the corresponding image data source based on width
/// @param image Image to be scaled
/// @param width Target width after scaling
/// @return Scaled image
+ (UIImage *)imageWithScaleImage:(UIImage *)image andScaleWidth:(int)width;

@end


NS_ASSUME_NONNULL_END
