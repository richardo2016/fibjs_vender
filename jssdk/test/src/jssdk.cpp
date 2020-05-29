#include "gtest/gtest.h"
#include "exlib/include/service.h"
#include <jssdk/include/jssdk-fibjs.h>

void* fucK_def_fibjs_api = js::fibjs_api;
void* fucK_def_getFibjsApi = js::getFibjsApi;

int main(int argc, char* argv[])
{
    js::jssdk_setup_fibjs();

    return 0;
}