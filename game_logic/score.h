#ifndef SCORE_H
#define SCORE_H
#include <SDL_render.h>
#include <SDL_ttf.h>


class Score {
public:
    Score();
    ~Score();

    void draw(SDL_Renderer* renderer, TTF_Font* font);
    void update_left();
    void update_right();
    int get_left_score();
    int get_right_score();
    void restart();

private:
    int right_score, left_score;
};



#endif //SCORE_H
