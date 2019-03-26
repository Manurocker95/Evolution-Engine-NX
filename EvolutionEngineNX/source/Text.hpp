/* This file is part of T-Rekt NX!

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
#ifndef _TEXT_HPP_
#define _TEXT_HPP_

#include <string>
#include <functional>
#include <pu/element/Element.hpp>
#include "Plutonium/Include/pu/element/Element.hpp"

namespace EvolutionEngine
{
	namespace UI
	{
		class Text
		{
		private:
			pu::
			bool m_active;
			std::string m_text;
			bool m_customFont;
			int m_x;
			int m_y;
			int m_size;
	
			SDL_Color m_textColor;

		public:
			Text(std::string _text, u32 _x, u32 _y, int _size, bool _customFont, char * _font, SDL_Color _color);
			~Text();
			void Draw();
			void End();
			void SetText(std::string _text);
//			void SetFont(FC_Font *_font);
//			render::NativeFont * GetFont();
			void SetCustomFont(bool _value, char * _newFont);
			bool GetCustomFont();
			void LoadFont(char * _font);
			void SetColor(SDL_Color _color);
			bool IsActive();
			void SetActive(bool _value);

			int GetX();
			void SetX(int _value);
			int GetY();
			void SetY(int _value);

			void MoveX(int _value);
			void MoveY(int _value);
			void MoveToCoord(int _x, int _y);
		};
	}
	

}
#endif