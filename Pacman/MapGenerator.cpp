#include "MapGenerator.h"
#include<iostream>


std::unique_ptr<std::vector<std::vector<MapTile*>>> MapGenerator::CreateMap(const char* mapImagePath)
{
	auto walls = std::make_unique<std::vector<std::vector<MapTile*>>>();

	if (!mapImage.loadFromFile(mapImagePath)) {
		std::cout << "Failed to load map" << std::endl;

	}
	if (!mapTileMap.loadFromFile("assets/pac man/tiles set.png")) {
		std::cout << "Failed to load tilesheet" << std::endl;
	}
	const sf::Uint8* pByteBuffer = mapImage.getPixelsPtr();
	const sf::Uint32* pPixelBuffer = reinterpret_cast<const sf::Uint32*>(pByteBuffer);

	int sizeX = mapImage.getSize().x;
	int sizeY = mapImage.getSize().y;
	for (int i = 0; i < sizeX;i++) {
		walls->push_back(std::vector<MapTile*>());
		for (int j = 0; j < sizeY; j++)
		{
			auto tile = new MapTile();
			sf::Vector2i tileSize = sf::Vector2i(32, 32);
			walls->at(i).push_back(std::move(tile));
			auto color = mapImage.getPixel(i, j);
			tile->SetPosition((i * 32) + 16, (j * 32) + 16);
			if (color == sf::Color::Blue) {
				tile->SetTileType(TileType::WALL);
			}
			else {
				if (color == sf::Color::Yellow) {
					playerSpawnPoint = tile->position;
				}
				tile->SetTileType(TileType::EMPTY);

			}
		

		}
	}
	SetProperTileTexture(walls);
	return walls;
}

//void MapGenerator::Render(sf::RenderTarget* target)
//{
//
//	for (size_t i = 0; i < walls.size() * walls[0].size(); ++i) {
//		size_t row = i / walls[0].size();
//		size_t col = i % walls[0].size();
//		target->draw(walls[row][col]->shape);
//	}
//}

