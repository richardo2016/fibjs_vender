# OS in context required
# you could put addons.cmake after os.cmake

if(NOT OS)
include(./os.cmake)
endif()

# specify symbols dynamic-found instead of global enabling it. 
if(${OS} STREQUAL "Windows")
    set(addons_flags "-Xlinker //dll")
    target_link_libraries(${PROJECT_NAME} ${BIN_DIR}/jssdk_test${CMAKE_STATIC_LIBRARY_SUFFIX})

    # set(addons_flags "${addons_flags} -Xlinker //EXPORT:_fibjs_api")
    # set(addons_flags "${addons_flags} -Xlinker //EXPORT:_getFibjsApi")
    # @warning never allow undefined symbols!
    # set(addons_flags "${addons_flags} -Xlinker //force:unresolved")
else()
# @warning never allow undefined symbols!
# set(flags "${flags} -undefined dynamic_lookup")
set(EXPORT_SYMBOLS
"\
-U,_jsapi,\
-U,_getFibjsApi,\
-U,_isFibjsApiSetup,\
-U,_isJSRuntimeSetup,\
"
)
set(addons_flags "-Wl,-U,-Wl,${EXPORT_SYMBOLS}")
endif()