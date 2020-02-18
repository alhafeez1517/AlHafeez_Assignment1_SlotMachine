#pragma once
#ifndef __MACHINE_SCENE__
#define __MACHINE_SCENE__

#include "Scene.h"
#include "SpinButton.h"
#include "ResetButton.h"
#include "QuitButton.h"
#include "AddBetButton.h"
#include "ReduceBetButton.h"
#include "Label.h"
#include "Config.h"
#include "SlotMachine.h"
#include "KiwiImage.h"
#include "BananaImage.h"
#include "WaterMelonImage.h"
#include "Rotten.h"

class MachineScene :public Scene
{
public:

	MachineScene();
	~MachineScene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;


	void drawKiwi();
	void drawBanana();
	void drawWaterMelon();

	void resetTally();
	void increaseBetAmount();
	void decreaseBetAmount();
	void spinButtonCall();
	void resetButtonCall();
	void Reels();
	void determineWinnings();
	bool checkRange(int val, int upper, int lower);


	void resetAll();
	void checkJackpot();
	void showWinMessage();
	void showLossMessage();

	int playerMoney = 1000;
	int playerBet = 0;
	int winnings = 0;
	int jackpot = 5000;
	int turn = 0;
    int winNumber = 0;
	int lossNumber = 0;
	int winRatio = 0;
	int kiwis = 0;
	int bananas = 0;
	int watermelons = 0;
	int cherries = 0;
	int bars = 0;
	int bells = 0;
	int seven = 0;
	int rottens = 0;

	std::string playerBetText;
	std::string playerAmountText;
	std::string playerJackpotText;
	std::string playerTurnsText;
	std::string playerWinsText;
	std::string playerLossText;
	SDL_Color red;

private:

	std::string ReelResults[3] = { "","","" };
	//static MachineScene* s_pInstance;
	glm::vec2 m_mousePosition;

#pragma region Images
	SlotMachine* m_pSlotMachine;
	KiwiImage* m_pKiwi;
	BananaImage* m_pBanana;
	WaterMelonImage* m_pWaterMelon;
	Rotten* m_pRotten;
#pragma endregion

#pragma region Labels
	Label* m_pPlayerMoney;
	Label* m_pPlayerBets;
	Label* m_pPlayerJackpot;
	Label* m_pPlayerWins;
	Label* m_pPlayerLoss;
	Label* m_pPlayerTurns;
	Label* m_pPlayerResult;

	Label* m_pLoseMessage;
#pragma endregion

#pragma region Buttons
	SpinButton* m_pSpinButton;
	ResetButton* m_pResetButton;
	QuitButton* m_pQuitButton;
	AddBetButton* m_pAddBetButton;
	ReduceBetButton* m_pReduceBetButton;
	
#pragma endregion



};


#endif /* defined(__MACHINE_SCENE__)*/
