#include "ball.h"


Ball::Ball(float x, float y) {
    x_pos = x;
    y_pos = y;
    x_vel = 3.0f;
    y_vel = 0.0f;
    speed = 10.0f;
    rect.w = 10;
    rect.h = 10;
    update();
}

void Ball::restart(float x, float y) {
    x_pos = x;
    y_pos = y;
    x_vel = 3.0f;
    y_vel = 0.0f;
    speed = 10.0f;
    rect.w = 10;
    rect.h = 10;
}

Ball::~Ball() = default;

void Ball::update() {
    x_pos += x_vel;
    y_pos += y_vel;
    rect.x = static_cast<int>(x_pos - 5.0f);
    rect.y = static_cast<int>(y_pos - 5.0f);
}

void Ball::invert_y() {
    y_vel = -y_vel;
}

void Ball::bounce_from_paddle(SDL_Rect& paddle_position, bool is_left_paddle) {
    int paddle_center = paddle_position.y + paddle_position.h / 2;
    float difference = y_pos - static_cast<float>(paddle_center);
    float normalize = difference / (static_cast<float>(paddle_position.h) / 2);

    float max_angle = M_PI / 4;
    float angle = normalize * max_angle;

    float direction = is_left_paddle ? 1.0f : -1.0f;

    x_vel = direction * speed * cos(angle);
    y_vel = speed * sin(angle);
}

SDL_Rect &Ball::get_ball_position() {
    return rect;
}


void Ball::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Ball::speed_up() {
    speed += 0.3f;
}

float Ball::get_x_velocity() {
    return x_vel;
}

float Ball::get_y_velocity() {
    return y_vel;
}

