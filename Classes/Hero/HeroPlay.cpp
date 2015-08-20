//
//  HeroPlay.cpp
//  rushAndCrush
//
//  Created by Coffee on 15/8/18.
//
//

#include "HeroPlay.h"
#include "DefaultSettings.h"
USING_NS_CC;

bool HeroPlay::init() {
    m_type = (int)(CCRANDOM_0_1()*4);
    m_acceleration = 2;
    m_speedX = 0;
    std::string str = StringUtils::format("hero/hero%d.png", m_type + 1);
    this->initWithFile(str);
    this->setPosition(VISIBLE_SIZE_WIDTH/2, VISIBLE_SIZE_HEIGHT/8);
    return true;
}


void HeroPlay::update(float delay) {
    auto posX = this->getPositionX();
    //加速度
    if (abs(m_speedX) <= MAX_HERO_SPEED) {
        m_speedX = m_acceleration + m_speedX;
    }
    
    this->setPositionX(posX + m_speedX);
}


