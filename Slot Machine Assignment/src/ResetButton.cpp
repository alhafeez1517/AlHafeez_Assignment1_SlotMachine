#include "ResetButton.h"
#include "MachineScene.h"
#include "Game.h"

ResetButton::ResetButton()
	:Button(
		"../Assets/textures/Reset.png",
		"reset",
		RESET_BUTTON, glm::vec2(100.0f, 525.0f)), m_isClicked(false)
{
}

ResetButton::~ResetButton()
{
}

bool ResetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			m_isClicked = true;
			
			//Game::Instance()->changeSceneState(START_SCENE);
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
