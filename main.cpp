#include "game.h"

int main() {
    auto game = new Game();;
    game->init("pong", 800, 600);
    game->run();
    game->clean();
    return 0;
}