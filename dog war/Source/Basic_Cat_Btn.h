#ifndef BASIC_CAT_BTN_H
#define BASIC_CAT_BTN_H
#include "Button.h"

namespace game_framework
{
	class Basic_Cat_Btn : public Button
	{
	public:
		Basic_Cat_Btn();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		~Basic_Cat_Btn();

	private:
		CAnimation available;
		CAnimation unavailable;
	};
}
#endif