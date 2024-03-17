#pragma once
#include "Object.h"

#include "Animation.h"
class Actor :
    public Object
{
    // Inherited via Object
public:
    Actor(const char* texturePath);
    virtual ~Actor(){}
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Render(sf::RenderTarget* target) override;

    Animation animator;
    void SetPosition(sf::Vector2f pos);
    void SetPosition(float x, float y);
    void SetTexture(const char* path);

    sf::Texture texture;
    // 
    //audioSource
    //collision
};

