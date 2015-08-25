//
//  MapEntity.cpp
//  Interaction
//
//  Created by Coffee on 15/8/4.
//
//

#include "MapEntity.h"
#include "DefaultSettings.h"
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
    switch (color) {
        case green: {
            this->initWithFile("texture/green.png");
            Texture2D* tex = Director::getInstance()->getTextureCache()->addImage("texture/green.png");
            Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT};
            tex->setTexParameters(tp);
            setTexture(tex);
            setTextureRect(Rect(0,0,width, 50));
        }
            
            break;
        case stone:
        {
            this->initWithFile("texture/stone.png");
            Texture2D* tex = Director::getInstance()->getTextureCache()->addImage("texture/stone.png");
            Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT};
            tex->setTexParameters(tp);
            setTexture(tex);
            setTextureRect(Rect(0,0,width, 50));
        }
            break;
        case purple:
        {
            this->initWithFile("texture/purple.png");
            Texture2D* tex = Director::getInstance()->getTextureCache()->addImage("texture/purple.png");
            Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT};
            tex->setTexParameters(tp);
            setTexture(tex);
            setTextureRect(Rect(0,0,width, 50));
        }
            break;
        case yellow:
        {
            this->initWithFile("texture/yellow.png");
            Texture2D* tex = Director::getInstance()->getTextureCache()->addImage("texture/yellow.png");
            Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT};
            tex->setTexParameters(tp);
            setTexture(tex);
            setTextureRect(Rect(0,0,width, 50));
        }
            break;
        default:
            break;
    }
    this->scheduleUpdate();
    return true;
}

void MapEntity::levelUp() {
    if (m_level >= 5) {
        return;
    }
    m_level++;
}

void MapEntity::update(float delay) {
    switch (m_level) {
        case 1:
            m_boardSpeed = MAX_STAGE_SPEEDY_1;
            break;
        case 2:
            m_boardSpeed = MAX_STAGE_SPEEDY_2;
            break;
        case 3:
            m_boardSpeed = MAX_STAGE_SPEEDY_3;
            break;
        case 4:
            m_boardSpeed = MAX_STAGE_SPEEDY_4;
            break;
        case 5:
            m_boardSpeed = MAX_STAGE_SPEEDY_5;
            break;
        default:
            break;
    }
    setPosition(this->getPositionX(), this->getPositionY() - m_boardSpeed);
    if (getPositionY() <= 0) {
        this->removeFromParent();
    }
}
