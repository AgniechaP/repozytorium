#include "FirstGameState.h"
#include<sstream>
#include "Definitions.hpp"
#include "GameOverstate.h"
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
   _data->assets.LoadTexture("InvisibleScoringCloud", SCORING_CLOUD_FILEPATH);
   _data->assets.LoadFont("arial", FONT_FILEPATH);

   cloud = new Cloud(_data);
   cow = new Cow(_data);
   white = new White(_data);
   score = new Score(_data);
   _background.setTexture(this->_data->assets.GetTexture("backgroundColorGrass"));

   _score = 0;
   score->UpdateScore(_score);
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
        else if(sf::Event::KeyPressed == event.type) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
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
    cloud->Scoring();

    clock.restart();
}
cow->Update(dt);

std::vector<sf::Sprite> cloudSprites = cloud->GetSprites();
for(unsigned int i =0; i<cloudSprites.size(); i++) {
    if(collision.CheckSpriteCollision(cow->GetSprite(), 0.325f, cloudSprites.at(i), 0.90f)) {
        _gameState = GameStates::eGameOver;

        clock.restart();
    }

    }
if(GameStates::ePlaying == _gameState) {
std::vector<sf::Sprite> &scoringSprites = cloud->GetScoringSprite();
for(unsigned int i =0; i< scoringSprites.size(); i++) {
    if(collision.CheckSpriteCollision(cow->GetSprite(), 0.325f, scoringSprites.at(i), 0.90f)) {
        _score++;
        score->UpdateScore(_score);
        scoringSprites.erase(scoringSprites.begin() + i);
    }

    }
}
}
    if(GameStates::eGameOver == _gameState) {
        white->Show(dt);
        if(clock.getElapsedTime().asSeconds() > TIME_TO_GAMEOVER) {
            _data->machine.AddState(StateRef(new GameOverState(_data)), true);
        }
    }
}
void FirstGameState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw(_background);
    cloud->DrawClouds();
    cow->Draw();
    white->Draw();
    score->Draw();

    _data->window.display();


}
}

