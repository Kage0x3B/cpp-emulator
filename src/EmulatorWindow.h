#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class EmulatorWindow {
private:
    static const std::string WINDOW_TITLE;

    sf::RenderWindow window;
    sf::RenderTexture render_target;
public:
    EmulatorWindow(sf::VideoMode videoMode) : window{videoMode, WINDOW_TITLE} {
        window.setVerticalSyncEnabled(true);
    }

    void game_loop();

    void update(float deltaTime);

    void render();
};
