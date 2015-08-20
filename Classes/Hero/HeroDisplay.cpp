//
//  HeroDisplay.cpp
//  Interaction
//
//  Created by Coffee on 15/8/3.
//
//

#include "HeroDisplay.h"
#include "DefaultSettings.h"
#include "BackgroudManager.h"
USING_NS_CC;
HeroDisplay* HeroDisplay::create(int displayType) {
    
    auto hero = new HeroDisplay();
    if (hero && hero->init(displayType)) {
        hero->autorelease();
        return hero;
    }
    CC_SAFE_DELETE(hero);
    return nullptr;
}


bool HeroDisplay::init(int displayType) {
    m_displayType = displayType;
    m_scale = 0.5*VISIBLE_SIZE_WIDTH/DEFAULT_IPHONE6_SCREEN_WIDTH;
    switch (displayType) {
        case green: {
            
            this->initWithFile("hero/hero1.png");
            this->setPosition(VISIBLE_SIZE_WIDTH + HERO_WIDTH, HERO_HEIGHT);
            CCLOG("%f，%f",getContentSize().width,getContentSize().height);
            auto sequence = Sequence::create(JumpTo::create(10, Vec2(-this->getContentSize().width, this->getPositionY()), JUMP_HEIGHT, 12),CallFunc::create([=]{
                this->setPositionX(VISIBLE_SIZE_WIDTH + HERO_WIDTH);
            }), DelayTime::create(3.0f), NULL);
            
            this->runAction(RepeatForever::create(sequence));
            this->setScale(m_scale);
        }
            
            break;
        case stone:
            this->initWithFile("hero/hero2.png");
            this->setPosition(VISIBLE_SIZE_WIDTH + getContentSize().width*m_scale, getContentSize().height*m_scale);
            this->runAction(RepeatForever::create(Sequence::create(MoveBy::create(1.5f, Vec2(0, 0)),JumpTo::create(10, Vec2(-getContentSize().width, getPositionY()), 85*VISIBLE_SIZE_WIDTH/DEFAULT_MIN_SCREEN_WIDTH, 12),MoveTo::create(0.0f, Vec2(VISIBLE_SIZE_WIDTH + getContentSize().width*m_scale, getPositionY())),MoveBy::create(1.5f, Vec2(0, 0)), NULL)));
            this->setScale(m_scale);
            break;
        case purple:{
            this->initWithFile("hero/hero3.png");
            Sprite* title = BackgroundManager::getInstance()->getTitle();
            this->setPosition(VISIBLE_SIZE_WIDTH*5/8.0, title->getPositionY() + title->getContentSize().height*VISIBLE_SIZE_WIDTH*2/(DEFAULT_MAX_SCREEN_WIDTH*3));
            this->runAction(RepeatForever::create(JumpBy::create(1, Vec2::ZERO, 100*DEFAULT_IPHONE6_SCREEN_WIDTH/DEFAULT_MAX_SCREEN_WIDTH, 1)));
            this->setScale(m_scale);
        }
            break;
        case yellow:
            this->initWithFile("hero/hero4.png");
            this->setPosition(VISIBLE_SIZE_WIDTH + getContentSize().width*m_scale, getContentSize().height*m_scale);
            this->runAction(RepeatForever::create(Sequence::create(MoveBy::create(3.0f, Vec2(0, 0)),JumpTo::create(10, Vec2(-getContentSize().width, getPositionY()), 85*VISIBLE_SIZE_WIDTH/DEFAULT_MIN_SCREEN_WIDTH, 12),MoveTo::create(0.0f, Vec2(VISIBLE_SIZE_WIDTH + getContentSize().width*m_scale, getPositionY())), NULL)));
            this->setScale(m_scale);

            break;
        default:
            return false;
    }
    return true;
    
}

