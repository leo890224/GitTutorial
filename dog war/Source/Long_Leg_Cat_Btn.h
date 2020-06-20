#ifndef LONG_LEG_CAT_BTN_H
#define LONG_LEG_CAT_BTN_H
#include "Button.h"

namespace game_framework
{
	class Long_Leg_Cat_Btn : public Button
	{
	public:
		Long_Leg_Cat_Btn();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		~Long_Leg_Cat_Btn();

	private:
		CAnimation available;
		CAnimation unavailable;
	};
}
#endif