#ifndef CLOUD_H
#define CLOUD_H
#include<SFML/Graphics.hpp>
#include "FirstGame.h"
#include<vector>
#include "Definitions.hpp"

namespace minigry{

class Cloud {
public:
    Cloud(GameFDataRef data);

    void SpawnDownCloud();
    void SpawnUpCloud();
    void SpawnInvisibleCloud();
    void MoveClouds(float dt);
    void DrawClouds();
private:
    GameFDataRef _data;
    std::vector<sf::Sprite> cloudSprites;

};

}
#endif // CLOUD_H

