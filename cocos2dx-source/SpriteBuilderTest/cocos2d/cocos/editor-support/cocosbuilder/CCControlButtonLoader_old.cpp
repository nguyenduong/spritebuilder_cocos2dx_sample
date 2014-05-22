#include "CCControlButtonLoader.h"
#include "CCLabel.h"

using namespace cocos2d;
using namespace cocos2d::extension;

namespace cocosbuilder {;
#define PROPERTY_TITLE_NORMAL "title|1"
#define PROPERTY_TITLE_HIGHLIGHTED "title|2"
#define PROPERTY_TITLE_DISABLED "title|3"
#define PROPERTY_TITLETTF_NORMAL "titleTTF|1"
#define PROPERTY_TITLETTF_HIGHLIGHTED "titleTTF|2"
#define PROPERTY_TITLETTF_DISABLED "titleTTF|3"
#define PROPERTY_TITLETTFSIZE_NORMAL "titleTTFSize|1"
#define PROPERTY_TITLETTFSIZE_HIGHLIGHTED "titleTTFSize|2"
#define PROPERTY_TITLETTFSIZE_DISABLED "titleTTFSize|3"
#define PROPERTY_LABELANCHORPOINT "labelAnchorPoint"
#define PROPERTY_PREFEREDSIZE "preferredSize"
#define PROPERTY_MAXSIZE "maxSize"
    
    
#define PROPERTY_TITLE "title"
#define PROPERTY_ZOOMWHENHIGHLIGHTED "zoomWhenHighlighted"
#define PROPERTY_TOGGLESELECTEDSTATE "toggleSelectedState"
#define PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL "backgroundSpriteFrame|Normal"
#define PROPERTY_BACKGROUNDOPACITY_NORMAL "backgroundOpacity|Normal"
#define PROPERTY_BACKGROUNDCOLOR_NORMAL "backgroundColor|Normal"
#define PROPERTY_LABELOPACITY_NORMAL "labelOpacity|Normal"
#define PROPERTY_LABELCOLOR_NORMAL "labelColor|Normal"
#define PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED "backgroundSpriteFrame|Highlighted"
#define PROPERTY_BACKGROUNDOPACITY_HIGHLIGHTED "backgroundOpacity|Highlighted"
#define PROPERTY_BACKGROUNDCOLOR_HIGHLIGHTED "backgroundColor|Highlighted"
#define PROPERTY_LABELOPACITY_HIGHLIGHTED "labelOpacity|Highlighted"
#define PROPERTY_LABELCOLOR_HIGHLIGHTED "labelColor|Highlighted"
#define PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED "backgroundSpriteFrame|Disabled"
#define PROPERTY_BACKGROUNDOPACITY_DISABLED "backgroundOpacity|Disabled"
#define PROPERTY_BACKGROUNDCOLOR_DISABLED "backgroundColor|Disabled"
#define PROPERTY_LABELOPACITY_DISABLED "labelOpacity|Disabled"
#define PROPERTY_LABELCOLOR_DISABLED "labelColor|Disabled"
#define PROPERTY_BACKGROUNDSPRITEFRAME_SELECTED "backgroundSpriteFrame|Selected"
#define PROPERTY_BACKGROUNDOPACITY_SELECTED "backgroundOpacity|Selected"
#define PROPERTY_BACKGROUNDCOLOR_SELECTED "backgroundColor|Selected"
#define PROPERTY_LABELOPACITY_SELECTED "labelOpacity|Selected"
#define PROPERTY_LABELCOLOR_SELECTED "labelColor|Selected"
#define PROPERTY_FONTNAME "fontName"
#define PROPERTY_FONTSIZE "fontSize"
#define PROPERTY_HORIZONTAL_PADDING "horizontalPadding"
#define PROPERTY_VERTICAL_PADDING "verticalPadding"
#define PROPERTY_FONTCOLOR "fontColor"
#define PROPERTY_OUTLINECOLOR "outlineColor"
#define PROPERTY_OUTLINEWIDTH "outlineWidth"
#define PROPERTY_SHADOWCOLOR "shadowColor"
#define PROPERTY_SHADOWBLURRADIUS "shadowBlurRadius"
#define PROPERTY_SHADOWOFFSET "shadowOffset"
    
    CCBControlButton::CCBControlButton() :
    _fontColor(Color4B::WHITE)
    {
        this->setTitleOpacityDispatchTable(__Dictionary::create());
        this->setTitleOpacityForState(255, Control::State::NORMAL);
    }
    
    CCBControlButton::~CCBControlButton() {
        CC_SAFE_RELEASE(_titleOpacityDispatchTable);
    }
    
