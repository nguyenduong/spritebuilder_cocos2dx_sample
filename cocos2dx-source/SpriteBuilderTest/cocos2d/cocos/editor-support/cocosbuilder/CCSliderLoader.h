//
//  CCSliderLoader.h
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/23/14.
//
//

#ifndef __cocos2d_libs__CCSliderLoader__
#define __cocos2d_libs__CCSliderLoader__

#include "CCControlLoader.h"
#include "extension.h"
#include "extensions/cocos-ext.h"


namespace cocosbuilder {
    
    /* Forward declaration. */
    class CCBReader;
    
    class SliderLoader : public ControlLoader{
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~SliderLoader() {};
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SliderLoader, loader);
        
    protected:
        virtual cocos2d::extension::ControlSlider * createNode(cocos2d::Node * pParent, CCBReader * ccbReader) {
            auto pRet = cocos2d::extension::ControlSlider::create(cocos2d::Sprite::create(), cocos2d::Sprite::create(), cocos2d::Sprite::create());
            
            return pRet;
        }
        
        virtual void onHandlePropTypeBlock(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, BlockData * pBlockData, CCBReader * ccbReader);
        
        virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader);
        virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader);
        virtual void onDone(cocos2d::Node * pNode, cocos2d::Node * pParent, CCBReader * ccbReader);
        /*
        virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader);*/
    protected:
        cocos2d::SpriteFrame* _progressSprite;
        cocos2d::SpriteFrame* _backgroundSprite;
        cocos2d::SpriteFrame* _handleSprite;
        cocos2d::SpriteFrame* _selectedHandleSprite;
        cocos2d::Size         _contentSize;
    };
    
}
#endif /* defined(__cocos2d_libs__CCSliderLoader__) */
