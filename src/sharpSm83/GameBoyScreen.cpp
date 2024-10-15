#include "GameBoyScreen.h"

sf::Sprite *GameBoyScreen::buildScreenSprite() {
    image.create(64, 32, buffer);
    texture.loadFromImage(image);


    return &sprite;
}
