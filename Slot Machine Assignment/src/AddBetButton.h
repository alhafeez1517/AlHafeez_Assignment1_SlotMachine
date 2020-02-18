#pragma once
#ifndef  __ADD_BET_BUTTON__
#define __ADD_BET_BUTTON__

#include "Button.h"

class AddBetButton :public Button
{
public:
	AddBetButton();
	~AddBetButton();

	bool ButtonClick() override;
private:
	bool m_isClicked;

};
#endif // defined (__ADD_BET_BUTTON__) //

