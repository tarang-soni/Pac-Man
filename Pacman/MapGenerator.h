#pragma once
#include <vector>
#include "MapTile.h"
#include <SFML/Graphics.hpp>
enum BrickType {
	None,
	Horizontal,
	Vertical,
	Hor_LeftEnd,
	Hor_RightEnd,
	Ver_TopEnd,
	Ver_BottomEnd,
	Corner_TopLeft,
	Corner_TopRight,
	Corner_BottomLeft,
	Corner_BottomRight,
	CC_Left_Wall_Right,	//cc stands for corner corner 
	CC_Right_Wall_Left,
	CC_Top_Wall_Bottom,
	CC_Bottom_Wall_Top,
	NoBlock,
	NoBlockFourCorners,
	Single
};
class MapGenerator
{
	public:
		std::unique_ptr<std::vector<std::vector<MapTile*>>> CreateMap(const char* mapImagePath);
		//void Render(sf::RenderTarget* target);
		void SetProperTileTexture(std::unique_ptr<std::vector<std::vector<MapTile*>>>& walls);
		void SetTextureFromBrickType(sf::IntRect& tileRect,BrickType brickType);
		sf::Vector2f GetPlayerSpawnTilePosition() { return playerSpawnPoint; }
	private:
		sf::Image mapImage;
		sf::Texture mapTileMap;
		sf::Vector2f playerSpawnPoint;
		//std::vector<std::vector<MapTile*>> walls;


};
