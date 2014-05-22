#ifndef _CCB_CCLAYERGRADIENTLOADER_H_
#define _CCB_CCLAYERGRADIENTLOADER_H_

#include "CCNodeLoader.h"


namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

class NodeGradientLoader : public NodeLoader {
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~NodeGradientLoader() {};
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(NodeGradientLoader, loader);

protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(cocos2d::Nodec);

    virtual void onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color3B pColor3B, CCBReader * ccbReader);
    virtual void onHandlePropTypeByte(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader);
    virtual void onHandlePropTypePoint(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Point pPoint, CCBReader * ccbReader);
    virtual void onHandlePropTypeBlendFunc(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::BlendFunc pBlendFunc, CCBReader * ccbReader);
};

}

#endif
