cmake_minimum_required(VERSION 3.13)
project(lib)

set(CMAKE_C_STANDARD 99)

add_executable(lib
        ./chapter3/3.2/file_with_hole.c ./chapter3/pread-and-pwrite.c
        ./chapter3/3.5/3.5-copy-standard-input-to-standard-output.c
        ./chapter7/test.c ./chapter7/7.4.c ./chapter7/effect-of-longjmp-on-various-types-of-variables.c
        ./chapter8/fork-example.c
        )