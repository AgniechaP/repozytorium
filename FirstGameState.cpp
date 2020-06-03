#include "FirstGameState.h"
#include<sstream>
#include "Definitions.hpp"
#include<iostream>


namespace minigry {
FirstGameState::FirstGameState(GameFDataRef data) : _data(data) {

}
void FirstGameState::Init() {
    //std::cout<<"First game!"<<std::endl;
   _data->assets.LoadTexture("backgroundColorGrass", KROWA_BACKGROUND_FILEPATH );
   _data->assets.LoadTexture("cloudup", CLOUD_UP_FILEPATH);
   _data->assets.LoadTexture("cloud",CLOUD_DOWN_FILEPATH);
   cloud = new Cloud(_data);
   _background.setTexture(this->_data->assets.GetTexture("backgroundColorGrass"));



}
void FirstGameState::HandleInput() {
    sf::Event event;
    while(_data->window.pollEvent(event)) {
        if(sf::Event::Closed == event.type) {
            _data->window.close();

        }

        if(this->_data->input.IsSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window)) {
            cloud->SpawnInvisibleCloud();
            cloud->SpawnDownCloud();
            cloud->SpawnUpCloud();
        }

    }

}
void FirstGameState::Update(float dt) {
cloud->MoveClouds(dt);
}
void FirstGameState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw(_background);
    cloud->DrawClouds();
    _data->window.display();

}
}

