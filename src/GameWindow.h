#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class GameWindow {
private:
    static const std::string WINDOW_TITLE;

    sf::Window window;
    sf::RenderTexture render_target;
public:
    GameWindow(sf::VideoMode videoMode) : window{videoMode, WINDOW_TITLE} {
        window.setVerticalSyncEnabled(true);
    }

    void game_loop();

    void update();

    void render() const;
};
