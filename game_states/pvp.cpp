#include "pvp.h"

#include <iostream>
#include <ostream>

#include "../game.h"
#include "../game_logic/collision.h"

Pvp::Pvp(Game *game, bool left_is_human, bool right_is_human) {
    this->game = game;
    left_paddle = std::make_unique<Paddle>(0, left_is_human);
    right_paddle = std::make_unique<Paddle>(1, right_is_human);
    ball = std::make_unique<Ball>(360.0f, 240.0f);
    score = std::make_unique<Score>();
    paused = finished = false;
}

Pvp::~Pvp() = default;

void Pvp::handle_events(SDL_Event &event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_p:
                paused = !paused;
                break;
            case SDLK_r:
                restart();
                break;
            case SDLK_ESCAPE:
                game->change_state(MENU, false, false);
            default:
                break;
        }
    }
}

void Pvp::update() {
    if (paused) {
        return;
    }
    if (finished) {
        return;
    }

    const Uint8* keystates = SDL_GetKeyboardState(nullptr);

    if (left_paddle->is_human()) {
        if (keystates[SDL_SCANCODE_W]) {
            left_paddle->move(-1);
        }
        if (keystates[SDL_SCANCODE_S]) {
            left_paddle->move(1);
        }
    }
    else {
        SDL_Rect pos = ball->get_ball_position();
        left_paddle->auto_move(pos.y - 5);
    }
    if (right_paddle->is_human()) {
        if (keystates[SDL_SCANCODE_UP]) {
            right_paddle->move(-1);
        }
        if (keystates[SDL_SCANCODE_DOWN]) {
            right_paddle->move(1);
        }
    }
    else {
        SDL_Rect pos = ball->get_ball_position();
        right_paddle->auto_move(pos.y - 5);
    }

    SDL_Rect ball_possition = ball->get_ball_position();
    float x_velocity = ball->get_x_velocity();
    float y_velocity = ball->get_y_velocity();

    float steps = std::max(fabs(x_velocity), fabs(y_velocity));
    float step_x = x_velocity / steps;
    float step_y = y_velocity / steps;

    for (int i = 0; i < steps; ++i) {
        ball_possition.x += step_x;
        ball_possition.y += step_y;
        if (Collision::hit_wall(ball_possition, 0, 480)) {
            ball->invert_y();
            break;
        }
        if (Collision::hit_paddle(ball_possition, left_paddle->get_paddle_pos())) {
            ball->speed_up();
            ball->bounce_from_paddle(left_paddle->get_paddle_pos(), true);
            break;
        }
        if (Collision::hit_paddle(ball_possition, right_paddle->get_paddle_pos())) {
            ball->speed_up();
            ball->bounce_from_paddle(right_paddle->get_paddle_pos(), false);
            break;
        }
        if (Collision::scored_left(ball_possition, 0)) {
            score->update_right();
            ball->restart(360.0f, 240.0f);
            if (is_winner(score->get_right_score())) finished = true;
            break;
        }
        if (Collision::scored_right(ball->get_ball_position(), 720)) {
            score->update_left();
            ball->restart(360.0f, 240.0f);
            if (is_winner(score->get_left_score())) finished = true;
            break;
        }
    }
    ball->update();
}

void Pvp::render(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderDrawLine(renderer, 720 / 2, 0, 720 / 2, 480);

    if (paused) {
        SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
        SDL_Rect rect;
        rect.x = 320;
        rect.y = 180;
        rect.w = 30;
        rect.h = 125;
        SDL_RenderFillRect(renderer, &rect);
        rect.x = 370;
        rect.y = 180;
        rect.w = 30;
        rect.h = 125;
        SDL_RenderFillRect(renderer, &rect);
    }

    if (finished) {
        const char* winnerText = nullptr;
        if (score->get_left_score() > score->get_right_score()) {
            winnerText = "Left Player Wins!";
        } else {
            winnerText = "Right Player Wins!";
        }

        SDL_Color white = {255, 255, 255, 255};

        SDL_Surface* text_surface = TTF_RenderText_Solid(font, winnerText, white);
        if (!text_surface) {
            std::cout << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
            return;
        }

        SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
        SDL_FreeSurface(text_surface);

        if (!text_texture) {
            std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
            return;
        }

        int text_w, text_h;
        SDL_QueryTexture(text_texture, nullptr, nullptr, &text_w, &text_h);

        SDL_Rect dstrect = { (720 - text_w) / 2, (300 - text_h) / 2, text_w, text_h };

        SDL_RenderCopy(renderer, text_texture, nullptr, &dstrect);
        SDL_DestroyTexture(text_texture);
    }


    left_paddle->draw(renderer);
    right_paddle->draw(renderer);
    ball->draw(renderer);
    score->draw(renderer, font);
}

bool Pvp::is_winner(int score) {
    if (score >= 10) {
        return true;
    }
    return false;
}

void Pvp::restart() {
    finished = false;
    paused = true;
    left_paddle->reset_paddle();
    right_paddle->reset_paddle();
    ball->restart(360.0f, 240.0f);
    score->restart();
}
