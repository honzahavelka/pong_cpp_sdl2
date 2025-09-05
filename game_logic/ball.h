#ifndef BALL_H
#define BALL_H
#include <SDL_render.h>


class Ball {

public:
    Ball(float x, float y);
    ~Ball();

    void draw(SDL_Renderer *renderer);
    void update();
    void invert_y();
    void bounce_from_paddle(SDL_Rect& paddle_position, bool is_left_paddle);
    void speed_up();
    void restart(float x, float y);

    float get_x_velocity();
    float get_y_velocity();

    SDL_Rect &get_ball_position();
private:
    SDL_Rect rect {};
    float x_pos, y_pos;
    float x_vel, y_vel;
    float speed;
};



#endif //BALL_H
