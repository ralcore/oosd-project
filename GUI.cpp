#include "GUI.h"
#include "iostream"
#include <SFML/Graphics.hpp>

void GUI::displayStats(Player& player)
{
    sf::Font font;
    if (font.loadFromFile("Montserrat-Regular.ttf"))
    {
        sf::Text text;
        text.setFont(font);
        text.setString("Your current health is: " + );
        text.setCharacterSize(24);
        text.setFillColor(sf::Color(0, 255, 0));
        text.setPosition(50, 50);

        sf::Text text2;
        text.setFont(font);
        text.setString(player.getHealth());
        text.setCharacterSize(24);
        text.setFillColor(sf::Color(0, 255, 0));
        text.setPosition(100, 50);

        window.draw(text);
        window.draw(text2);
    }
    else {
        std::cout << "ERROR: font not found" << std::endl;
    }
}