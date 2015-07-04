#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

/** We need this to easily convert between pixel and real-world coordinates*/
static const float SCALE = 30.f;

/** Create the base for the boxes to land */
void CreateGround(b2World& World, float X, float Y);

/** Create the boxes */
void CreateBox(b2World& World, int MouseX, int MouseY);

int main()
{
	/** Prepare the window */
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Test");
	window.setFramerateLimit(60);

	/** Prepare the world */
	b2Vec2 gravity(0.f, 9.8f);
	b2World world(gravity);
	CreateGround(world, 400.f, 500.f);

	/** Prepare textures */
	sf::Texture groundTexture;
	sf::Texture boxTexture;
	groundTexture.loadFromFile("media/images/ground.png");
	boxTexture.loadFromFile("media/images/box.png");

	while (window.isOpen())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			int mouseX = sf::Mouse::getPosition(window).x;
			int mouseY = sf::Mouse::getPosition(window).y;
			CreateBox(world, mouseX, mouseY);
		}
		world.Step(1 / 60.f, 8, 3);

		window.clear(sf::Color::White);
		int bodyCount = 0;
		for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
		{
			if (bodyIterator->GetType() == b2_dynamicBody)
			{
				sf::Sprite sprite;
				sprite.setTexture(boxTexture);
				sprite.setOrigin(16.f, 16.f);
				sprite.setPosition(SCALE * bodyIterator->GetPosition().x, SCALE * bodyIterator->GetPosition().y);
				sprite.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
				window.draw(sprite);
				++bodyCount;
			}
			else
			{
				sf::Sprite groundSprite;
				groundSprite.setTexture(groundTexture);
				groundSprite.setOrigin(400.f, 8.f);
				groundSprite.setPosition(bodyIterator->GetPosition().x * SCALE, bodyIterator->GetPosition().y * SCALE);
				groundSprite.setRotation(180 / b2_pi * bodyIterator->GetAngle());
				window.draw(groundSprite);
			}
		}
		window.display();
	}

	return 0;
}

void CreateBox(b2World& World, int MouseX, int MouseY)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(MouseX / SCALE, MouseY / SCALE);
	BodyDef.type = b2_dynamicBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((32.f / 2) / SCALE, (32.f / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
}

void CreateGround(b2World& World, float X, float Y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X / SCALE, Y / SCALE);
	BodyDef.type = b2_staticBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((800.f / 2) / SCALE, (16.f / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
}