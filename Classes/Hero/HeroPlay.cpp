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
    m_scale = 0.5*VISIBLE_SIZE_WIDTH/DEFAULT_IPHONE6_SCREEN_WIDTH;
    m_type = (int)(CCRANDOM_0_1()*4);
    m_accelerationX = DEFAULT_ACCELERATIONX;
    m_accelerationY = DEFAULT_ACCELERATIONY;
    m_speedX = DEFALUT_SPEEDX_INIT;
    m_speddY = DEFALUT_SPEEDY_INIT;
    std::string str = StringUtils::format("hero/hero%d.png", m_type + 1);
    this->initWithFile(str);
    this->setPosition(VISIBLE_SIZE_WIDTH/2, VISIBLE_SIZE_HEIGHT/8);
    this->setScale(m_scale);
    this->setAnchorPoint(Vec2(m_scale, m_scale));
    return true;
}


void HeroPlay::update(float delay) {
    auto posX = this->getPositionX();
    
    //超出边界
    if (posX < 0) {
        this->setPositionX(VISIBLE_SIZE_WIDTH);
    }else if (posX > VISIBLE_SIZE_WIDTH) {
        this->setPositionX(0);
    }
    //加速度
    if (std::abs(m_speedX) <= MAX_HERO_SPEEDX) {
        m_speedX = m_accelerationX + m_speedX;
    }
    
    this->setPositionX(posX + m_speedX);
}


