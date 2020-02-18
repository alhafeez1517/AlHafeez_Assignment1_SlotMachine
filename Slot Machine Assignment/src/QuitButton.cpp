#include "QuitButton.h"
#include "Game.h"

QuitButton::QuitButton()
	:Button(
		"../Assets/textures/Quit.png",
		"quit",
		QUIT_BUTTON, glm::vec2(400.0f, 525.0f)), m_isClicked(false)
{
}

QuitButton::~QuitButton()
{
}

bool QuitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			m_isClicked = true;
			TheGame::Instance()->quit();
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
