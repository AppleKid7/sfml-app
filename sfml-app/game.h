#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>

#include "texturemanager.h"

class GameState;

class Game
{
private:
	void loadTextures();

public:

	std::stack<GameState*> states;

	sf::RenderWindow window;
	TextureManager textureManager;
	sf::Sprite background;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
};

#endif /* GAME_H */