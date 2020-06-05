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
   _data->assets.LoadTexture("cow",COW_FILEPATH);
   cloud = new Cloud(_data);
   cow = new Cow(_data);
   white = new White(_data);
   _background.setTexture(this->_data->assets.GetTexture("backgroundColorGrass"));

   _gameState = GameStates::eReady;

}
void FirstGameState::HandleInput() {
    sf::Event event;
    while(_data->window.pollEvent(event)) {
        if(sf::Event::Closed == event.type) {
            _data->window.close();

        }

        if(this->_data->input.IsSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window)) {
            if(GameStates::eGameOver!=_gameState) {
                _gameState = GameStates::ePlaying;
                cow->Tap();
            }
        }

    }

}
void FirstGameState::Update(float dt) {
    if(GameStates::eGameOver!=_gameState) {
//cloud->MoveClouds(dt);
    }
    if(GameStates::ePlaying == _gameState) {
        cloud->MoveClouds(dt);
if(clock.getElapsedTime().asSeconds() > CLOUD_FREQUENCY) {
    cloud->RandomizeCloudY();
    cloud->SpawnInvisibleCloud();
    cloud->SpawnDownCloud();
    cloud->SpawnUpCloud();

    clock.restart();
}
cow->Update(dt);

std::vector<sf::Sprite> cloudSprites = cloud->GetSprites();
for(int i =0; i<cloudSprites.size(); i++) {
    if(collision.CheckSpriteCollision(cow->GetSprite(), 0.325f, cloudSprites.at(i), 0.90f)) {
        _gameState = GameStates::eGameOver;
    }

    }
}
    if(GameStates::eGameOver == _gameState) {
        white->Show(dt);
    }
}
void FirstGameState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw(_background);
    cloud->DrawClouds();
    cow->Draw();
    white->Draw();

    _data->window.display();


}
}

