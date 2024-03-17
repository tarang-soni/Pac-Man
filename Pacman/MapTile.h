#pragma once
#include "Object.h"
#include "Enums.h"
class MapTile:public Object
{
	// Inherited via Object
public:
	MapTile(TileType tileType = TileType::EMPTY);
	virtual ~MapTile(){}
	void Start() override;
	void Update(float dt) override;
	void Render(sf::RenderTarget* target) override;
	void SetTexture(sf::Texture& texture, sf::IntRect rectBox);
	void SetPosition(int x,int y);
	TileType& GetTileType() { return _tileType; }
	void SetTileType(TileType type) { _tileType = type; }
private:
	TileType _tileType;
	
};

