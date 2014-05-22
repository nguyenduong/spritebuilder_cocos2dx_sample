#ifndef _CCB_CCCONTROLBUTTONLOADER_H_
#define _CCB_CCCONTROLBUTTONLOADER_H_

#include "CCControlLoader.h"
#include "extensions//GUI/CCControlExtension/CCControlButton.h"

namespace cocosbuilder {

    class CCBControlButton : public cocos2d::extension::ControlButton {
    public:
        static CCBControlButton* create();
        
        CCBControlButton();
        virtual ~CCBControlButton();
        
        /**
         * Returns the title opacity used for a state.
         *
         * @param state The state that uses the specified opacity. The values are described
         * in "CCControlState".
         *
         * @return The opacity of the title for the specified state.
         */
        
        virtual GLubyte getTitleOpacityForState(State state) const;
        
        /**
         * Sets the opacity of the title to use for the specified state.
         *
         * @param opacity The opacity of the title to use for the specified state.
         * @param state The state that uses the specified opacity. The values are described
         * in "CCControlState".
         */
        virtual void setTitleOpacityForState(GLubyte color, State state);
        
        virtual void setFontColor(const cocos2d::Color4B & color);
        virtual void setShadowOffset(const cocos2d::Size & size);
        virtual void setShadowColor(const cocos2d::Color4B & color);
        virtual void setShadowBlurRadius(float blurRadius);
        virtual void enableShadow();
        
        virtual void setPreferredSize(cocos2d::Size size);
        virtual void setMaxSize(cocos2d::Size size);
        virtual void needsLayout();
        
    protected:
        CC_SYNTHESIZE_READONLY(cocos2d::Size, _maxSize, MaxSize);
        CC_SYNTHESIZE_READONLY(cocos2d::Color4B, _fontColor, FontColor);
        CC_SYNTHESIZE_READONLY(cocos2d::Size, _shadowOffset, shadowOffset);
        CC_SYNTHESIZE_READONLY(cocos2d::Color4B, _shadowColor, shadowColor);
        CC_SYNTHESIZE_READONLY(float, _shadowBlurRadius, shadowBlurRadius);
        
        // <ControlState, CCBValue*>
        CC_SYNTHESIZE_RETAIN(cocos2d::__Dictionary*, _titleOpacityDispatchTable, TitleOpacityDispatchTable);
    };
    
    /* Forward declaration. */
    class CCBReader;
    
    class ControlButtonLoader : public ControlLoader {
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~ControlButtonLoader() {};
        /**
         * @js NA
         * @lua NA
         */
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControlButtonLoader, loader);
        
    protected:
        /**
         * @js NA
         * @lua NA
         */
        virtual cocos2d::extension::ControlButton * createNode(cocos2d::Node * pParent, CCBReader * ccbReader) {
            cocos2d::extension::ControlButton* pNode = CCBControlButton::create();
            pNode->setZoomOnTouchDown(false);
            
            return pNode;
        };
        
        virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader);
		virtual void onHandlePropTypeByte(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader);
        virtual void onHandlePropTypeString(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader);
        virtual void onHandlePropTypeFontTTF(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader);
        virtual void onHandlePropTypeFloatScale(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader);
		virtual void onHandlePropTypePosition(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Point pPoint, CCBReader * ccbReader);
        virtual void onHandlePropTypePoint(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Point pPoint, CCBReader * ccbReader);
        virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader);
        virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader);
        virtual void onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color3B pColor3B, CCBReader * ccbReader);
		virtual void onHandlePropTypeColor4(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color4B pColor4B, CCBReader * ccbReader);
    };
    

}

#endif
