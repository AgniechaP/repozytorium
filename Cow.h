#ifndef COW_H
#define COW_H
#include<SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "FirstGame.h"


namespace minigry {
class Cow
{
public:
    Cow(GameFDataRef data);

    void Draw();
    void Update(float dt);
    void Tap();

    void BackToPreviousPosition();
    void Rotate(const float &angle);

    const sf::Sprite &GetSprite() const;
private:
    GameFDataRef _data;
    sf::Sprite _cowSprite;

    sf::Clock _clock;
    sf::Clock _movementClock;

    int _CowState;

};
}
#endif // COW_H
