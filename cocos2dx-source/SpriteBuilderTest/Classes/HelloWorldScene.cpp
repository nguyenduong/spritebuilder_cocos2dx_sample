#include "HelloWorldScene.h"
#include "extensions/cocos-ext.h"
#include "spritebuilder/SpriteBuilder.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace spritebuilder;


class MainSceneContent : public NodeLoader
, public spritebuilder::CCBSelectorResolver
, public spritebuilder::CCBMemberVariableAssigner
, public spritebuilder::NodeLoaderListener {
public:
    virtual ~MainSceneContent() {};
    SB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LayerLoader, loader);
};

class Level : public cocos2d::Layer
, public spritebuilder::CCBSelectorResolver
, public spritebuilder::CCBMemberVariableAssigner
, public spritebuilder::NodeLoaderListener {
public:
    SB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Level, create);
    
    Level():
    mMySlider(NULL),
    mLauncher(NULL),
    mPhysicNode(NULL),
    mTTFLabel(NULL),
    mBMFLabel(NULL),
    mClickCount(0)
    {

    }
    virtual ~Level() {}
    
    void setCCBReader(CCBReader* reader) {
        mReader = reader;
    }
    
    virtual void onNodeLoaded(cocos2d::Node * pNode, NodeLoader * pNodeLoader) {
        this->mMySlider->setMaximumAllowedValue(100);
        this->mMySlider->setMinimumValue(0);
        //mBMFLabel->setString("This is BMF label");
        //Show Physic debug
        //this->mPhysicNode->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    }
    
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref* pTarget, const char* pMemberVariableName, cocos2d::Node* pNode) {
        SB_MEMBERVARIABLEASSIGNER_GLUE(this, "mMySlider", ControlSlider*, this->mMySlider);
        SB_MEMBERVARIABLEASSIGNER_GLUE(this, "mLauncher", Sprite*, this->mLauncher);
        SB_MEMBERVARIABLEASSIGNER_GLUE(this, "mPhysicNode", PhysicsNode*, this->mPhysicNode);
        SB_MEMBERVARIABLEASSIGNER_GLUE(this, "mBMFLabel", Label*, this->mBMFLabel);
        SB_MEMBERVARIABLEASSIGNER_GLUE(this, "mTTFLabel", Label*, this->mTTFLabel);
        
        return false;
    }
    
    virtual bool onAssignCCBCustomProperty(cocos2d::Ref* target, const char* memberVariableName, const cocos2d::Value& value) {
        return false;
    };
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName) {
        return NULL;
    }
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(cocos2d::Ref * pTarget, const char* pSelectorName) {
        return NULL;
    };
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char* pSelectorName) {
        CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onButtonClicked", Level::onControlButtonClicked);
        
        CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onEditBox", Level::onEditDone);
        CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onSliderChanged", Level::onSliderChanged);
        CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onFireClicked", Level::onFireClicked);
        
        return NULL;
    }
    
    void onControlButtonClicked(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent) {
        
        char buffer[255];
        sprintf(buffer, "Click #%d", mClickCount);
        mClickCount ++;
        mBMFLabel->setString(buffer);
    }
    void onEditDone(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent) {
        
    }
    void onSliderChanged(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent) {
        if (mTTFLabel) {
            printf("Slider value: %f\n", ((ControlSlider*)sender)->getValue());
            char buffer[255];
            sprintf(buffer, "Slider: %f", ((ControlSlider*)sender)->getValue());
            mTTFLabel->setString(buffer);
        }
    }
    
    void onFireClicked(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent) {
        float angle = CC_DEGREES_TO_RADIANS(mLauncher->getRotation());
        Point directionVect = Point(sinf(angle), cosf(angle));
        Point ballOffset = directionVect * mLauncher->getContentSize().height;
        
        mReader = new CCBReader(NodeLoaderLibrary::getInstance());

        Node* ball = mReader->readNodeGraphFromFile("Ball.ccbi");
        ball->setPosition(mLauncher->getPosition() + ballOffset);
        mPhysicNode->addChild(ball);

        ball->setVisible(true);

        Point force = directionVect * 50;
        ball->getPhysicsBody()->applyImpulse(force);
        mReader->release();
        
    }
    
   
private:
    ControlSlider* mMySlider;
    Sprite*        mLauncher;
    PhysicsNode*   mPhysicNode;
    CCBReader*     mReader;
    Label*         mBMFLabel;
    Label*         mTTFLabel;
    int            mClickCount;
};

class LevelLoader : public spritebuilder::LayerLoader {
public:
    SB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelLoader, loader);
    
protected:
    SB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Level);
    
};


Scene* HelloWorld::createScene()
{

    NodeLoaderLibrary * ccNodeLoaderLibrary = NodeLoaderLibrary::getInstance();
    
    ccNodeLoaderLibrary->registerNodeLoader("MainScene", MainSceneContent::loader());
    
    ccNodeLoaderLibrary->registerNodeLoader("Level", LevelLoader::loader());
    
    spritebuilder::CCBReader * ccbReader = new spritebuilder::CCBReader(ccNodeLoaderLibrary);
    
    //std::string str = CCBLocalizationManager::sharedManager()->localizedStringForKey("this_is_a_game");
    
    return ccbReader->createSceneWithNodeGraphFromFile("MainScene.ccbi");
}
