//
//  BackgroudManager.cpp
//  Interaction
//
//  Created by Coffee on 15/7/31.
//
//

#include "BackgroudManager.h"
#include "HeroManager.h"

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
    m_level = 1;
    m_backgroundSpeed = 0;
    m_heightForNewBoard = 0;//初始化Board距离
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
    
    if (stopAllAction) {
        return;
    }
    
    int addBoardPerPXDividedBy3;
    switch (m_level) {
        case 1:
            m_backgroundSpeed = BACKGROUND_SPEED_1;
            addBoardPerPXDividedBy3 = ADD_BOARD_PER_PX_DIVIDED_BY_3_1;
            break;
        case 2:
            m_backgroundSpeed = BACKGROUND_SPEED_2;
            addBoardPerPXDividedBy3 = ADD_BOARD_PER_PX_DIVIDED_BY_3_2;
            break;
        case 3:
            m_backgroundSpeed = BACKGROUND_SPEED_3;
            addBoardPerPXDividedBy3 = ADD_BOARD_PER_PX_DIVIDED_BY_3_3;
            break;
        case 4:
            m_backgroundSpeed = BACKGROUND_SPEED_4;
            addBoardPerPXDividedBy3 = ADD_BOARD_PER_PX_DIVIDED_BY_3_4;
            break;
        case 5:
            m_backgroundSpeed = BACKGROUND_SPEED_5;
            addBoardPerPXDividedBy3 = ADD_BOARD_PER_PX_DIVIDED_BY_3_5;
            break;
        default:
            m_backgroundSpeed = BACKGROUND_SPEED_1;
            addBoardPerPXDividedBy3 = ADD_BOARD_PER_PX_DIVIDED_BY_3_1;
            break;
    }
    m_heightForNewBoard += m_backgroundSpeed;
    m_height += m_backgroundSpeed;
    
    
    //新增一个障碍
    
    if (m_heightForNewBoard%addBoardPerPXDividedBy3 == 0) {
        m_heightForNewBoard = 0;//归零
        addBoard(layer);
    }
    m_background_1->setPositionY(m_background_1->getPositionY() - m_backgroundSpeed);
    m_background_2->setPositionY(m_background_2->getPositionY() - m_backgroundSpeed);
    if (m_background_1->getPositionY() < -(m_background_1->getContentSize().height)*(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH)) {
        m_background_1->setPositionY((m_background_1->getContentSize().height)*(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH));
    }else if (m_background_2->getPositionY() < -(m_background_2->getContentSize().height*(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH))) {
        m_background_2->setPositionY((m_background_1->getContentSize().height)*(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH));
    }
    
    
    if (m_height > LEVELUP_HEIGHT_1 && m_height <= LEVELUP_HEIGHT_2) {
        levelUp();
    }else if (m_height > LEVELUP_HEIGHT_2 && m_height <= LEVELUP_HEIGHT_3) {
        levelUp();
    }else if (m_height > LEVELUP_HEIGHT_3 && m_height <= LEVELUP_HEIGHT_4) {
        levelUp();
    }else if (m_height > LEVELUP_HEIGHT_4 && m_height <= LEVELUP_HEIGHT_5) {
        levelUp();
    }
}

void BackgroundManager::levelUp(){
    if (m_level >= 5) {
        return;
    }
    m_level++;
    for (int i = 0; i < m_mapEntities.size(); i++) {
        MapEntity* entity = m_mapEntities[i];
        entity->levelUp();
    }
    HeroManager::getInstance()->levelUp();
}

BackgroundManager* BackgroundManager::getInstance() {
    
    if (sm_instance == NULL) {
        sm_instance = new BackgroundManager();
    }
    return sm_instance;
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


int BackgroundManager::getCrashEntity(cocos2d::Rect heroRect, int color){
    for (int i = 0; i < m_mapEntities.size(); i++) {
        MapEntity* entity = m_mapEntities[i];
        Rect rect = entity->getBoundingBox();
        if (rect.intersectsRect(heroRect) && color != entity->getBoardColor()) {
            return WRONG;
        }
        if (rect.intersectsRect(heroRect) && color == entity->getBoardColor() ) {
            return RIGHT;
        }
    }
    return NOTHING;
}


void BackgroundManager::stopAllActions() {
    stopAllAction = true;
    for (int i = 0; i < m_mapEntities.size(); i++) {
        MapEntity* entity = m_mapEntities[i];
        entity->unscheduleUpdate();
        
    }
}

void BackgroundManager::startEntity() {
    stopAllAction = false;
    for (int i = 0; i < m_mapEntities.size(); i++) {
        MapEntity* entity = m_mapEntities[i];
        entity->scheduleUpdate();
    }
}



void BackgroundManager::remove(MapEntity *removeEntity) {
    
    for (int i = 0; i < m_mapEntities.size(); i++) {
        MapEntity* entity = m_mapEntities[i];
        if (entity == removeEntity) {
            m_mapEntities.erase(std::find(m_mapEntities.begin(), m_mapEntities.end(), entity));
        }
    }
    
}
