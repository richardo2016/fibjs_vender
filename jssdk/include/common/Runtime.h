/**
 * @author Richard
 * @email richardo2016@mail.com
 * @create date 2020-05-05 01:13:31
 * @modify date 2020-05-05 01:13:31
 * @desc jssdk's fiber runtime for fibjs
 */

#ifndef _jssdk_rt_h__
#define _jssdk_rt_h__

#include "Isolate.h"

namespace js {

class FiberRuntime {
public:
    FiberRuntime(Isolate* isolate)
        : m_isolate(isolate)
    {
        reg();
    }

public:
    static FiberRuntime* current();

    Isolate* isolate()
    {
        assert(v8::Locker::IsLocked(m_isolate->m_isolate));
        return m_isolate;
    }

    Isolate* getIsolate()
    {
        return m_isolate;
    }

    v8::Isolate* getV8Isolate()
    {
        return m_isolate->m_isolate;
    }

private:
    void reg();

private:
    Isolate* m_isolate;
};
}

#endif // _jssdk_rt_h__