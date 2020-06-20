#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Button.h"

namespace game_framework
{
	Button::Button()
	{
		x = y = 0;
		isClick = false;
		isClickable = false;
		delay_count = 0;
	}

	void Button::onClick()
	{
		isClick = true;
	}

	void Button::SetMoney(int money)
	{
		this->money = money;
	}

	Button::~Button()
	{
	}
}
