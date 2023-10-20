/****************************************************************************
** MIT License
**
** Author	: xiaofeng.zhu
** Support	: zxffffffff@outlook.com, 1337328542@qq.com
**
****************************************************************************/
#include "SampleDynamicLib.h"

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* msvc兼容utf-8: https://support.microsoft.com/en-us/kb/980263 */
#if (_MSC_VER >= 1700)
#pragma execution_character_set("utf-8")
#endif
#pragma warning(disable : 4566)
#endif

int main(int argc, char *argv[])
{
#ifdef _WIN32
    /* 命令行统一 utf-8 */
    SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32

    std::cerr << "执行 " << __func__ << std::endl;
    SampleDynamicLib sample_dynamic_lib;
    std::cout << SampleDynamicLib_getText("C") << std::endl;
    std::cout << sample_dynamic_lib.getText("C++") << std::endl;

    return 0;
}
