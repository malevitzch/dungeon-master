#ifndef TILEMAPMODULE_H
#define TILEMAPMODULE_H
#include "SpriteModule.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
namespace m2d
{
    class TileMap
    {
        private:
            std::vector<std::vector<unsigned int> > grid;
            std::vector<std::vector<sf::Sprite> > sprites;
            Vector2u dimensions;
        public:
            SpriteSheet* spritesheet;
            TileMap();
            TileMap(int _width, int _height, std::string _filename, sf::Vector2u _sprsize)
            {
                dimensions = Vector2u(_width, _height);
                grid.resize(_width);
                for(std::vector<unsigned int> &v: grid)
                {
                    v.resize(_height);
                    fill(v.begin(), v.end(), 0);
                }
                sprites.resize(_width);
                for(std::vector<sf::Sprite> &v: sprites)
                {
                    v.resize(_height);
                }
                spritesheet = new SpriteSheet(_filename, _sprsize);
            }
            void setTile(unsigned int _x, unsigned int _y, unsigned int _type) //TODO error handling
            {
                grid[_x][_y] = _type;
            }
            int getTile(unsigned int _x, unsigned int _y)
            {
                return grid[_x][_y];
            }
            void refreshTile(sf::RenderWindow& _w, unsigned int _x, unsigned int _y, unsigned int _dx, unsigned int _dy)
            {
                //this needs to be rewritten, write macros for SpriteSheet so that there is less code, also add universal storage
                unsigned int x(_x*spritesheet->getSprsize().x + _dx), y(_y*spritesheet->getSprsize().y + _dy);
                sprites[_x][_y].setPosition(sf::Vector2f(x, y));
                sprites[_x][_y].setTexture(spritesheet->getTexture(grid[_x][_y]));
                _w.draw(sprites[_x][_y]);
            }
            void renderTilemap(sf::RenderWindow& _w, unsigned int _dx, unsigned int _dy)
            {
                for(int i = 0; i < dimensions.x; i++)
                {
                    for(int j = 0; j < dimensions.y; j++)
                    {
                        refreshTile(_w, i, j, _dx, _dy);
                    }
                }
            }
            void saveTilemap(std::string _filename)
            {
                std::ofstream os;
                os.open(_filename);
                for(int i = 0; i < dimensions.y; i++)
                {
                    for(int j = 0; j < dimensions.x; j++)
                    {
                        os<<grid[j][i]<<" ";
                    }
                    os<<"\n";
                }
            }
            void loadTilemap(std::string _filename)
            {
                std::ifstream is;
                is.open(_filename);
                for(int i = 0; i < dimensions.y; i++)
                {
                    for(int j = 0; j < dimensions.x; j++)
                    {
                        is >> grid[j][i];
                    }
                }
            }
    };
}
#endif
