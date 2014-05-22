//
//  CCSliderLoader.cpp
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/23/14.
//
//

#include "CCSliderLoader.h"

using namespace cocos2d;
/*
#define PROPERTY_TOUCH_ENABLED "isTouchEnabled"
#define PROPERTY_ACCELEROMETER_ENABLED "isAccelerometerEnabled"
#define PROPERTY_MOUSE_ENABLED "isMouseEnabled"
#define PROPERTY_KEYBOARD_ENABLED "isKeyboardEnabled"

#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (push)
#pragma warning (disable: 4996)
#endif
*/
using namespace cocos2d;
using namespace cocos2d::extension;
#define PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL "backgroundSpriteFrame|Normal"
#define PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED "backgroundSpriteFrame|Highlighted"
#define PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED "backgroundSpriteFrame|Disabled"

#define PROPERTY_HANDLESPRITEFRAME_NORMAL "handleSpriteFrame|Normal"
#define PROPERTY_HANDLESPRITEFRAME_HIGHLIGHTED "handleSpriteFrame|Highlighted"
#define PROPERTY_HANDLESPRITEFRAME_DISABLED "handleSpriteFrame|Disabled"

namespace cocosbuilder {
    void SliderLoader::onHandlePropTypeBlock(Node * pNode, Node * pParent, const char* pPropertyName, BlockData * pBlockData, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, "block") == 0) {
//            ((cocos2d::ui::Slider*)pNode)->set
        } else {
            NodeLoader::onHandlePropTypeBlock(pNode, pParent, pPropertyName, pBlockData, ccbReader);
        }
    }
    void SliderLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char* pPropertyName, Size pSize, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, "preferredSize") == 0) {
            //((ControlSlider*)pNode)->setContentSize(pSize);
            _contentSize = pSize;
        } else {
            NodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
        }
    }
    
    void SliderLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char* pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL) == 0) {
            if(pSpriteFrame != NULL) {
                //((Slider *)pNode)->loadSlidBallTextureNormal(pSpriteFrame, Control::State::NORMAL);
                //((ControlSlider*)pNode)->setBackgroundSprite(CCSprite::createWithSpriteFrame(pSpriteFrame));
                //((ControlSlider*)pNode)->setProgressSprite(CCSprite::createWithSpriteFrame(pSpriteFrame));
                //this->_progressSprite = pSpriteFrame;
                this->_backgroundSprite = pSpriteFrame;
                _backgroundSprite->retain();
            }
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED) == 0) {
            if(pSpriteFrame != NULL) {
                //((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::HIGH_LIGHTED);
            }
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED) == 0) {
            if(pSpriteFrame != NULL) {
                //((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::DISABLED);
            }
        } else if(strcmp(pPropertyName, PROPERTY_HANDLESPRITEFRAME_NORMAL) == 0) {
            if(pSpriteFrame != NULL) {
                //((Slider *)pNode)->loadSlidBallTextureNormal(pSpriteFrame, Control::State::NORMAL);
//                ((ControlSlider*)pNode)->setThumbSprite(CCSprite::createWithSpriteFrame(pSpriteFrame));
                this->_handleSprite = pSpriteFrame;
                _handleSprite->retain();
            }
        } else if(strcmp(pPropertyName, PROPERTY_HANDLESPRITEFRAME_HIGHLIGHTED) == 0) {
            if(pSpriteFrame != NULL) {

                this->_selectedHandleSprite = pSpriteFrame;
                _selectedHandleSprite->retain();
                //((ControlSlider*)pNode)->setSelectedThumbSprite(CCSprite::createWithSpriteFrame(pSpriteFrame));
                //((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::HIGH_LIGHTED);
            }
        } else if(strcmp(pPropertyName, PROPERTY_HANDLESPRITEFRAME_DISABLED) == 0) {
            if(pSpriteFrame != NULL) {
                //((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::DISABLED);
            }
        } else {
            NodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
        }
    }

    void SliderLoader::onDone(cocos2d::Node * pNode, cocos2d::Node * pParent, CCBReader * ccbReader) {
        Scale9Sprite* background = Scale9Sprite::createWithSpriteFrame(this->_backgroundSprite);
        background->setContentSize(_contentSize);

        Sprite* progressSprite = Sprite::create();
        progressSprite->setContentSize(_contentSize);
        progressSprite->addChild(background);
        background->setAnchorPoint(Point(0.0, 0.5));
        
        Sprite* sprite = Sprite::create();
        sprite->setContentSize(_contentSize);
        sprite->setAnchorPoint(Point(0.0, 0.0));
        
        ((ControlSlider*)pNode)->setContentSize(_contentSize);

        
        if (_selectedHandleSprite)
            ((ControlSlider *)pNode)->initWithSprites(sprite,
                                                  progressSprite,
                                                  Sprite::createWithSpriteFrame(this->_handleSprite),
                                                  Sprite::createWithSpriteFrame(this->_selectedHandleSprite));
        else
            ((ControlSlider *)pNode)->initWithSprites(sprite,
                                                      progressSprite,
                                                      Sprite::createWithSpriteFrame(this->_handleSprite));
        
        
        ((ControlSlider*)pNode)->setAnchorPoint(Point(0.0, 0.25));
        
        _backgroundSprite->release();
        _handleSprite->release();
        if (_selectedHandleSprite)
            _selectedHandleSprite->release();
//        ((ControlSlider *)pNode)->setMaximumValue(100);
//        ((ControlSlider *)pNode)->setMinimumValue(0);
        

    }
}

#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic warning "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (pop)
#endif