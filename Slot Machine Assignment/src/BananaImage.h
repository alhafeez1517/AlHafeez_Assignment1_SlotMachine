
#pragma once
#ifndef __BANANA_IMAGE__
#define __BANANA_IMAGE__
#include "DisplayObject.h"

class BananaImage :public DisplayObject
{
public:
	BananaImage(std::string imagePath = "../Assets/textures/banana.png",
		std::string imageName = "banana",
		GameObjectType type = BANANA,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool isCentered = true);
	~BananaImage();


	void draw() override;
	void update() override;
	void clean() override;

};
#endif // defined (__BANANA_IMAGE__) //
