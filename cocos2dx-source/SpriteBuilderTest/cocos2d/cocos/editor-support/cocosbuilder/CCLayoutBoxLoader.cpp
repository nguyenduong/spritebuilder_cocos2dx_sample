//
//  CCLayoutBoxLoader.cpp
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/23/14.
//
//

#include "CCLayoutBoxLoader.h"

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

#define PROPERTY_DIRECTION "direction"
#define PROPERTY_SPACING "spacing"
using namespace cocos2d;

namespace cocosbuilder {
    void LayoutBoxLoader::onHandlePropTypeIntegerLabeled(Node * pNode, Node * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_DIRECTION) == 0) {
            ((LayoutBox *)pNode)->setDirection((CCLayoutBoxDirection)pIntegerLabeled);
        } else
            NodeLoader::onHandlePropTypeIntegerLabeled(pNode, pParent, pPropertyName, pIntegerLabeled, ccbReader);
    }
    
    void LayoutBoxLoader::onHandlePropTypeFloatScale(Node * pNode, Node * pParent, const char* pPropertyName, float pFloatScale, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_SPACING) == 0) {
            ((LayoutBox *)pNode)->setSpacing(pFloatScale);
        } else
            NodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, ccbReader);
    }

}

#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic warning "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (pop)
#endif