#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Tank_Cat_Btn.h"

namespace game_framework
{
	Tank_Cat_Btn::Tank_Cat_Btn()
	{
		const int X_POS = 222;
		const int Y_POS = 410;
		x = X_POS;
		y = Y_POS;
	}

	void Tank_Cat_Btn::LoadBitmap()
	{
		available.AddBitmap(tank_cat_btn, RGB(255, 255, 255));
		unavailable.AddBitmap(tank_cat_btn_dark, RGB(255, 255, 255));
	}

	void Tank_Cat_Btn::OnMove()
	{
		if (money >= 100 && delay_count <= 0)
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

	void Tank_Cat_Btn::OnShow()
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

	Tank_Cat_Btn::~Tank_Cat_Btn()
	{
	}
}