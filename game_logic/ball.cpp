#include "ball.h"


Ball::Ball(int x, int y) {
    x_pos = x;
    y_pos = y;
    x_vel = 3;
    y_vel = 0;
    speed = 3;
}

Ball::~Ball() = default;

void Ball::update() {
    x_pos += x_vel;
    y_pos += y_vel;
}

void Ball::invert_y() {
    y_vel = -y_vel;
}

void Ball::bounce_from_paddle(SDL_Rect& paddle_position, bool is_left_paddle) {
    int paddle_center = paddle_position.y + paddle_position.h / 2;
    int difference = y_pos - paddle_center;
    float normalize = difference / (paddle_position.h / 2);

    float max_angle = M_PI / 4;
    float angle = normalize * max_angle;

    float direction = is_left_paddle ? 1.0f : -1.0f;

    x_vel = direction * speed * cos(angle);
    y_vel = speed * sin(angle);
}


void Ball::draw(SDL_Renderer *renderer) {
    rect.x = x_pos - 5;
    rect.y = y_pos - 5;
    rect.w = 10;
    rect.h = 10;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

