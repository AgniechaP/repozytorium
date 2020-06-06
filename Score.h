#ifndef SCORE_H
#define SCORE_H
#include<SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "FirstGame.h"

namespace minigry {
class Score
{
public:
    Score(GameFDataRef data);
    void Draw();
    void UpdateScore(int score);
private:
    GameFDataRef _data;
    sf::Text _scoreText;
};
}
#endif // SCORE_H
