#include <napi.h>

#include "windows.h"
#include <type_traits>

#ifdef _WIN32
using FNewObj = std::add_pointer<void*(int)>::type;
using FDelObj = std::add_pointer<void(void*)>::type;
using FTestMulti = std::add_pointer<int(void*,int)>::type;
static FNewObj fNewObj = nullptr;
static FDelObj fDelObj = nullptr;
static FTestMulti fTestMulti = nullptr;
#endif

Napi::Number TestMulti(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return Napi::Number::New(env, 0);
    }

    int i = 0;
    if (!info[i++].IsNumber() || !info[i++].IsNumber())
    {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return Napi::Number::New(env, 0);
    }

    i = 0;
    int a = info[i++].ToNumber().Int32Value();
    int b = info[i++].ToNumber().Int32Value();

    void *obj = fNewObj(a);
    int r = fTestMulti(obj, b);
    fDelObj(obj);

    return Napi::Number::New(env, r);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
#ifdef _WIN32
    ::SetDllDirectory("./addon/testDll");
    HINSTANCE h = ::LoadLibraryA("testDll.dll");
    if (h)
    {
        fNewObj = (FNewObj)GetProcAddress(h, "NewObj");
        fDelObj = (FDelObj)GetProcAddress(h, "DelObj");
        fTestMulti = (FTestMulti)GetProcAddress(h, "TestMulti");
    }
#endif

  exports.Set(Napi::String::New(env, "TestMulti"), Napi::Function::New(env, TestMulti));
  return exports;
}

NODE_API_MODULE(hello, Init)
