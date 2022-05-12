#pragma once
#include "SFML/Graphics.hpp"

class Tilemap : public sf::Drawable, public sf::Transformable
{
	// adapted from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

