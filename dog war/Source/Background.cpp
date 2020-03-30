#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Background.h"

namespace game_framework
{
	background::background()
	{
		sx = 130;
		sy = 0;
	}
	void background::LoadBitmap()
	{
		map.AddBitmap(IDB_MAP);
	}

	void background::SetMovingUp(bool flag)
	{
		IsMovingUp = flag;
	}

	void background::SetMovingDown(bool flag)
	{
		IsMovingDown = flag;
	}
	int background::ScreenX(int x)
	{
		return x - sx;
	}
	void background::OnMove()
	{
		if (IsMovingUp)
		{
			if (sx < 0) sx = 0;
			else sx-=2;
			map.OnMove();
		}

		if (IsMovingDown)
		{
			if (sx > 130) sx = 130;
			else sx+=2;
			map.OnMove();
		}
	}
	void background::OnShow()
	{
		map.SetTopLeft(-sx, sy);
		map.OnShow();
	}
}