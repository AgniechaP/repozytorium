#include "SplashState.h"
#include<sstream>
#include "Definitions.hpp"
#include<iostream>
#include "MainMenuState.h"

namespace minigry{
SplashState::SplashState(GameFDataRef data) : _data(data) {

}
void SplashState::Init() {
   _data->assets.LoadTexture("year2", SPLASH_BACKGROUND_FILEPATH );
   _background.setTexture(this->_data->assets.GetTexture("year2"));
   if(!_splashSoundBuffer.loadFromFile(SPLASH_SOUND_EFFECT_FILEPATH)) {
       std::cout<<"Sound error!"<<std::endl;
   }
   _splashSound.setBuffer(_splashSoundBuffer);
   _splashSound.play();
}
void SplashState::HandleInput() {
    sf::Event event;
    while(_data->window.pollEvent(event)) {
        if(sf::Event::Closed == event.type) {
            _data->window.close();
        }
    }

}
void SplashState::Update(float dt) {
    if(_clock.getElapsedTime().asSeconds() >SPLASH_SCREEN_TIME) {
        _data->machine.AddState(StateRef(new MainMenuState(_data)), true); //true - zamiana obecnego stanu

    }
}
void SplashState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();

}
}
