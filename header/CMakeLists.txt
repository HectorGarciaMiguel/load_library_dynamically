cmake_minimum_required(VERSION 3.16)
project(header LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core )
link_directories(${CMAKE_SOURCE_DIR})

qt_add_executable(header
    main.cpp
)

target_link_libraries(header PUBLIC
    Qt::Core
    core
)
