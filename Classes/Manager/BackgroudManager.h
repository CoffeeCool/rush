//
//  BackgroudManager.h
//  Interaction
//
//  Created by Coffee on 15/7/31.
//
//

#ifndef __Interaction__BackgroudManager__
#define __Interaction__BackgroudManager__

#include "cocos2d.h"
#include "DefaultSettings.h"
#include "HeroDisplay.h"
#include "GameScene.h"
#include "MapEntity.h"
USING_NS_CC;
class BackgroundManager {
private:

    static BackgroundManager* sm_instance;
    CC_SYNTHESIZE(Sprite*, m_title, Title);
    CC_SYNTHESIZE(Sprite*, m_background_1, Background_1);
    CC_SYNTHESIZE(Sprite*, m_background_2, Background_2);
    CC_SYNTHESIZE(Sprite*, m_startCloud, StartCloud);
    CC_SYNTHESIZE(Sprite*, m_startTriangle,StartTriangle);
    CC_SYNTHESIZE(Sprite*, m_house, House);
    CC_SYNTHESIZE(Sprite*, m_rank, Rank);
    CC_SYNTHESIZE(Sprite*, m_music, Music);
    CC_SYNTHESIZE(int, m_backgroundSpeed, BackgroundSpeed);
    
    std::vector<MapEntity*> m_mapEntities;//board容器
    int m_height;//地图滚动的高度
    int m_heightForNewBoard;
    int m_level;//难度
    float m_entitySpeed;
    bool stopAllAction = false;
    void addHouse(Layer* layer);
    void addBackground(Layer* layer);
    void addStartButton(Layer* layer);//开始游戏
    void addFunctionButton(Layer* layer);
    void addDisplayHeros(Layer* layer);
    void addTitle(Layer* layer);
    void levelUpByHeight();
    void scrollBackground();//滚动背景地图
    int getSpeedByLevel();
    
public:
    
    static BackgroundManager* getInstance();
    void addStartEntity(Layer* layer);//添加开始界面实体
    void addGameEntity(Layer* layer);//添加游戏界面实体
    void addBoard(Layer* layer);
    void update(float delay, Layer* layer);
    void levelUp();
    void stopAllActions();
    void startEntity();
    void remove(MapEntity* removeEntity);
    int getCrashEntity(Rect heroRect, int color);
};

#endif /* defined(__Interaction__BackgroudManager__) */
