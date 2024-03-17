#include "Actor.h"
#include <iostream>
Actor::Actor(const char* path):animator(shape)
{
	SetTexture(path);
}
void Actor::Start()
{

}

void Actor::Update(float dt)
{
}

void Actor::Render(sf::RenderTarget* target)
{
	target->draw(shape);
}

void Actor::SetPosition(sf::Vector2f pos)
{
	position = pos;
}

void Actor::SetPosition(float x, float y)
{
	position = sf::Vector2f(x, y);
}

void Actor::SetTexture(const char* path)
{
	if (!texture.loadFromFile(path)) {
		std::cout << "Failed To load texture" << std::endl;
	}
	shape.setTexture(texture);
}
