#include "WaterMelonImage.h"
#include "Game.h"

WaterMelonImage::WaterMelonImage(std::string imagePath, std::string imageName, GameObjectType type, glm::vec2 position, bool isCentered)
{
	TheTextureManager::Instance()->load("../Assets/textures/watermelon.png",
		"watermelon", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("watermelon");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(477.0f, 305.0f));
	setType(WATER_MELON);
}

WaterMelonImage::~WaterMelonImage()
{
}

void WaterMelonImage::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("watermelon", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void WaterMelonImage::update()
{
}

void WaterMelonImage::clean()
{
}
