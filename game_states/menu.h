#ifndef MENU_H
#define MENU_H

#include "scenes.h"

#include <string>
#include <vector>

class Game;

class Menu : public Scenes {
public:

    explicit Menu(Game* game);
    ~Menu() override;

    void handle_events(SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer, TTF_Font* font) override;

private:
    Game* game;

    std::vector<std::string> options;
    int selected_option = 0;
};



#endif //MENU_H
