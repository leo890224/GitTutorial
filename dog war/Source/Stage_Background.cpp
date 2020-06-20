#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage_Background.h"

namespace game_framework
{
	Stage_Background::Stage_Background()
	{
		sx = 130;
		sy = 0;
		IsMovingLeft = IsMovingRight = false;
	}
	void Stage_Background::LoadBitmap()
	{
		map.LoadBitmap(IDB_MAP);
	}

	void Stage_Background::SetMovingLeft(bool flag)
	{
		IsMovingLeft = flag;
	}

	void Stage_Background::SetMovingRight(bool flag)
	{
		IsMovingRight = flag;
	}
	int Stage_Background::ScreenX(int x)
	{
		return x - sx;
	}
	void Stage_Background::OnMove()
	{
		if (IsMovingLeft)
		{
			if (sx < 0) sx = 0;
			else sx -= 2;
		}

		if (IsMovingRight)
		{
			if (sx > 130) sx = 130;
			else sx += 2;
		}
	}
	void Stage_Background::OnShow()
	{
		map.SetTopLeft(-sx, sy);
		map.ShowBitmap();
	}
}