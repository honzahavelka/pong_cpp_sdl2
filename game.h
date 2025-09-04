#ifndef GAME_H
#define GAME_H

#include <SDL.h>

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

    bool is_running() { return running; };

private:
    bool running = false;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Game_State game_state = MENU;
};



#endif //GAME_H
