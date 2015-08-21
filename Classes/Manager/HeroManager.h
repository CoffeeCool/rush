//
//  HeroManager.h
//  rushAndCrush
//
//  Created by Coffee on 15/8/18.
//
//

#ifndef __rushAndCrush__HeroManager__
#define __rushAndCrush__HeroManager__

#include "cocos2d.h"
#include "DefaultSettings.h"
#include "HeroPlay.h"
USING_NS_CC;

class HeroManager {
private:
    HeroManager();
    HeroPlay* m_hero;
    static HeroManager* m_instance;
    
public:
    static HeroManager* getInstance();
    void addHero(Layer* layer);
};


#endif /* defined(__rushAndCrush__HeroManager__) */
