#ifndef BATTLE_CAT_BTN_H
#define BATTLE_CAT_BTN_H
#include "Button.h"

namespace game_framework
{
	class Battle_Cat_Btn : public Button
	{
	public:
		Battle_Cat_Btn();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		~Battle_Cat_Btn();

	private:
		CAnimation available;
		CAnimation unavailable;
	};
}
#endif