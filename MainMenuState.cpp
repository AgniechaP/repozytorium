#include "MainMenuState.h"
#include<sstream>
#include "Definitions.hpp"
#include "FirstGameState.h"
#include "InstructionState.h"
#include<iostream>

namespace minigry{
MainMenuState::MainMenuState(GameFDataRef data) : _data(data) {

}
void MainMenuState::Init() {
   _data->assets.LoadTexture("backgroundForest", MAIN_MENU_BACKGROUND_FILEPATH );
   _background.setTexture(this->_data->assets.GetTexture("backgroundForest"));
   _data->assets.LoadTexture("zwierzakowo", GAME_TITLE_FILEPATH );
   _title.setTexture(this->_data->assets.GetTexture("zwierzakowo"));
   _data->assets.LoadTexture("latajaca_krowa", LATAJACA_KROWA_BUTTON_FILEPATH );
   _playKrowaButton.setTexture(this->_data->assets.GetTexture("latajaca_krowa"));
   _data->assets.LoadTexture("instrukcja_button", INSTRUKCJA_BUTTON_FILEPATH);
   _instrukcjaButton.setTexture(this->_data->assets.GetTexture("instrukcja_button"));

   _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width/2), _title.getGlobalBounds().height/2);
   _playKrowaButton.setPosition((SCREEN_WIDTH / 2) - (_playKrowaButton.getGlobalBounds().width/2), (SCREEN_HEIGHT/2)-(_playKrowaButton.getGlobalBounds().height/2));
   _instrukcjaButton.setPosition((SCREEN_WIDTH / 2) - (_instrukcjaButton.getGlobalBounds().width/2),600);
}
void MainMenuState::HandleInput() {
    sf::Event event;
    while(_data->window.pollEvent(event)) {
        if(sf::Event::Closed == event.type) {
            this->_data->window.close();
        }
        if(this->_data->input.IsSpriteClicked(this->_playKrowaButton, sf::Mouse::Left, this->_data->window)) {
            this->_data->machine.AddState(StateRef(new FirstGameState(_data)), true); //true - zamiana obecnego stanu
        }

        if(this->_data->input.IsSpriteClicked(this->_instrukcjaButton, sf::Mouse::Left, this->_data->window)) {
            this->_data->machine.AddState(StateRef(new InstructionState(_data)), true); //true - zamiana obecnego stanu
        }
    }

}
void MainMenuState::Update(float dt) {

}
void MainMenuState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_title);
    _data->window.draw(_playKrowaButton);
    _data->window.draw(_instrukcjaButton);
    _data->window.display();

}
}
