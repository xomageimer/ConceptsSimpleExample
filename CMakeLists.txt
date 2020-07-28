cmake_minimum_required(VERSION 3.5)
project(hellworld)

add_executable(std20 test20std.cpp)

set_target_properties(std20  PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-fsanitize=thread"
        LINK_OPTIONS "-fsanitize=thread"
        )

