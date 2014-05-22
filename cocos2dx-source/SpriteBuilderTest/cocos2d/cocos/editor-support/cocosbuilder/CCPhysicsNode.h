//
//  CCPhysicsNode.h
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/19/14.
//
//

#ifndef __cocos2d_libs__CCPhysicsNode__
#define __cocos2d_libs__CCPhysicsNode__

#include "cocos2d.h"


NS_CC_BEGIN

class PhysicsNode : public Scene {
public:
    static PhysicsNode* create();
    
    virtual ~PhysicsNode() {}
    PhysicsNode();

    virtual kmMat4 getNodeToWorldTransform() const;
    void setGravity(cocos2d::Point& gravity);
    cocos2d::Point getGravity();
    
protected:
    bool initWithPhysics();

};

NS_CC_END

#endif /* defined(__cocos2d_libs__CCPhysicsNode__) */
