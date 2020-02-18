#pragma once
#ifndef __ROTTEN__
#define __ROTTEN__

#include "DisplayObject.h"
class Rotten :public DisplayObject
{
public:

	Rotten(std::string imagePath = "../Assets/textures/rotten.png",
		std::string imageName = "rotten",
		GameObjectType type = ROTTEN,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool isCentered = true);
	~Rotten();

	void draw() override;
	void update() override;
	void clean() override;

};
#endif //defined(__ROTTEN__)//

