#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Basic_Cat_Btn.h"

namespace game_framework
{
	Basic_Cat_Btn::Basic_Cat_Btn()
	{
		const int X_POS = 135;
		const int Y_POS = 410;
		x = X_POS;
		y = Y_POS;
	}

	void Basic_Cat_Btn::LoadBitmap()
	{
		available.AddBitmap(basic_cat_btn, RGB(255, 255, 255));
		unavailable.AddBitmap(basic_cat_btn_dark, RGB(255, 255, 255));
	}

	void Basic_Cat_Btn::OnMove()
	{
		if (money >= 50 && delay_count <= 0)
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

	void Basic_Cat_Btn::OnShow()
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

	Basic_Cat_Btn::~Basic_Cat_Btn()
	{
	}
}