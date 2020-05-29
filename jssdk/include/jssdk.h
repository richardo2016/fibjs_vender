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

inline bool set_js_api(Api*& api, Api* _agent_api, const char* eng)
{
    if (strcmp(eng, _agent_api->getEngine()) || Api::version != _agent_api->getVersion())
        return false;

    api = _agent_api;
    return true;
}

}

#endif // _jssdk_h__
