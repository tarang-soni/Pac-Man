#pragma once
#include"BaseState.h"
#include<SFML/Graphics.hpp>
class GameStateManager
{
public:
	void NextState(BaseState* state);
	void Update(float dt);
	void Render(sf::RenderTarget* target);
	void HandleInput();
	void Exit();
private:
	BaseState* currentState;
	
};

