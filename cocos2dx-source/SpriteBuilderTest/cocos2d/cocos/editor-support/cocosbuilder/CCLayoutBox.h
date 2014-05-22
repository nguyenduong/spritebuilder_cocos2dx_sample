//
//  CCLayoutBox.h
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/23/14.
//
//

#ifndef __cocos2d_libs__CCLayoutBox__
#define __cocos2d_libs__CCLayoutBox__

#include "cocos2d.h"
#include "CCLayout.h"
NS_CC_BEGIN

typedef enum {
    /// The children will be layout out in a horizontal line.
    CCLayoutBoxDirectionHorizontal,
    
    /// The children will be layout out in a vertical line.
    CCLayoutBoxDirectionVertical,
} CCLayoutBoxDirection;

class CC_DLL LayoutBox : public Layout {
public:
    static LayoutBox* create();
    LayoutBox();
    void setDirection(CCLayoutBoxDirection direction);
    CCLayoutBoxDirection getDirection();
    
    void setSpacing(float spacing);
    float getSpacing();
    virtual void removeChild(Node* child, bool cleanup = true);
    virtual void layout();
protected:
    CCLayoutBoxDirection m_eDirection;
    float           m_nSpacing;
};
NS_CC_END
#endif /* defined(__cocos2d_libs__CCLayoutBox__) */
