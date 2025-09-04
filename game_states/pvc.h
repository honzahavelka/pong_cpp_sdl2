#ifndef PVC_H
#define PVC_H

#include "scenes.h"


class Game;

class Pvc : public Scenes {
public:
    explicit Pvc(Game *game);
    ~Pvc() override;

    void handle_events(SDL_Event &event) override;
    void update() override;
    void render(SDL_Renderer *renderer, TTF_Font *font) override;

private:
    Game *game;
};


#endif //PVC_H
