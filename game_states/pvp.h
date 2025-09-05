#ifndef PVP_H
#define PVP_H

#include "scenes.h"
#include "../game_logic/paddle.h"
#include "../game_logic/ball.h"

class Game;

class Pvp : public Scenes {
public:
    explicit Pvp(Game* game);
    ~Pvp() override;

    void handle_events(SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer *renderer, TTF_Font *font) override;

private:
    Game* game;
    Paddle* right_paddle;
    Paddle* left_paddle;
    Ball* ball;
};



#endif //PVP_H
