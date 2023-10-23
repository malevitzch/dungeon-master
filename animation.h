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
            Animation(std::string image_file_name, sf::Vector2u tile_size, std::vector<sf::Vector2f> movements); //initializes a single animation from an image file containing a sequence of same-sized frames
            std::pair<sf::Texture*, sf::Vector2f> getFrame(unsigned int index, sf::Vector2i direction); //returns the texture and movement vector for the frame of select index, the direction parameter is important in case of movement animations
    };
}
#include "animation.cpp"
#endif
