#include "..\src\MachineScene.h"
#include "..\src\Game.h"
#include <iostream>
#include <GLM\glm\gtx\string_cast.hpp>




MachineScene::MachineScene()
{
	
	red = { 255, 0, 0, 0 };

	MachineScene::start();

	
}

MachineScene::~MachineScene()
{
}

void MachineScene::draw()
{
	m_pSlotMachine->draw();
	drawKiwi();
	drawBanana();
	drawWaterMelon();
	m_pKiwi->draw();
	m_pWaterMelon->draw();
	m_pBanana->draw();


#pragma region Button Drawings
	m_pSpinButton->draw();
	m_pResetButton->draw();
	m_pQuitButton->draw();
	m_pAddBetButton->draw();
	m_pReduceBetButton->draw();
#pragma endregion

    
#pragma region Label Drawings
	m_pPlayerMoney->draw();
	m_pPlayerBets->draw();
	m_pPlayerJackpot->draw();
	m_pPlayerTurns->draw();
	m_pPlayerWins->draw();
	m_pPlayerLoss->draw();
#pragma endregion

}

void MachineScene::update()
{
	m_pSpinButton->setMousePosition(m_mousePosition);
	m_pSpinButton->ButtonClick();

	m_pResetButton->setMousePosition(m_mousePosition);
	m_pResetButton->ButtonClick();

	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();

	m_pAddBetButton->setMousePosition(m_mousePosition);
	m_pAddBetButton->ButtonClick();

	m_pReduceBetButton->setMousePosition(m_mousePosition);
	m_pReduceBetButton->ButtonClick();

    if (m_pAddBetButton->ButtonClick())
	{
	   increaseBetAmount();
	   m_pAddBetButton->setMouseButtonClicked(false);
	}

	if (m_pReduceBetButton->ButtonClick())
	{
		decreaseBetAmount();
		m_pReduceBetButton->setMouseButtonClicked(false);
	}

	if (m_pSpinButton->ButtonClick())
	{
		spinButtonCall();
		m_pSpinButton->setMouseButtonClicked(false);
	}

	if (m_pResetButton->ButtonClick())
	{
		resetButtonCall();
		m_pResetButton->setMouseButtonClicked(false);
	}
	

}

void MachineScene::clean()
{
	delete m_pPlayerJackpot;
	delete m_pPlayerBets;
	delete m_pPlayerJackpot;
	delete m_pPlayerTurns;
	delete m_pPlayerWins;
	delete m_pPlayerLoss;

	removeAllChildren();
}

void MachineScene::handleEvents()
{

	int wheel = 0;

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			//std::cout << "MouseX:" << m_mousePosition.x << std::endl;
			//std::cout << "MouseY:" << m_mousePosition.y << std::endl;
			
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinButton->setMouseButtonClicked(true);
				m_pResetButton->setMouseButtonClicked(true);
				m_pQuitButton->setMouseButtonClicked(true);
				m_pAddBetButton->setMouseButtonClicked(true);
				m_pReduceBetButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinButton->setMouseButtonClicked(false);
				m_pResetButton->setMouseButtonClicked(false);
				m_pQuitButton->setMouseButtonClicked(false);
				m_pAddBetButton->setMouseButtonClicked(false);
				m_pReduceBetButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				//TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				//TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
		
			
			case SDLK_w:
				
				break;
			case SDLK_s:
			
				break;
			case SDLK_a:
				
				break;
			case SDLK_d:
			
				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:
				
				break;
			case SDLK_d:
				
				break;
			}
			
			break;
		default:
			break;
		}
	}

}

