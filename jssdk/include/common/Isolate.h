/**
 * @author Richard
 * @email richardo2016@mail.com
 * @create date 2020-05-03 17:23:24
 * @modify date 2020-05-03 17:23:24
 * @desc isolate definition
 */

#ifndef _jssdk_isolate_h_
#define _jssdk_isolate_h_

#include <exlib/include/list.h>
#include <exlib/include/qstring.h>
#include <exlib/include/service.h>

#include <v8/include/v8.h>

#include "../../src/utf8.h"

namespace js {

inline v8::Local<v8::String> NewString(v8::Isolate* isolate, const char* data, int32_t length = -1)
{
    exlib::wstring wstr = utf8to16String(data, length);

    return v8::String::NewFromTwoByte(isolate, (const uint16_t*)wstr.c_str(),
        v8::String::kNormalString, (int32_t)wstr.length());
}

inline v8::Local<v8::String> NewString(v8::Isolate* isolate, exlib::string str)
{
    return NewString(isolate, str.c_str(), (int32_t)str.length());
}

class JSRuntime;

class Isolate : public exlib::linkitem {
public:
    Isolate();

public:
    static Isolate* current();
    virtual void init() = 0;

    virtual void RequestInterrupt(v8::InterruptCallback callback, void* data) = 0;

    virtual void start_profiler() = 0;

    virtual void Ref() = 0;
    virtual void Unref(int32_t hr = 0) = 0;

public:
    // js helpers
    v8::Local<v8::String> NewString(exlib::string str)
    {
        return js::NewString(m_isolate, str.c_str());
    }

public:
    JSRuntime* m_jsruntime;
    exlib::spinlock m_weakLock;
    exlib::List<exlib::linkitem> m_weak;

    v8::Isolate* m_isolate;

    v8::Global<v8::Context> m_context;
    v8::Global<v8::Object> m_env;

    v8::Global<v8::Object> m_AssertionError;

    exlib::List<exlib::linkitem> m_fibers;

    exlib::Semaphore m_sem;
    exlib::LockedList<exlib::linkitem> m_jobs;

    exlib::atomic m_has_timer;
};

}

#endif // _jssdk_isolate_h_