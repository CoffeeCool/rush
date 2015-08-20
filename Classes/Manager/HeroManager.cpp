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