cmake_minimum_required(VERSION 3.16)
project(core LANGUAGES CXX)

add_library(core SHARED core.cpp core.h exports.h)
