#pragma once
#include<SFML/Graphics.hpp>

class Object
{
public:
	sf::Sprite shape;
	sf::Vector2f position;
	sf::IntRect rect;

	virtual void Start() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderTarget* target) = 0;

};

