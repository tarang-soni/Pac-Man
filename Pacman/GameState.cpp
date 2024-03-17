#include "GameState.h"
#include "GameStateManager.h"
#include <iostream>
#include "MenuState.h"
#include<iostream>
void GameState::OnStateEnter()
{
	std::cout << "Entered GameState" << std::endl;
	player = new Player("assets/pac man/pac man movement.png");
	tiles = levelGenerator.CreateMap("assets/maps/pacman_map1.png");
	
	player->SetPosition(levelGenerator.GetPlayerSpawnTilePosition());
}

void GameState::OnStateExit()
{
	std::cout << "Exited GameState" << std::endl;
}

void GameState::Update(float dt)
{
	player->Update(dt);
	

}

void GameState::Render(sf::RenderTarget* target)
{
	//levelGenerator.Render(target);


	for (size_t i = 0; i < (*tiles).size() * (*tiles)[0].size(); ++i)
	{
	size_t row = i / (*tiles)[0].size();
	size_t col = i % (*tiles)[0].size();
	target->draw((*tiles)[row][col]->shape);
	}
	player->Render(target);
}

void GameState::HandleInput(GameStateManager* stateManager)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		stateManager->NextState(new MenuState);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player->velocity.x = playerSpeed;
		player->velocity.y = 0;
		player->SetRotation(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player->velocity.x = -playerSpeed;
		player->velocity.y = 0;
		player->SetRotation(180);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player->velocity.y = -playerSpeed;
		player->velocity.x = 0;
		player->SetRotation(-90);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player->velocity.y = playerSpeed;
		player->velocity.x = 0;
		player->SetRotation(90);
	}
}
