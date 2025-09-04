#ifndef PVP_H
#define PVP_H

#include "scenes.h"

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
};



#endif //PVP_H
