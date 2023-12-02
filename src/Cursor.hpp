#pragma once

#include "RenderEngine.hpp"
#include "Renderable.hpp"
#include <SDL2/SDL_rect.h>

enum Direction { D_UP, D_DOWN, D_LEFT, D_RIGHT };

class Cursor : Renderable {
    public:
        Cursor(int pixelSize, int screenWidth, int screenHeight);
        void moveCursor(Direction dir, int pixelSize);
        SDL_Rect gitRekt();
        void render(RenderEngine renderEngine);

    private:
        int gridPosX;
        int gridPosY;
        SDL_Rect rect;
};
