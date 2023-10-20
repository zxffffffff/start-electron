/****************************************************************************
** MIT License
**
** Author	: xiaofeng.zhu
** Support	: zxffffffff@outlook.com, 1337328542@qq.com
**
****************************************************************************/
#include "SampleDynamicLib.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* msvc兼容utf-8: https://support.microsoft.com/en-us/kb/980263 */
#if (_MSC_VER >= 1700)
#pragma execution_character_set("utf-8")
#endif
#pragma warning(disable : 4566)
#endif

SampleDynamicLib::SampleDynamicLib()
{
    std::cerr << "执行 " << __func__ << std::endl;
}

std::string SampleDynamicLib::getText(std::string name) const
{
    return SampleDynamicLib_getText(name.c_str());
}

const char *SampleDynamicLib_getText(const char *name)
{
    static char buf[512];
    memset(buf, sizeof(buf), 0);
    sprintf(buf, "你好 %s", name);
    return buf;
}
