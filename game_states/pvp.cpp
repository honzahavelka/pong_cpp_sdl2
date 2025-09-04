#include "pvp.h"


Pvp::Pvp(Game *game) {
    this->game = game;
}

Pvp::~Pvp() = default;

void Pvp::handle_events(SDL_Event &event) {
}

void Pvp::update() {
}

void Pvp::render(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color color = {200, 200, 200, 255};

    SDL_Surface* text_surface = TTF_RenderText_Blended(font, "PvP", color);
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_FreeSurface(text_surface);

    int text_w, text_h;
    SDL_QueryTexture(text_texture, nullptr, nullptr, &text_w, &text_h);

    SDL_Rect rect = {340, 100, text_w, text_h};
    SDL_RenderCopy(renderer, text_texture, nullptr, &rect);
    SDL_DestroyTexture(text_texture);
}


