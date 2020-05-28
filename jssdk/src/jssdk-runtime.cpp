#include <v8/include/v8.h>
#include "jssdk-fibjs.h"

namespace js {
void JSRuntime::ObjectSet(const Object& o, exlib::string key, const Value& v)
{
    v8::Local<v8::Object>::Cast(o.m_v)->Set(
        v8::String::NewFromUtf8(m_isolate,
            key.c_str(), v8::String::kNormalString,
            (int32_t)key.length()),
        v.m_v);
}
}