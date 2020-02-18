#pragma once
#ifndef __KIWI_IMAGE__
#define __KIWI_IMAGE__
#include "DisplayObject.h"

class KiwiImage :public DisplayObject
{
public:
	KiwiImage(std::string imagePath = "../Assets/textures/kiwi.png",
		std::string imageName = "kiwi",
		GameObjectType type = KIWI,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool isCentered = true);
	~KiwiImage();


	void draw() override;
	void update() override;
	void clean() override;

};
#endif // defined (__IMAGE__) //
