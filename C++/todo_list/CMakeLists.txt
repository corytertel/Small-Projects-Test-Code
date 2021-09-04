cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS_DEBUG "_UNSET" CACHE STRING "")

project(main VERSION 1.0)
add_executable(${PROJECT_NAME} main.cpp cmdarg.hpp cmdarg.cpp)

#if(${CMAKE_CXX_FLAGS_DEBUG} STREQUAL "_UNSET")
#    # Do some compiler switching here and then set your flags with FORCE.
#    set(CMAKE_CXX_FLAGS_DEBUG "-g3 -pthread -gdwarf-4 -fPIC -Wno-deprecated -pipe -fno-elide-type -fdiagnostics-show-template-tree -Wall -Werror -Wextra -Wpedantic -Wvla -Wextra-semi -Wnull-dereference -Wswitch-enum -Wduplicated-cond -Wduplicated-branches -Wsuggest-override -O0 -MMD -MP -Wno-gnu-include-next -Wno-unused-variable -Wno-unused-parameter -rdynamic" CACHE STRING "" FORCE)
#endif()