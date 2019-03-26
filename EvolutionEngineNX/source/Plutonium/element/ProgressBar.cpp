#include "../pu/element/ProgressBar.hpp"

namespace pu
{
	namespace element
	{

		ProgressBar::ProgressBar(u32 X, u32 Y, u32 Width, u32 Height) : Element::Element()
		{
			this->x = X;
			this->y = Y;
			this->w = Width;
			this->h = Height;
			this->clr = { 140, 140, 140, 255 };
			this->oclr = { 139, 195, 74, 255 };
			this->perc = 0;
		}

		u32 ProgressBar::GetX()
		{
			return this->x;
		}

		void ProgressBar::SetX(u32 X)
		{
			this->x = X;
		}

		u32 ProgressBar::GetY()
		{
			return this->y;
		}

		void ProgressBar::SetY(u32 Y)
		{
			this->y = Y;
		}

		u32 ProgressBar::GetWidth()
		{
			return this->w;
		}

		void ProgressBar::SetWidth(u32 Width)
		{
			this->w = Width;
		}

		u32 ProgressBar::GetHeight()
		{
			return this->h;
		}

		void ProgressBar::SetHeight(u32 Height)
		{
			this->h = Height;
		}

		draw::Color ProgressBar::GetColor()
		{
			return this->clr;
		}

		void ProgressBar::SetColor(draw::Color Color)
		{
			this->clr = Color;
		}

		draw::Color ProgressBar::GetProgressColor()
		{
			return this->oclr;
		}

		void ProgressBar::SetProgressColor(draw::Color Color)
		{
			this->oclr = Color;
		}

		u8 ProgressBar::GetProgress()
		{
			return this->perc;
		}

		void ProgressBar::SetProgress(u8 Percentage)
		{
			if (Percentage >= 100) this->perc = 100;
			else this->perc = Percentage;
		}

		void ProgressBar::IncrementProgress(u8 Percentage)
		{
			u8 res = (this->perc + Percentage);
			if (res >= 100) this->perc = 100;
			else this->perc = res;
		}

		void ProgressBar::DecrementProgress(u8 Percentage)
		{
			this->perc -= Percentage;
		}

		void ProgressBar::FillProgress()
		{
			this->perc = 100;
		}

		void ProgressBar::ClearProgress()
		{
			this->perc = 0;
		}

		bool ProgressBar::IsCompleted()
		{
			return (this->perc >= 100);
		}

		void ProgressBar::OnRender(render::Renderer *Drawer)
		{
			u32 rad = (this->h / 2);
			Drawer->RenderRectangleFill(this->clr, this->x, this->y, this->w, this->h);
			u32 pcw = ((this->perc * this->w) / 100);
			Drawer->RenderRectangleFill(this->oclr, this->x, this->y, pcw, this->h);
		}

		void ProgressBar::OnInput(u64 Down, u64 Up, u64 Held, bool Touch, bool Focus)
		{
		}
	}
}