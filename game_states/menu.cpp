#include "menu.h"
#include "../game.h"

Menu::Menu(Game* game) {
    this->game = game;

    options.push_back("2 players");
    options.push_back("vs computer");
    options.push_back("pc vs pc");
}

Menu::~Menu() = default;


void Menu::handle_events(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_DOWN:
                selected_option = (selected_option + 1) % static_cast<int>(options.size());
            break;
            case SDLK_RETURN:
                if (selected_option == 0) {
                    game->change_state(PVP, true, true);
                }
                else if (selected_option == 1) {
                    game->change_state(PVP, false, true);
                }
                else if (selected_option == 2) {
                    game->change_state(PVP, false, false);
                }
            default: break;
        }
    }
}

void Menu::update() {
}

void Menu::render(SDL_Renderer* renderer, TTF_Font* font) {
    for (int i = 0; i < options.size(); ++i) {
        SDL_Rect rect = {260, 100 + 70 * i, 200, 40};
        SDL_Color text_color;
        if (i == selected_option) {
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
            SDL_RenderDrawRect(renderer, &rect);
            text_color = {50, 50, 50, 255};
        }
        else {
            SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_RenderDrawRect(renderer, &rect);
            text_color = {200, 200, 200, 255};
        }

        SDL_Surface* text_surface = TTF_RenderText_Blended(font, options[i].c_str(), text_color);
        SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
        SDL_FreeSurface(text_surface);

        int text_w, text_h;
        SDL_QueryTexture(text_texture, nullptr, nullptr, &text_w, &text_h);

        SDL_Rect textRect;
        textRect.x = rect.x + (rect.w - text_w) / 2;
        textRect.y = rect.y + (rect.h - text_h) / 2;
        textRect.w = text_w;
        textRect.h = text_h;

        SDL_RenderCopy(renderer, text_texture, nullptr, &textRect);
        SDL_DestroyTexture(text_texture);
    }
}