#include "StartButton.h"
#include "Game.h"

StartButton::StartButton()
	// call super constructor
	:Button(
		"../Assets/textures/StartButton2.png",
		"startButton2",
		START_BUTTON, glm::vec2(400.0f, 350.0f)), m_isClicked(false)
{
	
}

StartButton::~StartButton()
{
}

bool StartButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			
			m_isClicked = true;
			Game::Instance()->changeSceneState(MACHINE_SCENE);
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


