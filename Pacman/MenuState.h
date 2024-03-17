#pragma once
#include "BaseState.h"
#include <SFML/Graphics.hpp>
class MenuState :
    public BaseState
{
    // Inherited via BaseState
    void OnStateEnter() override;
    void OnStateExit() override;
    void Update(float dt) override;
    void Render(sf::RenderTarget* target) override;
    void HandleInput(GameStateManager* manager) override;
    sf::Text text;//create ui class and have all text in it
    sf::Font font;//use fonts stored in ui class

    sf::Texture* BGImg;
    sf::Sprite backgroundTexture;
    
};

