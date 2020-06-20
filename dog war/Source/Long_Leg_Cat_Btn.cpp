#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Long_Leg_Cat_Btn.h"

namespace game_framework
{
	Long_Leg_Cat_Btn::Long_Leg_Cat_Btn()
	{
		const int X_POS = 309;
		const int Y_POS = 410;
		x = X_POS;
		y = Y_POS;
	}

	void Long_Leg_Cat_Btn::LoadBitmap()
	{
		available.AddBitmap(long_leg_cat_btn, RGB(255, 255, 255));
		unavailable.AddBitmap(long_leg_cat_btn_dark, RGB(255, 255, 255));
	}

	void Long_Leg_Cat_Btn::OnMove()
	{
		if (money >= 400 && delay_count <= 0)
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

	void Long_Leg_Cat_Btn::OnShow()
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

	Long_Leg_Cat_Btn::~Long_Leg_Cat_Btn()
	{
	}
}