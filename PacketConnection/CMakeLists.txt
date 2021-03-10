#==============================
# Requirements
#==============================

cmake_minimum_required(VERSION 3.10)

#==============================
# Unit Settings
#==============================

set(TARGET_NAME "PacketConnection")

#==============================
# Command Lines
#==============================

set(CMAKE_CXX_STANDARD 17)

#==============================
# Source
#==============================

#------------------------------
# C++
#------------------------------
# C++ Source Files
file(GLOB_RECURSE TARGET_SOURCE "*.cpp")
# C++ Header Files
file(GLOB_RECURSE TARGET_HEADER "*.hpp")

#==============================
# Compile Targets
#==============================

# To lower the running cost, this module will be compiled as a static library.
add_library(${TARGET_NAME} STATIC ${TARGET_SOURCE} ${TARGET_HEADER} ${TARGET_CUDA_SOURCE} ${TARGET_CUDA_HEADER} ../ChannelConneciton/Channel.cpp ../ChannelConneciton/Channel.hpp)

# Enable 'DEBUG' Macro in Debug Mode
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    target_compile_definitions(${TARGET_NAME} PRIVATE  -DDEBUG)
endif()

#==============================
# Dependencies
#==============================

# Boost
find_package(Boost 1.71 REQUIRED COMPONENTS system)
target_include_directories(${TARGET_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} PUBLIC ${Boost_LIBRARIES})

# In Linux, 'Threads' need to explicitly linked.
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(Threads)
    target_link_libraries(${TARGET_NAME} PUBLIC ${CMAKE_THREAD_LIBS_INIT})
endif()