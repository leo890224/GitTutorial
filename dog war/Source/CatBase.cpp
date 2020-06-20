#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "CatBase.h"
#include "Dog.h"

namespace game_framework
{
	CatBase::CatBase()
	{
		const int X_POS = 668;
		const int Y_POS = 136;
		x = X_POS;
		y = Y_POS;
		blood = 4000;
	}

	int CatBase::GetX2()
	{
		return x + good.Width();
	}

	int CatBase::GetY2()
	{
		return y + good.Height();
	}

	void CatBase::LoadBitmap()
	{
		good.AddBitmap(cat_base, RGB(255, 255, 255));
	}

	void CatBase::OnMove()
	{
		isAttack = false;
	}
	
	bool CatBase::MeetDog(Dog *enemy)
	{
		if (!isDead)
		{
			if (enemy->isAlive() && x <= enemy->GetX2())
			{
				return true;
			}
		}
		return false;
	}

	void CatBase::OnShow(Background* map)
	{
		good.SetTopLeft(map->ScreenX(x), y);
		good.OnShow();
	}

	CatBase::~CatBase()
	{
	}
}