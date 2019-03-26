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
#include "SfxSound.hpp"

namespace EvolutionEngine
{

	SfxSound::SfxSound(char * _file, bool _inLoop, int _channel) : Sound(SOUND_TYPE::SFX, _inLoop, _channel)
	{
		LoadAudio(_file);
	}


	SfxSound::~SfxSound()
	{

	}

	std::shared_ptr<Mix_Chunk> SfxSound::GetAudio()
	{
		return this->m_chunk;
	}

	void SfxSound::SetAudio(std::shared_ptr<Mix_Chunk>  _audio)
	{
		
		this->m_chunk = _audio;
	}

	void SfxSound::LoadAudio(char * _file)
	{
		Mix_Chunk * chunk = this->m_chunk.get();
		SDL_Helper::Instance()->SDL_LoadSound(&chunk, _file);
	}

	void SfxSound::End()
	{
		SDL_Helper::Instance()->SDL_DestroySound(this->m_chunk.get());
	}

	void SfxSound::Play()
	{
		SDL_Helper::Instance()->SDL_PlaySound(this->m_chunk.get(), this->m_channel);
	}

	void SfxSound::Resume()
	{
		SDL_Helper::Instance()->SDL_ResumeChannel(this->m_channel);
	}

	void SfxSound::Pause()
	{
		SDL_Helper::Instance()->SDL_PauseChannel(this->m_channel);
	}
}