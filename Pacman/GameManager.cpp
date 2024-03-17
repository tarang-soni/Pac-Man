#include "GameManager.h"
#include <iostream>
#include "MenuState.h"
#include"Utilities.h"

GameManager::GameManager():window(0),_stateManager(0)
{
	_stateManager = new GameStateManager();
}

bool GameManager::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Works!");
	if (window == nullptr) {
		std::cout << "Window not being created!"<<std::endl;
		return false;
	}
	return true;
}

void GameManager::Run()
{
	Start();
	sf::Clock deltaClock;
	while (window->isOpen())
	{
		float dt = deltaClock.restart().asSeconds();
		HandleInput();
		Update(dt);
		Render();
	}
}


void GameManager::Start()
{
	std::cout << "Start Called"<< std::endl;
	_stateManager->NextState(new MenuState);
}

void GameManager::Update(float dt)
{
	_stateManager->Update(dt);
}

void GameManager::Render()
{

	window->clear();
	_stateManager->Render(window);
	//window->draw(shape);
	window->display();
}

void GameManager::HandleInput()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		_stateManager->HandleInput();
	}
}
void GameManager::Exit()
{
	_stateManager->Exit();
	delete _stateManager;
	_stateManager = NULL;

	delete window;
	window = NULL;
}

