#ifndef PADDLE_H
#define PADDLE_H

#include <SDL.h>

class Paddle {

public:
    explicit Paddle(int side, bool is_player);
    ~Paddle();

    void draw(SDL_Renderer *renderer);
    void move(int direction);
    SDL_Rect get_paddle_pos();

private:
    int y_position;
    int speed;
    bool is_player;
    SDL_Rect paddle_rect {};
};



#endif //PADDLE_H
