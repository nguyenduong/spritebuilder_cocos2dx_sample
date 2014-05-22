//
//  CCLayout.h
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/23/14.
//
//

#ifndef __cocos2d_libs__CCLayout__
#define __cocos2d_libs__CCLayout__


#include "cocos2d.h"

NS_CC_BEGIN


class CC_DLL Layout : public Node {
public:
    Layout();
    virtual void needLayout();
    virtual void layout();
    
    virtual void addChild(Node * child, int localZOrder);
    virtual void visit(Renderer *renderer, const kmMat4& parentTransform, bool parentTransformUpdated);
    virtual const Size& getContentSize();
protected:
    bool m_bNeedLayout;
};
NS_CC_END
#endif /* defined(__cocos2d_libs__CCLayout__) */
