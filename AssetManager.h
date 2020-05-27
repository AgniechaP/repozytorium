#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include<map>
#include<SFML/Graphics.hpp>
namespace minigry {

class AssetManager {
public:
    AssetManager() {}
    ~AssetManager(){}

    void LoadTexture(std::string name, std::string FileName);
    sf::Texture &GetTexture(std::string name); //name of a texture

    void LoadFont(std::string name, std::string FileName);
    sf::Font &GetFont(std::string name); //czcionki

private: //mapy do przechowywania tekstur
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;

};

}
#endif // ASSETMANAGER_H
