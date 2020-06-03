#include "FirstGameState.h"
#include<sstream>
#include "Definitions.hpp"
#include<iostream>
#include "MainMenuState.h"

namespace minigry {
FirstGameState::FirstGameState(GameFDataRef data) : _data(data) {

}
void FirstGameState::Init() {
    //std::cout<<"First game!"<<std::endl;
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


    /*this->ending_text.setFont(FirstGameState::_font);
    this->ending_text.setPosition(SCREEN_WIDTH/6, SCREEN_HEIGHT/3);
    this->ending_text.setCharacterSize(30);
    this->ending_text.setFillColor(sf::Color(255,0,128));
    this->ending_text.setStyle(sf::Text::Bold);

    this->_passing_time.setFont(_font);
    this->_passing_time.setPosition(SCREEN_WIDTH*0.2,22);
    this->_passing_time.setCharacterSize(17);
    this->_passing_time.setFillColor(sf::Color(255,0,0));

    this->_max_time = sf::seconds(90);*/

}
}

