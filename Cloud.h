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
    void Scoring();
    void MoveClouds(float dt);
    void DrawClouds();

    void RandomizeCloudY();

    const std::vector<sf::Sprite> &GetSprites() const;
    std::vector<sf::Sprite> &GetScoringSprite();

private:
    GameFDataRef _data;
    std::vector<sf::Sprite> cloudSprites;
    std::vector<sf::Sprite> scoringClouds;
    int _CloudY;

};

}
#endif // CLOUD_H

