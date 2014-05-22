#include "CCPhysicsNodeLoader.h"

using namespace cocos2d;

#define PROPERTY_GRAVITY "gravity"

namespace cocosbuilder {

    void PhysicsNodeLoader::onHandlePropTypePoint(Node * pNode, Node * pParent, const char* pPropertyName, Point pPoint, CCBReader * ccbReader) {
        if (strcmp(pPropertyName, PROPERTY_GRAVITY) == 0) {
            ((PhysicsNode*)pNode)->setGravity(pPoint);
        } else {
            NodeLoader::onHandlePropTypePoint(pNode, pParent, pPropertyName, pPoint, ccbReader);
        }
    }

}
