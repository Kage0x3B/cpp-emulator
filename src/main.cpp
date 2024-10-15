#include <SFML/Window.hpp>

#include "EmulatorWindow.h"

int main() {
    EmulatorWindow emulatorWindow{sf::VideoMode(800, 600)};
    emulatorWindow.game_loop();

    return 0;
}
