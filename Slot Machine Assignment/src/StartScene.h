#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"

class StartScene : public Scene
{
public:
	// constructor
	StartScene();
	// destructor
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	Label* m_pTitleLabel;
	Label* m_pInstructionLabel;
	StartButton* m_pStartButton;
	glm::vec2 m_mousePosition;
	
};

#endif /* defined (__START_SCENE__) */