//
//  HeroPlay.cpp
//  rushAndCrush
//
//  Created by Coffee on 15/8/18.
//
//

#include "HeroPlay.h"
#include "DefaultSettings.h"
#include "BackgroudManager.h"
USING_NS_CC;

bool HeroPlay::init() {
    m_level = 1;
    m_isStart = false;
    m_scale = 0.5*VISIBLE_SIZE_WIDTH/DEFAULT_IPHONE6_SCREEN_WIDTH;
    m_type = (int)(CCRANDOM_0_1()*4);
    m_accelerationX = DEFAULT_ACCELERATIONX;
    m_speedX = DEFALUT_SPEEDX_INIT;
    std::string str = StringUtils::format("hero/hero%d.png", m_type + 1);
    this->initWithFile(str);
    this->setPosition(VISIBLE_SIZE_WIDTH/2, VISIBLE_SIZE_HEIGHT/8);
    this->setScale(m_scale);
    this->setAnchorPoint(Vec2(m_scale, m_scale));
    return true;
}

void HeroPlay::changeDirection() {


    m_direction = !m_direction;
    m_accelerationX = -m_accelerationX;
    
    changeRotation();
}

void HeroPlay::changeRotation() {
    float rotationTime;
    //通过游戏难度调整旋转速度
    switch (m_level) {
        case 1:
            rotationTime = ROTATION_TIME_1;
            break;
        case 2:
            rotationTime = ROTATION_TIME_2;
            break;
        case 3:
            rotationTime = ROTATION_TIME_3;
            break;
        case 4:
            rotationTime = ROTATION_TIME_4;
            break;
        case 5:
            rotationTime = ROTATION_TIME_5;
            break;
        default:
            rotationTime = ROTATION_TIME_1;
            break;
    }
    if (m_isStart) {
        if (m_direction) {
            this->runAction(RotateTo::create(rotationTime, 30));
        }else {
            this->runAction(RotateTo::create(rotationTime, -30));
        }
    }else {
        this->runAction(RotateTo::create(rotationTime, 15));
    }
}

void HeroPlay::levelUp() {
    if (m_level >= 5) {
        return;
    }
    m_level++;
}



void HeroPlay::update(float delay) {
    auto posX = this->getPositionX();
    
    //超出边界
    if (posX < 0) {
        posX = VISIBLE_SIZE_WIDTH;
        this->setPositionX(posX);
    }else if (posX > VISIBLE_SIZE_WIDTH) {
        posX = 0.0;
        this->setPositionX(posX);
    }
    
    float heroSpeedX;
    //通过游戏难度调整平移速度
    switch (m_level) {
        case 1:
            heroSpeedX = MAX_HERO_SPEEDX_1;
            if (m_accelerationX > 0) {
            }
            break;
        case 2:
            heroSpeedX = MAX_HERO_SPEEDX_2;
            break;
        case 3:
            heroSpeedX = MAX_HERO_SPEEDX_3;
            break;
        case 4:
            heroSpeedX = MAX_HERO_SPEEDX_4;
            break;
        case 5:
            heroSpeedX = MAX_HERO_SPEEDX_5;
            break;
        default:
            heroSpeedX = MAX_HERO_SPEEDX_1;

            break;
    }
    
    //加速度
    if (m_direction) {
        if (m_speedX > 0) {
            if (std::fabsf(m_speedX) <= heroSpeedX) {
                m_speedX = m_accelerationX + m_speedX;
            }
        }else {
            m_speedX = m_accelerationX + m_speedX;
        }
    }else {
        if (m_speedX < 0) {
            if (std::fabsf(m_speedX) <= heroSpeedX) {
                m_speedX = m_accelerationX + m_speedX;
            }
        }else {
            m_speedX = m_accelerationX + m_speedX;
        }
    }
    this->setPositionX(posX + m_speedX);
    
    int msg = BackgroundManager::getInstance()->getCrashEntity(boundingBox(), m_type);
    
    if(msg == WRONG){
        BackgroundManager::getInstance()->stopAllActions();
        this->unscheduleUpdate();
    }else if (msg == RIGHT) {
        changeType();
    }
    
}

void HeroPlay::changeColor() {
    int temp = m_type;
    m_type = (int)(CCRANDOM_0_1()*4) + 1;
    if (m_type == temp) {
        changeColor();
    }
}

void HeroPlay::changeType() {
    changeColor();
    std::string str = StringUtils::format("hero/hero%d.png", m_type);
    this->setTexture(str);
}

