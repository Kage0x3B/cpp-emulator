#include "EmulatorWindow.h"

const std::string EmulatorWindow::WINDOW_TITLE = "SharpSm83 Emulator";

void EmulatorWindow::game_loop() {
    auto clock = sf::Clock{};

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        update(deltaTime);

        render();

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}

void EmulatorWindow::update(float deltaTime) {

}

void EmulatorWindow::render() {
    window.clear(sf::Color::Black);

    window.draw()

    window.display();
}
