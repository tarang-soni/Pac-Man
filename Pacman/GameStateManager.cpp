#include "GameStateManager.h"



void GameStateManager::NextState(BaseState* state)
{
	if (currentState != nullptr) {
		currentState->OnStateExit();
	}
	currentState = state;
	currentState->OnStateEnter();
}

void GameStateManager::Update(float dt)
{
	if (currentState != nullptr)
		currentState->Update(dt);
}

void GameStateManager::Render(sf::RenderTarget* target)
{
	if (currentState != nullptr)
		currentState->Render(target);
}

void GameStateManager::HandleInput()
{
	if (currentState != nullptr)
		currentState->HandleInput(this);
}

void GameStateManager::Exit()
{
	if (currentState != nullptr) {
		currentState->OnStateExit();
	}
	delete currentState;
	currentState = nullptr;
}
