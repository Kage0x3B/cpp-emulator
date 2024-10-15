#include "GameWindow.h"

const std::string GameWindow::WINDOW_TITLE = "Platformer";

void GameWindow::game_loop() {
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
