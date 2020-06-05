#include "Cow.h"

namespace minigry {
Cow::Cow(GameFDataRef data) : _data(data) {
    _cowSprite.setTexture( _data->assets.GetTexture("cow"));

    _cowSprite.setPosition((_data->window.getSize().x / 4) - (_cowSprite.getGlobalBounds().width /2 ), (_data->window.getSize().y / 2) - (_cowSprite.getGlobalBounds().height /2 ) );
    _CowState = COW_STATE_STILL;

}
void Cow::Draw() {
    _data->window.draw(_cowSprite);
}
void Cow::Update(float dt) {
    if(COW_STATE_FALLING == _CowState) {
        _cowSprite.move(0 , GRAVITY * dt);

    } else if(COW_STATE_FLYING == _CowState) {
        _cowSprite.move(0, -COW_SPEED * dt);
    }

    if(_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
        _movementClock.restart();
        _CowState = COW_STATE_FALLING;
    }
}
void Cow::Tap() {
    _movementClock.restart();
    _CowState = COW_STATE_FLYING;
}
const sf::Sprite &Cow::GetSprite() const {
    return _cowSprite;
}
}
