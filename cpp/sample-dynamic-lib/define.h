/****************************************************************************
** MIT License
**
** Author	: xiaofeng.zhu
** Support	: zxffffffff@outlook.com, 1337328542@qq.com
**
****************************************************************************/
#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* msvc兼容utf-8: https://support.microsoft.com/en-us/kb/980263 */
#if (_MSC_VER >= 1700)
#pragma execution_character_set("utf-8")
#endif
#pragma warning(disable:4566)
#endif

#ifdef _WIN32
# ifdef SAMPLE_DYNAMIC_LIB_EXPORT
#  define SAMPLE_DYNAMIC_LIB_API __declspec(dllexport)
# else
#  define SAMPLE_DYNAMIC_LIB_API __declspec(dllimport)
# endif
#else
# define SAMPLE_DYNAMIC_LIB_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
// todo
#ifdef __cplusplus
}
#endif //__cplusplus
