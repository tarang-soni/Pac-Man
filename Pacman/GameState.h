#pragma once
#include "BaseState.h"
#include "Player.h"
#include "MapGenerator.h"
class GameState :
    public BaseState
{
    // Inherited via BaseState
public:
    void OnStateEnter() override;
    void OnStateExit() override;
    void Update(float dt) override;
    void Render(sf::RenderTarget* target) override;
    void HandleInput(GameStateManager* stateManager) override;


private:

    Player* player;
    float playerSpeed = 100;
    MapGenerator levelGenerator;

    std::unique_ptr<std::vector<std::vector<MapTile*>>> tiles;

};

