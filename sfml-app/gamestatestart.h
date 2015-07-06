#ifndef GAMESTATESTART_H
#define GAMESTATESTART_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"

class GameStateStart : public GameState
{
private:
	sf::View view;
	void loadgame();

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateStart(Game *game);
};

#endif//GAMESTATESTART_H