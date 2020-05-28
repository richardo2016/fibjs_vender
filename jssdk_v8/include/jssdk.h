/*
 *  jssdk.h
 *  Created on: Mar 31, 2016
 *
 *  Copyright (c) 2016 by Leo Hoo
 *  lion@9465.net
 */

#ifndef _jssdk_h__
#define _jssdk_h__

#include <jssdk/include/utils.h>
#include <stdint.h>
#include <exlib/include/qstring.h>

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
class Runtime;

class Runtime_core {
public:
    class Locker;
    class Unlocker;
    class Scope;

public:
    virtual ~Runtime_core() {}

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
};

inline bool set_js_api(Api*& api, Api* _agent_api, const char* eng)
{
    if (strcmp(eng, _agent_api->getEngine()) || Api::version != _agent_api->getVersion())
        return false;

    api = _agent_api;
    return true;
}

extern Api* v8_api;
EXTERN_C_START
extern Api* fibjs_api;
EXTERN_C_END
}

#endif // _jssdk_h__
