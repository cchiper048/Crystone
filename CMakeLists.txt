cmake_minimum_required(VERSION 3.22)
project(Qhilius)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/Qhilius/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Qhilius/*.h ${CMAKE_CURRENT_SOURCE_DIR}/test/*.h ${SDL2_INCLUDE_DIRS})

add_executable(Qhilius ${sources})

target_link_libraries(Qhilius ${SDL2_LIBRARIES} -ldl -lpthread)