void MachineScene::start()
{
#pragma region Images Initialization
	m_pSlotMachine = new SlotMachine();
	//m_pKiwi = new KiwiImage();
	m_pBanana = new BananaImage();
	m_pWaterMelon = new WaterMelonImage();
	m_pRotten = new Rotten();
#pragma endregion

#pragma region Texts
	playerBetText = "0";
	playerAmountText = "1000";
	playerJackpotText = "0";
	playerTurnsText = "0";
	playerWinsText = "0";
	playerLossText = "0";
#pragma endregion

#pragma region Button Initialization

	m_pSpinButton = new SpinButton();
	m_pSpinButton->setMouseButtonClicked(false);

	m_pResetButton = new ResetButton();
	m_pResetButton->setMouseButtonClicked(false);

	m_pQuitButton = new QuitButton();
	m_pQuitButton->setMouseButtonClicked(false);

	m_pAddBetButton = new AddBetButton();
	m_pAddBetButton->setMouseButtonClicked(false);

	m_pReduceBetButton = new ReduceBetButton();
	m_pReduceBetButton->setMouseButtonClicked(false);
#pragma endregion

#pragma region Label Initialization

	//Intializes the Player Money Label
	std::string playerMoneyText = std::to_string(playerMoney);
    m_pPlayerMoney = new Label
	("Money Left: "+playerMoneyText+"$", "Sony", 20, red, glm::vec2(100.0f,50.0f),false);
	m_pPlayerMoney->setParent(this);
	addChild(m_pPlayerMoney);

	//Initialized the Player Bet Label
	m_pPlayerBets = new Label
	("Player Bet Amount: " + playerBetText + "$", "Sony", 20, red, glm::vec2(115.0f, 80.0f), false);
	m_pPlayerBets->setParent(this);
	addChild(m_pPlayerBets);
	
	//Initialized the Jackpot Label
	
	m_pPlayerJackpot = new Label
	("Jackpot: "+ playerJackpotText + "$","Sony",20,red,glm::vec2(85.0f,110.0f),false);
	m_pPlayerJackpot->setParent(this);
	addChild(m_pPlayerJackpot);

    //Initialized the Turns Label
	m_pPlayerTurns = new Label
	("Turns: " + playerTurnsText, "Sony", 20, red, glm::vec2(85.0f, 140.0f), false);
	m_pPlayerTurns->setParent(this);
	addChild(m_pPlayerTurns);

	//Initialized the Wins Label
	m_pPlayerWins = new Label
	("Winnings: " + playerWinsText, "Sony", 20, red, glm::vec2(85.0f, 170.0f), false);
	m_pPlayerWins->setParent(this);
	addChild(m_pPlayerWins);

	//Initialized the Loses Label
	m_pPlayerLoss = new Label
	("Loses:" + playerLossText, "Sony", 20, red, glm::vec2(85.0f, 200.0f), false);
	m_pPlayerLoss->setParent(this);
	addChild(m_pPlayerLoss);



#pragma endregion

	
}

void MachineScene::drawKiwi()
{
	
				if (ReelResults[0] == "kiwi")
				{
					std::cout << "KIWII!!" << std::endl;
					m_pKiwi->setPosition(glm::vec2(287.0f, 305.0f));
					m_pKiwi->draw();
				}
				else if (ReelResults[1] == "kiwi")
				{
					m_pKiwi->setPosition(glm::vec2(382.0f, 305.0f));
					m_pKiwi->draw();
				}
				else if (ReelResults[2] == "kiwi")
				{
					m_pKiwi->setPosition(glm::vec2(477.0f, 305.0f));
					m_pKiwi->draw();
				}
				
}

void MachineScene::drawBanana()
{
	if (ReelResults[0] == "banana")
	{
		m_pBanana->setPosition(glm::vec2(287.0f, 305.0f));
		m_pBanana->draw();
	}
	else if (ReelResults[1] == "banana")
	{
		m_pBanana->setPosition(glm::vec2(382.0f, 305.0f));
		m_pBanana->draw();
	}
	else if (ReelResults[2] == "banana")
	{
		m_pBanana->setPosition(glm::vec2(477.0f, 305.0f));
		m_pBanana->draw();
	}
}

