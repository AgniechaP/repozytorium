#include "Cloud.h"

namespace minigry {
Cloud::Cloud(GameFDataRef data) : _data(data) {

}
void Cloud::SpawnDownCloud() {
    sf::Sprite sprite(_data->assets.GetTexture("cloudup"));
    sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
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
void Cloud::MoveClouds(float dt) {
     for(unsigned short int i=0; i<cloudSprites.size(); i++) {
         sf::Vector2f position = cloudSprites.at(i).getPosition();
         float movement = CLOUD_SPEED*dt;

         cloudSprites.at(i).move(-movement, 0);
     }
}

void Cloud::DrawClouds() {
    for(unsigned short int i=0; i<cloudSprites.size(); i++) {
        _data->window.draw(cloudSprites.at(i));
    }
}

}
