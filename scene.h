#include <SFML/Graphics.hpp>
#include "SpriteModule.h"
#ifndef SCENE
#define SCENE
namespace m2d
{
    class Scene
    {
        protected:
        public:
            sf::RenderWindow* window;
            Scene(sf::RenderWindow* window);
            virtual void initScene() = 0; //initializes scene
            virtual std::string sceneProc(int player_input) = 0; //handles the procedure during each frame
            virtual void endScene() = 0; //cleans up after the scene, mostly necessary in case of dynamically-allocated memory
    };
    class TitleScene : public Scene
    {
        private:
            int stage;
            sf::Sprite title;
            sf::Texture title_texture;
        public:
            TitleScene(sf::RenderWindow* window);
            void initScene();
            std::string sceneProc(int player_input);
            void endScene();
    };
    class DungeonScene : public Scene
    {
        private:
            SpriteSheet* sprite_sheet;
            std::vector<std::vector<int> > map_plan;
            sf::Vector2u player_position;
            sf::Vector2u map_size;
            std::vector<sf::Vector2u> slimes; //either this or we replace that part with a general approach that works for any monster
        public:
            DungeonScene(sf::RenderWindow* window, sf::Vector2u map_size, std::vector<std::vector<int> > map_plan);
            sf::Vector2u getPlayerPos();
    };
}
#include "scene.cpp"
#endif
