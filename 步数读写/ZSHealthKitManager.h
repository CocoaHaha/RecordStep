//
//  HealthKitManager.h
//  步数读写
//
//  Created by 石向锋 on 2017/5/12.
//  Copyright © 2017年 CocoHaHa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HealthKit/HealthKit.h>//获取系统步数
@interface ZSHealthKitManager : NSObject
@property (nonatomic, strong) HKHealthStore *healthStore;
+(id)shareInstance;
/*
 *  @brief  检查是否支持获取健康数据
 */
- (void)authorizeHealthKit:(void(^)(BOOL success, NSError *error))compltion;
/*!
 *  @brief  写权限
 *  @return 集合
 */
- (NSSet *)dataTypesToWrite;
/*!
 *  @brief  读权限
 *  @return 集合
 */
- (NSSet *)dataTypesRead;

//获取步数
- (void)getStepCount:(void(^)(double value, NSError *error))completion;
//获取公里数
- (void)getDistance:(void(^)(double value, NSError *error))completion;
/*!
 *  @brief  当天时间段
 *
 *  @return 时间段
 */
+ (NSPredicate *)predicateForSamplesToday;

@end
