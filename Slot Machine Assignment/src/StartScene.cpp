#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include "TileComparators.h"


StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	m_pTitleLabel->draw();
	m_pInstructionLabel->draw();
	m_pStartButton->draw();
	
}

void StartScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
}

void StartScene::clean()
{
	delete m_pTitleLabel;
	delete m_pInstructionLabel;
	
	removeAllChildren();
}

void StartScene::handleEvents()
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
			/*std::cout << "Mouse X: " << m_mousePosition.x << std::endl;
			std::cout << "Mouse Y: " << m_mousePosition.y << std::endl;
			std::cout << "---------------------------------------------" << std::endl;*/
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
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
				TheGame::Instance()->changeSceneState(SceneState::MACHINE_SCENE);
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

// this function is used for initialization
void StartScene::start()
{
	SDL_Color red = { 255, 0, 0, 0 };
	m_pTitleLabel = new Label
	("The Slot Machine Of Undvik", "Sony", 55, red, glm::vec2(400.0f, 50.0f));
	m_pTitleLabel->setParent(this);
	addChild(m_pTitleLabel);

	SDL_Color green = { 0,255,0,0 };
	m_pInstructionLabel = new Label
	("Press Start Button To Play","Sony",35,green,glm::vec2(400.0f,150.0f));
	m_pInstructionLabel->setParent(this);
	addChild(m_pInstructionLabel);

	m_pStartButton = new StartButton();
	m_pStartButton->setMouseButtonClicked(false);
		
	
}
