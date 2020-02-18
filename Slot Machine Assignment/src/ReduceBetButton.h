#pragma once
#ifndef __REDUCE_BET_BUTTON__
#define __REDUCE_BET_BUTTON__
#include "Button.h"

class ReduceBetButton :public Button
{
public:
	ReduceBetButton();
	~ReduceBetButton();

	bool ButtonClick() override;
private:
	bool m_isClicked;
};
#endif // (__REDUCE_BET_BUTTON__) //

