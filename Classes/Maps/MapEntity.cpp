//
//  MapEntity.cpp
//  Interaction
//
//  Created by Coffee on 15/8/4.
//
//

#include "MapEntity.h"
#include "DefaultSettings.h"
#include "BackgroudManager.h"
USING_NS_CC;
MapEntity* MapEntity::create(int color, int width)
{
    MapEntity* sprite = new (std::nothrow) MapEntity();
    if (sprite && sprite->init(color, width)) {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

bool MapEntity::init(int color, int width) {
    m_level = 1;
    m_boardColor = color;
    m_boardWidth = width;
    m_boardSpeed = 5;
    initWithFileByColor(color, width);
    scheduleUpdate();
    return true;
}

void MapEntity::initWithFileByColor(int color, int width) {
    std::string sColor;
    switch (color) {
        case green:
            sColor = "green";
            break;
        case stone:
            sColor = "stone";
            break;
        case purple:
            sColor = "purple";
            break;
        case yellow:
            sColor = "yellow";
            break;
        default:
            sColor = "green";
            break;
    }
    std::string str = StringUtils::format("texture/%s.png",sColor.c_str());
    this->initWithFile(str);
    Texture2D* tex = Director::getInstance()->getTextureCache()->addImage(str);
    Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT};
    tex->setTexParameters(tp);
    setTexture(tex);
    setTextureRect(Rect(0,0,width, 50));

}

void MapEntity::levelUp() {
    if (m_level >= 5) {
        return;
    }
    m_level++;
}

float getBoardSpeedByLevel(int level) {
    switch (level) {
        case 1:
            return MAX_STAGE_SPEEDY_1;
            break;
        case 2:
            return MAX_STAGE_SPEEDY_2;
            break;
        case 3:
            return MAX_STAGE_SPEEDY_3;
            break;
        case 4:
            return MAX_STAGE_SPEEDY_4;
            break;
        case 5:
            return MAX_STAGE_SPEEDY_5;
            break;
        default:
            return MAX_STAGE_SPEEDY_1;
            break;
    }
}


void MapEntity::update(float delay) {
    m_boardSpeed = getBoardSpeedByLevel(m_level);
    setPosition(this->getPositionX(), this->getPositionY() - m_boardSpeed);
    if (getPositionY() <= 0) {
        BackgroundManager::getInstance()->remove(this);
        this->removeFromParent();

    }
}
