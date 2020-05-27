#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H
#include<SFML/Graphics.hpp>
#include "State.hpp"
#include "FirstGame.h"

namespace minigry {

class SplashState : public State {
public:
    SplashState(GameFDataRef data);

    void Init();

    void HandleInput();
    void Update(float dt);
    void Draw(float dt);
private:
    GameFDataRef _data; //local reference
    sf::Clock _clock;
    sf::Texture _backgroundTexture;
    sf::Sprite _background;
};

}
#endif // SPLASHSTATE_H
