#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Background.h"

namespace game_framework
{
	Background::Background()
	{
		sx = 130;
		sy = 0;
		IsMovingLeft = IsMovingRight = false;
	}
	void Background::LoadBitmap()
	{
		map.AddBitmap(IDB_MAP);
	}

	void Background::SetMovingLeft(bool flag)
	{
		IsMovingLeft = flag;
	}

	void Background::SetMovingRight(bool flag)
	{
		IsMovingRight = flag;
	}
	int Background::ScreenX(int x)
	{
		return x - sx;
	}
	void Background::OnMove()
	{
		if (IsMovingLeft)
		{
			if (sx < 0) sx = 0;
			else sx-=2;
			map.OnMove();
		}

		if (IsMovingRight)
		{
			if (sx > 130) sx = 130;
			else sx+=2;
			map.OnMove();
		}
	}
	void Background::OnShow()
	{
		map.SetTopLeft(-sx, sy);
		map.OnShow();
	}
}