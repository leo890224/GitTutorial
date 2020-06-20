#ifndef TANK_CAT_BTN_H
#define TANK_CAT_BTN_H
#include "Button.h"

namespace game_framework
{
	class Tank_Cat_Btn : public Button
	{
	public:
		Tank_Cat_Btn();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		~Tank_Cat_Btn();

	private:
		CAnimation available;
		CAnimation unavailable;
	};
}
#endif