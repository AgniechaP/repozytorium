#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "State.hpp"
#include "FirstGame.h"

namespace minigry {

class MainMenuState : public State {
public:
    MainMenuState(GameFDataRef data);

    void Init();

    void HandleInput();
    void Update(float dt);
    void Draw(float dt);
private:
    GameFDataRef _data; //local reference
    sf::Sprite _title;
    sf::Sprite _playKrowaButton;
    sf::Sprite _instrukcjaButton;
    sf::Sprite _background;

    sf::SoundBuffer _splashSoundBuffer;
    sf::Sound _splashSound;

};
}
#endif // MAINMENUSTATE_H



