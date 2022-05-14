#include "Tilemap.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

bool Tilemap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, const int numtiles, unsigned int width, unsigned int height)
{
    // save tiles array
    for (int i = 0; i < numtiles; i++) {
        savedtiles.push_back(tiles[i]);
    }

    // save width
    tileswidth = width;

    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);

}

int Tilemap::getTile(sf::Vector2<float> pos)
{
    // returns the type of tile located at given float coordinates
    // i.e. getTile(1.23, 6.53) where tile 0, 0 is wall, returns 1

    // reduce pos to array indexes
    pos /= 32.f;
    pos.x = floor(pos.x);
    pos.y = floor(pos.y);

    // convert to 1d vector index and return value
    int index = pos.x + pos.y * tileswidth;
    if (0 <= index && index <= savedtiles.size())
    {
        return savedtiles[pos.x + pos.y * tileswidth];
    } else {
        std::cout << "player out of bounds" << std::endl;
        return 0;
    }
}