#pragma once

#include <array>
#include <cstdint>
#include "SFML/Graphics.hpp"

class GameBoyScreen {
private:
    sf::Uint8 *buffer = new sf::Uint8[64 * 32 * 4];
    sf::Image image{};
    sf::Texture texture{};
    sf::Sprite sprite{};
public:
    ~GameBoyScreen() {
        delete[] buffer;
    }

    sf::Sprite *buildScreenSprite();
};
