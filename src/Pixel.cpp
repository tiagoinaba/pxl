#include "Pixel.hpp"
#include "RenderEngine.hpp"
#include <SDL2/SDL_rect.h>

Pixel::Pixel(int pixelSize, int x, int y) {
    this->rect = { x,  y, pixelSize ,pixelSize };
}

SDL_Rect* Pixel::gitRekt() {
    return &this->rect;
}

void Pixel::render(RenderEngine renderEngine) {
    renderEngine.renderRect(&rect, 0xFF, 0xFF, 0xFF, 0xFF, true);
}
