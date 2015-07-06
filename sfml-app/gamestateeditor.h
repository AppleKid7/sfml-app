#ifndef GAMESTATEEDITOR_H
#define GAMESTATEEDITOR_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"

class GameStateEditor : public GameState
{
private:
	sf::View gameView;
	sf::View guiView;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateEditor(Game *game);
};

#endif//GAMESTATEEDITOR_H