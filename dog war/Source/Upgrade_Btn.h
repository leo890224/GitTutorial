#ifndef UPGRADE_BTN_H
#define UPGRADE_BTN_H
#include "Button.h"

namespace game_framework
{
	class Upgrage_btn : public Button
	{
	public:
		Upgrage_btn();
		void LoadBitmap();
		void SetLevel(int);
		void SetUpgradeMoney(int);
		void OnMove();
		void OnShow();
		~Upgrage_btn();

	private:
		CAnimation L1_available;
		CAnimation L1_unavailable;
		CAnimation L2_available;
		CAnimation L2_unavailable;
		CAnimation L3_available;
		CAnimation L3_unavailable;
		CAnimation L4_available;
		CAnimation L4_unavailable;
		CAnimation L5_available;
		CAnimation L5_unavailable;
		CAnimation L6_available;
		CAnimation L6_unavailable;
		CAnimation L7_available;
		CAnimation L7_unavailable;
		CAnimation L8_available;
		int level;
		int upgrage_money;
	};
}
#endif