cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(lexical_analyzer VERSION 1.0)
add_executable(${PROJECT_NAME} inputbuf.h inputbuf.cc lexer.h lexer.cc parser.h parser.cc)
