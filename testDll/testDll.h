// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 TESTDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// TESTDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef TESTDLL_EXPORTS
#define TESTDLL_API __declspec(dllexport)
#else
#define TESTDLL_API __declspec(dllimport)
#endif

extern "C" {

    extern TESTDLL_API int ntestDll;

    TESTDLL_API int fntestDll(void);

    TESTDLL_API void* NewObj(int n);
    TESTDLL_API void DelObj(void* obj);
    TESTDLL_API int TestMulti(void* obj, int a);
}
