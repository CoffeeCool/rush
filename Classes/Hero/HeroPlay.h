//
//  HeroPlay.h
//  rushAndCrush
//
//  Created by Coffee on 15/8/18.
//
//

#ifndef __rushAndCrush__HeroPlay__
#define __rushAndCrush__HeroPlay__

#include "cocos2d.h"

class HeroPlay : public cocos2d::Sprite {
    
private:
    float m_scale;//放大倍数
    CC_SYNTHESIZE(float, m_accelerationX, AccelerationX);//X轴加速度 负数为左
    CC_SYNTHESIZE(float, m_speedX, SpeedX);//X轴速度，绝对速度 负数为左
    int m_type;//类型
    bool m_direction = true;//true为右,false为左
    virtual bool init();
    virtual void update(float delay);
public:
    CREATE_FUNC(HeroPlay);
    void changeDirection();
};

#endif /* defined(__rushAndCrush__HeroPlay__) */
