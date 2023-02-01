// testDll.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "testDll.h"


// 这是导出变量的一个示例
TESTDLL_API int ntestDll=123;

// 这是导出函数的一个示例。
TESTDLL_API int fntestDll(void)
{
    return 456;
}

class TestObj
{
public:
    int n;

    TestObj(int n)
        : n(n)
    {
    }

    int multi(int a)
    {
        return n * a;
    }
};

void* NewObj(int n)
{
    auto o = new TestObj(n);
    return o;
}

void DelObj(void* obj)
{
    auto o = static_cast<TestObj*>(obj);
    delete o;
}

int TestMulti(void* obj, int a)
{
    auto o = static_cast<TestObj*>(obj);
    return o->multi(a);
}
