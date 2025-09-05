#ifndef PVP_H
#define PVP_H

#include <memory>
#include "scenes.h"
#include "../game_logic/paddle.h"
#include "../game_logic/ball.h"
#include "../game_logic/score.h"

class Game;

class Pvp : public Scenes {
public:
    explicit Pvp(Game* game, bool left_is_human, bool right_is_human);
    ~Pvp() override;

    void handle_events(SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer *renderer, TTF_Font *font) override;
    bool is_winner(int score);
    void restart();

private:
    bool finished;
    bool paused;
    Game* game;
    std::unique_ptr<Paddle> right_paddle;
    std::unique_ptr<Paddle> left_paddle;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<Score> score;
};

#endif
