#include "Rotten.h"
#include "Game.h"

Rotten::Rotten(std::string imagePath, std::string imageName, GameObjectType type, glm::vec2 position, bool isCentered)
{
	TheTextureManager::Instance()->load("../Assets/textures/rotten.png",
		"rotten", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("rotten");
	setWidth(size.x);
	setHeight(size.y);
	//setPosition(glm::vec2(477.0f, 305.0f));
	setType(ROTTEN);
}

Rotten::~Rotten()
{
}

void Rotten::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("rotten", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Rotten::update()
{
}

void Rotten::clean()
{
}
