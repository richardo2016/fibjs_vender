/**
 * @author Richard
 * @email richardo2016@mail.com
 * @create date 2020-05-04 21:56:21
 * @modify date 2020-05-04 21:56:21
 * @desc module definitions
 */

#ifndef _jssdk_module_h_
#define _jssdk_module_h_

#include "Isolate.h"

namespace js {

class CJSModule {
public:
    CJSModule()
        : m_next(NULL)
    {
    }

public:
    virtual void install() = 0;
    CJSModule* getNext()
    {
        return m_next;
    }
    void setNext(CJSModule* nextVal)
    {
        m_next = nextVal;
    }

public:
    virtual v8::Local<v8::Object> getModule(Isolate* isolate) = 0;

    virtual const char* name() = 0;

private:
    CJSModule* m_next;
};

}

#endif // _jssdk_module_h_