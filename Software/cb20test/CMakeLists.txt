cmake_minimum_required(VERSION 2.8)
project(can-eeros-test)

find_package(EEROS REQUIRED)
include_directories(${EEROS_INCLUDE_DIR})
link_directories(${EEROS_LIB_DIR})

find_package(flink REQUIRED)
include_directories(${FLINK_INCLUDE_DIR})
link_directories(${FLINK_LIB_DIR})

# Additional include and link directories
include_directories(${ADDITIONAL_INCLUDE_DIRS})
link_directories(${ADDITIONAL_LINK_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(cb20test Cb20Test.cpp
				  control/Cb20ControlSystem.cpp

				  sequences/Cb20TestMainSequence.cpp
				  safety/Cb20SafetyProperties.cpp
		       )

target_link_libraries(cb20test eeros cb20)
INSTALL(TARGETS cb20test RUNTIME DESTINATION bin)

