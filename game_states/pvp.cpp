#include "pvp.h"

#include <iostream>
#include <ostream>

Pvp::Pvp(Game *game) {
    this->game = game;
    this->left_paddle = new Paddle(0, true);
    this->right_paddle = new Paddle(1, true);
    this->ball = new Ball(360, 240);
}

Pvp::~Pvp() = default;

void Pvp::handle_events(SDL_Event &event) {

}

void Pvp::update() {
    const Uint8* keystates = SDL_GetKeyboardState(nullptr);

    if (keystates[SDL_SCANCODE_W]) {
        left_paddle->move(-1);
    }
    if (keystates[SDL_SCANCODE_S]) {
        left_paddle->move(1);
    }
    if (keystates[SDL_SCANCODE_UP]) {
        right_paddle->move(-1);
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        right_paddle->move(1);
    }

    ball->update();


}

void Pvp::render(SDL_Renderer *renderer, TTF_Font *font) {
    left_paddle->draw(renderer);
    right_paddle->draw(renderer);
    ball->draw(renderer);
}
