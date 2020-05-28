/*
 *  jssdk_api.cpp
 *  Created on: Mar 31, 2016
 *
 *  Copyright (c) 2016 by Leo Hoo
 *  lion@9465.net
 */

#include "jssdk.h"
#include <string.h>
#include <jssdk/include/utils.h>

namespace js {

const int32_t Api::version = 1;
Api* v8_api;

EXTERN_C_START
Api* fibjs_api;
EXTERN_C_END
};