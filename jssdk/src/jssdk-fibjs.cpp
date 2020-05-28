/**
 * @author Richard
 * @email richardo2016@mail.com
 * @create date 2020-05-02 22:53:14
 * @modify date 2020-05-02 22:53:14
 * @desc jssdk's engine for fibjs
 */

#include "jssdk-fibjs.h"

#include <stdlib.h>
#include <string.h>
#include <vector>

namespace js {

class Api_fibjs : public Api {
public:
    virtual const char* getEngine()
    {
        return "fibjs";
    }

    virtual int32_t getVersion()
    {
        return version;
    }

    virtual void init(/* void* (*get_platform)() */)
    {
        static bool s_bInit = false;

        if (!s_bInit) {
            s_bInit = true;

            v8::Platform* platform = v8::platform::CreateDefaultPlatform();

            // if (get_platform != NULL)
            //     platform = get_platform();
            // else
            platform = v8::platform::CreateDefaultPlatform();

            v8::V8::InitializePlatform(platform);

            v8::V8::Initialize();
        }
    }

    virtual Runtime* createRuntime()
    {
        return new JSRuntime(this);
    }

    virtual Isolate* getCurrentIsolate()
    {
        return Isolate::current();
    }

    virtual FiberRuntime* getCurrentRuntime()
    {
        return FiberRuntime::current();
    }

    virtual Runtime* getCurrentJSRuntime()
    {
        Isolate* isolate = Isolate::current();
        if (isolate == NULL)
            return NULL;

        return (Runtime*)isolate->m_jsruntime;
    }
};

Isolate::Isolate()
{
    m_jsruntime = (js::JSRuntime*)fibjs_api->createRuntime();
    m_isolate = m_jsruntime->createV8Isolate();
}

Isolate* Isolate::current()
{
    FiberRuntime* rt = FiberRuntime::current();
    if (rt == NULL)
        return NULL;

    return rt->isolate();
};

static int32_t s_tls_rt;

class rt_initer {
public:
    rt_initer()
    {
        s_tls_rt = exlib::Fiber::tlsAlloc();
    }
} s_rt_initer;

void FiberRuntime::reg()
{
    exlib::Fiber::tlsPut(s_tls_rt, this);
}

FiberRuntime* FiberRuntime::current()
{
    return (FiberRuntime*)exlib::Fiber::tlsGet(s_tls_rt);
}

static Api_fibjs s_fibjs_api;
Api* _fibjs_api = &s_fibjs_api;

Api* fibjs_api;
Api* getFibjsApi()
{
    return fibjs_api;
}
bool isFibjsApiSetup()
{
    return !!fibjs_api;
}
bool isJSRuntimeSetup()
{
    if (!isFibjsApiSetup())
        return false;

    js::Runtime* js_runtime = fibjs_api->getCurrentJSRuntime();

    return !!js_runtime;
}

bool jssdk_setup_fibjs()
{
    return set_js_api(fibjs_api, _fibjs_api, "fibjs");
}

}