//
//  CocosSaveManager.cpp
//  FightFootball-independent
//
//  Created by yons on 9/17/14.
//
//

#include "CocosSaveManager.h"

IMPLEMENT_SINGLETON(CocosSaveManager);

string CocosSaveManager::value2string(int value)
{
    stringstream ss;
    string endValue;
    ss << value;
    ss >> endValue;
    return endValue;
}

string CocosSaveManager::value2string(float value)
{
    stringstream ss;
    string endValue;
    ss << value;
    ss >> endValue;
    return endValue;
 
}

string CocosSaveManager::value2string(double value)
{
    stringstream ss;
    string endValue;
    ss << value;
    ss >> endValue;
    return endValue;
}

string CocosSaveManager::value2string(bool value)
{
    stringstream ss;
    string endValue;
    ss << value;
    ss >> endValue;
    return endValue;
}

string CocosSaveManager::value2string(const char * value)
{
    stringstream ss;
    string endValue;
    ss << value;
    ss >> endValue;
    return endValue;
}

string CocosSaveManager::EncryptString(string &value)
{
    string resultString = "";
    for (int i = 0; i < value.length()-2; i++)
    {
        if (i%2 == 0)
        {
            if ((i+1) == (value.length()-2)) {
                continue;
            }
            resultString.append(value,i+1,1);
        }
        else
        {
            resultString.append(value, i-1, 1);
        }
    }
    resultString.append(value,value.length()-2, 2);
    return resultString;
}

bool CocosSaveManager::getBoolForKey(const char *pKey)
{
    return getBoolForKey(pKey,false);
}

bool CocosSaveManager::getBoolForKey(const char *pKey, bool defaultValue)
{
    return getIntegerForKey(pKey, defaultValue);
}

int CocosSaveManager::getIntegerForKey(const char *pKey)
{
    return getIntegerForKey(pKey, 0);
}

int CocosSaveManager::getIntegerForKey(const char *pKey, int defaultValue)
{
//    CCLog("getIntegerForKey%d",defaultValue);
    string str(getStringForKey(pKey,value2string(defaultValue)));
    return atoi(str.c_str());
}

float CocosSaveManager::getFloatForKey(const char *pKey)
{
    return getFloatForKey(pKey, 0);
}

float CocosSaveManager::getFloatForKey(const char *pKey, float defaultValue)
{
    string str(getStringForKey(pKey,value2string(defaultValue)));
    return atof(str.c_str());
}

double CocosSaveManager::getDoubleForKey(const char *pKey)
{
    return getDoubleForKey(pKey, 0);
}

double CocosSaveManager::getDoubleForKey(const char *pKey, double defaultValue)
{
    string str(getStringForKey(pKey,value2string(defaultValue)));
    return atof(str.c_str());
}

string CocosSaveManager::getStringForKey(const char *pKey)
{
    return getStringForKey(pKey, "");
    
}

string CocosSaveManager::getStringForKey(const char *pKey, const std::string &defaultValue)
{
    string saveOrg = CCUserDefault::sharedUserDefault()->getStringForKey("bvjOiLwe");
  
    if (saveOrg.empty())
    {
        mSaveString = saveOrg;
    }
    else
    {
        saveOrg = EncryptString(saveOrg);
        mSaveString = string(CocosParseData(saveOrg));
    }
//    CCLog("%s",mSaveString.c_str());
    if (mSaveString.find(pKey) == string::npos)
    {
        mSaveString.append(pKey);
//        CCLog("%s",defaultValue.c_str());
        mSaveString.append(defaultValue);
        mSaveString.append(pKey);
        saveOrg = CocosSaveData(reinterpret_cast<const unsigned char*>(mSaveString.c_str()), mSaveString.length());
        saveOrg = EncryptString(saveOrg);

        CCUserDefault::sharedUserDefault()->setStringForKey("bvjOiLwe", saveOrg);
        CCUserDefault::sharedUserDefault()->flush();
    }
    int positionFirstIndex = mSaveString.find(pKey);
    int positionSecondIndex = mSaveString.rfind(pKey);
    string result;
    result.assign(mSaveString, positionFirstIndex+strlen(pKey), positionSecondIndex-positionFirstIndex-strlen(pKey));
//    CCLog("RoleTest pKey%s",pKey);
//    CCLog("RoleTest result.c_str%s",result.c_str());
    return result;
    
}

void    CocosSaveManager::setBoolForKey(const char* pKey, bool value)
{
    setStringForKey(pKey, value2string(value));
}

void    CocosSaveManager::setIntegerForKey(const char* pKey, int value)
{
//    CCLog("%s",value2string(value).c_str());
    setStringForKey(pKey, value2string(value));
}

void    CocosSaveManager::setFloatForKey(const char* pKey, float value)
{
    setStringForKey(pKey, value2string(value));
}

void    CocosSaveManager::setDoubleForKey(const char* pKey, double value)
{
    setStringForKey(pKey, value2string(value));
}

void CocosSaveManager::setStringForKey(const char* pKey, const std::string & value)
{
//    string saveOrg =   CCUserDefault::sharedUserDefault()->getStringForKey("bvjOiLwe");
//    mSaveString = CocosParseData(saveOrg);
//      CCLog("setStringForKe1%s",mSaveString.c_str());
    if (mSaveString.find(pKey) == string::npos)
    {
        mSaveString.append(pKey);
        mSaveString.append(value);
        mSaveString.append(pKey);
    }
    else
    {
        int positionFirstIndex = mSaveString.find(pKey);
        int positionSecondIndex = mSaveString.rfind(pKey);
        mSaveString.replace(positionFirstIndex+strlen(pKey),positionSecondIndex-positionFirstIndex-strlen(pKey), value);
    }
//    CCLog("setStringForKe2%s",mSaveString.c_str());
    string saveOrg = CocosSaveData(reinterpret_cast<const unsigned char*>(mSaveString.c_str()), mSaveString.length());
//    CCLog("setStringForKe3%s",saveOrg.c_str());
    saveOrg = EncryptString(saveOrg);

//    CCLog("%s",saveOrg.c_str());
    CCUserDefault::sharedUserDefault()->setStringForKey("bvjOiLwe", saveOrg);
    CCUserDefault::sharedUserDefault()->flush();
   
}



static const std::string dataChars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

static inline bool baseData(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string CocosSaveData(unsigned char const* bytes_to_encode, unsigned int in_len) {
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];
    
    while (in_len--) {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;
            
            for(i = 0; (i <4) ; i++)
                ret += dataChars[char_array_4[i]];
            i = 0;
        }
    }
    
    if (i)
    {
        for(j = i; j < 3; j++)
            char_array_3[j] = '\0';
        
        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;
        
        for (j = 0; (j < i + 1); j++)
            ret += dataChars[char_array_4[j]];
        
        while((i++ < 3))
            ret += '=';
        
    }
    
    return ret;
    
}

std::string CocosParseData(std::string const& encoded_string) {
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;
    
    while (in_len-- && ( encoded_string[in_] != '=') && baseData(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i ==4) {
            for (i = 0; i <4; i++)
                char_array_4[i] = dataChars.find(char_array_4[i]);
            
            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
            
            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }
    
    if (i) {
        for (j = i; j <4; j++)
            char_array_4[j] = 0;
        
        for (j = 0; j <4; j++)
            char_array_4[j] = dataChars.find(char_array_4[j]);
        
        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
        
        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }
    
    return ret;
}
