#include <SFML/Graphics.hpp>
#include "SpriteModule.h"
#ifndef SCENE
#define SCENE
m2d
{
    class Scene
    {
        protected:
            bool toSwap;
            string next_scene;
            std::vector<const sf::Drawable &drawables> scene_objects; //not sure if this works
        public:
            void initScene();
            void sceneProc();
            void endScene();
    };
    class DungeonScene : Scene
    {
        private:
            std::vector<std::vector<int> > map_placement;
            std::vector<sf::Vector2u> slimes; //either this or we replace that part with a general approach that works for any monster
        public:
    };
}
#endif SCENE
