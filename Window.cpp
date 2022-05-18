#include "Window.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

Window::Window() : window(sf::VideoMode(608, 608), "SFML works!")
{
    // constructs a window, alongside a default Level of level 1
	sf::Clock frametimer;
    sf::Int32 frametime;
    levelnum = 7;
    level = new Level(levelnum);
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
        int state = level->tick(frametime, window, level);
        if (state == 1) {
            // level beaten
            delete level;
            levelnum++;
            level = new Level(levelnum);
        }
        else if (state == 2) {
            // player killed
            delete level;
            levelnum = 7;
            level = new Level(levelnum);
        }
        // run game draw tick
        level->draw(window);
    }
}