void MapGenerator::SetProperTileTexture(std::unique_ptr<std::vector<std::vector<MapTile*>>>& walls)
{
	int sizeX = mapImage.getSize().x;
	int sizeY = mapImage.getSize().y;
	int leftTile = 0;
	int rightTile = 0;
	int topTile = 0;
	int bottomTile = 0;
	int topLeftTile = 0;
	int topRightTile = 0;
	int bottomLeftTile = 0;
	int bottomRightTile = 0;


	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++)
		{
			auto currentTile = (*walls)[i][j];

			for (int dx = -1; dx <= 1; ++dx) {
				for (int dy = -1; dy <= 1; ++dy) {
					// Skip the center tile
					if (dx == 0 && dy == 0)
						continue;

					int ni = i + dx;
					int nj = j + dy;

					// Determine the neighboring tile's type
					int tileType;
					if (ni >= 0 && ni < sizeX && nj >= 0 && nj < sizeY) {
						// Neighboring tile is within bounds
						tileType = (*walls)[ni][nj]->GetTileType() == WALL ? 1 : 0;
					}
					else {
						// Neighboring tile is outside bounds, consider it as an empty tile
						tileType = 0;
					}

					// Update the corresponding tile variables based on the relative position
					if (dx == -1 && dy == -1) {
						topLeftTile = tileType;
					}
					else if (dx == -1 && dy == 0) {
						leftTile = tileType;
					}
					else if (dx == -1 && dy == 1) {
						bottomLeftTile = tileType;
					}
					else if (dx == 0 && dy == -1) {
						topTile = tileType;
					}
					else if (dx == 0 && dy == 1) {
						bottomTile = tileType;
					}
					else if (dx == 1 && dy == -1) {
						topRightTile = tileType;
					}
					else if (dx == 1 && dy == 0) {
						rightTile = tileType;
					}
					else if (dx == 1 && dy == 1) {
						bottomRightTile = tileType;
					}

				}
			}

			BrickType type = BrickType::None;
			if (currentTile->GetTileType() == TileType::WALL) {
				// Check for various brick types based on surrounding tiles
				 if (leftTile == EMPTY && rightTile == EMPTY && topTile == EMPTY && bottomTile == EMPTY) {
					type = BrickType::Single;
				}
				else if (leftTile == WALL && rightTile == WALL && topTile == EMPTY && bottomTile == EMPTY) {
					type = BrickType::Horizontal;
				}
				else if (leftTile == EMPTY && rightTile == WALL && topTile == EMPTY && bottomTile == EMPTY) {
					type = BrickType::Hor_LeftEnd;
				}
				else if (leftTile == WALL && rightTile == EMPTY && topTile == EMPTY && bottomTile == EMPTY) {
					type = BrickType::Hor_RightEnd;
				}

				else if (leftTile == EMPTY && rightTile == EMPTY && topTile == WALL && bottomTile == WALL) {
					type = BrickType::Vertical;
				}
				else if (leftTile == EMPTY && rightTile == EMPTY && topTile == EMPTY && bottomTile == WALL) {
					type = BrickType::Ver_TopEnd;
				}
				else if (leftTile == EMPTY && rightTile == EMPTY && topTile == WALL && bottomTile == EMPTY) {
					type = BrickType::Ver_BottomEnd;
				}
				else if (leftTile == EMPTY && rightTile == WALL && topTile == EMPTY && bottomTile == WALL) {
					type = BrickType::Corner_TopLeft;
				}
				else if (leftTile == WALL && rightTile == EMPTY && topTile == EMPTY && bottomTile == WALL) {
					type = BrickType::Corner_TopRight;
				}
				else if (leftTile == EMPTY && rightTile == WALL && topTile == WALL && bottomTile == EMPTY) {
					type = BrickType::Corner_BottomLeft;
				}
				else if (leftTile == WALL && rightTile == EMPTY && topTile == WALL && bottomTile == EMPTY) {
					type = BrickType::Corner_BottomRight;
				}
				else if (leftTile == WALL && rightTile == WALL && topTile == WALL && bottomTile == EMPTY) {
					type = BrickType::CC_Bottom_Wall_Top;
				}
				else if (leftTile == WALL && rightTile == WALL && topTile == EMPTY && bottomTile == WALL) {
					type = BrickType::CC_Top_Wall_Bottom;
				}
				else if (leftTile == EMPTY && rightTile == WALL && topTile == WALL && bottomTile == WALL) {
					type = BrickType::CC_Left_Wall_Right;
				}
				else if (leftTile == WALL && rightTile == EMPTY && topTile == WALL && bottomTile == WALL) {
					type = BrickType::CC_Right_Wall_Left;
				}
				//type = BrickType::Corner_BottomLeft;
			}
			else if (currentTile->GetTileType() == TileType::EMPTY) {
				type = BrickType::None;
			}
			sf::IntRect rect;
			SetTextureFromBrickType(rect,type);
			currentTile->SetTexture(mapTileMap, rect);

		}
	}
}

void MapGenerator::SetTextureFromBrickType(sf::IntRect& tileRect, BrickType brickType)
{

	int x = -1, y = -1;
	switch (brickType)
	{
	case None:
		std::cout << "Edge case alert!" << std::endl;
		break;
	case Horizontal:
		x = 2;
		y = 0;
		break;
	case Vertical:
		x = 0;
		y = 1;
		break;
	case Hor_LeftEnd:
		x = 1;
		y = 0;
		break;
	case Hor_RightEnd:
		x = 3;
		y = 0;
		break;
	case Ver_TopEnd:
		x = 0;
		y = 0;
		break;
	case Ver_BottomEnd:
		x = 0;
		y = 2;
		break;
	case Single:
		x = 0;
		y = 3;
		break;
	case Corner_TopLeft:
		x = 1;
		y = 1;
		break;
	case Corner_TopRight:
		x = 2;
		y = 1;
		break;
	case Corner_BottomLeft:
		x = 1;
		y = 2;
		break;
	case Corner_BottomRight:
		x = 2;
		y = 2;
		break;
	case CC_Right_Wall_Left:
		x = 4;
		y = 2;
		break;
	case CC_Left_Wall_Right:
		x = 3;
		y = 1;
		break;
	case CC_Bottom_Wall_Top:
		x = 3;
		y = 2;
		break;
	case CC_Top_Wall_Bottom:
		x = 4;
		y = 1;
		break;
	default:
		break;
	}
	
	if (x == -1 || y == -1) {
		std::cout << "negative x and y" << std::endl;
	}
	tileRect = sf::IntRect(x * 32, y * 32, 32, 32);
}

