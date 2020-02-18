#pragma once
#ifndef  __SLOT_MACHINE__
#define __SLOT_MACHINE__
#include "DisplayObject.h"

class SlotMachine :public DisplayObject
{
public:
	SlotMachine(std::string imagePath = "../Assets/textures/SlotMachine.png",
		std::string imageName = "slotMachine",
		GameObjectType type = SLOT_MACHINE,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool isCentered = true);
	~SlotMachine();

	void draw() override;
	void update() override;
	void clean() override;
};
#endif //  defined(__SLOT_MACHINE__) //

