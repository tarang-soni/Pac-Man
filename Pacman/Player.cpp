#include "Player.h"

Player::Player(const char* path):Actor(path)
{
	Start();
}

void Player::Start()
{
	Actor::Start();
	rect = sf::IntRect(0, 0, 32, 32);
	shape.setTextureRect(rect);
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
	position.x = 32 * 10;
	position.y = 32 * 15;
	for (size_t i = 0; i < 5; i++)
	{
		animator.AddFrame({ sf::IntRect(32*i,0,32,32), 0.15 });

	}
	animator.SetPlaybackMode(PlayBackMode::LOOP);
}

void Player::Update(float dt)
{
	Actor::Update(dt);
	animator.Update(dt);
	position += velocity * dt;
	shape.setPosition(position);
}

void Player::Render(sf::RenderTarget* target)
{
	Actor::Render(target);
}

void Player::SetRotation(float rot)
{
	shape.setRotation(rot);
}
