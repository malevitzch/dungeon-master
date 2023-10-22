#include <bits/stdc++.h>
namespace m2d
{
    Scene::Scene(sf::RenderWindow* window) : window(window) {}
    TitleScene::TitleScene(sf::RenderWindow* window) : Scene(window)
    {
        std::cout<<"HA";
    }
    void TitleScene::initScene()
    {
        std::cout<<"AMOGUS";
    }
    std::string TitleScene::sceneProc(int player_input)
    {
        sf::Sprite s;
        sf::Texture tx;
        tx.loadFromFile("slime.png");
        s.setTexture(tx);
        window->clear();
        window->draw(s);
        window->display();
        if(player_input == 57)
        {
            return "close";
        }
        return "";
    }
    void TitleScene::endScene()
    {

    }
}
