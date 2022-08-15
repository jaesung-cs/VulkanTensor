cmake_minimum_required(VERSION 3.18)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(vten)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(Vulkan REQUIRED)

add_subdirectory(dependencies/VulkanMemoryAllocator)

# vten
file(GLOB_RECURSE VTEN_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/vten/*.cc)
file(GLOB_RECURSE VTEN_INCLUDE_FILES
  ${PROJECT_SOURCE_DIR}/include/vten/*.h
)

add_library(vten
  ${VTEN_SOURCE_FILES}
  ${VTEN_INCLUDE_FILES}
)

target_include_directories(vten
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(vten
  Vulkan::Vulkan
  VulkanMemoryAllocator
)

# test
add_executable(vten_test
  test/main.cc
)

target_link_libraries(vten_test
  vten
)
