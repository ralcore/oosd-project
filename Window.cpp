#include "Window.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

Window::Window() : level(loadLevel(1)), window(sf::VideoMode(576, 576), "SFML works!")
{
    // constructs a window, alongside a default Level of level 1
    // TODO: window size will need later adjustment
	sf::Clock frametimer;
    sf::Int32 frametime;
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
        level.tick(frametime, window);

        // run game draw tick
        level.draw(window);
    }
}

Level Window::loadLevel(int levelnum) 
{
    // for now we skip this function, simply returning the default level
    Level level;
    return level;

    // opens and iterates through csv file
    // (format: "enemy,42,44" - enemytype,xpos,ypos)
    // constructs entities and passes to level
    // modified from https://www.geeksforgeeks.org/csv-file-management-using-c/

    std::ifstream csv;
    std::string path = "level" + std::to_string(levelnum) + ".csv";
    csv.open(path);

    std::vector<std::string> row;
    std::string line, word, temp;

    while (csv >> temp) {
        row.clear();
        // dump next line
        std::getline(csv, line);

        // convert line to stream
        std::stringstream stream(line);

        // split line using , to get individual entries
        while (std::getline(stream, word, ',')) {
            // push split entry to vector
            row.push_back(word);
        }

        std::vector<Enemy*> enemies;
        // use vector to create objects
        // unfortunately we cannot run a switch statement on strings
        if (row[0] == "enemy") {
            // create enemy
            Enemy enemy;
            enemies.push_back(new Enemy(enemy));
        }
        else if (row[0] == "player") {
            // construct player with coordinates
            Player player(std::stof(row[1]), std::stof(row[2]));
        }
        else if (row[0] == "tilemap") {
            // create tilemap
            Tilemap tilemap();
        }

        // push references to level constructor + return level
    }
}