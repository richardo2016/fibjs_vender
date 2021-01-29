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

namespace js {

class Api;
class Value;
class Object;
class Array;
class Function;
class HandleScope;
class EscapableHandleScope;
class Runtime;

/** core definition about Runtime, provide basic members/interface for:
 * - enter js scope/handlescope after app switch to js thread
 * - leave js scope/handlescope before app switch away from js thread
 */
class Runtime_core {
public:
    /* in  */
    class Locker;
    class Unlocker;
    class Scope;

public:
    virtual ~Runtime_core() { }

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

/** basic definitions for global API instance
 */
class Api {
public:
    /* version of API */
    static const int32_t version;

public:
    /* return engine's name, specify it in child class */
    virtual const char* getEngineName() = 0;
    /* return engine's version, specify it in child class */
    virtual int32_t getVersion() = 0;
    /* do some initial work for engine */
    virtual void init() = 0;
    /* create one runtime instance */
    virtual Runtime* createRuntime() = 0;
};

extern Api* v8_api;
extern Api* spider_api;

extern Api* _v8_api;
extern bool set_v8_api(Api* _api);
inline bool setup_v8()
{
    return set_v8_api(_v8_api);
}

extern Api* _spider_api;
extern bool set_spider_api(Api* _api);
inline bool setup_spider()
{
    return set_spider_api(_spider_api);
}

}

#endif // _jssdk_h__
