//
//  BaseScene.cpp
//  Plane
//
//  Created by 姜彬彬 on 4/10/15.
//
//

#include "BaseScene.h"



CCScene * CBaseScene::scene()
{
    CCScene * scene = NULL;
    do
    {
        scene = CCScene::create();
        CC_BREAK_IF(! scene);
        
        CBaseScene *layer = CBaseScene::create();
        CC_BREAK_IF(! layer);
        
        scene->addChild(layer);
    } while (0);
    
    return scene;
}


bool CBaseScene::init()
{
    do
    {
        CC_BREAK_IF(!CCLayer::init());
    } while (0);
    setKeypadEnabled(true);

    return true;
}


void CBaseScene::onEnter()
{
    CCLayer::onEnter();
    scheduleUpdate();
}

void CBaseScene::onExit()
{
    CCLayer::onExit();
    unscheduleUpdate();
}

void CBaseScene::keyBackClicked()
{
    HideLayer();
}

void CBaseScene::ShowLayer(CCBLayer *_layer)
{
    
    if (mLayerStack.size() > 0)
    {
        if (mLayerStack.top()->GetIsTheDialog() || (!_layer->GetIsTheDialog() && !mLayerStack.top()->GetIsTheDialog() )) {
            mLayerStack.top()->Hide();

        }
    }
    
//    if (_layer->GetIsTheDialog() && mLayerStack.size() > 0 && mLayerStack.top()->GetIsTheDialog())//!_layer->GetIsTheDialog() &&
//    {
//        mLayerStack.top()->Hide();
//    }
    

    _layer->Show();
    mLayerStack.push(_layer);
}

void CBaseScene::HideLayer()
{
    if (mLayerStack.size() > 0)
    {
        if (mLayerStack.top()->GetIsTheLast())
        {
            SwitchToPrevScene();
            return;
        }
        else
        {
            mLayerStack.top()->Hide();
            mLayerStack.pop();
        }
    }else
    {
        SwitchToPrevScene();
        return;
    }
    
    if (mLayerStack.size() > 0 && !mLayerStack.top()->isVisible())
    {
        mLayerStack.top()->Show();
    }

}

void CBaseScene::update(float _time)
{
    if (!mBgSprite1 || !mBgSprite2)
    {
        unscheduleUpdate();
        return;
    }
    
    float Y1 = mBgSprite1->getPositionY();
    float Y2 = mBgSprite2->getPositionY();
    Y1+=0.2;
    Y2+=0.2;
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    if (Y1>=size.height*1.5)
    {
        Y1=-size.height*0.5;
    }
    if (Y2>=size.height*1.5)
    {
        Y2=-size.height*0.5;
    }
   
    mBgSprite1->setPositionY(Y1+0.1);
    mBgSprite2->setPositionY(Y2+0.1);
}

