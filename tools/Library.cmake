get_filename_component(name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${name})

include(${CMAKE_CURRENT_LIST_DIR}/option.cmake)

if(NOT DEFINED src_list)
	file(GLOB_RECURSE src_list "src/*.c*")
endif()
add_library(${name} ${src_list})

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../bin/${CMAKE_HOST_SYSTEM_NAME}_${ARCH}_${BUILD_TYPE})

set_target_properties(${name} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${LIBRARY_OUTPUT_PATH}"
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${LIBRARY_OUTPUT_PATH}"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${EXECUTABLE_OUTPUT_PATH}"
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${EXECUTABLE_OUTPUT_PATH}"
)

include_directories(${PROJECT_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/../")

link_libraries(${name}) 