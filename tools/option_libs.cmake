if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    cmake_policy(SET CMP0091 NEW)

    target_link_libraries(${name} winmm ws2_32 psapi dbghelp shlwapi urlmon
         userenv advapi32 kernel32 psapi iphlpapi userenv ws2_32)

    # find_library(libcmt libcmt "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.16.27023\\lib\\x64")
    # target_link_libraries(${name} libcmt)
    # find_library(msvcrt msvcrt "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.16.27023\\lib\\x64")
    # target_link_libraries(${name} msvcrt)

    # find_library(ucrt ucrt "C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.17763.0\\ucrt\\x64")
    # target_link_libraries(${name} ucrt)
    
    # find_library(vcruntime vcruntime "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.16.27023\\lib\\x64")
    # target_link_libraries(${name} vcruntime)
else()
    if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin")
        target_link_libraries(${name} dl iconv stdc++)
    elseif(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
        target_link_libraries(${name} dl rt)
    elseif(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "FreeBSD")
        find_library(execinfo execinfo "/usr/local/lib" "/usr/lib")
        target_link_libraries(${name} ${execinfo})
    endif()

	target_link_libraries(${name} pthread)
    if(NOT HAVE_GLIB_C_ATOMIC_H)
        target_link_libraries(${name} atomic)
    endif()
endif()
