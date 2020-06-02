#include "FirstGameState.h"
#include<sstream>
#include "Definitions.hpp"
#include<iostream>
#include "MainMenuState.h"

namespace minigry{
FirstGameState::FirstGameState(GameFDataRef data) : _data(data) {

}
void FirstGameState::Init() {
    std::cout<<"First game!"<<std::endl;
   _data->assets.LoadTexture("backgroundColorGrass", KROWA_BACKGROUND_FILEPATH );
   _background.setTexture(this->_data->assets.GetTexture("backgroundColorGrass"));
}
void FirstGameState::HandleInput() {
    sf::Event event;
    while(_data->window.pollEvent(event)) {
        if(sf::Event::Closed == event.type) {
            _data->window.close();
        }
    }

}
void FirstGameState::Update(float dt) {

}
void FirstGameState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();

}
}

