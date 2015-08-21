//
//  GameScene.h
//  Interaction
//
//  Created by Coffee on 15/8/3.
//
//

#ifndef __Interaction__GameScene__
#define __Interaction__GameScene__
#include "cocos2d.h"
USING_NS_CC;
class GameScene: public Layer {
protected:
    bool pm_isStartGame = false;
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(GameScene);
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);  // 开始触摸屏幕时响应
    virtual void onTouchMoved(Touch *touch, Event *unused_event);  // 触摸屏幕并在屏幕上滑动时响应
    virtual void onTouchEnded(Touch *touch, Event *unused_event);  // 触摸结束时响应
};

#endif /* defined(__Interaction__GameScene__) */
