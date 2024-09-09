#
# Be sure to run `pod lib lint libPrinterSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'libPrinterSDK'
  s.version          = '2.3.7'
  s.summary          = 'A software development kit for printer communication and control.'
  s.description      = <<-DESC
libPrinterSDK is a software development kit designed for printer operations, offering functions and interfaces for communicating with and controlling printers.
                       DESC

  s.homepage         = 'https://github.com/rjgcs/libPrinterSDK.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Apple Mac mini intel' => 'rj-gcs10@xprinter.net' }
  s.source           = { :git => 'https://github.com/rjgcs/libPrinterSDK.git', :tag => "#{s.version}"}
  s.ios.deployment_target = '11.0'
  s.source_files = 'Framework/libPrinterSDK.framework/Headers/*.{h,m}'
  s.public_header_files = 'Framework/libPrinterSDK.framework/Headers/*.{h}'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.frameworks = 'UIKit', 'CoreBluetooth', 'Foundation', 'CoreGraphics', 'SystemConfiguration'
  s.ios.vendored_frameworks = 'Framework/libPrinterSDK.framework'
  s.vendored_frameworks = 'libPrinterSDK.framework'
end
