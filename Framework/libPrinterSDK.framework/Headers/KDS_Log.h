//
//  KDS_Log.h
//  Printer
//
//  Created by Apple Mac mini intel on 2022/11/4.
//  Copyright © 2022 Admin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Custom log with configurable switch (used to replace NSLog)
#define KDS_Log(format,...) CustomLog(__FUNCTION__,__LINE__,format,##__VA_ARGS__)

/// Converts a custom log function for logging purposes.
/// This function allows for logging with the method name and line number.
/// @warning Can be directly called from outside using KDS_Log.
/// @param func         The name of the method.
/// @param lineNumber   The line number.
/// @param format       The log content.
/// @param ...          Variable number of log parameters.
void CustomLog(const char *func, int lineNumber, NSString *format, ...);

@interface KDS_Log : NSObject

/// Sets the log output switch (default is off).
/// @param flag Indicates whether to enable logging.
+ (void)setLogEnable:(BOOL)flag;

/// Returns the current status of the log switch.
/// @return YES if logging is enabled, NO otherwise.
+ (BOOL)logEnable;

@end


NS_ASSUME_NONNULL_END
