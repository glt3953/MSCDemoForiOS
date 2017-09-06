//
//  IATViewController.h
//  MSCDemo_UI
//
//  Created by wangdan on 15-4-28.
//
//

#import <UIKit/UIKit.h>
#import "iflyMSC/iflyMSC.h"

//forward declare
@class PopupView;
@class IFlyDataUploader;
@class IFlySpeechRecognizer;
@class IFlyPcmRecorder;
/**
 语音听写demo
 使用该功能仅仅需要四步
 1.创建识别对象；
 2.设置识别参数；
 3.有选择的实现识别回调；
 4.启动识别
 */
@interface IATViewController : UIViewController<IFlySpeechRecognizerDelegate,IFlyRecognizerViewDelegate,UIActionSheetDelegate,IFlyPcmRecorderDelegate>

@property (nonatomic, strong) NSString *pcmFilePath;//音频文件路径
@property (nonatomic, strong) IFlySpeechRecognizer *iFlySpeechRecognizer;//不带界面的识别对象
@property (nonatomic, strong) IFlyRecognizerView *iflyRecognizerView;//带界面的识别对象
@property (nonatomic, strong) IFlyDataUploader *uploader;//数据上传对象
@property (nonatomic, strong) PopupView *popUpView;

@property (weak, nonatomic) IBOutlet UIButton *startRecBtn;
@property (weak, nonatomic) IBOutlet UIButton *stopRecBtn;
@property (weak, nonatomic) IBOutlet UIButton *cancelRecBtn;
@property (weak, nonatomic) IBOutlet UIButton *upContactBtn;
@property (weak, nonatomic) IBOutlet UIButton *upWordListBtn;
@property (weak, nonatomic) IBOutlet UIButton *audioStreamBtn;

@property (weak, nonatomic) IBOutlet UITextView *textView;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *settingBtn;

@property (nonatomic, strong) NSString * result;
@property (nonatomic, assign) BOOL isCanceled;

@property (nonatomic,strong) IFlyPcmRecorder *pcmRecorder;//录音器，用于音频流识别的数据传入
@property (nonatomic,assign) BOOL isStreamRec;//是否是音频流识别
@property (nonatomic,assign) BOOL isBeginOfSpeech;//是否返回BeginOfSpeech回调

@property (nonatomic, retain) NSThread *fileReadThread;
@property (nonatomic, retain) NSFileHandle *fileHandle;
@property (nonatomic) NSUInteger hasReadFileSize;
@property (nonatomic) int sizeToRead;
@property (nonatomic) NSInteger fileTestIndex; //文件测试序号
@property (nonatomic, strong) NSDate *firstPkgDate; //发送第一包的时间戳
@property (nonatomic, strong) NSDate *negativePkgDate; //发送负包的时间戳
@property (nonatomic) double allTimeInterval; //批量跑完文件的累计耗时
@property (nonatomic, copy) NSString *fileTestResult; //批量音频文件的识别结果

@end
