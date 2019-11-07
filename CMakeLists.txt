cmake_minimum_required(VERSION 3.0)

project(NoXGeometry)
set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)
set (${PROJECT_NAME}_VERSION_PATCH 1)


# PATCH NAME CREATE
set (${PROJECT_NAME}_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}")
# Check for 0 patch
if (${PROJECT_NAME}_VERSION_PATCH) 
  set (${PROJECT_NAME}_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}")
endif()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src_lib)

add_library(SimpleNoXG STATIC
  src_lib/StdNXG.cpp
  src_lib/SimpleGeom.cpp
)

add_library(NoXGMenu STATIC
  src_lib/NoXGMenu.cpp
)


message("CREATE PROJECT = [${PROJECT_NAME}]. VERSION = [${${PROJECT_NAME}_VERSION}]")

add_executable("${PROJECT_NAME}${${PROJECT_NAME}_VERSION}" src/main.cpp)
add_executable("${PROJECT_NAME}_menu" src/menu.cpp)

target_link_libraries("${PROJECT_NAME}${${PROJECT_NAME}_VERSION}"
  PRIVATE
    SimpleNoXG
)

target_link_libraries("${PROJECT_NAME}_menu"
  PRIVATE
   NoXGMenu
)
