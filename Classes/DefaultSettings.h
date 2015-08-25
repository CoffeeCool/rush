//
//  DefaultSettings.h
//  Interaction
//
//  Created by Coffee on 15/8/3.
//  Coffee的游戏编程思想：出现的数字尽量用宏定义代替
//

#ifndef Interaction_DefaultSettings_h
#define Interaction_DefaultSettings_h

#pragma mark  屏幕适配

#define DEFAULT_MAX_SCREEN_WIDTH 1080.0
#define DEFAULT_MAX_SCREEN_HEIGHT 1920.0
#define DEFAULT_MIN_SCREEN_WIDTH 640.0
#define DEFAULT_MIN_SCREEN_HEIGHT 1136.0
#define DEFAULT_IPHONE4S_SCREEN_HEIGHT 960.0
#define DEFAULT_IPHONE6_SCREEN_WIDTH 750.0
#define DEFAULT_IPHONE6_SCREEN_HEIGHT 1334.0
#define VISIBLE_SIZE_WIDTH Director::getInstance()->getVisibleSize().width
#define VISIBLE_SIZE_HEIGHT Director::getInstance()->getVisibleSize().height


#pragma mark 位置和长度相关
#define JUMP_HEIGHT 85*Director::getInstance()->getVisibleSize().width/640
#define HERO_WIDTH 181
#define HERO_HEIGHT 209
#define TITLE_WIDTH 263
#define TITLE_HEIGHT 861

#define ENTITY_SPACE 100*Director::getInstance()->getVisibleSize().width/750.0
#define BOARD_MIN_WIDTH 200*Director::getInstance()->getVisibleSize().width/750.0
#define BOARD_MAX_WIDTH 350*Director::getInstance()->getVisibleSize().width/750.0
#define RANK_POSITIONX_PERCENT  33/36
#define MUSIC_POSITIONX_PERCENT 27/36

#define MIN_BOARD_WIDTH 200
#define MAX_BOARD_WIDTH 350

#pragma mark 速度


#define DEFALUT_SPEEDX_INIT 0   //默认X轴起始速度
#define DEFALUT_SPEEDY_INIT 0   //默认Y轴其实速度
#define DEFAULT_ACCELERATIONX 0.3 //默认X轴加速度
#define DEFAULT_ACCELERATIONY 2 //默认Y轴加速度


#define ADD_BOARD_PER_PX_DIVIDED_BY_3_1 100
#define ADD_BOARD_PER_PX_DIVIDED_BY_3_2 90
#define ADD_BOARD_PER_PX_DIVIDED_BY_3_3 80
#define ADD_BOARD_PER_PX_DIVIDED_BY_3_4 70
#define ADD_BOARD_PER_PX_DIVIDED_BY_3_5 60


#define LEVELUP_HEIGHT_1 100
#define LEVELUP_HEIGHT_2 250
#define LEVELUP_HEIGHT_3 400
#define LEVELUP_HEIGHT_4 550
#define LEVELUP_HEIGHT_5 700


#define MAX_HERO_SPEEDX_1 6   //HERO最大X轴速度的绝对值
#define MAX_HERO_SPEEDX_2 7
#define MAX_HERO_SPEEDX_3 8
#define MAX_HERO_SPEEDX_4 9
#define MAX_HERO_SPEEDX_5 10

#define BACKGROUND_SPEED_1 3
#define BACKGROUND_SPEED_2 4
#define BACKGROUND_SPEED_3 5
#define BACKGROUND_SPEED_4 6
#define BACKGROUND_SPEED_5 7

#define MAX_STAGE_SPEEDY_1 10 //第一阶段速度峰值
#define MAX_STAGE_SPEEDY_2 15 //第二阶段速度峰值
#define MAX_STAGE_SPEEDY_3 20 //第三阶段速度峰值
#define MAX_STAGE_SPEEDY_4 25 //第四阶段速度峰值
#define MAX_STAGE_SPEEDY_5 30 //第五阶段速度峰值

#define ROTATION_TIME_1 0.4   //旋转方向
#define ROTATION_TIME_2 0.32
#define ROTATION_TIME_3 0.26
#define ROTATION_TIME_4 0.20
#define ROTATION_TIME_5 0.15


enum ColorType{
    green = 0,
    stone = 1,
    purple = 2,
    yellow = 3
};
#endif

