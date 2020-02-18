#include "SpinButton.h"
#include "Game.h"

SpinButton::SpinButton()
	:Button(
		"../Assets/textures/Spin.png",
		"spin",
		SPIN_BUTTON, glm::vec2(700.0f, 525.0f)),m_isClicked(false)
{
	
	
}

SpinButton::~SpinButton()
{
}

bool SpinButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
		
			m_isClicked = true;

#pragma region Actual Code
           /* playerBet = $("div#betEntry>input").val();

            if (playerMoney == 0)
            {
                if (confirm("You ran out of Money! \nDo you want to play again?")) {
                    resetAll();
                    showPlayerStats();
                }
            }
            else if (playerBet > playerMoney) {
                alert("You don't have enough Money to place that bet.");
            }
            else if (playerBet < 0) {
                alert("All bets must be a positive $ amount.");
            }
            else if (playerBet <= playerMoney) {
                spinResult = Reels();
                fruits = spinResult[0] + " - " + spinResult[1] + " - " + spinResult[2];
                $("div#result>p").text(fruits);
                determineWinnings();
                turn++;
                showPlayerStats();
            }
            else {
                alert("Please enter a valid bet amount");
            }*/
#pragma endregion
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
