#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#ifndef ANIMATION
#define ANIMATION
namespace m2d
{
    class Animation
    {
        private:
            std::vector<sf::Texture*> frames;
            std::vector<sf::Vector2f> movements;
        public:
            unsigned int frame_count;
            sf::Vector2u tile_size;
            Animation(std::string image_file_name, sf::Vector2u tile_size, std::vector<sf::Vector2f> movements); //needs initializer list
            std::pair<sf::Texture*, sf::Vector2f> getFrame(unsigned int index, sf::Vector2i direction);
    };
}
#include "animation.cpp"
#endif
