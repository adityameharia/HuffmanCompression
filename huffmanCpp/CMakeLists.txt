cmake_minimum_required(VERSION 3.12)
project(huffmanCompression)
set(CMAKE_CXX_STANDARD 17)
add_executable(
    huffmanCompression
    main.cpp
    include/compress.h
    src/compress.cpp
    include/decompress.hpp    
)