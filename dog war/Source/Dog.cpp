#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Dog.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// Dog: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	Dog::Dog()
	{
		x = y = 0;
		Attack = 0;
		blood = 0;
		floor = 0;
		isAttack = isDead = diff = false;
		count = delay_count = 0;
		money = 0;
	}

	int Dog::GetX1()
	{
		return x;
	}

	int Dog::GetY1()
	{
		return y;
	}

	bool Dog::isAlive()
	{
		return !isDead;
	}

	void Dog::SetAttack(bool flag)
	{
		isAttack = flag;
	}

	void Dog::SetBlood(int max_blood)
	{
		blood = max_blood;
	}

	int Dog::GetBlood()
	{
		return blood;
	}

	int Dog::GetMoney()
	{
		return money;
	}

	void Dog::Hurt(int attack)
	{
		if (attack != 0) diff = true;
		blood -= attack;
	}
}