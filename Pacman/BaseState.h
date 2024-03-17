#pragma once
#include <SFML/Graphics.hpp>
class GameStateManager;
class BaseState
{
public:
	virtual void OnStateEnter() = 0;
	virtual void OnStateExit() = 0;

	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
	virtual void HandleInput(GameStateManager* stateManager) = 0;


};

