#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

void render(sf::RenderWindow &window) {
    window.clear();
}

int main() {
    sf::Window window(sf::VideoMode(800, 600), "Platformer");
    window.setVerticalSyncEnabled(true);



    return 0;
}
