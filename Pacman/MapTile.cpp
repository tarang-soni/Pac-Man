#include "MapTile.h"

MapTile::MapTile(TileType tileType) :_tileType(tileType)
{

}


void MapTile::Start()
{
}

void MapTile::Update(float dt)
{
}

void MapTile::Render(sf::RenderTarget* target)
{
	target->draw(shape);
}

void MapTile::SetTexture(sf::Texture& texture, sf::IntRect rectBox)
{
	rect = rectBox;
	shape.setTexture(texture,true);
	shape.setTextureRect(rect);
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
}

void MapTile::SetPosition(int x,int y)
{
	position = sf::Vector2f(x, y);
	shape.setPosition(x,y);
}
