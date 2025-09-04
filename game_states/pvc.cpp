#include "pvc.h"


Pvc::Pvc(Game *game) {
    this->game = game;
}

Pvc::~Pvc() = default;

void Pvc::handle_events(SDL_Event &event) {

}

void Pvc::update() {

}

void Pvc::render(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color color = {200, 200, 200, 255};

    SDL_Surface* text_surface = TTF_RenderText_Blended(font, "PvC", color);
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_FreeSurface(text_surface);

    int text_w, text_h;
    SDL_QueryTexture(text_texture, nullptr, nullptr, &text_w, &text_h);

    SDL_Rect rect = {340, 100, text_w, text_h};
    SDL_RenderCopy(renderer, text_texture, nullptr, &rect);
    SDL_DestroyTexture(text_texture);
}

