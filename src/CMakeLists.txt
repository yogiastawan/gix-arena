cmake_minimum_required(VERSION 3.10.0)

set(srcs gix_arena_impl.c gix_arena_version.c)

if(BUILD_STATIC)
    add_library(${PROJECT_NAME}-static STATIC ${srcs})
    set_target_properties(${PROJECT_NAME}-static
        PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
        OUTPUT_NAME ${PROJECT_NAME})
   
endif()
if(BUILD_SHARED)
    add_library(${PROJECT_NAME} SHARED ${srcs})
    set_target_properties(${PROJECT_NAME}
        PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
        OUTPUT_NAME ${PROJECT_NAME})
endif()
