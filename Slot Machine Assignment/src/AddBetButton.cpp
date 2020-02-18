#include "AddBetButton.h"
#include "Game.h"
#include "MachineScene.h"
#include <iostream>

AddBetButton::AddBetButton()
	:Button(
		"../Assets/textures/AddBetButton.png",
		"addbetbutton",
		ADD_BET_BUTTON, glm::vec2(250.0f, 80.0f)), m_isClicked(false)
{

}

AddBetButton::~AddBetButton()
{
}

bool AddBetButton::ButtonClick()
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
