/****************************************************************************
** MIT License
**
** Author	: xiaofeng.zhu
** Support	: zxffffffff@outlook.com, 1337328542@qq.com
**
****************************************************************************/
#pragma once
#include "define.h"
#include <iostream>

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* msvc兼容utf-8: https://support.microsoft.com/en-us/kb/980263 */
#if (_MSC_VER >= 1700)
#pragma execution_character_set("utf-8")
#endif
#pragma warning(disable:4566)
#endif

class SAMPLE_DYNAMIC_LIB_API SampleDynamicLib
{
public:
    SampleDynamicLib();

    std::string getText(std::string name = "") const;
};

extern "C" {

SAMPLE_DYNAMIC_LIB_API
const char* SampleDynamicLib_getText(const char* name = NULL);

}
