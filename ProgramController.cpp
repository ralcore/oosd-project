#include "ProgramController.h"
#include <iostream>

ProgramController::ProgramController() : game_controller(), window(sf::VideoMode(200, 200), "SFML works!")
{
    // TODO: do NOT immediately init a gamecontroller
    // instead wait for menu input
	sf::Clock frame_timer;
    sf::Time frame_time;
	// TODO: window size will need later adjustment
    state = 0;
}

void ProgramController::gameLoop()
{

    while (window.isOpen())
    {
        frame_time = frame_timer.getElapsedTime();
        frame_timer.restart();

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // run game tick
        game_controller.gameTick(frame_time);

        // get drawable objects
        std::vector<std::shared_ptr<sf::Drawable>> drawables = game_controller.getDrawables();
        for (auto& element : drawables)
        {
            std::cout << "hello";
            window.draw(*element);
        }
        window.display();
    }
}

sf::Time ProgramController::getFrameTime()
{
    return frame_time;
}

int ProgramController::getState()
{
    return state;
}

void ProgramController::setState(int new_state)
{
    state = new_state;
}