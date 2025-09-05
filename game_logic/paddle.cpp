#include "paddle.h"

#include <iostream>

Paddle::Paddle(int side, bool is_player) {
    y_position = 192;
    speed = 10;
    if (side == 0) {
        paddle_rect = { 0,  y_position,  10, 96};
    }
    else if (side == 1) {
        paddle_rect = { 710, y_position,  10, 96};
    }
    else {
        std::cout << "invalid paddle side" << std::endl;
        exit(2);
    }
    this->is_player = is_player;
}

Paddle::~Paddle() = default;


void Paddle::move(int direction) {
    y_position += direction * speed;
    paddle_rect.y = y_position;
}

void Paddle::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &paddle_rect);
}

SDL_Rect& Paddle::get_paddle_pos() {
    return paddle_rect;
}

