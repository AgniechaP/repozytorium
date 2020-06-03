#include "GameOverstate.h"
#include<sstream>
#include "Definitions.hpp"
#include<iostream>

namespace minigry {
GameOverState::GameOverState(GameFDataRef data) : _data(data) {

}
void GameOverState::Init() {

   _data->assets.LoadTexture("backgroundForest", GAME_OVER_BACKGROUND_FILEPATH );
   _background.setTexture(this->_data->assets.GetTexture("backgroundForest"));

}
void GameOverState::HandleInput() {
    sf::Event event;
    while(_data->window.pollEvent(event)) {
        if(sf::Event::Closed == event.type) {
            _data->window.close();
        }

    }

}
void GameOverState::Update(float dt) {

}
void GameOverState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();

}
}
