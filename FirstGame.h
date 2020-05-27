#ifndef FIRSTGAME_H
#define FIRSTGAME_H
#include<memory>
#include<string>
#include<SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.h"
#include "inputmanager.h"

namespace minigry {

struct GameFData
{
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;

};

typedef std::shared_ptr<GameFData> GameFDataRef;
class FirstGame {
public:
    FirstGame(int width, int height, std::string title);
private:
    const float dt = 1.0f/60.0f; //how many times update per second
    sf::Clock _clock;

    GameFDataRef _data = std::make_shared<GameFData>(); //giving access to all game data, state

    void RunF();
};
}
#endif // FIRSTGAME_H
