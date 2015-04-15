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

    return true;
}

void CBaseScene::ShowLayer(CCBLayer *_layer)
{
    
    if (!_layer->GetIsTheDialog() && mLayerStack.size() > 0)
    {
        mLayerStack.top()->Hide();
    }
    

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

