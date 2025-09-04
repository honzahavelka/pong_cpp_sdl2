#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include "game_states/menu.h"
#include "game_states/pvp.h"
#include "game_states/pvc.h"


enum Game_State {
    MENU,
    PVP,
    PVC,
    END
};

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height);
    void run();
    void clean();
    void handle_events();
    void update();
    void render();

    void change_state(Game_State state);

    bool is_running() { return running; };

private:
    bool running = false;
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *font;
    Game_State game_state = MENU;

    std::unique_ptr<Menu> menu;
    std::unique_ptr<Pvp> pvp;
    std::unique_ptr<Pvc> pvc;
};



#endif //GAME_H
