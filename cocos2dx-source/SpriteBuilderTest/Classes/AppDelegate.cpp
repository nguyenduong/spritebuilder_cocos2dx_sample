#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "spritebuilder/SpriteBuilder.h"

USING_NS_CC;

#define PHYSIC_FACTOR 32

const char* CCSetupPixelFormat = "CCSetupPixelFormat";
const char* CCSetupScreenMode = "CCSetupScreenMode";
const char* CCSetupScreenOrientation = "CCSetupScreenOrientation";
const char* CCSetupAnimationInterval = "CCSetupAnimationInterval";
const char* CCSetupFixedUpdateInterval = "CCSetupFixedUpdateInterval";
const char* CCSetupShowDebugStats = "CCSetupShowDebugStats";
const char* CCSetupTabletScale2X = "CCSetupTabletScale2X";

const char* CCSetupDepthFormat = "CCSetupDepthFormat";
const char* CCSetupPreserveBackbuffer = "CCSetupPreserveBackbuffer";
const char* CCSetupMultiSampling = "CCSetupMultiSampling";
const char* CCSetupNumberOfSamples = "CCSetupNumberOfSamples";

const char* CCScreenOrientationLandscape = "CCScreenOrientationLandscape";
const char* CCScreenOrientationPortrait = "CCScreenOrientationPortrait";

const char* CCScreenModeFlexible = "CCScreenModeFlexible";
const char* CCScreenModeFixed = "CCScreenModeFixed";

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }


    Size size = director->getWinSize();
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
//    glview->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);
    //glview->setDesignResolutionSize(480, 320, ResolutionPolicy::SHOW_ALL);
    //glview->setDesignResolutionSize(568, 320, ResolutionPolicy::SHOW_ALL);
    
    float scaleFactor = size.height / 320.0f;
    glview->setDesignResolutionSize(size.width / scaleFactor, 320, ResolutionPolicy::SHOW_ALL);

    //director->setContentScaleFactor(scaleFactor);
    director->setContentScaleFactor(scaleFactor / (size.height / 640)); //because the current resource is phonehd's


    
    spritebuilder::CCBReader::setupSpriteBuilder("resources-phonehd", PHYSIC_FACTOR);
    
    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
