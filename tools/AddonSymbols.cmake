# OS in context required
# you could put addons.cmake after os.cmake

if(NOT OS)
include(./os.cmake)
endif()

# specify symbols dynamic-found instead of global enabling it. 
# set(flags "${flags} -undefined dynamic_lookup")
if(${OS} STREQUAL "Windows")
    set(addons_flags "-Xlinker //dll")
    set(addons_flags "${addons_flags} -Xlinker //force:unresolved")
    # set(addons_flags "-Wl,-U,fibjs_api,-U,getFibjsApi")

    #s see `lld-link -help | grep "symbol"`
    # set(addons_flags "${addons_flags} -Xlinker //include:__imp_getFibjsApi")
    # set(addons_flags "${addons_flags} -Xlinker //include:__imp_fibjs_api")
else()
set(EXPORT_SYMBOLS
"\
-U,_fibjs_api,\
-U,_getFibjsApi,\
"
)
set(addons_flags "-Wl,-U,-Wl,${EXPORT_SYMBOLS}")
endif()