cmake_minimum_required(VERSION 2.6)

include_directories(
    "${PROJECT_SOURCE_DIR}/../v8"
    "${PROJECT_SOURCE_DIR}/../v8/include"
)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	set(link_flags "${link_flags} -lkernel32")
endif()

include(../tools/Library.cmake)