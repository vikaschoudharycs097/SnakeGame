cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

set(CXX_FLAGS "-std=c++11 -Wall -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SnakeGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(snake src/main.cpp src/game.cpp src/rat.cpp src/renderer.cpp src/snake.cpp src/animal.cpp)
target_link_libraries(snake ${SDL2_LIBRARIES} "-lSDL2_ttf")
