#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
private:
	std::map<std::string, sf::Texture> textures;

public:
	void loadTexture(const std::string &name, const std::string &filename);

	sf::Texture &getRef(const std::string &texture);

	TextureManager()
	{

	}
};

#endif//TEXTUREMANAGER_H