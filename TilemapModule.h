#include "TilemapModule.cpp"
#ifndef TILEMAPMODULE_H
#define TILEMAPMODULE_H
#include "SpriteModule.h"
#incldue <SFML/Graphics.hpp>
#include <iostream>
namespace m2d
{
    class TileMap
    {
        private:
            std::vector<std::vector<unsigned int> > grid;
            std::vector<std::vector<sf::Sprite> > sprites;
            Vector2u dimensions;
        public:
            SpriteSheet* spritesheet; //rewrite so that the code is safe
            TileMap();
            TileMap(int _width, int _height, std::string _filename, sf::Vector2u _sprsize);
            void setTile(unsigned int _x, unsigned int _y, unsigned int _type);
            int getTile(unsigned int _x, unsigned int _y);

            void refreshTile(sf::RenderWindow& _w, unsigned int _x, unsigned int _y, unsigned int _dx, unsigned int _dy); //TODO: add Vector2u mirrors to everything and vice versa
            void renderTilemap(sf::RenderWindow& _w, unsigned int _dx, unsigned int _dy);

            void saveTilemap(std::string _filename);
            void loadTilemap(std::string _filename);
    };
}
#endif
