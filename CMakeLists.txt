cmake_minimum_required(VERSION 3.10)

project(learn-sip LANGUAGES CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -static-libasan")

add_compile_definitions(
        SPDLOG_COMPILED_LIB
        SPDLOG_ACTIVE_LEVEL=0
)

include_directories(
        include
        src
)
link_directories(lib)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
