cmake_minimum_required(VERSION 3.30)
project(pong)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        /opt/homebrew/opt/sdl2/include/SDL2
        /opt/homebrew/opt/sdl2_image/include/SDL2
        /opt/homebrew/opt/sdl2_ttf/include/SDL2
)

link_directories(
        /opt/homebrew/opt/sdl2/lib
        /opt/homebrew/opt/sdl2_image/lib
        /opt/homebrew/opt/sdl2_ttf/lib
)

add_executable(pong main.cpp
        game.cpp
        game.h
        game_states/scenes.h)


target_link_libraries(pong
        SDL2
        SDL2_image
        SDL2_ttf
)
