cmake_minimum_required(VERSION 2.8)
project(cb20Test)

find_package(EEROS REQUIRED)
include_directories(${EEROS_INCLUDE_DIR};${EEROS_LIBUCL_INCLUDE_DIR})
link_directories(${EEROS_LIB_DIR};${EEROS_LIBUCL_LINK_DIR})

# Additional include and link directories
# include_directories(${ADDITIONAL_INCLUDE_DIRS})
# link_directories(${ADDITIONAL_LINK_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(cb20Test Cb20Test.cpp)
target_link_libraries(cb20Test eeros ${CMAKE_DL_LIBS} ucl pthread)