    CCBControlButton* CCBControlButton::create() {
        CCBControlButton *pControlButton = new CCBControlButton();
        if (pControlButton && pControlButton->init())
        {
            pControlButton->autorelease();
            return pControlButton;
        }
        CC_SAFE_DELETE(pControlButton);
        return NULL;
    }
    
    GLubyte CCBControlButton::getTitleOpacityForState(State state) const
    {
        GLubyte returnOpacity = 255;
        /*
        do
        {
            CC_BREAK_IF(NULL == _titleOpacityDispatchTable);
            CCBValue* opacityValue=(CCBValue*)_titleOpacityDispatchTable->objectForKey((int)state);
            if (opacityValue)
            {
                returnOpacity = opacityValue->getByteValue();
                break;
            }
            
            opacityValue = (CCBValue*)_titleOpacityDispatchTable->objectForKey((int)Control::State::NORMAL);
            if (opacityValue)
            {
                returnOpacity = opacityValue->getByteValue();
            }
        } while (0);
        */
        return returnOpacity;
    }
    
    void CCBControlButton::setTitleOpacityForState(GLubyte opacity, State state)
    {
        /*
        //Color3B* colorValue=&color;
        _titleOpacityDispatchTable->removeObjectForKey((int)state);
        CCBValue* opacityValue = CCBValue::create(opacity);
        _titleOpacityDispatchTable->setObject(opacityValue, (int)state);
        
        // If the current state if equal to the given state we update the layout
        if (getState() == state)
        {
            needsLayout();
        }*/
    }
    
    void CCBControlButton::setFontColor(const Color4B & color) {
        this->_fontColor = color;
        this->needsLayout();
    }
    
    void CCBControlButton::setShadowOffset(const Size & size) {
        this->_shadowOffset = size;
        this->enableShadow();
    }
    
    void CCBControlButton::setShadowColor(const Color4B & color) {
        this->_shadowColor = color;
        this->enableShadow();
    }
    
    void CCBControlButton::setShadowBlurRadius(float blurRadius) {
        this->_shadowBlurRadius = blurRadius;
        this->enableShadow();
    }
    
    void CCBControlButton::enableShadow() {
        /*
        ((Label*)this->getTitleLabelForState(Control::State::NORMAL))->enableShadow(this->_shadowOffset, this->_shadowColor.a/255.f, this->_shadowBlurRadius);
        ((LabelTTF *)this->getTitleLabelForState(Control::State::HIGH_LIGHTED))->enableShadow(this->_shadowOffset, this->_shadowColor.a/255.f, this->_shadowBlurRadius);
        ((LabelTTF *)this->getTitleLabelForState(Control::State::DISABLED))->enableShadow(this->_shadowOffset, this->_shadowColor.a/225.f, this->_shadowBlurRadius);
        ((LabelTTF *)this->getTitleLabelForState(Control::State::SELECTED))->enableShadow(this->_shadowOffset, this->_shadowColor.a/225.f, this->_shadowBlurRadius);
        this->needsLayout();
        */
    }
    
    void CCBControlButton::setPreferredSize(Size size) {
        this->_preferredSize = size;
    }
    
    void CCBControlButton::setMaxSize(Size size) {
        this->_maxSize = size;
        this->needsLayout();
    }
    
