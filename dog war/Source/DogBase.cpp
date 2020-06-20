#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include<string>
#include "audio.h"
#include "gamelib.h"
#include "DogBase.h"
#include "Cat.h"

namespace game_framework
{
	DogBase::DogBase()
	{
		const int X_POS = 63;
		const int Y_POS = 128;
		x = X_POS;
		y = Y_POS;
	}

	int DogBase::GetX2()
	{
		return x + good.Width();
	}

	int DogBase::GetY2()
	{
		return y + good.Height();
	}

	void DogBase::LoadBitmap()
	{
		good.AddBitmap(dog_base, RGB(255, 255, 255));
	}

	void DogBase::OnMove()
	{
		isAttack = false;
	}

	bool DogBase::MeetCat(Cat *enemy)
	{
		if (!isDead)
		{
			if (enemy->isAlive() && GetX2() >= enemy->GetX1())
			{
				return true;
			}
		}
		return false;
	}

	void DogBase::OnShow(Background *map)
	{
		good.SetTopLeft(map->ScreenX(x), y);
		good.OnShow();
	}

	DogBase::~DogBase()
	{
	}
}