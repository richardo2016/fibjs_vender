# dirty code for replace compilation options of MSVC
macro(configure_msvc_runtime)
    set(variables
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_RELEASE
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_RELEASE)

    foreach(variable ${variables})
        if(${variable} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
            set(${variable} "${${variable}}" CACHE STRING "MSVC_${variable}" FORCE)
        endif()
    endforeach()
endmacro()

# keep same name format with Unix
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_PREFIX_C "lib")
set(CMAKE_STATIC_LIBRARY_PREFIX_CXX "lib")

set(CXX_STD_VER_FLAG "-std=c++14")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DWIN32 -D_LIB -D_CRT_SECURE_NO_WARNINGS -D_CRT_RAND_S -DNOMINMAX -D_FILE_OFFSET_BITS=64)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(MSVC)
    add_compile_options(/MP)
endif()

set(link_flags "${link_flags} /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1")

set(ccflags "${ccflags} ${CXX_STD_VER_FLAG}")

add_definitions(-DWIN32 -D_LIB -D_CRT_SECURE_NO_WARNINGS -D_CRT_RAND_S -DNOMINMAX)

if(${BUILD_TYPE} STREQUAL "release")
	set(flags "${flags} -W0")

	set(link_flags "${link_flags} -static-libstdc++")
    configure_msvc_runtime()
	add_definitions(-DNDEBUG=1)
elseif(${BUILD_TYPE} STREQUAL "debug")
	set(flags "${flags} -g -O0 -Wall -Wno-overloaded-virtual")
	set(link_flags "${link_flags}")
	add_definitions(-DDEBUG=1 -D_DEBUG)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${flags} ${cflags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flags} ${ccflags}")

# message(FATAL_ERROR "CMAKE_C_FLAGS_RELEASE is ${CMAKE_C_FLAGS_RELEASE}")
# message(FATAL_ERROR "CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")

# message(FATAL_ERROR "CMAKE_MSVC_RUNTIME_LIBRARY_DEFAULT is ${CMAKE_MSVC_RUNTIME_LIBRARY_DEFAULT}")