cmake_minimum_required(VERSION 3.16)
project(runtime_native LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core )
link_directories(${CMAKE_SOURCE_DIR})

qt_add_executable(runtime_native
    main.cpp
)

target_link_libraries(runtime_native PUBLIC
    Qt::Core
)
