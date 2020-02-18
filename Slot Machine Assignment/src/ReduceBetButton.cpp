#include "ReduceBetButton.h"
#include "MachineScene.h"
#include "Game.h"

ReduceBetButton::ReduceBetButton()
	:Button(
		"../Assets/textures/ReduceBetButton.png",
		"reducebetbutton",
		REDUCE_BET_BUTTON, glm::vec2(280.0f, 80.0f)), m_isClicked(false)
{
}

ReduceBetButton::~ReduceBetButton()
{
}

bool ReduceBetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			m_isClicked = true;

		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
