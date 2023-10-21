#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
namespace m2d
{
        Animation::Animation(std::string image_file_name, sf::Vector2u tile_size, std::vector<sf::Vector2f> movements) : tile_size(tile_size), movements(movements)
        {
            sf::Image sprite_sheet;
            sprite_sheet.loadFromFile(image_file_name);
            frame_count = sprite_sheet.getSize().x / tile_size.x;
            for(unsigned int i = 0; i < frame_count; i++)
            {
                sf::Texture* cur_frame;
                cur_frame->loadFromImage(sprite_sheet, sf::Rect(int(i*tile_size.x), 0, int(tile_size.x), int(tile_size.y)));
                frames.push_back(cur_frame);
            }
        }
        std::pair<sf::Texture*, sf::Vector2f> Animation::getFrame(unsigned int index, sf::Vector2i direction)
        {
            return {frames[index], {movements[index].x * direction.x, movements[index].y * direction.y}};
        }
}
