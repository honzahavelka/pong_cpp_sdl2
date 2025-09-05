#include "score.h"
#include <string>

Score::Score() {
    right_score = left_score = 0;
}

Score::~Score() = default;

void Score::update_right() {
    ++right_score;
}

int Score::get_left_score() {
    return left_score;
}

int Score::get_right_score() {
    return right_score;
}

void Score::restart() {
    right_score = left_score = 0;
}

void Score::update_left() {
    ++left_score;
}

void Score::draw(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color white = {255, 255, 255, 255};

    std::string left_text = std::to_string(left_score);
    SDL_Surface* left_surface = TTF_RenderText_Solid(font, left_text.c_str(), white);
    SDL_Texture* left_texture = SDL_CreateTextureFromSurface(renderer, left_surface);

    int lw, lh;
    SDL_QueryTexture(left_texture, nullptr, nullptr, &lw, &lh);
    SDL_Rect left_rect = {180 - lw / 2, 20, lw, lh};

    SDL_RenderCopy(renderer, left_texture, nullptr, &left_rect);

    SDL_FreeSurface(left_surface);
    SDL_DestroyTexture(left_texture);

    std::string right_text = std::to_string(right_score);
    SDL_Surface* right_surface = TTF_RenderText_Solid(font, right_text.c_str(), white);
    SDL_Texture* right_texture = SDL_CreateTextureFromSurface(renderer, right_surface);

    int rw, rh;
    SDL_QueryTexture(right_texture, nullptr, nullptr, &rw, &rh);
    SDL_Rect right_rect = {540 - rw / 2, 20, rw, rh};

    SDL_RenderCopy(renderer, right_texture, nullptr, &right_rect);

    SDL_FreeSurface(right_surface);
    SDL_DestroyTexture(right_texture);

}
