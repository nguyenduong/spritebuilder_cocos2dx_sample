//
//  CCLayoutBox.cpp
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/23/14.
//
//

#include "CCLayoutBox.h"

NS_CC_BEGIN

static float roundUpToEven(float f)
{
    return ceilf(f/2.0f) * 2.0f;
}

LayoutBox* LayoutBox::create() {
    LayoutBox* ret = new LayoutBox();
    if (ret->init())
        return ret;
    else
        return NULL;
}
LayoutBox::LayoutBox() {
    m_eDirection = CCLayoutBoxDirectionHorizontal;
    m_nSpacing = 0;
}
void LayoutBox::layout() {
    Layout::layout();
    if (m_eDirection == CCLayoutBoxDirectionHorizontal)
    {
        // Get the maximum height
        float maxHeight = 0;

        for(auto it = _children.cbegin(); it != _children.cend(); ++it) {
            float height = (*it)->getContentSize().height;
            if (height > maxHeight) maxHeight = height;
        }
        
        // Position the nodes
        float width = 0;
        for(auto it = _children.cbegin(); it != _children.cend(); ++it) {
            
            Size childSize = (*it)->getContentSize();
            
            Point offset = (*it)->getAnchorPointInPoints();
            Point localPos(roundf(width), roundf((maxHeight-childSize.height)/2.0f));
            Point position = localPos + offset;
            
            (*it)->setPosition(position);
//            (*it)->setPositionType(CCPositionTypePoints);
            
            width += childSize.width;
            width += m_nSpacing;
        }
        
        // Account for last added increment
        width -= m_nSpacing;
        if (width < 0) width = 0;
        
        this->setContentSize(Size(roundUpToEven(width), roundUpToEven(maxHeight)));
    }
    else
    {
        // Get the maximum height
        float maxWidth = 0;
        
        for(auto it = _children.cbegin(); it != _children.cend(); ++it) {
            float width = (*it)->getContentSize().width;
            if (width > maxWidth) maxWidth = width;
        }
        
        // Position the nodes
        float height = 0;
        for(auto it = _children.cbegin(); it != _children.cend(); ++it) {
            
            Size childSize = (*it)->getContentSize();
            
            Point offset = (*it)->getAnchorPointInPoints();
            Point localPos(roundf((maxWidth-childSize.width)/2.0f), roundf(height));
            Point position = localPos + offset;
            
            (*it)->setPosition(position);
            //            (*it)->setPositionType(CCPositionTypePoints);
            
            height += childSize.height;
            height += m_nSpacing;
        }
        
        // Account for last added increment
        height -= m_nSpacing;
        if (height < 0) height = 0;
        
        
        this->setContentSize(Size(roundUpToEven(maxWidth), roundUpToEven(height)));
    }
}

void LayoutBox::setDirection(CCLayoutBoxDirection direction) {
    m_eDirection = direction;
    needLayout();
}
CCLayoutBoxDirection LayoutBox::getDirection() {
    return m_eDirection;
}

void LayoutBox::setSpacing(float spacing) {
    m_nSpacing = spacing;
    needLayout();
}

float LayoutBox::getSpacing() {
    return m_nSpacing;
}

void LayoutBox::removeChild(Node* child, bool cleanup) {
    Layout::removeChild(child, cleanup);
    needLayout();
}

NS_CC_END