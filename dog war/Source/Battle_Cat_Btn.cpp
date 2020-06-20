#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Battle_Cat_Btn.h"

namespace game_framework
{
	Battle_Cat_Btn::Battle_Cat_Btn()
	{
		const int X_POS = 396;
		const int Y_POS = 410;
		x = X_POS;
		y = Y_POS;
	}

	void Battle_Cat_Btn::LoadBitmap()
	{
		available.AddBitmap(battle_cat_btn, RGB(255, 255, 255));
		unavailable.AddBitmap(battle_cat_btn_dark, RGB(255, 255, 255));
	}

	void Battle_Cat_Btn::OnMove()
	{
		if (money >= 200 && delay_count <= 0)
		{
			if (isClick) {
				isClickable = false;
				delay_count = 90;
				isClick = false;
			}
			else isClickable = true;
		}
		else isClickable = false;
	}

	void Battle_Cat_Btn::OnShow()
	{
		if (isClickable) {
			available.SetTopLeft(x, y);
			available.OnShow();
		}
		else {
			unavailable.SetTopLeft(x, y);
			unavailable.OnShow();
			delay_count--;
		}
	}

	Battle_Cat_Btn::~Battle_Cat_Btn()
	{
	}
}