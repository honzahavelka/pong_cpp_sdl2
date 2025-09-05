#ifndef COLLISION_H
#define COLLISION_H

#include <SDL.h>
class Collision {
public:
    static bool hit_wall(SDL_Rect& ball_position, int y_min, int y_max);
    static bool hit_paddle(SDL_Rect& ball_position, SDL_Rect& paddle_position);
    static bool scored_left(SDL_Rect& ball_position, int x_min);
    static bool scored_right(SDL_Rect& ball_position, int x_max);
};



#endif //COLLISION_H
