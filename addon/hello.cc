#include <napi.h>

#include "windows.h"
#include <type_traits>

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  HINSTANCE h = ::LoadLibraryA("./addon/testDll/testDll.dll");
  if (h) {
    using F = std::add_pointer<int()>::type;
    F f = (F)GetProcAddress(h, "fntestDll");
    int a = f();
    return Napi::String::New(env, std::to_string(a));
  }
  return Napi::String::New(env, "world");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(hello, Init)
