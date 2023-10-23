#include <bits/stdc++.h>
using namespace std::chrono_literals;
namespace m2d
{
    Scene::Scene(sf::RenderWindow* window) : window(window) {}
    TitleScene::TitleScene(sf::RenderWindow* window) : Scene(window)
    {

    }
    void TitleScene::initScene()
    {
        title_texture.loadFromFile("assets/TitleScreen.png");
        title.setTexture(title_texture);
        title.setPosition({0, 0});
        stage = 0;
    }
    std::string TitleScene::sceneProc(int player_input)
    {
        if(player_input == 57)
        {
            return "Title";
        }
        if(stage < 8) title.move({0, -10*sinf((7 - stage) / 7.0)});
        else if(stage < 16) title.move({0, 10*sinf((stage - 8) / 7.0)});
        else if(stage < 24) title.move({0, 10*sinf((23 - stage) / 7.0)});
        else title.move({0, -10*sinf((stage - 24) / 7.0)});
        window->clear();
        window->draw(title);
        window->display();
        std::this_thread::sleep_for(50ms);
        stage = (stage + 1) % 32;
        return "";
    }
    void TitleScene::endScene()
    {
        std::cout<<"HIHIHIHA";
        std::cout.flush();
    }
}
