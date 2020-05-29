/*
 *  jssdk_api.cpp
 *  Created on: Mar 31, 2016
 *
 *  Copyright (c) 2016 by Leo Hoo
 *  lion@9465.net
 */

#include <jssdk/include/jssdk.h>
#include <string.h>

namespace js {

const int32_t Api::version = 1;

/**
 * @description keep jsapi in same bit files
 */
Api* jsapi;

Api* getFibjsApi()
{
    return jsapi;
}
bool isFibjsApiSetup()
{
    return !!jsapi;
}
bool isJSRuntimeSetup()
{
    if (!isFibjsApiSetup())
        return false;

    js::Runtime* js_runtime = jsapi->getCurrentJSRuntime();

    return !!js_runtime;
}

};