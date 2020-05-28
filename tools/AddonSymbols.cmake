# OS in context required
# you could put addons.cmake after os.cmake

if(NOT OS)
include(./os.cmake)
endif()

# specify symbols dynamic-found instead of global enabling it. 
# set(flags "${flags} -undefined dynamic_lookup")
if(${OS} STREQUAL "Windows")
set(EXPORT_SYMBOLS
"\
-U,_fibjs_api,\
-U,_api_hello,\
-U,_getFibjsApi,\
"
)
else()
set(EXPORT_SYMBOLS
"\
-U,_fibjs_api,\
-U,_api_hello,\
-U,_getFibjsApi,\
"
)
endif()
set(addons_flags "-Wl,${EXPORT_SYMBOLS}")