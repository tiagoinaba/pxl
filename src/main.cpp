#include "Cursor.hpp"
#include "Pixel.hpp"
#include "RenderEngine.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

const int PIXEL_SIZE = 16;
const int GRID_W = 64;
const int GRID_H = 64;
const int SCREEN_W = PIXEL_SIZE * GRID_W;
const int SCREEN_H = PIXEL_SIZE * GRID_H;

int main(int argc, char* argv[]) {
    RenderEngine renderEngine(SCREEN_W, SCREEN_H);

    Cursor cursor(PIXEL_SIZE, SCREEN_W, SCREEN_H);

    Pixel* grid[GRID_H][GRID_W] = {};

    std::vector<Pixel> pixels;

    bool quit = false;

    while (!quit) {

        renderEngine.clear();

        for (unsigned int i = 0; i < pixels.size(); i++) {
            pixels[i].render(renderEngine);
        }

        cursor.render(renderEngine);

        renderEngine.renderPresent();

        SDL_Event e;

        SDL_PollEvent(&e);

        switch(e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym) {
                    case SDLK_j:
                        if (cursor.gitRekt().y != SCREEN_H - 32)
                            cursor.moveCursor(D_DOWN, PIXEL_SIZE);
                        break;
                        
                    case SDLK_k:
                        if (cursor.gitRekt().y != 0)
                            cursor.moveCursor(D_UP, PIXEL_SIZE);
                        break;

                    case SDLK_h:
                        if (cursor.gitRekt().x != 0)
                            cursor.moveCursor(D_LEFT, PIXEL_SIZE);
                        break;

                    case SDLK_l:
                        if (cursor.gitRekt().x != SCREEN_W - 32)
                            cursor.moveCursor(D_RIGHT, PIXEL_SIZE);
                        break;

                    case SDLK_e: {
                                     std::vector<Pixel>::iterator it = std::find_if(pixels.begin(), pixels.end(), [&cursor](Pixel pix) {
                                             return pix.gitRekt()->x == cursor.gitRekt().x && pix.gitRekt()->y == cursor.gitRekt().y;
                                             });
                                     if (it == pixels.end()) {
                                         pixels.push_back(Pixel(PIXEL_SIZE, cursor.gitRekt().x, cursor.gitRekt().y));
                                     }
                                     break;
                                 }
                                 
                    case SDLK_x: {
                                     std::vector<Pixel>::iterator it = std:: find_if(pixels.begin(), pixels.end(), [&cursor](Pixel pix) {
                                             return (
                                                     pix.gitRekt()->x == cursor.gitRekt().x 
                                                     && pix.gitRekt()->y == cursor.gitRekt().y
                                                    );
                                             });
                                     if (it != pixels.end()) {
                                         pixels.erase(it);
                                     }
                                     break;
                                 }

                    case SDLK_ESCAPE:
                                 quit = true;
                }
        }
    }

    renderEngine.close();
}

