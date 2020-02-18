#include "BananaImage.h"
#include "Game.h"

BananaImage::BananaImage(std::string imagePath, std::string imageName, GameObjectType type, glm::vec2 position, bool isCentered)
{
	TheTextureManager::Instance()->load("../Assets/textures/banana.png",
		"banana", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("banana");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(287.0f, 305.0f));
	setType(KIWI);
}

BananaImage::~BananaImage()
{
}

void BananaImage::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("banana", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void BananaImage::update()
{

}

void BananaImage::clean()
{
}
