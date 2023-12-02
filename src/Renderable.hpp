#pragma once

#include "RenderEngine.hpp"

class Renderable {
    public:
        virtual void render(RenderEngine renderEngine) = 0;
};
