#include "CCTextFieldLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#define PROPERTY_PREFERREDSIZE "preferredSize"
#define PROPERTY_SPRITEFRAME "backgroundSpriteFrame"
#define PROPERTY_PADDING "padding"

namespace cocosbuilder {

void EditBoxLoader::editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox)
{
    log("editBox %p DidBegin !", editBox);
}

void EditBoxLoader::editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox)
{
    log("editBox %p DidEnd !", editBox);
}

void EditBoxLoader::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text)
{
    log("editBox %p TextChanged, text: %s ", editBox, text.c_str());
    
    // editBox->setTitleForState(String::create(text), Control::State::NORMAL);
}

void EditBoxLoader::editBoxReturn(EditBox* editBox)
{
    log("editBox %p was returned !",editBox);
    /*
    if (_editName == editBox)
    {
        _TTFShowEditReturn->setString("Name EditBox return !");
    }
    else if (_editPassword == editBox)
    {
        _TTFShowEditReturn->setString("Password EditBox return !"); 
    }
    else if (_editEmail == editBox)
    {
        _TTFShowEditReturn->setString("Email EditBox return !");
    }
    */
}

void EditBoxLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char* pPropertyName, Size pSize, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_PREFERREDSIZE) == 0) {
        ((EditBox*)pNode)->setPreferredSize(pSize);
        ((EditBox*)pNode)->setFontSize(pSize.height*2/3);
    } else {
        ControlLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
    }
}

void EditBoxLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_SPRITEFRAME) == 0) {
        ((EditBox*)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::NORMAL);
    } else {
        ControlLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

void EditBoxLoader::onHandlePropTypeFloatScale(Node * pNode, Node * pParent, const char* pPropertyName, float pFloatScale, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_PADDING) == 0) {
    } else {
        ControlLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, ccbReader);
    }
}


};