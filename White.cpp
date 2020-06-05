#include "White.h"

namespace minigry {
White::White(GameFDataRef data) : _data(data) {
    _shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
    _shape.setFillColor(sf::Color(255, 255, 255, 0));
    _whiteOn = true;
}
void White::Show(float dt) {
    if(_whiteOn == true) {
        int color_part = (int)_shape.getFillColor().a + (WHITE_SPPED *dt);

        if(color_part >=255.0f) {
            color_part = 255.0f;
            _whiteOn = false;
        }
        _shape.setFillColor(sf::Color(255, 255, 255, color_part));
    } else {
        int color_part = (int)_shape.getFillColor().a + (WHITE_SPPED *dt);

        if(color_part <=255.0f) {
            color_part = 0.0f;
            _whiteOn = false;
        }
        _shape.setFillColor(sf::Color(255, 255, 255, color_part));
    }
}
void White::Draw() {
    _data->window.draw(_shape);
}
}
