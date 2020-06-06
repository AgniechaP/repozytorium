#include "Score.h"
#include <string>
namespace minigry {
Score::Score(GameFDataRef data) : _data(data) {
    _scoreText.setFont(_data->assets.GetFont("arial"));//("Kenney Blocks.ttf"));
    _scoreText.setString("0");
    _scoreText.setCharacterSize(128);
    _scoreText.setFillColor(sf::Color::White);
    _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height /2 );
    _scoreText.setPosition(_data->window.getSize().x /2, _data->window.getSize().y /5 );
}
void Score::Draw() {
    _data->window.draw(_scoreText);
}
void Score::UpdateScore(int score) {
    _scoreText.setString(std::to_string(score));
}
}
