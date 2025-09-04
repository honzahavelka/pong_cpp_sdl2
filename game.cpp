#include "game.h"

#include <iostream>

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                width, height, 0);
    if (!window) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    std::cout << "Created window and renderer" << std::endl;
    running = true;
}

void Game::handle_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }

        switch (game_state) {
            case MENU: menu->handle_events(event); break;
            /*case PVP: pvp->handle_events(event); break;
            case PVC: pvc->handle_events(event); break;*/

            default:
                break;
        }
    }
}

void Game::update() {
    switch (game_state) {
        case MENU: menu->update(); break;
        /*case PVP: pvp->update(); break;
        case PVC: pvc->update(); break;*/

        default:
            break;
    }
}

void Game::render() {
    switch (game_state) {
        case MENU: menu->render(); break;
        /*case PVP: pvp->update(); break;
        case PVC: pvc->update(); break;*/

        default:
            break;
    }

}



void Game::run() {
    int fps = 60;
    int frame_delay = 1000 / fps;

    Uint32 frame_start;
    int frame_time;

    while (running) {
        frame_start = SDL_GetTicks();

        handle_events();
        update();
        render();

        frame_time = SDL_GetTicks() - frame_start;
        if (frame_delay > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }
    }
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}