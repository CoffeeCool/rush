//
//  HeroManager.cpp
//  rushAndCrush
//
//  Created by Coffee on 15/8/18.
//
//

#include "HeroManager.h"

HeroManager* HeroManager::m_instance;

HeroManager::HeroManager(){

}

HeroManager* HeroManager::getInstance() {
    if (m_instance == NULL) {
        m_instance = new HeroManager();
    }
    return m_instance;
}

void HeroManager::addHero(Layer* layer) {
    if (!m_hero) {
        m_hero = HeroPlay::create();
        layer->addChild(m_hero);
    }
}

void HeroManager::heroStart() {
    if (m_hero) {
        m_hero->scheduleUpdate();
    }
}

void HeroManager::changeDirection() {
    if (m_hero) {
        m_hero->changeDirection();
    }
}