void MachineScene::drawWaterMelon()
{
	if (ReelResults[0] == "watermelon")
	{
		m_pWaterMelon->setPosition(glm::vec2(287.0f, 305.0f));
		m_pWaterMelon->draw();
	}
	else if (ReelResults[1] == "watermelon")
	{
		m_pWaterMelon->setPosition(glm::vec2(382.0f, 305.0f));
		m_pWaterMelon->draw();
	}
	else if (ReelResults[2] == "watermelon")
	{
		m_pWaterMelon->setPosition(glm::vec2(477.0f, 305.0f));
		m_pWaterMelon->draw();
	}
}

void MachineScene::resetTally()
{
	kiwis = 0;
	m_pKiwi->clean();
	bananas = 0;
	m_pBanana->clean();
	watermelons = 0;
	m_pWaterMelon->clean();
}

void MachineScene::increaseBetAmount()
{
	if (playerMoney > 0)
	{
		playerBet += 10;
		playerBetText = std::to_string(playerBet);
		m_pPlayerBets->setText("Player Bet Amount: "+playerBetText+"$");
	}
	else if (playerBet > playerMoney)
	{
		playerBet = playerMoney;
		playerBetText = std::to_string(playerBet);
		m_pPlayerBets->setText("Player Bet Amount: " + playerBetText + "$");

	}
	else
	{
		playerBet = 0;
	 playerBetText = std::to_string(playerBet);
	m_pPlayerBets->setText("Player Bet Amount: " + playerBetText + "$");
	}
}

void MachineScene::decreaseBetAmount()
{
	if (playerBet != 0)
	{
		playerBet -= 10;
		playerBetText = std::to_string(playerBet);
		m_pPlayerBets->setText("Player Bet Amount: " + playerBetText + "$");
	}
	else
	{
		playerBet = 0;
		playerBetText = std::to_string(playerBet);
		m_pPlayerBets->setText("Player Bet Amount: " + playerBetText + "$");
	}
}

void MachineScene::spinButtonCall()
{
	resetTally();
	if (playerMoney != 0 && playerBet <= playerMoney && playerBet>0)
	{ 
		Reels();
		determineWinnings();

		turn++;
		playerTurnsText = std::to_string(turn);
		m_pPlayerTurns->setText("Turns: " + playerTurnsText);
		
	}
		
		
		
}

void MachineScene::resetButtonCall()
{
	resetAll();
}

void MachineScene::Reels()
{
	std::string betLine[3] = { "","","" };
	int outCome[3] = { 0,0,0 };

	for (auto spin = 0; spin < 3; spin++) {
		outCome[spin] = rand() % 65 + 1;
		if (checkRange(outCome[spin], 1, 27)) // 41.5% probability
		{
			betLine[spin] = "rotten";
			rottens++;
		}
		else if (checkRange(outCome[spin], 28, 37)) // 15.4% probability
		{
			betLine[spin] = "kiwi";
			kiwis++;
		}
		else if (checkRange(outCome[spin], 38, 46))  // 13.8% probability
		{
			betLine[spin] = "banana";
			bananas++;
		}
		else if (checkRange(outCome[spin], 47, 54))// 12.3% probability
		{
			betLine[spin] = "watermelon";
			watermelons++;
		}
		else if (checkRange(outCome[spin], 55, 59))//  7.7% probability
		{
			betLine[spin] = "Cherry";
			cherries++;
		}
		else if (checkRange(outCome[spin], 60, 62))//  4.6% probability
		{
			betLine[spin] = "Bar";
			bars++;
		}
		else if (checkRange(outCome[spin], 63, 64)) //  3.1% probability
		{
			betLine[spin] = "Bell";
			bells++;
		}
		else if (checkRange(outCome[spin], 65, 65)) //  1.5% probability
		{
			betLine[spin] = "Seven";
			seven++;
		}
	}
	ReelResults[0] = betLine[0];
	ReelResults[1] = betLine[1];
	ReelResults[2] = betLine[2];
}

