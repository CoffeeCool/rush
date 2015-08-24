//
//  BackgroudManager.cpp
//  Interaction
//
//  Created by Coffee on 15/7/31.
//
//

#include "BackgroudManager.h"

BackgroundManager* BackgroundManager::sm_instance;

void BackgroundManager::addStartEntity(cocos2d::Layer *layer){
    addBackground(layer);
    addHouse(layer);
    addFunctionButton(layer);
    addTitle(layer);
    addDisplayHeros(layer);
    addStartButton(layer);
}

void BackgroundManager::addGameEntity(cocos2d::Layer *layer) {
    m_speed = BOARD_SPEED;
    m_heightForNewBoard = 0;//初始化高度阈值
    m_height = 0;//
    addBackground(layer);
    addHouse(layer);
}

void BackgroundManager::addBoard(cocos2d::Layer *layer) {
    //随机颜色添加ENTITY，宽度介于MAX_BOARD_WIDTH和MIN_BOARD_WIDTH之间
    auto entity = MapEntity::create((int)(CCRANDOM_0_1()*4), (int)(CCRANDOM_0_1()*(MAX_BOARD_WIDTH - MIN_BOARD_WIDTH) + MIN_BOARD_WIDTH));
    //随机设置新BOARD位置
    entity->setPosition(CCRANDOM_0_1()*VISIBLE_SIZE_WIDTH,VISIBLE_SIZE_HEIGHT + entity->getContentSize().height);
    m_mapEntities.push_back(entity);
    layer->addChild(entity);
}

void BackgroundManager::update(float delay, Layer* layer) {
    m_heightForNewBoard += m_speed;
    m_height += m_speed;
    //300px新增一个障碍
    if (m_heightForNewBoard%ADD_BOARD_PER_PX_DIVIDED_BY_3 == 0) {
        m_heightForNewBoard = 0;//归零
        addBoard(layer);
    }
    m_background_1->setPositionY(m_background_1->getPositionY() - m_speed);
    m_background_2->setPositionY(m_background_2->getPositionY() - m_speed);
    if (m_background_1->getPositionY() < -(m_background_1->getContentSize().height)*(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH)) {
        m_background_1->setPositionY((m_background_1->getContentSize().height)*(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH));
    }else if (m_background_2->getPositionY() < -(m_background_2->getContentSize().height*(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH))) {
        m_background_2->setPositionY((m_background_1->getContentSize().height)*(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH));
    }
}

void BackgroundManager::updateLevel(){
    m_speedLevel += 1;
}

BackgroundManager* BackgroundManager::getInstance() {
    
    if (sm_instance == NULL) {
        sm_instance = new BackgroundManager();
    }
    return sm_instance;
}

BackgroundManager::BackgroundManager() {
}

void BackgroundManager::addHouse(cocos2d::Layer* layer) {
    m_house = Sprite::create("background/house.png");
    m_house->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    m_house->setAnchorPoint(Vec2::ZERO);
    layer->addChild(m_house);
}

void BackgroundManager::addBackground(cocos2d::Layer *layer) {
    
    m_background_1 = Sprite::create("background/background.png");
    m_background_2 = Sprite::create("background/background.png");
    m_background_1->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    m_background_2->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    m_background_1->setAnchorPoint(Vec2::ZERO);
    m_background_2->setAnchorPoint(Vec2::ZERO);
    m_background_1->setPosition(0, 0);
    m_background_2->setPosition(0, VISIBLE_SIZE_HEIGHT-2);
    layer->addChild(m_background_1);
    layer->addChild(m_background_2);
}

void BackgroundManager::addStartButton(cocos2d::Layer *layer) {

    m_startCloud = Sprite::create("background/startCloud.png");
    m_startTriangle = Sprite::create("background/startTriangle.png");
    //        m_startCloud->setScale(m_visibaleSize.width/1080);
    //        m_startTriangle->setScale(m_visibaleSize.width/1080);
    m_startCloud->setPosition(VISIBLE_SIZE_WIDTH/2, VISIBLE_SIZE_HEIGHT/2);
    m_startTriangle->setPosition(VISIBLE_SIZE_WIDTH/2, VISIBLE_SIZE_HEIGHT/2);
    m_startCloud->runAction(RepeatForever::create(RotateBy::create(10, 360)));//云朵持续旋转
    layer->addChild(m_startCloud);
    layer->addChild(m_startTriangle);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch* t, Event* e){
        auto position = t->getLocation();
        if (this->m_startTriangle->getBoundingBox().containsPoint(position)) {

            CCLOG("Touched!!!");
        }
        else {
            CCLOG("MISS!");
        }
        return true;
    };
    listener->onTouchEnded = [this](Touch* t, Event* e){
        auto position = t->getLocation();
        if (this->m_startTriangle->getBoundingBox().containsPoint(position)) {
            
            //渐变切换至游戏场景
            auto sceneWillDisplay = TransitionCrossFade::create(1, GameScene::createScene());
            Director::getInstance()->replaceScene(sceneWillDisplay);
        }
        CCLOG("END!");
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, layer);
}

void BackgroundManager::addFunctionButton(cocos2d::Layer *layer) {
    m_rank = Sprite::create("background/rank.png");
    m_music = Sprite::create("background/music.png");
    m_rank->setPosition(VISIBLE_SIZE_WIDTH*RANK_POSITIONX_PERCENT,VISIBLE_SIZE_HEIGHT - m_rank->getContentSize().height/2);
    m_music->setPosition(VISIBLE_SIZE_WIDTH*MUSIC_POSITIONX_PERCENT,VISIBLE_SIZE_HEIGHT - m_rank->getContentSize().height/2);
    m_rank->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    m_music->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    layer->addChild(m_rank);
    layer->addChild(m_music);
}

void BackgroundManager::addTitle(cocos2d::Layer *layer)  {
    m_title = Sprite::create("background/title.png");
    m_title->setPosition(VISIBLE_SIZE_WIDTH/2, VISIBLE_SIZE_HEIGHT*3/4);
    m_title->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    layer->addChild(m_title);
}


void BackgroundManager::addDisplayHeros(cocos2d::Layer *layer) {
    auto heroDisplay1 = HeroDisplay::create(green);
    auto heroDisplay2 = HeroDisplay::create(stone);
    auto heroDisplay3 = HeroDisplay::create(purple);
    auto heroDisplay4 = HeroDisplay::create(yellow);
    layer->addChild(heroDisplay1);
    layer->addChild(heroDisplay2);
    layer->addChild(heroDisplay3);
    layer->addChild(heroDisplay4);
}


MapEntity* BackgroundManager::getCrashEntity(cocos2d::Rect heroRect, int color){
    for (int i = 0; i < m_mapEntities.size(); i++) {
        MapEntity* entity = m_mapEntities[i];
        Rect rect;
        rect.size = Size(entity->getBoardWidth(),50);
        rect.origin = entity->getPosition();
        if (rect.intersectsRect(heroRect) && color != entity->getBoardColor()) {
            return entity;
        }
    }

    
}

