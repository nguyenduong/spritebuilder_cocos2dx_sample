//
//  CCPhysicsNode.cpp
//  cocos2d_libs
//
//  Created by Duong Nguyen on 4/19/14.
//
//

#include "CCPhysicsNode.h"


NS_CC_BEGIN


PhysicsNode::PhysicsNode() {
}

PhysicsNode* PhysicsNode::create() {
    PhysicsNode* ret = new PhysicsNode();
    
    if (ret->initWithPhysics()) {
        return ret;
    }
    return NULL;
}
kmMat4 PhysicsNode::getNodeToWorldTransform() const
{
    return this->getNodeToParentTransform();
}
bool PhysicsNode::initWithPhysics()
{


    bool ret = false;
    ret = Scene::initWithPhysics();
    this->setContentSize(Size(0, 0));
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    //Vect gra(0, 0);
    //this->setGravity(gra);


    return ret;
}
void PhysicsNode::setGravity(cocos2d::Point& gravity) {
    getPhysicsWorld()->setGravity(Vect(gravity.x, gravity.y));
}
cocos2d::Point PhysicsNode::getGravity() {
    Vect gravity = getPhysicsWorld()->getGravity();
    return cocos2d::Point(gravity.x, gravity.y);
}


NS_CC_END
