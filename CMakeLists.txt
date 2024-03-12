cmake_minimum_required(VERSION 3.5)
project(CSV-JSON-Converter)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 20)

add_executable(Main
    Header-Files/Header.h
    Header-Files/CSV_JSON.h
    Header-Files/Err_Codes.h
    Source-Files/CSV_JSON.cpp
    Source-Files/main.cpp
)

set_target_properties(Main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Output"
)