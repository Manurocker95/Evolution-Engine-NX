/* This file is part of Manurocker95's Template!

this is made for my tutorial: https://gbatemp.net/threads/tutorial-setting-up-visual-studio-2017-environment-for-nintendo-switch-homebrew-development.525977/#post-8439059

Copyright (C) 2018/2019 Manuel Rodríguez Matesanz
>    This program is free software: you can redistribute it and/or modify
>    it under the terms of the GNU General Public License as published by
>    the Free Software Foundation, either version 3 of the License, or
>    (at your option) any later version.
>
>    This program is distributed in the hope that it will be useful,
>    but WITHOUT ANY WARRANTY; without even the implied warranty of
>    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
>    GNU General Public License for more details.
>
>    You should have received a copy of the GNU General Public License
>    along with this program.  If not, see <http://www.gnu.org/licenses/>.
>    See LICENSE for information.
*/

#include "GameScreen.hpp"
#include "SceneManager.hpp"
#include "Filepaths.h"
#include "Colors.h"
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
// swap algorithm example (C++98)
#include <iostream>     // std::cout

namespace EvolutionEngine
{

	GameScreen::GameScreen(Settings * _settings) : Scene(_settings)
	{
		this->m_settings = _settings;
		this->m_changeScene = false;
		this->m_tokenSize = _settings->m_tokenSize;
		this->m_score = 0;
		srand(time(NULL));

	}

	GameScreen::~GameScreen()
	{
		this->m_music->End();
		delete(this->m_music);

		this->m_background->End();
		delete(this->m_background);

		this->m_scoreText->End();
		delete(this->m_scoreText);

		this->m_debugText->End();
		delete(this->m_debugText);

	}

	void GameScreen::Start()
	{
		this->m_background = new Sprite(0, 0, IMG_BACKGROUND, 1, 1, SWITCH_SCREEN_WIDTH, SWITCH_SCREEN_HEIGHT, 0, 0, false, false, 1);

		this->m_scoreText = new Text(std::string(LocalizationManager::Instance()->GetText("scoreText")) + std::to_string(this->m_score), 1000, 30, 30, true, FONT_NORMAL, C_WHITE);
		this->m_debugText = new Text("DEBUG TEXT", 30, 630, 15, true, FONT_NORMAL, C_WHITE);
		this->m_pointSFX = new SfxSound(SND_SFX_POINT, false, 2);
		this->m_music = new MusicSound(SND_BGM_GAME, true, 1);
		this->m_music->Play();

		if (this->m_settings->m_muted)
			SDL_Helper::Instance()->SDL_PauseMusic();

	}

	void GameScreen::Draw()
	{
		this->m_background->Draw();

		if (this->m_debugMode)
			this->m_debugText->Draw();
	}

	void GameScreen::Update()
	{
		if (this->m_changeScene)
		{
			NextScene();
		}
		else
		{
		}
	}

	void GameScreen::CheckInputs(u64 kDown, u64 kHeld, u64 kUp)
	{
		
		if (kDown & KEY_R && kDown & KEY_L)
		{
			this->m_debugMode = !this->m_debugMode;
		}

		if (kDown & KEY_PLUS)
		{
			this->m_changeScene = true;
		}

		if (kDown & KEY_MINUS)
		{
			AddScore();
		}
	}

	void GameScreen::AddScore()
	{
		++this->m_score;
		this->m_scoreText->SetText(std::string(LocalizationManager::Instance()->GetText("scoreText")) + std::to_string(this->m_score));

		if (!this->m_muted)
			m_pointSFX->Play();
	}

	// * We go to the next scene = GameScreen
	void GameScreen::NextScene()
	{
		this->m_settings->m_debugMode = this->m_debugMode;
		SceneManager::Instance()->SaveData(this->m_score);
		SceneManager::Instance()->LoadScene(SceneManager::TITLE);
	}
}