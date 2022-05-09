#include "Window.h"
#include <iostream>

Window::Window() : level(loadLevel(1)), window(sf::VideoMode(200, 200), "SFML works!")
{
    // constructs a window, alongside a default Level of level 1
    // TODO: window size will need later adjustment
	sf::Clock frametimer;
    sf::Int32 frametime;
    state = 0;
}

void Window::windowLoop()
{
    // handles window opening/closing
    // handles gamecontroller ticks

    while (window.isOpen())
    {
        frametime = frametimer.getElapsedTime().asMilliseconds();
        frametimer.restart();

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // run game logic tick
        level.tick(frametime);

        // run game draw tick
        level.draw(window);
    }
}