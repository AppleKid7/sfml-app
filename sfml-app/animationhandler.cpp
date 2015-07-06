#include <SFML/Graphics.hpp>
#include <vector>

#include "animationhandler.h"

void AnimationHandler::update(const float dt)
{
	if (currentAnimation >= this->animations.size() || currentAnimation < 0)
	{
		return;
	}
	float duration = this->animations[currentAnimation].duration;

	if (int(t + dt) > int(t / duration))
	{
		int frame = int((t + dt) / duration);

		frame %= this->animations[currentAnimation].getLength();

		sf::IntRect rect = this->frameSize;
		rect.left = rect.width * frame;
		rect.top = rect.height * this->currentAnimation;
		this->bounds = rect;
	}
	this->t += dt;

	if (this->t > duration * this->animations[currentAnimation].getLength())
	{
		this->t = 0.0f;
	}
	return;
}

void AnimationHandler::addAnimation(Animation &anim)
{
	this->animations.push_back(anim);
	return;
}

void AnimationHandler::changeAnimation(unsigned int animationnum)
{
	if (this->currentAnimation == animationnum || animationnum >= this->animations.size()
		|| animationnum < 0)
	{
		return;
	}

	this->currentAnimation = animationnum;
	sf::IntRect rect = this->frameSize;
	rect.top = rect.height * animationnum;
	this->bounds = rect;
	this->t = 0.0;

	return;
}