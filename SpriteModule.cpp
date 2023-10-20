#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
namespace m2d
{
    unsigned long long hashing_function(std::string to_hash, unsigned long long hash_base, unsigned long long hash_mod) //plain old polynomial hash function that hashes strings
    {
        unsigned long long cur_hash = 0;
        for(char c : to_hash)
        {
            cur_hash = (cur_hash + c) % hash_mod;
            cur_hash = (cur_hash * hash_base) % hash_mod;
        }
        return cur_hash;
    }
    void SpriteSheet::loadTexture(unsigned int index)
    {
        loaded[index] = true;
        //using math to determine the position of the texture in the sheet image
        unsigned int columns = sheet.getSize().x / sprite_size.x;
        unsigned int column = index % columns;
        unsigned int row = index / columns;
        unsigned int x(index * sprite_size.x), y(row * sprite_size.y);
        sf::Texture* new_texture = new sf::Texture();
        new_texture->loadFromImage(sheet, sf::IntRect(x, y, sprite_size.x, sprite_size.y));
        textures[index] = new_texture;
    }
    void SpriteSheet::initDictionary(std::string dictionary_file_name)
    {
        std::string in;
        std::ifstream dictionary_input(dictionary_file_name);
        while(dictionary_input>>in)
        {
            names.push_back(in);
        }
        //we iterate through five potential hash bases until we find one that will cause no hash collisions
        //with a 1e9 + 7 modulo and 5 tries the chances of not getting a collisionless initialisation are abysmal
        for(unsigned int cur_base : hash_bases)
        {
            unsigned int counter = 0;
            dictionary.clear();
            bool is_collision = false;
            for(std::string s : names)
            {
                long long word_hash = hashing_function(s, cur_base, 1000000007);
                if(dictionary.find(word_hash) != dictionary.end())
                {
                    is_collision = true;
                    break;
                }
                dictionary.insert({word_hash, counter}); //we insert the hashes into a map that later allows us to get the tile by name using getTileIndex
                counter++;
            }
            if(!is_collision)
            {
                break;
            }
            hash_base_index++;
        }
    }
    void SpriteSheet::initObject(std::string file_name)
    {
        if(sprite_size.x * sprite_size.y == 0)
        {
            printf("sprite cannot have any dimension equal to zero\n");
            throw;
        }
        //base initialisation of a SpriteSheet
        sheet.loadFromFile(file_name);
        if(sheet.getSize().x % sprite_size.x != 0 && sheet.getSize().y % sprite_size.y != 0)
        {
            printf("the spritesheet needs to be evenly divided into tiles\n");
            throw;
        }
        sprite_count = (sheet.getSize().x / sprite_size.x) * (sheet.getSize().y / sprite_size.y);
        if(sprite_count == 0)
        {
            printf("you cannot define a spritesheet without tiles\n");
            throw;
        }
        textures.resize(sprite_count);
        loaded.resize(sprite_count);
        std::fill(loaded.begin(), loaded.end(), 0);
    }
    SpriteSheet::SpriteSheet(std::string file_name, sf::Vector2u sprite_size) : sprite_size(sprite_size)
    {
        initObject(file_name);
    }
    SpriteSheet::SpriteSheet(std::string image_file_name, sf::Vector2u sprite_size, std::string dictionary_file_name) : sprite_size(sprite_size)
    {
        initObject(image_file_name);
        initDictionary(dictionary_file_name);
    }
    sf::Vector2u SpriteSheet::getSize() const
    {
        return sheet.getSize();
    }
    sf::Vector2u SpriteSheet::getSpriteSize() const
    {
        return sprite_size;
    }
    unsigned int SpriteSheet::getTileIndex(std::string name) const
    {
        //throw an exception in case we try to access a tile that doesn't exist
        //perhaps try catch would be a better idea here so that we don't have to crash the program
        unsigned int out_ans = 0;
        try
        {
            out_ans = dictionary.at(hashing_function(name, hash_bases[hash_base_index], 1000000007)); //the map::at function throws an exception in case of non-existent key
        }
        catch(...)
        {
            printf("unknown tile name \"%s\" \n", name.c_str()); //output the tile name that caused the error
            out_ans = error_tile_index;
        }
        return out_ans;
    }
    sf::Texture& SpriteSheet::getTexture(unsigned int index) //TODO: add error handling when reading out of bounds or from uninitialized spritesheet
    {
        //this kind of implementation should give a performance boost in case of larger spritesheets as we don't have to load all the textures instantly, only loading when they are needed
        if(!loaded[index])
        {
            loadTexture(index);
        }
        return *(textures[index]);
    }
    sf::Texture& SpriteSheet::getTexture(std::string name)
    {
        return getTexture(getTileIndex(name));
    }
    std::string SpriteSheet::getName(unsigned int index) const
    {
        std::string out_ans;
        try
        {
            out_ans = names.at(index); //the at function throws an out_of_range exception in case of too high index
        }
        catch(...)
        {
            printf("accessing name out of bounds, attempting to get %u, max index is %u\n", index, (unsigned int)(names.size()) - 1u);
            out_ans = getName(error_tile_index);
        }
        return out_ans;
    }
    bool SpriteSheet::inDictionary(std::string name) const
    {
        return dictionary.find(hashing_function(name, hash_bases[hash_base_index], 1000000007)) != dictionary.end();
    }
    void SpriteSheet::setErrorTileIndex(unsigned int index)
    {
        //preventing setting invalid error_tile_index
        if(index >= sprite_count)
        {
            printf("%u is not a valid tile index\n", index);
            return;
        }
        error_tile_index = index;
    }
}
