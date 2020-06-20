#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Upgrade_Btn.h"

namespace game_framework 
{
	Upgrage_btn::Upgrage_btn()
	{
		const int X_POS = 0;
		const int Y_POS = 386;
		x = X_POS;
		y = Y_POS;
	}

	void Upgrage_btn::LoadBitmap()
	{
		L1_available.AddBitmap(level1, RGB(255, 255, 255));
		L1_available.AddBitmap(level1_2, RGB(255, 255, 255));
		L1_unavailable.AddBitmap(level1_dark, RGB(255, 255, 255));
		L2_available.AddBitmap(level2, RGB(255, 255, 255));
		L2_available.AddBitmap(level2_2, RGB(255, 255, 255));
		L2_unavailable.AddBitmap(level2_dark, RGB(255, 255, 255));
		L3_available.AddBitmap(level3, RGB(255, 255, 255));
		L3_available.AddBitmap(level3_2, RGB(255, 255, 255));
		L3_unavailable.AddBitmap(level3_dark, RGB(255, 255, 255));
		L4_available.AddBitmap(level4, RGB(255, 255, 255));
		L4_available.AddBitmap(level4_2, RGB(255, 255, 255));
		L4_unavailable.AddBitmap(level4_dark, RGB(255, 255, 255));
		L5_available.AddBitmap(level5, RGB(255, 255, 255));
		L5_available.AddBitmap(level5_2, RGB(255, 255, 255));
		L5_unavailable.AddBitmap(level5_dark, RGB(255, 255, 255));
		L6_available.AddBitmap(level6, RGB(255, 255, 255));
		L6_available.AddBitmap(level6_2, RGB(255, 255, 255));
		L6_unavailable.AddBitmap(level6_dark, RGB(255, 255, 255));
		L7_available.AddBitmap(level7, RGB(255, 255, 255));
		L7_available.AddBitmap(level7_2, RGB(255, 255, 255));
		L7_unavailable.AddBitmap(level7_dark, RGB(255, 255, 255));
		L8_available.AddBitmap(level8, RGB(255, 255, 255));
	}

	void Upgrage_btn::SetLevel(int level)
	{
		this->level = level;
	}

	void Upgrage_btn::SetUpgradeMoney(int upgrade_money)
	{
		this->upgrage_money = upgrade_money;
	}

	void Upgrage_btn::OnMove()
	{
		if (money >= upgrage_money) isClickable = true;
		else isClickable = false;

		if (level == 1)
		{
			L1_available.SetDelayCount(4);
			L1_available.OnMove();
		}
		if (level == 2)
		{
			L2_available.SetDelayCount(4);
			L2_available.OnMove();
		}
		if (level == 3)
		{
			L3_available.SetDelayCount(4);
			L3_available.OnMove();
		}
		if (level == 4)
		{
			L4_available.SetDelayCount(4);
			L4_available.OnMove();
		}
		if (level == 5)
		{
			L5_available.SetDelayCount(4);
			L5_available.OnMove();
		}
		if (level == 6)
		{
			L6_available.SetDelayCount(4);
			L6_available.OnMove();
		}
		if (level == 7)
		{
			L7_available.SetDelayCount(4);
			L7_available.OnMove();
		}
	}

	void Upgrage_btn::OnShow()
	{
		if (level == 1)
		{
			if (isClickable){
				L1_available.SetTopLeft(x, y);
				L1_available.OnShow();
			}
			else {
				L1_unavailable.SetTopLeft(x, y);
				L1_unavailable.OnShow();
			}
		}

		if (level == 2)
		{
			if (isClickable) {
				L2_available.SetTopLeft(x, y);
				L2_available.OnShow();
			}
			else {
				L2_unavailable.SetTopLeft(x, y);
				L2_unavailable.OnShow();
			}
		}

		if (level == 3)
		{
			if (isClickable) {
				L3_available.SetTopLeft(x, y);
				L3_available.OnShow();
			}
			else {
				L3_unavailable.SetTopLeft(x, y);
				L3_unavailable.OnShow();
			}
		}
		if (level == 4)
		{
			if (isClickable) {
				L4_available.SetTopLeft(x, y);
				L4_available.OnShow();
			}
			else {
				L4_unavailable.SetTopLeft(x, y);
				L4_unavailable.OnShow();
			}
		}

		if (level == 5)
		{
			if (isClickable) {
				L5_available.SetTopLeft(x, y);
				L5_available.OnShow();
			}
			else {
				L5_unavailable.SetTopLeft(x, y);
				L5_unavailable.OnShow();
			}
		}

		if (level == 6)
		{
			if (isClickable) {
				L6_available.SetTopLeft(x, y);
				L6_available.OnShow();
			}
			else {
				L6_unavailable.SetTopLeft(x, y);
				L6_unavailable.OnShow();
			}
		}

		if (level == 7)
		{
			if (isClickable) {
				L7_available.SetTopLeft(x, y);
				L7_available.OnShow();
			}
			else {
				L7_unavailable.SetTopLeft(x, y);
				L7_unavailable.OnShow();
			}
		}
		if (level == 8)
		{
			L8_available.SetTopLeft(x, y);
			L8_available.OnShow();
		}

	}

	Upgrage_btn::~Upgrage_btn()
	{
	}
}