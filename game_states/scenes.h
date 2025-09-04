#ifndef SCENES_H
#define SCENES_H

#include <SDL.h>
#include <SDL_ttf.h>

class Scenes {
public:
    virtual ~Scenes() = default;
    virtual void handle_events(SDL_Event& event) {};
    virtual void update() {};
    virtual void render(SDL_Renderer* renderer, TTF_Font* font) {};
};

#endif //SCENES_H
