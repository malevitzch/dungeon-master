#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#ifndef ANIMATION.H
#define ANIMATION.H
#endif // ANIMATION
namespace m2d
{
    class Animation
    {
        private:
            std::vector<sf::Texture> frames;
            std::vector<sf::Vector2f> movements;
            unsigned int frame_count;
        public:
            Animation(std::string image_file_name, std::vector<sf::Vector2f> movements); //needs initializer list
            std::pair<sf::Texture, sf::Vector2f> getFrame(unsigned int index, sf::Vector2i direction);
    };
}
#include "animation.cpp"
#endif
