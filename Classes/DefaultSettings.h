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
#define BOARD_SPEED 3
#define ADD_BOARD_PER_PX_DIVIDED_BY_3 100
#define ENTITY_SPACE 100*Director::getInstance()->getVisibleSize().width/750.0
#define BOARD_MIN_WIDTH 200*Director::getInstance()->getVisibleSize().width/750.0
#define BOARD_MAX_WIDTH 350*Director::getInstance()->getVisibleSize().width/750.0
#define RANK_POSITIONX_PERCENT  33/36
#define MUSIC_POSITIONX_PERCENT 27/36

#define MIN_BOARD_WIDTH 200
#define MAX_BOARD_WIDTH 350

#pragma mark 速度
#define MAX_HERO_SPEED 10


enum ColorType{
    green = 0,
    stone = 1,
    purple = 2,
    yellow = 3
};
#endif