#ifndef _SB_CCEDITBOXLOADER_H_
#define _SB_CCEDITBOXLOADER_H_

#include "CCControlButtonLoader.h"
#include "extensions//GUI/CCEditBox/CCEditBox.h"

namespace cocosbuilder {
    
/* Forward declaration. */
class CCBReader;

class EditBoxLoader : public ControlLoader, public cocos2d::extension::EditBoxDelegate {
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~EditBoxLoader() {};
    /**
     * @js NA
     * @lua NA
     */
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(EditBoxLoader, loader);

protected:
    virtual cocos2d::extension::EditBox * createNode(cocos2d::Node * pParent, cocosbuilder::CCBReader * ccbReader) {
        auto pRet = cocos2d::extension::EditBox::create(cocos2d::Size(0,0), cocos2d::extension::Scale9Sprite::create());
        //pRet->setDelegate(this);
        pRet->setFontName("Helvetica");
        pRet->setFontColor(cocos2d::Color3B::BLACK);
        
        return pRet;
    }

    virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);

    /**
     * @js NA
     * @lua NA
     */
    
    virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader);
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader);
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeFloatScale(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, float pFloatScale, CCBReader * ccbReader);

};


};

#endif
