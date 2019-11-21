cmake_minimum_required(VERSION 3.14)
project(technoStandart)

set(CMAKE_CXX_STANDARD 14)

add_executable(technoStandart main.cpp PackFrameProcessor.cpp PackFrameProcessor.h PackFrame.h ByteGenerator.cpp ByteGenerator.h)