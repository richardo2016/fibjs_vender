/**
 * @author Richard
 * @email richardo2016@mail.com
 * @create date 2020-05-02 21:38:47
 * @modify date 2020-05-02 21:38:47
 * @desc jssdk's engine for fibjs
 */

#ifndef _jssdk_fibjs_h__
#define _jssdk_fibjs_h__

#include <assert.h>

#ifndef FAPI_EXTERN
#ifdef _WIN32
// Building native module against fibjs
#define FAPI_EXTERN __declspec(dllexport)
#endif
#endif

#include <jssdk/include/utils.h>

#include <jssdk/include/jssdk.h>
#include <v8/include/v8.h>
#include "libplatform/libplatform.h"

namespace js {

bool loadAddon(const char* dll_fname, v8::Local<v8::Value>& addonVal);

class Api_fibjs;
class JSRuntime;

/* context about api :start */
class Locker {
public:
    Locker(Runtime* rt);
    ~Locker();

private:
    Runtime* m_rt;
    char m_locker[sizeof(v8::Locker)];

    friend class JSRuntime;
};

class Unlocker {
public:
    Unlocker(Runtime* rt);
    ~Unlocker();

private:
    Runtime* m_rt;
    char m_unlocker[sizeof(v8::Unlocker)];

    friend class JSRuntime;
};

class Scope {
public:
    Scope(Runtime* rt);
    ~Scope();

private:
    Runtime* m_rt;
    char m_locker[sizeof(v8::Locker)];
    char m_scope[sizeof(v8::Isolate::Scope)];

    friend class JSRuntime;
};

class HandleScope {
public:
    HandleScope(Runtime* rt);
    ~HandleScope();

private:
    Runtime* m_rt;
    char m_handle_scope[sizeof(v8::HandleScope)];

    friend class JSRuntime;
};

class EscapableHandleScope {
public:
    EscapableHandleScope(Runtime* rt);
    ~EscapableHandleScope();

public:
    Value escape(Value v);

private:
    Runtime* m_rt;
    char m_handle_scope[sizeof(v8::EscapableHandleScope)];

    friend class JSRuntime;
};
/* context about api :end */

class FunctionCallbackInfo : private v8::FunctionCallbackInfo<v8::Value> {
};

bool jssdk_setup_fibjs();

inline Locker::Locker(Runtime* rt)
    : m_rt(rt)
{
    rt->Locker_enter(*this);
}

inline Locker::~Locker()
{
    m_rt->Locker_leave(*this);
}

inline Unlocker::Unlocker(Runtime* rt)
    : m_rt(rt)
{
    rt->Unlocker_enter(*this);
}

inline Unlocker::~Unlocker()
{
    m_rt->Unlocker_leave(*this);
}

inline Scope::Scope(Runtime* rt)
    : m_rt(rt)
{
    rt->Scope_enter(*this);
}

inline Scope::~Scope()
{
    m_rt->Scope_leave(*this);
}

inline HandleScope::HandleScope(Runtime* rt)
    : m_rt(rt)
{
    rt->HandleScope_enter(*this);
}

inline HandleScope::~HandleScope()
{
    m_rt->HandleScope_leave(*this);
}

inline EscapableHandleScope::EscapableHandleScope(Runtime* rt)
    : m_rt(rt)
{
    rt->EscapableHandleScope_enter(*this);
}

inline EscapableHandleScope::~EscapableHandleScope()
{
    m_rt->EscapableHandleScope_leave(*this);
}

inline Value EscapableHandleScope::escape(Value v)
{
    return m_rt->EscapableHandleScope_escape(*this, v);
}

}

#include "jssdk-jsruntime.inl"

#endif // _jssdk_fibjs_h__