    void CCBControlButton::needsLayout() {
        Label *label = static_cast<Label*>(this->getTitleLabel());
        
        if (label) {
            label->setScale(1);
            label->setOpacity(getTitleOpacityForState(_state));
        }
        
        ControlButton::needsLayout();
        
        Size maxSize(getMaxSize());
        float scale = 1.0f;
        
        if (label) {
            Size labelSize(label->getBoundingBox().size);
            float scaleX = 1.f, scaleY = 1.f;
            if (maxSize.width > 0 && maxSize.width - (this->getHorizontalOrigin() * 2) < labelSize.width) {
                scaleX = (maxSize.width - (this->getHorizontalOrigin() * 2)) / labelSize.width;
            }
            if (maxSize.height > 0 && maxSize.height - (this->getVerticalMargin() * 2) < labelSize.height) {
                scaleY = (maxSize.height - (this->getVerticalMargin() * 2)) / labelSize.height;
            }
            
            if (scaleX > 0.f && scaleY > 0.f) {
                scale = std::min(scaleX, scaleY);
            }
            else {
                scale = std::max(scaleX, scaleY);
            }
            
            label->setScale(scale);
            
            cocos2d::Point position = label->getPosition();
            position.x += this->_shadowOffset.width/2.f;
            position.y += this->_shadowOffset.height/2.f;
            
            label->setPosition(position);
            //DuongNT
            //label->setFontFillColor(getTitleColorForState(_state));
            label->setColor(Color3B(getFontColor()));
        }
        
        if (this->getBackgroundSprite() != NULL)
        {
            cocos2d::Size size = this->getBackgroundSprite()->getContentSize();
            size.width += abs(this->_shadowOffset.width)+this->_shadowBlurRadius*2.f;
            size.height += abs(this->_shadowOffset.height)+this->_shadowBlurRadius*2.f;
            
            if (size.width < this->_preferredSize.width) {
                size.width = this->_preferredSize.width;
            }
            if (size.height < this->_preferredSize.height) {
                size.height = this->_preferredSize.height;
            }
            
            if (maxSize.width > 0.f && size.width > maxSize.width) {
                size.width = maxSize.width;
            }
            
            if (maxSize.height > 0.f && size.height > maxSize.height) {
                size.height = maxSize.height;
            }
            
            this->getBackgroundSprite()->setContentSize(size);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeCheck(Node * pNode, Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_ZOOMWHENHIGHLIGHTED) == 0) {
            ((ControlButton *)pNode)->setZoomOnTouchDown(pCheck);
        } else if (strcmp(pPropertyName, PROPERTY_TOGGLESELECTEDSTATE) == 0) {
            // ((ControlButton *)pNode)->
        } else {
           // ControlLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeByte(Node * pNode, Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_BACKGROUNDOPACITY_NORMAL) == 0) {
            ((ControlButton *)pNode)->getBackgroundSpriteForState(Control::State::NORMAL)->setOpacity(pByte);
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDOPACITY_HIGHLIGHTED) == 0) {
            ((ControlButton *)pNode)->getBackgroundSpriteForState(Control::State::HIGH_LIGHTED)->setOpacity(pByte);
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDOPACITY_DISABLED) == 0) {
            ((ControlButton *)pNode)->getBackgroundSpriteForState(Control::State::DISABLED)->setOpacity(pByte);
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDOPACITY_SELECTED) == 0) {
            ((ControlButton *)pNode)->getBackgroundSpriteForState(Control::State::SELECTED)->setOpacity(pByte);
        } else if(strcmp(pPropertyName, PROPERTY_LABELOPACITY_NORMAL) == 0) {
            ((CCBControlButton *)pNode)->setTitleOpacityForState(pByte, Control::State::NORMAL);
        } else if(strcmp(pPropertyName, PROPERTY_LABELOPACITY_HIGHLIGHTED) == 0) {
            ((CCBControlButton *)pNode)->setTitleOpacityForState(pByte, Control::State::HIGH_LIGHTED);
        } else if(strcmp(pPropertyName, PROPERTY_LABELOPACITY_DISABLED) == 0) {
            ((CCBControlButton *)pNode)->setTitleOpacityForState(pByte, Control::State::DISABLED);
        } else if(strcmp(pPropertyName, PROPERTY_LABELOPACITY_SELECTED) == 0) {
            ((CCBControlButton *)pNode)->setTitleOpacityForState(pByte, Control::State::SELECTED);
        } else {
            //ControlLoader::onHandlePropTypeByte(pNode, pParent, pPropertyName, pByte, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeString(Node * pNode, Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_TITLE) == 0) {
            ((ControlButton *)pNode)->setTitleForState(__String::create(pString)->getCString(), Control::State::NORMAL);
            ((ControlButton *)pNode)->setTitleForState(__String::create(pString)->getCString(), Control::State::HIGH_LIGHTED);
            ((ControlButton *)pNode)->setTitleForState(__String::create(pString)->getCString(), Control::State::DISABLED);
            ((ControlButton *)pNode)->setTitleForState(__String::create(pString)->getCString(), Control::State::SELECTED);
        } else {
            //ControlLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeFontTTF(Node * pNode, Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_FONTNAME) == 0) {
            ((ControlButton *)pNode)->setTitleTTFForState(pFontTTF, Control::State::NORMAL);
            ((ControlButton *)pNode)->setTitleTTFForState(pFontTTF, Control::State::HIGH_LIGHTED);
            ((ControlButton *)pNode)->setTitleTTFForState(pFontTTF, Control::State::DISABLED);
            ((ControlButton *)pNode)->setTitleTTFForState(pFontTTF, Control::State::SELECTED);
            ((CCBControlButton *)pNode)->enableShadow();
        } else {
            //ControlLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeFloatScale(Node * pNode, Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_FONTSIZE) == 0) {
            ((ControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, Control::State::NORMAL);
            ((ControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, Control::State::HIGH_LIGHTED);
            ((ControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, Control::State::DISABLED);
            ((ControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, Control::State::SELECTED);
            ((ControlButton *)pNode)->needsLayout();
        } else if(strcmp(pPropertyName, PROPERTY_HORIZONTAL_PADDING) == 0) {
            ControlButton * pControlButton = static_cast<ControlButton*>(pNode);
            pControlButton->setMargins(pFloatScale, pControlButton->getVerticalMargin());
        } else if(strcmp(pPropertyName, PROPERTY_VERTICAL_PADDING) == 0) {
            ControlButton * pControlButton = static_cast<ControlButton*>(pNode);
            pControlButton->setMargins(pControlButton->getHorizontalOrigin(), pFloatScale);
        } else if(strcmp(pPropertyName, PROPERTY_OUTLINEWIDTH) == 0) {
            // TODO:
        } else if(strcmp(pPropertyName, PROPERTY_SHADOWBLURRADIUS) == 0) {
            ((CCBControlButton *)pNode)->setShadowBlurRadius(pFloatScale);
        } else {
            //ControlLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypePosition(Node * pNode, Node * pParent, const char * pPropertyName, Point pPosition, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_SHADOWOFFSET) == 0) {
            ((CCBControlButton *)pNode)->setShadowOffset(Size(pPosition));
        } else {
            //ControlLoader::onHandlePropTypePosition(pNode, pParent, pPropertyName, pPosition, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypePoint(Node * pNode, Node * pParent, const char * pPropertyName, Point pPoint, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_LABELANCHORPOINT) == 0) {
            ((ControlButton *)pNode)->setLabelAnchorPoint(pPoint);
        } else {
            //ControlLoader::onHandlePropTypePoint(pNode, pParent, pPropertyName, pPoint, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size pSize, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_PREFEREDSIZE) == 0) {
            ((CCBControlButton *)pNode)->setPreferredSize(pSize);
        } else if(strcmp(pPropertyName, PROPERTY_MAXSIZE) == 0) {
            ((CCBControlButton *)pNode)->setMaxSize(pSize);
        } else {
            //ControlLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
        }
    }
    
  
    void ControlButtonLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
        if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL) == 0) {
            if(pSpriteFrame != NULL) {
                ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::NORMAL);
            }
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED) == 0) {
            if(pSpriteFrame != NULL) {
                ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::HIGH_LIGHTED);
            }
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED) == 0) {
            if(pSpriteFrame != NULL) {
                ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::DISABLED);
            }
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_SELECTED) == 0) {
            if(pSpriteFrame != NULL) {
                ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::SELECTED);
            }
        } else {
            //ControlLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
        }
    }
    
    void ControlButtonLoader::onHandlePropTypeColor3(Node * pNode, Node * pParent, const char * pPropertyName, Color3B pColor3B, CCBReader * ccbReader) {
        /*
        if(strcmp(pPropertyName, PROPERTY_BACKGROUNDCOLOR_NORMAL) == 0) {
            ((ControlButton *)pNode)->getBackgroundSpriteForState(Control::State::NORMAL)->setColor(pColor3B);
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDCOLOR_HIGHLIGHTED) == 0) {
            ((ControlButton *)pNode)->getBackgroundSpriteForState(Control::State::HIGH_LIGHTED)->setColor(pColor3B);
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDCOLOR_DISABLED) == 0) {
            ((ControlButton *)pNode)->getBackgroundSpriteForState(Control::State::DISABLED)->setColor(pColor3B);
        } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDCOLOR_SELECTED) == 0) {
            ((ControlButton *)pNode)->getBackgroundSpriteForState(Control::State::SELECTED)->setColor(pColor3B);
        } else if(strcmp(pPropertyName, PROPERTY_LABELCOLOR_NORMAL) == 0) {
            ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::NORMAL);
        } else if(strcmp(pPropertyName, PROPERTY_LABELCOLOR_HIGHLIGHTED) == 0) {
            ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::HIGH_LIGHTED);
        } else if(strcmp(pPropertyName, PROPERTY_LABELCOLOR_DISABLED) == 0) {
            ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::DISABLED);
        } else if(strcmp(pPropertyName, PROPERTY_LABELCOLOR_SELECTED) == 0) {
            ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::SELECTED);
        } else {
            ControlLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor3B, ccbReader);
        }*/
    }
    
    void ControlButtonLoader::onHandlePropTypeColor4(Node * pNode, Node * pParent, const char * pPropertyName, Color4B pColor4B, CCBReader * ccbReader) {
        /*
        if(strcmp(pPropertyName, PROPERTY_FONTCOLOR) == 0) {
            ((CCBControlButton *)pNode)->setFontColor(pColor4B);
        } else if(strcmp(pPropertyName, PROPERTY_OUTLINECOLOR) == 0) {
            // TODO:
        } else if(strcmp(pPropertyName, PROPERTY_SHADOWCOLOR) == 0) {
            ((CCBControlButton *)pNode)->setShadowColor(pColor4B);
        } else {
            ControlLoader::onHandlePropTypeColor4(pNode, pParent, pPropertyName, pColor4B, ccbReader);
        }*/
    }
};