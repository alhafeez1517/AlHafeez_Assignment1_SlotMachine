#pragma once
#ifndef __WATER_MELON_IMAGE__
#define __WATER_MELON_IMAGE__
#include "DisplayObject.h"

class WaterMelonImage :public DisplayObject
{
public:
	WaterMelonImage(std::string imagePath = "../Assets/textures/watermelon.png",
		std::string imageName = "watermelon",
		GameObjectType type = WATER_MELON,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool isCentered = true);
	~WaterMelonImage();


	void draw() override;
	void update() override;
	void clean() override;
};

#endif //defined (__WATER_MELON_IMAGE)//