#ifndef SPRITEMODULE_H
#define SPRITEMODULE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
namespace m2d
{
    unsigned long long hashing_function(std::string to_hash, unsigned long long hash_base, unsigned long long hash_mod);
    class SpriteSheet
    {
        private:
            sf::Vector2u sprite_size;
            sf::Image sheet;
            unsigned int sprite_count;
            std::vector<sf::Texture*> textures;
            std::vector<bool> loaded;
            unsigned int hash_base_index;
            std::vector<unsigned int> hash_bases;
            std::map<unsigned long long, int> dictionary;
            std::vector<std::string> names;
            unsigned int error_tile_index;
            void loadTexture(unsigned int index);
            void initDictionary(std::string dictionary_file_name);
            void initObject(std::string file_name);
        public:
            SpriteSheet();
            SpriteSheet(std::string file_name, sf::Vector2u sprite_size);
            SpriteSheet(std::string image_file_name, sf::Vector2u sprite_size, std::string dictionary_file_name);
            sf::Vector2u getSize() const; //returns the size of the initial image
            sf::Vector2u getSpriteSize() const; //returns sprite size
            unsigned int getTileIndex(std::string name) const; //returns a numerical index of a tile with the chosen name
            sf::Texture& getTexture(unsigned int index); //returns the tile texture of the chosen index
            sf::Texture& getTexture(std::string name); //returns the tile texture of the chosen name
            std::string getName(unsigned int index) const; //returns the name of the tile with the chosen index
            bool inDictionary(std::string name) const; //checks whether a name is already inside the dictionary
            void setErrorTileIndex(unsigned int index); //sets the tile which will be returned in case of tile fetching errors, default is 0
    };
}
#include "SpriteModule.cpp"
#endif
