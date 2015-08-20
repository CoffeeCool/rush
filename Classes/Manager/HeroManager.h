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
USING_NS_CC;

class HeroManager {
private:
    HeroManager();
    static HeroManager* m_instance;
    
public:
    static HeroManager* getInstance();
};


#endif /* defined(__rushAndCrush__HeroManager__) */
