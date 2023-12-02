#pragma once

#include "Renderable.hpp"
#include <SDL2/SDL_rect.h>

class Pixel : Renderable {
    public:
        Pixel(int pixelSize, int x, int y);
        SDL_Rect* gitRekt();
        void render(RenderEngine renderEngine);

    private:
        SDL_Rect rect;
};
