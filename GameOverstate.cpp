#include "GameOverstate.h"
#include<sstream>
#include "Definitions.hpp"
#include "FirstGameState.h"
#include<iostream>

namespace minigry {
GameOverState::GameOverState(GameFDataRef data) : _data(data) {

}
void GameOverState::Init() {

   _data->assets.LoadTexture("backgroundForest", GAME_OVER_BACKGROUND_FILEPATH );
   _data->assets.LoadTexture("game_over_title", GAME_OVER_TITLE );
   _data->assets.LoadTexture("latajaca_krowa", LATAJACA_KROWA_BUTTON_FILEPATH );

   _background.setTexture(this->_data->assets.GetTexture("backgroundForest"));
   _gameOver_Pic.setTexture(this->_data->assets.GetTexture("game_over_title"));
   _try_again_button.setTexture(this->_data->assets.GetTexture("latajaca_krowa"));

   _gameOver_Pic.setScale(0.5, 0.5);
   _gameOver_Pic.setPosition(160, 200);
   _try_again_button.setPosition(200, 550);

}
void GameOverState::HandleInput() {
    sf::Event event;
    while(_data->window.pollEvent(event)) {
        if(sf::Event::Closed == event.type) {
            _data->window.close();
        }

    }
    if(_data->input.IsSpriteClicked(_try_again_button, sf::Mouse::Left, _data->window)) {
        _data->machine.AddState(StateRef(new FirstGameState(_data)), true);
    }

}
void GameOverState::Update(float dt) {

}
void GameOverState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_gameOver_Pic);
    _data->window.draw(_try_again_button);
    _data->window.display();

}
}
