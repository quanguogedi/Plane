//
//  CocosSaveManager.h
//  FightFootball-independent
//
//  Created by yons on 9/17/14.
//
//  wxf

#ifndef __FightFootball_independent__CocosSaveManager__
#define __FightFootball_independent__CocosSaveManager__


#include "cocos2d.h"
#include "stdio.h"
#include "Singleton.h"
using namespace cocos2d;
using namespace std;

string CocosSaveData(unsigned char const* , unsigned int len);
string CocosParseData(std::string const& s);




class CocosSaveManager
{
private:
    string mSaveString;
    string value2string(int value);
    string value2string(float value);
    string value2string(double value);
    string value2string(bool value);
    string value2string(const char* value);
    
    string EncryptString(string & value);
public:
    
    // get value methods
    
    /**
     @brief Get bool value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is false.
     */
    bool    getBoolForKey(const char* pKey);
    bool    getBoolForKey(const char* pKey, bool defaultValue);
    /**
     @brief Get integer value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is 0.
     */
    int     getIntegerForKey(const char* pKey);
    int     getIntegerForKey(const char* pKey, int defaultValue);
    /**
     @brief Get float value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is 0.0f.
     */
    float    getFloatForKey(const char* pKey);
    float    getFloatForKey(const char* pKey, float defaultValue);
    /**
     @brief Get double value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is 0.0.
     */
    double  getDoubleForKey(const char* pKey);
    double  getDoubleForKey(const char* pKey, double defaultValue);
    /**
     @brief Get string value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is "".
     */
    std::string getStringForKey(const char* pKey);
    std::string getStringForKey(const char* pKey, const std::string & defaultValue);
    
    // set value methods
    
    /**
     @brief Set bool value by key.
     */
    void    setBoolForKey(const char* pKey, bool value);
    /**
     @brief Set integer value by key.
     */
    void    setIntegerForKey(const char* pKey, int value);
    /**
     @brief Set float value by key.
     */
    void    setFloatForKey(const char* pKey, float value);
    /**
     @brief Set double value by key.
     */
    void    setDoubleForKey(const char* pKey, double value);
    /**
     @brief Set string value by key.
     */
    void    setStringForKey(const char* pKey, const std::string & value);
   
    DECLARE_SINGLETON(CocosSaveManager);
};
#endif /* defined(__FightFootball_independent__CocosSaveManager__) */
