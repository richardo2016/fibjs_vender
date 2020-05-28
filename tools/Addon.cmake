if(NOT DEFINED VENDER_DIR)
set(VENDER_DIR ${PROJECT_SOURCE_DIR}/../../)
message("no variable VENDER_DIR detected in context, use default value ${VENDER_DIR}")
endif()

include(${VENDER_DIR}/tools/arch.cmake)
include(${VENDER_DIR}/tools/os.cmake)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
	set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
	set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

if(NOT BUILD_TYPE)
	set(BUILD_TYPE "release")
endif()

set(USED_BY_FIBJS "1")
if((${USED_BY_FIBJS}) STREQUAL "1")
	set(BIN_DIR ${VENDER_DIR}/../bin/${OS}_${ARCH}_${BUILD_TYPE})
else()
	set(BIN_DIR ${VENDER_DIR}/.dist/bin/${OS}_${ARCH}_${BUILD_TYPE})
endif()

############################################################
# Create a library
############################################################

if(CMAKE_HOST_APPLE)
set(MACOSX_RPATH 1)
endif()

#Generate the shared library from the library sources
file(GLOB_RECURSE src_list "src/*.c*")

add_library(${PROJECT_NAME} MODULE ${src_list})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${VENDER_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${VENDER_DIR}/v8)
target_include_directories(${PROJECT_NAME} PUBLIC ${VENDER_DIR}/v8/include)

if(NOT flags)
	set(flags " ")
endif()
if(NOT cflags)
	set(cflags " ")
endif()
if(NOT ccflags)
	set(ccflags " ")
endif()

set(flags "${flags} -fsigned-char -fmessage-length=0 -fdata-sections -ffunction-sections -D_FILE_OFFSET_BITS=64")

set(flags "${flags} -fvisibility=hidden")

include(${VENDER_DIR}/tools/AddonSymbols.cmake)

if(addons_flags)
set(flags "${flags} -Wl,-U,${addons_flags}")
endif()

set(ccflags "${ccflags} -std=c++11")

if(${BUILD_TYPE} STREQUAL "release")
	set(flags "${flags} -O3 -s ${BUILD_OPTION} -w -fomit-frame-pointer")
	add_definitions(-DNDEBUG=1)
endif()

set(CMAKE_C_FLAGS "${flags}")
set(CMAKE_CXX_FLAGS "${flags} ${ccflags}")

if(NOT DEFINED CMAKE_C_COMPILER)
set(CMAKE_C_COMPILER clang)
endif()

if(NOT DEFINED CMAKE_CXX_COMPILER)
set(CMAKE_CXX_COMPILER clang++)
endif()