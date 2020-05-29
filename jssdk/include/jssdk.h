/*
 *  jssdk.h
 *  Created on: Mar 31, 2016
 *
 *  Copyright (c) 2016 by Leo Hoo
 *  lion@9465.net
 */

#ifndef _jssdk_h__
#define _jssdk_h__

#include <stdint.h>
#include <exlib/include/qstring.h>

#include <jssdk/include/common/Isolate.h>
#include <jssdk/include/common/Module.h>
#include <jssdk/include/common/Runtime.h>

#include <jssdk/include/utils.h>

namespace js {

class Api;
class Value;
class Object;
class Array;
class Function;
class FunctionCallbackInfo;
typedef void (*FunctionCallback)(const FunctionCallbackInfo& info);
class HandleScope;
class EscapableHandleScope;
class Locker;
class Unlocker;
class Scope;

class Runtime {
public:
public:
    virtual ~Runtime() {}

public:
    virtual void destroy() = 0;

    virtual void Locker_enter(Locker& locker) = 0;
    virtual void Locker_leave(Locker& locker) = 0;

    virtual void Unlocker_enter(Unlocker& unlocker) = 0;
    virtual void Unlocker_leave(Unlocker& unlocker) = 0;

    virtual void Scope_enter(Scope& scope) = 0;
    virtual void Scope_leave(Scope& scope) = 0;

    virtual void HandleScope_enter(HandleScope& scope) = 0;
    virtual void HandleScope_leave(HandleScope& scope) = 0;

    virtual void EscapableHandleScope_enter(EscapableHandleScope& scope) = 0;
    virtual void EscapableHandleScope_leave(EscapableHandleScope& scope) = 0;
    virtual Value EscapableHandleScope_escape(EscapableHandleScope& scope, Value v) = 0;

public:
    class Api* m_api;

public:
    virtual bool ValueIsUndefined(const Value& v) = 0;

    virtual bool ValueToBoolean(const Value& v) = 0;
    virtual bool ValueIsBoolean(const Value& v) = 0;

    virtual double ValueToNumber(const Value& v) = 0;
    virtual bool ValueIsNumber(const Value& v) = 0;

    virtual exlib::string ValueToString(const Value& v) = 0;
    virtual bool ValueIsString(const Value& v) = 0;

    virtual bool ObjectHas(const Object& o, exlib::string key) = 0;
    virtual Value ObjectGet(const Object& o, exlib::string key) = 0;
    virtual void ObjectSet(const Object& o, exlib::string key, const Value& v) = 0;
    virtual void ObjectRemove(const Object& o, exlib::string key) = 0;
    virtual Array ObjectKeys(const Object& o) = 0;
    virtual bool ObjectHasPrivate(const Object& o, exlib::string key) = 0;
    virtual Value ObjectGetPrivate(const Object& o, exlib::string key) = 0;
    virtual void ObjectSetPrivate(const Object& o, exlib::string key, const Value& v) = 0;
    virtual void ObjectRemovePrivate(const Object& o, exlib::string key) = 0;
    virtual bool ValueIsObject(const Value& v) = 0;

    virtual int32_t ArrayGetLength(const Array& a) = 0;
    virtual Value ArrayGet(const Array& a, int32_t idx) = 0;
    virtual void ArraySet(const Array& a, int32_t idx, const Value& v) = 0;
    virtual void ArrayRemove(const Array& a, int32_t idx) = 0;
    virtual bool ValueIsArray(const Value& v) = 0;

    virtual Value FunctionCall(const Function& f, Object obj, Value* args, int32_t argn) = 0;
    virtual bool ValueIsFunction(const Value& v) = 0;

public:
    virtual void gc() = 0;

    virtual Object GetGlobal() = 0;

    virtual Value execute(exlib::string code, exlib::string soname) = 0;

    virtual Value NewUndefined() = 0;
    virtual Value NewBoolean(bool b) = 0;
    virtual Value NewNumber(double d) = 0;
    virtual Value NewString(exlib::string s) = 0;
    virtual Object NewObject() = 0;
    virtual Array NewArray() = 0;
    virtual Array NewArray(int32_t sz) = 0;
    virtual Function NewFunction(FunctionCallback callback) = 0;
};

class Api {
public:
    static const int32_t version;

public:
    virtual const char* getEngine() = 0;
    virtual int32_t getVersion() = 0;
    /**
     * @description initialize js engine's environment, such as v8's platform
     */
    virtual void init() = 0;
    virtual Runtime* createRuntime() = 0;
    virtual Isolate* getCurrentIsolate() = 0;
    virtual FiberRuntime* getCurrentRuntime() = 0;
    virtual Runtime* getCurrentJSRuntime() = 0;
};

inline bool set_js_api(Api*& api, Api* _temp_api, const char* engine_name)
{
    if (strcmp(engine_name, _temp_api->getEngine()) || Api::version != _temp_api->getVersion()) {
        printf("[set_js_api] engine's name or version not matched \n");
        return false;
    }

    printf("[set_js_api] lalalala \n");

    api = _temp_api;
    return true;
}

extern Api* jsapi;

EXTERN_C_START
FAPI_EXTERN Api* getFibjsApi();
FAPI_EXTERN bool isFibjsApiSetup();
FAPI_EXTERN bool isJSRuntimeSetup();
EXTERN_C_END

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
            js::Isolate* isolate = js::getFibjsApi()->getCurrentIsolate();
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

}

#endif // _jssdk_h__
