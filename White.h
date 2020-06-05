#ifndef WHITE_H
#define WHITE_H
#include<SFML/Graphics.hpp>
#include "FirstGame.h"
#include "Definitions.hpp"

namespace minigry {
class White
{
public:
    White(GameFDataRef data);

    void Show(float dt);
    void Draw();
private:
    GameFDataRef _data;
    sf::RectangleShape _shape;
    bool _whiteOn;
};
}
#endif // WHITE_H
