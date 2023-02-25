#pragma once

#include <array>
#include <cstdint>

#include "GameBoyScreen.h"

class SharpSm83 {
private:
    /**
     * 4096*8-bit memory
     */
    std::array<uint8_t, 4096> memory;
    /**
     * 8-bit registers V0-15
     */
    std::array<uint8_t, 16> V;
    /**
     * 16-bit register, usually for memory addresses
     */
    uint16_t I;
    /**
     * Sound timer
     */
    uint8_t ST;
    /**
     * Delay timer
     */
    uint8_t DT;

    /**
     * 16-bit Program counter
     */
    uint16_t PC;
    /**
     * 8-bit Stack pointer
     */
    uint8_t SP;
    std::array<uint16_t, 16> stack;
    GameBoyScreen screen{};
public:
    void update(float delta);

    sf::Sprite *buildScreenSprite() {
        return screen.buildScreenSprite();
    }
};
