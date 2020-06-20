#include "Cloud.h"
#include <iostream>

namespace minigry {
Cloud::Cloud(GameFDataRef data) : _data(data) {

    _CloudY = 0;
}
void Cloud::SpawnDownCloud() {
    sf::Sprite sprite(_data->assets.GetTexture("cloudup"));
    sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _CloudY);//rand()%830);
    cloudSprites.push_back(sprite);
}
void Cloud::SpawnUpCloud() {
    sf::Sprite sprite(_data->assets.GetTexture("cloud"));
    sprite.setPosition(_data->window.getSize().x, rand()%500+1);
    cloudSprites.push_back(sprite);
}
void Cloud::SpawnInvisibleCloud() {
    sf::Sprite sprite(_data->assets.GetTexture("cloudup"));
    sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
    sprite.setColor(sf::Color(0,0,0,0));
    cloudSprites.push_back(sprite);

}

void Cloud::SpawnPigCloud() {
    sf::Sprite sprite(_data->assets.GetTexture("pig"));
    sprite.setPosition(rand()%600+20, rand()%800+1); //_data->window.getSize().x
    sprite.setScale(0.40, 0.40);
    pigScoringClouds.push_back(sprite);

}


void Cloud::Scoring() {
    sf::Sprite sprite(_data->assets.GetTexture("InvisibleScoringCloud"));//("cloudup"));
    sprite.setPosition(_data->window.getSize().x, 0);//_data->window.getSize().y - sprite.getGlobalBounds().height);
    sprite.setColor(sf::Color(0,0,0,0));
    scoringClouds.push_back(sprite);

}
void Cloud::MoveClouds(float dt) {
     for(unsigned short int i=0; i<cloudSprites.size(); i++) {
         //sf::Vector2f position = cloudSprites.at(i).getPosition();
         //if(cloudSprites.at(i).getPosition().x < 0 - cloudSprites.at(i).getGlobalBounds().width) {
         //    cloudSprites.erase(cloudSprites.begin() + i);
        // } else {
         float movement = CLOUD_SPEED*dt;
         cloudSprites.at(i).move(-movement, 0);
         //}
     }
     for(unsigned short int i=0; i<scoringClouds.size(); i++) {
       //  if(scoringClouds.at(i).getPosition().x < 0 - scoringClouds.at(i).getGlobalBounds().width) {
       //     scoringClouds.erase(scoringClouds.begin() + i);
        // } else {
         float movement = CLOUD_SPEED*dt;
         scoringClouds.at(i).move(-movement, 0);
       //  }
     }

     for(unsigned short int i=0; i<pigScoringClouds.size(); i++) {
         float movement = CLOUD_SPEED*dt;
         pigScoringClouds.at(i).move(-movement, 0);
     }
}


void Cloud::DrawClouds() {
    for(unsigned short int i=0; i<cloudSprites.size(); i++) {
        _data->window.draw(cloudSprites.at(i));
    }

    for(unsigned short int i=0; i<pigScoringClouds.size(); i++) {
        _data->window.draw(pigScoringClouds.at(i));
    }

}

void Cloud::RandomizeCloudY() {
    _CloudY = rand()%700;
}

const std::vector<sf::Sprite> &Cloud::GetSprites() const {
    return cloudSprites;


}
std::vector<sf::Sprite> &Cloud::GetScoringSprite() {
    return scoringClouds;

}

std::vector<sf::Sprite> &Cloud::GetScoringPigSprites() {
    return pigScoringClouds;
}
}
