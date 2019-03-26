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
#pragma once
#ifndef _GAME_SCREEN_HPP_
#define _GAME_SCREEN_HPP_

#include "Scene.hpp"
#include "SfxSound.hpp"
#include "MusicSound.hpp"
#include "Text.hpp"
#include "Settings.hpp"
#include <vector>
#include <string>

namespace EvolutionEngine
{
	class GameScreen : public Scene
	{
	private:

	private:

		Sprite * m_background;
	
		int m_tokenSize;
		int m_score;
		// Text
		Text * m_scoreText;
		Text * m_debugText;

		// Music and SFX
		MusicSound * m_music;
		SfxSound * m_pointSFX;

	public:

		GameScreen(Settings * _settings);									// Constructor
		~GameScreen();														// Destructor
		void Start() override;							// initialize
		void Draw() override;												// Draw
		void CheckInputs(u64 kDown, u64 kHeld, u64 kUp) override;			// CheckInput
		void Update() override;												// Update
		void NextScene() override;
		void AddScore();
	};

}
#endif