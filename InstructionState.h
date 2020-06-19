#ifndef INSTRUCTIONSTATE_H
#define INSTRUCTIONSTATE_H

#include<SFML/Graphics.hpp>
#include "State.hpp"
#include "FirstGame.h"
#include <sstream>
#include "MainMenuState.h"
#include "StateMachine.hpp"

namespace minigry {

class InstructionState : public State  {
public:
    InstructionState(GameFDataRef data);

    void Init();
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);
private:
    GameFDataRef _data; //local reference
    //sf::Texture _backgroundTexture;
    sf::Sprite _background;
    sf::Text _instructionText;
    sf::Text _sterowanieText;
    sf::Text _celText;
    sf::Text _ostrzezenie;
    sf::Text _obrotText;
    sf::Sprite _latajaca_krowa_po_instrukcji;
};
}
#endif // INSTRUCTIONSTATE_H
