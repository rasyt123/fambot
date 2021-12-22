cmake_minimum_required(VERSION 3.21)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp Game.cpp Game.h Player.cpp Player.h Move.cpp Move.h Pieces.cpp Pieces.h menu.cpp menu.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Chess sfml-system sfml-window sfml-graphics sfml-audio)