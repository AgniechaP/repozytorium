#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H


#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "State.hpp"
#include "FirstGame.h"

#include "Cloud.h"
#include<vector>
#include<sstream>

namespace minigry {

class GameOverState : public State  {
public:
    GameOverState(GameFDataRef data);

    void Init();
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);

private:
    GameFDataRef _data; //local reference
    //sf::Texture _backgroundTexture;
    sf::Sprite _background;

    sf::SoundBuffer _splashSoundBuffer;
    sf::Sound _splashSound;

};

}

#endif // GAMEOVERSTATE_H
