#pragma once
#include <SFML/Graphics.hpp>
#include "GameStateManager.h"
class GameManager
{
public:
	GameManager();//add fields later
	bool Init();
	void Run();
	void Exit();

private:
	void Start();
	void Update(float dt);
	void Render();
	void HandleInput();

	sf::RenderWindow* window;
	sf::Event event;
	GameStateManager* _stateManager;

};

