cmake_minimum_required(VERSION 2.6)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	set(CXX_STD_VER_FLAG "-std=c++14")
	add_definitions(-fno-strict-aliasing -fno-short-enums)
	add_definitions(-D_UNICODE -DUNICODE)
	# @warning on Windows, v8 at this version could emit a big deal of DBG about symbols
	# so we enable at lease -O2 level optimization
	if(NOT ${BUILD_TYPE} STREQUAL "release")
		set(flags "${flags} -O2")
	endif()
	
	include_directories(
		${PROJECT_SOURCE_DIR}
		"${PROJECT_SOURCE_DIR}/src"
		"${PROJECT_SOURCE_DIR}/include"
		"${PROJECT_SOURCE_DIR}/../"
	)
else()
	include_directories("/usr/local/include/")
endif()

set(ICU_ROOT_DIR "${PROJECT_SOURCE_DIR}/../icu")

set(ICU_ROOT "${ICU_ROOT_DIR}/source/common")

# set(ICU_DEBUG True)

# include(FindICU)

# message("ICU_INCLUDE_DIR is ${ICU_INCLUDE_DIR}")
# message("ICU_FOUND is ${ICU_FOUND}")
# message("ICU_VERSION is ${ICU_VERSION}")
# message("ICU_GENCNVAL_EXECUTABLE is ${ICU_GENCNVAL_EXECUTABLE}")

# icu about :start
include_directories("${ICU_ROOT_DIR}/source/common")
include_directories("${ICU_ROOT_DIR}/source/i18n")
# icu about :end

file(GLOB_RECURSE src_list
	"src/*.c*"
	# icu about :start
	"${ICU_ROOT_DIR}/source/common/*.c*"
	"${ICU_ROOT_DIR}/source/i18n/*.c*"
	"${ICU_ROOT_DIR}/source/stubdata/*.c*"
	# icu about :end
)

include(../tools/Library.cmake)

add_definitions(
	# icu about :start
	-DU_COMMON_IMPLEMENTATION=1
	# -DU_ICUDATAENTRY_IN_COMMON=1
	-DU_I18N_IMPLEMENTATION=1
	-DU_STATIC_IMPLEMENTATION=1
	-DUNISTR_FROM_CHAR_EXPLICIT=
	-DUNISTR_FROM_STRING_EXPLICIT=
	# icu about :end
	-DV8_INTL_SUPPORT=1
	-DV8_NO_FAST_TLS=1
	-DV8_DEPRECATION_WARNINGS=1
	-DV8_CONCURRENT_MARKING=1
	-DENABLE_HANDLE_ZAPPING=1
	-DDISABLE_UNTRUSTED_CODE_MITIGATIONS=1
)

if(${OS} STREQUAL "Windows")
	add_definitions(
		-DICU_UTIL_DATA_IMPL=1 # ICU_UTIL_DATA_SHARED=1
	)
else()
	add_definitions(
		-DICU_UTIL_DATA_IMPL=0 # ICU_UTIL_DATA_FILE=0
		# -DICU_UTIL_DATA_IMPL=2 # ICU_UTIL_DATA_STATIC=2
	)
endif()

if(${OS} STREQUAL "Windows")
	# always disable debug for MSVC(1925, VS 2019) + v8(6.9), maybe cancel in the future
	# add_definitions(-DNDEBUG)	
	if(${BUILD_TYPE} STREQUAL "debug")
		add_definitions(-DDEBUG)	
		set_property(TARGET ${name} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDllDebug")
	elseif(${BUILD_TYPE} STREQUAL "release")
		set_property(TARGET ${name} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded")
	endif()
else()
	if(${BUILD_TYPE} STREQUAL "Debug")
		add_definitions(
			-DVERIFY_HEAP=1
			-DOBJECT_PRINT=1
			-DENABLE_DISASSEMBLER=1
			-DV8_ENABLE_CHECKS=1
			-DTRACE_MAPS=1
			-DENABLE_SLOW_DCHECKS=1
		)
	endif()
endif()
