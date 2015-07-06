#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "texturemanager.h"

void TextureManager::loadTexture(const std::string &name, const std::string &filename)
{
	sf::Texture texture;
	texture.loadFromFile(filename);

	this->textures[name] = texture;

	return;
}

sf::Texture &TextureManager::getRef(const std::string &texture)
{
	return this->textures.at(texture);
}