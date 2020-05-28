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

#include "jssdk.h"

#include <v8/include/v8.h>
#include "libplatform/libplatform.h"

#ifndef FAPI_EXTERN
#define FAPI_EXTERN FAPI_EXPORT
#endif
#include "utils.h"

namespace js {

bool loadAddon(const char* dll_fname, v8::Local<v8::Value>& addonVal);

EXTERN_C_START
FAPI_EXTERN extern Api* fibjs_api;
FAPI_EXTERN Api* getFibjsApi();
FAPI_EXTERN bool isFibjsApiSetup();
FAPI_EXTERN bool isJSRuntimeSetup();
EXTERN_C_END

class Api_fibjs;
class JSRuntime;

typedef v8::Local<v8::Value> js_value;

class Value {
public:
    Value()
        : m_rt(NULL)
    {
    }

    Value(Runtime* rt, js_value v)
        : m_rt(rt)
        , m_v(v)
    {
    }

    Value(const Value& v)
        : m_rt(v.m_rt)
        , m_v(v.m_v)
    {
    }

    Value& operator=(const Value& v)
    {
        m_rt = v.m_rt;
        m_v = v.m_v;
        return *this;
    }

    js_value toValue() const
    {
        if (isEmpty()) {
            // Isolate* isolate = Isolate::current();
            js::Isolate* isolate = js::fibjs_api->getCurrentIsolate();
            return v8::Undefined(isolate->m_isolate);
        }

        return m_v;
    }

private:
    bool m_empty;

public:
    bool isEmpty() const
    {
        return m_rt == NULL || m_v.IsEmpty();
    }

public:
    bool isUndefined() const
    {
        return m_rt->ValueIsUndefined(*this);
    }

    bool toBoolean() const
    {
        return m_rt->ValueToBoolean(*this);
    }

    bool isBoolean() const
    {
        return m_rt->ValueIsBoolean(*this);
    }

    double toNumber() const
    {
        return m_rt->ValueToNumber(*this);
    }

    bool isNumber() const
    {
        return m_rt->ValueIsNumber(*this);
    }

    exlib::string toString() const
    {
        return m_rt->ValueToString(*this);
    }

    bool isString() const
    {
        return m_rt->ValueIsString(*this);
    }

    bool isArray() const
    {
        return m_rt->ValueIsArray(*this);
    }

    bool isObject() const
    {
        return m_rt->ValueIsObject(*this);
    }

    bool isFunction() const
    {
        return m_rt->ValueIsFunction(*this);
    }

public:
    Runtime* m_rt;
    js_value m_v;
};

class Object : public Value {
public:
    Object()
    {
    }

    Object(Runtime* rt, js_value v)
        : Value(rt, v)
    {
        assert(isObject());
    }

    Object(const Value& v)
        : Value(v)
    {
        assert(isObject());
    }

public:
    bool has(exlib::string key)
    {
        return m_rt->ObjectHas(*this, key);
    }

    Value get(exlib::string key)
    {
        return m_rt->ObjectGet(*this, key);
    }

    void set(exlib::string key, const Value& v)
    {
        m_rt->ObjectSet(*this, key, v);
    }

    void remove(exlib::string key)
    {
        m_rt->ObjectRemove(*this, key);
    }

    Array keys();

    bool hasPrivate(exlib::string key)
    {
        return m_rt->ObjectHasPrivate(*this, key);
    }

    Value getPrivate(exlib::string key)
    {
        return m_rt->ObjectGetPrivate(*this, key);
    }

    void setPrivate(exlib::string key, const Value& v)
    {
        m_rt->ObjectSetPrivate(*this, key, v);
    }

    void removePrivate(exlib::string key)
    {
        m_rt->ObjectRemovePrivate(*this, key);
    }

    v8::Local<v8::Object> operator=(const Value& v)
    {
        return v8::Local<v8::Object>::Cast(v.m_v);
    }
};

class Array : public Object {
public:
    Array()
    {
    }

    Array(Runtime* rt, js_value v)
        : Object(rt, v)
    {
        assert(isArray());
    }

    Array(const Value& v)
        : Object(v)
    {
        assert(isArray());
    }

public:
    int32_t length()
    {
        return m_rt->ArrayGetLength(*this);
    }

    Value get(int32_t idx)
    {
        return m_rt->ArrayGet(*this, idx);
    }

    void set(int32_t idx, const Value& v)
    {
        m_rt->ArraySet(*this, idx, v);
    }

    void remove(int32_t idx)
    {
        m_rt->ArrayRemove(*this, idx);
    }
};

class Function : public Object {
public:
    Function()
    {
    }

    Function(Runtime* rt, js_value v)
        : Object(rt, v)
    {
        assert(isFunction());
    }

    Function(const Value& v)
        : Object(v)
    {
        assert(isFunction());
    }

public:
    Value call(Value* args, int32_t argn)
    {
        return m_rt->FunctionCall(*this, Object(), args, argn);
    }

    Value call()
    {
        return m_rt->FunctionCall(*this, Object(), NULL, 0);
    }

    Value call(Object obj, Value* args, int32_t argn)
    {
        return m_rt->FunctionCall(*this, obj, args, argn);
    }

    Value call(Object obj)
    {
        return m_rt->FunctionCall(*this, obj, NULL, 0);
    }
};

inline Array Object::keys()
{
    return m_rt->ObjectKeys(*this);
}

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