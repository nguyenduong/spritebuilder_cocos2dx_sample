//
//  CCLayout.cpp
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/23/14.
//
//

#include "CCLayout.h"

NS_CC_BEGIN

Layout::Layout():
m_bNeedLayout(true)
{
    
}
void Layout::needLayout() {
    m_bNeedLayout = true;
}
void Layout::layout() {
    m_bNeedLayout = false;
}

void Layout::addChild(Node * child, int localZOrder) {
    Node::addChild(child, localZOrder);
    layout();
}

void Layout::visit(Renderer *renderer, const kmMat4& parentTransform, bool parentTransformUpdated) {
    if (m_bNeedLayout)
        layout();
    
    Node::visit(renderer, parentTransform, parentTransformUpdated);
}

const Size& Layout::getContentSize() {
    if (m_bNeedLayout)
        layout();
    
    return Node::getContentSize();
}

NS_CC_END