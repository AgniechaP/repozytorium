#include "AssetManager.h"
namespace minigry {

void AssetManager::LoadTexture(std::string name, std::string FileName) {

    sf::Texture tex;
    if(tex.loadFromFile(FileName)) {
        this->_textures[name] = tex;
    }
}

sf::Texture &AssetManager::GetTexture(std::string name) {
    return this->_textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string FileName) {

    sf::Font font;
    if(font.loadFromFile(FileName)) {
        this->_fonts[name] = font;
    }
}

sf::Font &AssetManager::GetFont(std::string name) {
    return this->_fonts.at(name);
}

}
