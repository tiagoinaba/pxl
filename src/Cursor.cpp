#include "Cursor.hpp"
#include "RenderEngine.hpp"
#include <SDL2/SDL_rect.h>
#include <iostream>
#include <ostream>

Cursor::Cursor(int pixelSize, int screenWidth, int screenHeight) {
    SDL_Rect rect = {.x = screenWidth / 2, .y = (screenHeight - 32) / 2, .w = pixelSize, .h = pixelSize};

    this->rect = rect;
}

void Cursor::moveCursor(Direction dir, int pixelSize) {
   switch (dir) {
       case D_UP:
           this->rect.y -= pixelSize;
           break;
       case D_DOWN:
           this->rect.y += pixelSize;
           break;
       case D_LEFT:
           this->rect.x -= pixelSize;
           break;
       case D_RIGHT:
           this->rect.x += pixelSize;
           break;
   } 
}

SDL_Rect Cursor::gitRekt() {
    return this->rect;
}

void Cursor::render(RenderEngine renderEngine) {
    renderEngine.renderRect(&rect, 0x00, 0xFF, 0x00, 0xFF, false);
}
