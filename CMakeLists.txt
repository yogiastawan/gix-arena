cmake_minimum_required(VERSION 3.10.0)
project(gix-arena VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/Wall)
    add_compile_options(/Wextra)
    # add_compile_options(/Werror)
else()
    add_compile_options(-Wall)
    add_compile_options(-Wextra)
    # add_compile_options(-Werror)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(BUILD_DEBUG)
endif()

# Build options
option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_STATIC "Build static library" ON)
option(BUILD_SHARED "Build static library" ON)

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "BUILD_EXAMPLES: ${BUILD_EXAMPLES}")
message(STATUS "BUILD_STATIC: ${BUILD_STATIC}")
message(STATUS "BUILD_SHARED: ${BUILD_SHARED}")

# Versioning
add_compile_definitions(GIX_ARENA_MAJOR_VERSION=${PROJECT_VERSION_MAJOR})
add_compile_definitions(GIX_ARENA_MINOR_VERSION=${PROJECT_VERSION_MINOR})
add_compile_definitions(GIX_ARENA_PATCH_VERSION=${PROJECT_VERSION_PATCH})
add_compile_definitions(GIX_ARENA_VERSION="${PROJECT_VERSION}")

# Add library source
add_subdirectory(src)
# type of library to build
if(BUILD_STATIC)
    target_include_directories(${PROJECT_NAME}-static PUBLIC ${PROJECT_SOURCE_DIR}/src/include)
endif()
if(BUILD_SHARED)
    target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/include)
endif()

# Examples
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif(BUILD_EXAMPLES)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
