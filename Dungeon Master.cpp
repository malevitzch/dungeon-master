#include <bits/stdc++.h>
#include "SpriteModule.h"
#include "scene.h"
#include "animation.h"

using namespace m2d;
int main()
{
    std::map<std::string, m2d::Scene*> scenes;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Dungeon Master");

    m2d::Scene *cur_scene = new m2d::TitleScene(window); //initialize it as starting scene
    cur_scene->initScene();
    while(window->isOpen())
    {
        sf::Event event;
        int playeraction = -1;
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::KeyReleased && playeraction == -1)
            {
                playeraction = event.key.code;
            }
            else if(event.type == sf::Event::Closed)
            {
                window->close();
                break;
            }
            //if(playeraction!=-1) std::cout<<playeraction; std::cout.flush();
        }
        std::string next_scene = cur_scene->sceneProc(playeraction);
        if(next_scene != "") //empty string means no scene change
        {
            cur_scene->endScene();
            cur_scene = scenes[next_scene];
            cur_scene->initScene();
        }
    }
}
