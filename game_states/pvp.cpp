#include "pvp.h"

#include <iostream>
#include <ostream>

#include "../game_logic/collision.h"

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

    if (Collision::hit_wall(ball->get_ball_position(), 0, 480))
        ball->invert_y();
    if (Collision::hit_paddle(ball->get_ball_position(), left_paddle->get_paddle_pos())) {
        ball->speed_up();
        ball->bounce_from_paddle(left_paddle->get_paddle_pos(), true);
    }
    if (Collision::hit_paddle(ball->get_ball_position(), right_paddle->get_paddle_pos())) {
        ball->speed_up();
        ball->bounce_from_paddle(right_paddle->get_paddle_pos(), false);
    }

    ball->update();
}

void Pvp::render(SDL_Renderer *renderer, TTF_Font *font) {
    left_paddle->draw(renderer);
    right_paddle->draw(renderer);
    ball->draw(renderer);
}
