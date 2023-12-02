#pragma once

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

class RenderEngine {
    public:
        RenderEngine(int p_w, int p_h$);
        void close();
        void renderRect(SDL_Rect* rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool isFilled);
        void renderPresent();
        void clear();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        int screenWidth;
        int screenHeight;
};
