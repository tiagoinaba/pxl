#include "RenderEngine.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <cstdio>
#include <iostream>

RenderEngine::RenderEngine(int p_w, int p_h)
    :window(NULL), renderer(NULL), screenWidth(p_w), screenHeight(p_h)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to initialize SDL! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Teste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Failed to create window! SDL_Error: %s\n", SDL_GetError());
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
    }
}

void RenderEngine::close() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
}

void RenderEngine::renderRect(SDL_Rect* rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool isFilled) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    if (isFilled) SDL_RenderFillRect(renderer, rect);
    else SDL_RenderDrawRect(renderer, rect);
}

void RenderEngine::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(renderer);
}

void RenderEngine::renderPresent() {
    SDL_RenderPresent(renderer);
}
