//
//  CCBIManager.cpp
//  BnB
//
//  Created by 杨延飞 on 14-10-28.
//
//
#include "CCBManager.h"


//IMPLEMENT_SINGLETON(CCBManager)

CCNode * CCBManager::LoadCCBByNameAndLoader(const char * _ccbName,CCNodeLoader * _loader)
{
    CCNode* node = NULL;
    CCBReader* ccbReader = NULL;
    CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    char path[256];
    
    sprintf(path, "%s%s%s","CN/", _ccbName, ".ccbi");
    ccNodeLoaderLibrary->registerCCNodeLoader(_ccbName, _loader);
    
    ccbReader = new CCBReader(ccNodeLoaderLibrary);
//    ccbReader->setCCBRootPath(LAYER_RES_PATH);
    node = ccbReader->readNodeGraphFromFile(path);
    
    if(ccbReader)
    {
        ccbReader->release();
    }
    
    return node;
}

CCNode * CCBManager::LoadCCBByNameAndLoader(CCArray * _ccbNameArr,CCArray * _loaderArr)
{
    CCNode* node = NULL;
    CCBReader* ccbReader = NULL;
    CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    char path[256];
    
    for (int i = 0; i < _ccbNameArr->count(); i++)
    {
        ccNodeLoaderLibrary->registerCCNodeLoader(((CCString*)_ccbNameArr->objectAtIndex(i))->getCString(),(CCNodeLoader*)_loaderArr->objectAtIndex(i));
    }
    
    sprintf(path, "%s%s%s","CN/", ((CCString*)_ccbNameArr->objectAtIndex(0))->getCString(), ".ccbi");
    
    ccbReader = new CCBReader(ccNodeLoaderLibrary);
//    ccbReader->setCCBRootPath(LAYER_RES_PATH);
    node = ccbReader->readNodeGraphFromFile(path);
    
    if(ccbReader)
    {
        ccbReader->release();
    }
    
    return node;
}

