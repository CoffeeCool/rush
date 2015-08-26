//
//  GameScene.cpp
//  Interaction
//
//  Created by Coffee on 15/8/3.
//
//

#include "GameScene.h"
#include "DefaultSettings.h"
#include "BackgroudManager.h"
#include "HeroManager.h"
USING_NS_CC;


Scene* GameScene::createScene() {
    
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init() {
    
    if (!Layer::init()) {
        return false;
    }
    //加入背景
    BackgroundManager::getInstance()->addGameEntity(this);
    schedule([this](float delay){
        BackgroundManager::getInstance()->update(delay,this);
    }, "gameRun");
    BackgroundManager::getInstance()->stopAllActions();
    //加入Hero
    HeroManager::getInstance()->addHero(this);
    
    // 获取事件分发器
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    // 创建单点触摸监听器
    auto listener = EventListenerTouchOneByOne::create();
    // 让监听器绑定事件处理函数
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan,this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved,this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded,this);
    // 将事件监听器添加到事件调度器
    dispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    
    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    return true;
}


void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    
}

void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    if (!pm_isStartGame) {
        pm_isStartGame = true;
        HeroManager::getInstance()->heroStart();
        BackgroundManager::getInstance()->startEntity();
        
    }else {
        HeroManager::getInstance()->changeDirection();
    }
    
}

