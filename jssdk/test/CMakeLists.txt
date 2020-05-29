cmake_minimum_required(VERSION 2.6)

include_directories(
    "${CMAKE_SOURCE_DIR}/../../v8"
    "${CMAKE_SOURCE_DIR}/../../v8/include"
)

set(libs v8 exlib)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)
    set(CMAKE_ENABLE_EXPORTS true)
endif()

include(../../tools/LibraryTest.cmake)
