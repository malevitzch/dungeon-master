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
            virtual void initScene();
            virtual std::string sceneProc(int player_input); //should return
            virtual void endScene();
    };
    class DungeonScene : Scene
    {
        private:
            std::vector<std::vector<int> > map_placement;
            std::vector<sf::Vector2u> slimes; //either this or we replace that part with a general approach that works for any monster
        public:
    };
}
#endif
