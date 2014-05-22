//
//  CCLayoutBoxLoader.h
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/23/14.
//
//

#ifndef __cocos2d_libs__CCLayoutBoxLoader__
#define __cocos2d_libs__CCLayoutBoxLoader__

#include <iostream>
#include "CCNodeLoader.h"
#include "CCLayoutBox.h"

namespace cocosbuilder {
    
    /* Forward declaration. */
    class CCBReader;
    
    class LayoutBoxLoader : public NodeLoader {
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~LayoutBoxLoader() {};
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LayoutBoxLoader, loader);
        
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(cocos2d::LayoutBox);
        virtual void onHandlePropTypeIntegerLabeled(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * ccbReader);
        virtual void onHandlePropTypeFloatScale(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, float pFloatScale, CCBReader * ccbReader);
        /*
        virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader);*/
    };
    
}
#endif /* defined(__cocos2d_libs__CCLayoutBoxLoader__) */
