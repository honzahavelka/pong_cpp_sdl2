#include "collision.h"


bool Collision::hit_wall(SDL_Rect &ball_position, int y_min, int y_max) {
    if (ball_position.y <= y_min ||
        ball_position.y + ball_position.h >= y_max) {
        return true;
    }
    return false;
}

bool Collision::hit_paddle(SDL_Rect& paddle_position, SDL_Rect& ball_position) {
    if (paddle_position.x + paddle_position.w >= ball_position.x &&
        paddle_position.x <= ball_position.x + ball_position.w &&
        paddle_position.y + paddle_position.h >= ball_position.y &&
        paddle_position.y <= ball_position.y + ball_position.h) {
        return true;
    }
    return false;
}
