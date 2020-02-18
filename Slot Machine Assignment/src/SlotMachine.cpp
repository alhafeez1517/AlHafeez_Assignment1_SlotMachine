#include "SlotMachine.h"
#include "Game.h"

SlotMachine::SlotMachine(std::string imagePath, std::string imageName, GameObjectType type, glm::vec2 position, bool isCentered)
{
	TheTextureManager::Instance()->load("../Assets/textures/SlotMachine.png",
		"slotMachine", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("slotMachine");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(400.0f, 250.0f));
	setType(SLOT_MACHINE);
}

SlotMachine::~SlotMachine()
{
}

void SlotMachine::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("slotMachine", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void SlotMachine::update()
{
}

void SlotMachine::clean()
{
}
