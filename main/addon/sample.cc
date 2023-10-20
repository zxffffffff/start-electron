#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include "windows.h"
#elif __APPLE__
#include <TargetConditionals.h>
#include <dlfcn.h>
#include <cstdlib>
#elif __linux__
// linux
#elif __unix__ // all unices not caught above
// Unix
#else
#error "Unknown compiler"
#endif

#include <napi.h>
#include <type_traits>
#include <memory>
#include <functional>
#include <iostream>

using Func = std::add_pointer<const char *(const char *name)>::type;
static Func func = nullptr;

Napi::String AddonFunc(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (!func)
    {
        Napi::TypeError::New(env, "Wrong func").ThrowAsJavaScriptException();
        return Napi::String::New(env, "");
    }

    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return Napi::String::New(env, "");
    }

    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return Napi::String::New(env, "");
    }

    std::string arg0 = info[0].ToString().Utf8Value();
    const char *ret = func(arg0.c_str());
    return Napi::String::New(env, ret);
}

Napi::Boolean Init(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return Napi::Boolean::New(env, false);
    }

    if (!info[0].IsString() || !info[1].IsString())
    {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return Napi::Boolean::New(env, false);
    }

    std::string arg0 = info[0].ToString().Utf8Value();
    std::string arg1 = info[1].ToString().Utf8Value();

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    ::SetDllDirectory(arg0.c_str());
    HINSTANCE h = ::LoadLibraryA(arg1.c_str());
    if (h)
    {
        func = (Func)GetProcAddress(h, "SampleDynamicLib_getText");
        std::cerr << "addon Init! \n";
    }
    else
    {
        std::cerr << "addon Init error! \n";
        return Napi::Boolean::New(env, false);
    }
#elif __APPLE__
    void *handle = dlopen(arg0.c_str(), RTLD_LAZY);
    if (handle)
    {
        func = reinterpret_cast<Func>(dlsym(handle, "SampleDynamicLib_getText"));
        std::cerr << "addon Init! \n";
    }
    else
    {
        std::cerr << "addon Init error! \n";
        return Napi::Boolean::New(env, false);
    }
#elif __linux__
    // linux
#elif __unix__ // all unices not caught above
    // Unix
#else
#error "Unknown compiler"
#endif
    return Napi::Boolean::New(env, true);
}

Napi::Object NapiInit(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "Init"), Napi::Function::New(env, Init));
    exports.Set(Napi::String::New(env, "Func"), Napi::Function::New(env, AddonFunc));
    return exports;
}

NODE_API_MODULE(addon, NapiInit)
