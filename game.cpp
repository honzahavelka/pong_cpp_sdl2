#include "game.h"

#include <iostream>

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (TTF_Init() != 0) {
        std::cout << "TTF_Init error: " << TTF_GetError() << std::endl;
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

    font = TTF_OpenFont("../assets/roboto-font.ttf", 24);
    if (!font) {
        std::cout << "TTF_OpenFont error: " << TTF_GetError() << std::endl;
    }

    std::cout << "Created window, renderer, font" << std::endl;
    menu = std::make_unique<Menu>(this);
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
            case PVP: pvp->handle_events(event); break;

            default:
                break;
        }
    }
}

void Game::update() {
    switch (game_state) {
        case MENU: menu->update(); break;
        case PVP: pvp->update(); break;

        default:
            break;
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    switch (game_state) {
        case MENU: menu->render(renderer, font); break;
        case PVP: pvp->render(renderer, font); break;

        default:
            break;
    }

    SDL_RenderPresent(renderer);
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

void Game::change_state(Game_State state, bool left_is_human, bool right_is_human) {
    switch (game_state) {
        case PVP:
            pvp.reset();
            break;
        default:
            break;
    }

    game_state = state;

    switch (state) {
        case MENU:
            menu = std::make_unique<Menu>(this);
        break;
        case PVP:
            pvp = std::make_unique<Pvp>(this, left_is_human, right_is_human);
        break;
        default:
            break;
    }
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}