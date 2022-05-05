cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Factory VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(factory 
               factory/conveyor.cpp
               factory/inventory-sink.cpp
               factory/inventory-source.cpp
               factory/logger.cpp
               factory/main.cpp
               factory/node.cpp
               factory/port.cpp
               factory/system.cpp
               )

target_include_directories(factory PUBLIC
                           "factory")