void MachineScene::determineWinnings()
{
	std::cout << kiwis << std::endl;
	std::cout << bananas << std::endl;
	std::cout << watermelons << std::endl;
	std::cout << cherries << std::endl;
	std::cout << bells << std::endl;
	std::cout << bars << std::endl;
	std::cout << seven << std::endl;
	std::cout << rottens << std::endl;
	if (rottens == 0)
	{

		if (kiwis == 3)
		{
			winnings = playerBet * 10;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);

		}
		else if (bananas == 3)
		{
			winnings = playerBet * 20;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (watermelons == 3)
		{
			winnings = playerBet * 30;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}

		else if (cherries == 3)
		{
			winnings = playerBet * 40;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (bars == 3)
		{
			winnings = playerBet * 50;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (bells == 3)
		{
			winnings = playerBet * 60;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (seven == 3)
		{
			winnings = playerBet * 150;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (kiwis == 2)
		{
			winnings = playerBet * 2;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (bananas == 2)
		{
			winnings = playerBet * 3;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (watermelons == 2)
		{
			winnings = playerBet * 4;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (cherries == 2)
		{
			winnings = playerBet * 5;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (bars == 2)
		{
			winnings = playerBet * 7;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (bells == 2)
		{
			winnings = playerBet * 8;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (seven == 2)
		{
			winnings = playerBet * 9;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		else if (seven == 1)
		{
			winnings = playerBet * 3;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}

		else
		{
			winnings = playerBet * 1;
			playerWinsText = std::to_string(winnings);
			m_pPlayerWins->setText("Winnings: " + playerWinsText);
		}
		winNumber++;
		checkJackpot();
		showWinMessage();

	}
	else
	{
		lossNumber++;
		playerLossText = std::to_string(lossNumber);
		m_pPlayerLoss->setText("Loses:" + playerLossText);

		playerMoney = playerMoney - playerBet;
		playerAmountText = std::to_string(playerMoney);
		m_pPlayerMoney->setText("Money Left: " + playerAmountText + "$");
	}
		
}

bool MachineScene::checkRange(int val, int upper, int lower)
{
	if (val >= lower && val <= upper)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void MachineScene::resetAll()
{
	playerMoney = 1000;
	playerAmountText = std::to_string(playerMoney);
	m_pPlayerMoney->setText("Money Left: " + playerAmountText + "$");

	lossNumber = 0;
	
	jackpot = 0;
	playerJackpotText = std::to_string(jackpot);
	m_pPlayerJackpot->setText("Jackpot: " + playerJackpotText);

	turn = 0;
	playerTurnsText = std::to_string(turn);
	m_pPlayerTurns->setText("Turns: " + playerTurnsText);

	playerBet = 0;
	playerBetText = std::to_string(playerBet);
	m_pPlayerBets->setText("Player Bet Amount: " + playerBetText + "$");

	winnings = 0;
	playerWinsText = std::to_string(winnings);
	m_pPlayerWins->setText("Winnings: " + playerWinsText);
	
}



void MachineScene::checkJackpot()
{
	auto jackPotTry = floor(rand() * 51 + 1);
	auto jackPotWin = floor(rand() * 51 + 1);
	if (jackPotTry == jackPotWin) 
	{
		
		playerMoney += jackpot;
		jackpot = 1000;
		playerJackpotText = std::to_string(jackpot);
		m_pPlayerJackpot->setText("Jackpot Earned! " + playerJackpotText + "$");
	}
	/*else
	{
		m_pPlayerJackpot->setText("No Jackpot for you!Better Luck Next Time" + playerJackpotText + "$");
	}*/
}

void MachineScene::showWinMessage()
{
	playerMoney += winnings;
	//playerWinsText = std::to_string(winnings);
	
	/*Label* m_pWinMessage = new Label
	("You Won " + playerWinsText, "Sony", 20, red, glm::vec2(85.0f, 200.0f), false);
	m_pWinMessage->draw();*/
	resetTally();
	
}

void MachineScene::showLossMessage()
{
	/*playerMoney -= playerBet;
	$("div#winOrLose>p").text("You Lost!");
	resetFTally();*/
}
