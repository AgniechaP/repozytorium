#include "InstructionState.h"
#include "FirstGameState.h"
#include<sstream>
#include "Definitions.hpp"
#include "GameOverstate.h"
#include<iostream>
#include "MainMenuState.h"


namespace minigry {
InstructionState::InstructionState(GameFDataRef data) : _data(data) {}

void InstructionState::Init() {
_data->assets.LoadTexture("backgroundForest", INSTRUCTION_BACKGROUND_FILEPATH );
_data->assets.LoadFont("arial", FONT_FILEPATH);
_data->assets.LoadTexture("latajaca_krowa", LATAJACA_KROWA_BUTTON_FILEPATH );

_background.setTexture(this->_data->assets.GetTexture("backgroundForest"));
_latajaca_krowa_po_instrukcji.setTexture(this->_data->assets.GetTexture("latajaca_krowa"));
_latajaca_krowa_po_instrukcji.setPosition(200, 700);

_instructionText.setFont(_data->assets.GetFont("arial"));
_instructionText.setString(std::string("INSTRUKCJA"));
_instructionText.setCharacterSize(50);
_instructionText.setFillColor(sf::Color::Black);
_instructionText.setOrigin(_instructionText.getGlobalBounds().width/2, _instructionText.getGlobalBounds().height/2);
_instructionText.setPosition(310,230);

_sterowanieText.setFont(_data->assets.GetFont("arial"));
_sterowanieText.setString(std::string("Sterowanie krowa: SPACJA lub KLIKANIE MYSZKA"));
_sterowanieText.setCharacterSize(25);
_sterowanieText.setFillColor(sf::Color::Black);
_sterowanieText.setOrigin(_instructionText.getGlobalBounds().width/2, _instructionText.getGlobalBounds().height/2);
_sterowanieText.setPosition(190,330);

_obrotText.setFont(_data->assets.GetFont("arial"));
_obrotText.setString(std::string("Klawiszem R obracaj krowiszczem"));
_obrotText.setCharacterSize(25);
_obrotText.setFillColor(sf::Color::Black);
_obrotText.setOrigin(_instructionText.getGlobalBounds().width/2, _instructionText.getGlobalBounds().height/2);
_obrotText.setPosition(190,430);

_celText.setFont(_data->assets.GetFont("arial"));
_celText.setString(std::string("Cel gry: omin jak najwiecej chmur!"));
_celText.setCharacterSize(25);
_celText.setFillColor(sf::Color::Black);
_celText.setOrigin(_instructionText.getGlobalBounds().width/2, _instructionText.getGlobalBounds().height/2);
_celText.setPosition(190,530);


_ostrzezenie.setFont(_data->assets.GetFont("arial"));
_ostrzezenie.setString(std::string("Nie pozwol spasc krowie!!"));
_ostrzezenie.setCharacterSize(25);
_ostrzezenie.setFillColor(sf::Color::Black);
_ostrzezenie.setOrigin(_instructionText.getGlobalBounds().width/2, _instructionText.getGlobalBounds().height/2);
_ostrzezenie.setPosition(190,630);
}
void InstructionState::HandleInput() {
    sf::Event event;
    while(_data->window.pollEvent(event)) {
        if(sf::Event::Closed == event.type) {
            _data->window.close();
        }

    }
    if(_data->input.IsSpriteClicked(_latajaca_krowa_po_instrukcji, sf::Mouse::Left, _data->window)) {
        _data->machine.AddState(StateRef(new FirstGameState(_data)), true);
    }


}
void InstructionState::Update(float dt) {

}
void InstructionState::Draw(float dt) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_latajaca_krowa_po_instrukcji);
    _data->window.draw(_instructionText);
    _data->window.draw(_sterowanieText);
    _data->window.draw(_obrotText);
    _data->window.draw(_celText);
    _data->window.draw(_ostrzezenie);
    _data->window.display();
 }



}
