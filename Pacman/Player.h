#pragma once
#include "Actor.h"
class Player :
    public Actor
{
public:
    Player(const char* path);
    void Start() override;
    void Update(float dt) override;
    void Render(sf::RenderTarget* target) override;

    void SetRotation(float rot);
    sf::Vector2f velocity;

};

