#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Cat.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// Cat: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	Cat::Cat()
	{
		x = y = 0;
		Attack = 0;
		blood = 0;
		floor = 0;
		isAttack = isDead = diff = false;
		count = delay_count = 0;
	}

	int Cat::GetX1()
	{
		return x;
	}

	int Cat::GetY1()
	{
		return y;
	}

	bool Cat::isAlive()
	{
		return !isDead;
	}

	void Cat::SetAttack(bool flag)
	{
		isAttack = flag;
	}

	int Cat::GetBlood()
	{
		return blood;
	}

	void Cat::Hurt(int attack)
	{
		if (attack != 0) diff = true;
		blood -= attack;
	}
}