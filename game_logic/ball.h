#ifndef BALL_H
#define BALL_H
#include <SDL_render.h>


class Ball {

public:
    Ball(int x, int y);
    ~Ball();

    void draw(SDL_Renderer *renderer);
    void update();
    void invert_y();
    void bounce_from_paddle(SDL_Rect& paddle_position, bool is_left_paddle);

private:
    SDL_Rect rect;
    int x_pos, y_pos;
    int x_vel, y_vel;
    int speed;
};



#endif //BALL_H
