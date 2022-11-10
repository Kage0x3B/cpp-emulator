#pragma once

#include <SFML/Graphics.hpp>

class Screen {
public:
    virtual void render(sf::RenderTexture &render_target) = 0;
};
