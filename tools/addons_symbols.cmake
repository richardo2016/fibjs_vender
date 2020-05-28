# OS in context required
# you could put addons.cmake after os.cmake

if(NOT OS)
include(./os.cmake)
endif()

if(${OS} STREQUAL "Darwin")
# specify symbols dynamic-found instead of global enabling it. 
# set(flags "${flags} -undefined dynamic_lookup")
set(EXPORT_SYMBOLS
"\
-U,_fibjs_api,\
-U,_api_hello,\
-U,_getFibjsApi,\
"
)
set(addons_flags "-Wl,${EXPORT_SYMBOLS}")
endif()