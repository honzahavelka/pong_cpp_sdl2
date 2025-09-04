#include "game.h"

int main() {
    auto game = new Game();;
    game->init("pong", 720, 480);
    game->run();
    game->clean();
    return 0;
}