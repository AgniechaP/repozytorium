#ifndef FIRSTGAMESTATE_H
#define FIRSTGAMESTATE_H


#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "State.hpp"
#include "FirstGame.h"

#include "Cloud.h"
#include<vector>
#include<sstream>

namespace minigry {

class FirstGameState : public State  {
public:
    FirstGameState(GameFDataRef data);

    void Init();
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);

private:
    GameFDataRef _data; //local reference
    sf::Texture _backgroundTexture;
    sf::Sprite _background;

    sf::SoundBuffer _splashSoundBuffer;
    sf::Sound _splashSound;

};

}

#endif // FIRSTGAMESTATE_H