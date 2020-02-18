#include "KiwiImage.h"
#include "Game.h"

KiwiImage::KiwiImage(std::string imagePath, std::string imageName, GameObjectType type, glm::vec2 position, bool isCentered)
{
	TheTextureManager::Instance()->load("../Assets/textures/kiwi.png",
		"kiwi", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("kiwi");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(382.0f, 305.0f));
	setType(KIWI);
}

KiwiImage::~KiwiImage()
{
}

void KiwiImage::draw()
{

	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("kiwi", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void KiwiImage::update()
{
}

void KiwiImage::clean()
{
}
