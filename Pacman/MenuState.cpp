#include "MenuState.h"
#include "Utilities.h"
#include "GameState.h"
#include <iostream>
#include "GameStateManager.h"
void MenuState::OnStateEnter()
{
	BGImg = new sf::Texture();
	std::cout << "Entered MenuState"<< std::endl;
	if (!font.loadFromFile("assets/MadimiOne-Regular.ttf")) {
		std::cout << "Wrong Path for font" << std::endl;
	}
	if (!BGImg->loadFromFile("assets/bg.jpg")) {
		std::cout << "Wrong Path for BG" << std::endl;
	}
	backgroundTexture.setTexture(*BGImg);
	std::cout << backgroundTexture.getLocalBounds().width;
	backgroundTexture.setScale( SCREEN_WIDTH/backgroundTexture.getLocalBounds().width , SCREEN_HEIGHT/backgroundTexture.getLocalBounds().height);
	text.setFont(font);
	text.setString("Press Space To Continue");
	// set the character size
	text.setCharacterSize(24); // in pixels, not points!
	text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height / 2);
	
	// set the color
	text.setFillColor(sf::Color::White);

	// set the text style
	text.setStyle(sf::Text::Bold);

	text.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/5);
}

void MenuState::OnStateExit()
{
	delete BGImg;
	BGImg = nullptr;
	std::cout << "Exited MenuState"<<std::endl;
}

void MenuState::Update(float dt)
{
}

void MenuState::Render(sf::RenderTarget* target)
{
	target->draw(backgroundTexture);
	target->draw(text);
}

void MenuState::HandleInput(GameStateManager* stateManager)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		stateManager->NextState(new GameState);
	}
}
