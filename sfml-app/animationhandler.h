#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
	unsigned int startFrame;
	unsigned int endFrame;

	float duration;

	Animation(unsigned int startFrame, unsigned int endFrame, float duration)
	{
		this->startFrame = startFrame;
		this->endFrame = endFrame;
		this->duration = duration;
	}

	unsigned int getLength()
	{
		return endFrame - startFrame + 1;
	}
};

class AnimationHandler
{
private:
	std::vector<Animation> animations;
	float t;
	int currentAnimation;

public:
	void addAnimation(Animation &anim);
	void update(const float dt);
	void changeAnimation(unsigned int animationnum);
	sf::IntRect bounds;
	sf::IntRect frameSize;

	AnimationHandler()
	{
		this->t = 0.0f;
		this->currentAnimation = -1;
	}

	AnimationHandler(const sf::IntRect &frameSize)
	{
		this->frameSize = frameSize;

		this->t = 0.0f;
		this->currentAnimation = -1;
	}
};

#endif//ANIMATIONHANDLER_H