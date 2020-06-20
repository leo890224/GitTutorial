#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Background.h"
#include "Long_Leg_Cat.h"
#include "Dog.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// Long_Leg_Cat: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	Long_Leg_Cat::Long_Leg_Cat()
	{
		srand((int)time(NULL));
		int random = rand() % 20 - 15;
		const int X_POS = 680;
		const int Y_POS = 145;
		x = X_POS;
		y = Y_POS + random;
		Attack = 20;
		blood = 200;
		floor = 145 + random;
		initial_velocity = velocity = 10;
		rising = isJump = isAttack = isDead = false;
		count = delay_count = 0;
	}

	int Long_Leg_Cat::GetX2()
	{
		return x + walk.Width();
	}

	int Long_Leg_Cat::GetY2()
	{
		return y + die.Height();
	}

	void Long_Leg_Cat::LoadBitmap()
	{
		walk.AddBitmap(long_leg_cat, RGB(255, 255, 255));
		walk.AddBitmap(long_leg_cat2, RGB(255, 255, 255));
		walk.AddBitmap(long_leg_cat3, RGB(255, 255, 255));
		walk.AddBitmap(long_leg_cat4, RGB(255, 255, 255));
		walk.AddBitmap(long_leg_cat5, RGB(255, 255, 255));
		walk.AddBitmap(long_leg_cat6, RGB(255, 255, 255));
		punch.AddBitmap(long_leg_cat_punch, RGB(255, 255, 255));
		attack.AddBitmap(long_leg_cat_attack1, RGB(255, 255, 255));
		attack.AddBitmap(long_leg_cat_attack, RGB(255, 255, 255));
		attack.AddBitmap(long_leg_cat_attack2, RGB(255, 255, 255));
		attack.AddBitmap(long_leg_cat_attack3, RGB(255, 255, 255));
		attack.AddBitmap(long_leg_cat_attack4, RGB(255, 255, 255));
		die.AddBitmap(die1, RGB(255, 255, 255));
		die.AddBitmap(die2, RGB(255, 255, 255));
		die.AddBitmap(die3, RGB(255, 255, 255));
		die.AddBitmap(die4, RGB(255, 255, 255));
	}

	void Long_Leg_Cat::OnMove()
	{
		const int STEP_SIZE = 2;

		if (!isDead)
		{
			if (!isJump && !isAttack)
			{
				x -= STEP_SIZE;
				walk.SetDelayCount(5);
				walk.OnMove();
			}

			if (isAttack)
			{
				attack.SetDelayCount(5);

				if (attack.IsFinalBitmap())
				{
					attack.SetDelayCount(50);
				}

				attack.OnMove();
			}

			Jump();
		}
		else
		{
			if (count == 0) x -= STEP_SIZE;

			if (count % 4 < 2)
			{
				x += STEP_SIZE * 2;
			}
			else
			{
				x -= STEP_SIZE * 2;
			}

			y -= 5;
			count++;
			die.SetDelayCount(10);
			die.OnMove();
		}
	}

	bool Long_Leg_Cat::MeetDog(Dog* enemy)
	{
		if (!isDead)
		{
			if (enemy->isAlive() && x <= enemy->GetX2())
			{
				if (delay_count-- <= 0)
				{
					delay_count = 70;
					enemy->Hurt(Attack);
				}
				return true;
			}
			return false;
		}
		return false;
	}

	void Long_Leg_Cat::Jump()
	{
		if (rising)  			// 上升狀態
		{
			if (velocity > 0)
			{
				y -= velocity;	// 當速度 > 0時，y軸上升(移動velocity個點，velocity的單位為 點/次)
				x += 3;
				velocity--;		// 受重力影響，下次的上升速度降低
			}
			else
			{
				rising = false; // 當速度 <= 0，上升終止，下次改為下降
				velocity = 1;	// 下降的初速(velocity)為1
			}

			isJump = true;
		}
		else  				// 下降狀態
		{
			if (y < floor)    // 當y座標還沒碰到地板
			{
				x += 3;
				y += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
				velocity++;		// 受重力影響，下次的下降速度增加
			}
			else
			{
				y = floor;  // 當y座標低於地板，更正為地板上
				velocity = initial_velocity; // 重設上升初始速度
				isJump = false;
			}
		}
	}

	void Long_Leg_Cat::OnShow(Background* map)
	{
		if (!isDead)
		{
			if (!isAttack && !isJump)
			{
				walk.SetTopLeft(map->ScreenX(x), y);
				walk.OnShow();
			}

			if (isJump)
			{
				punch.SetTopLeft(map->ScreenX(x), y-40);
				punch.OnShow();

				if (y == floor && blood <= 0)
				{
					isDead = true;
				}
			}

			if (isAttack)
			{
				if ((blood == 40 || blood <= 0) && delay_count <= 0)
				{
					if (diff) rising = true;
					isAttack = false;
					diff = false;
				}

				attack.SetTopLeft(map->ScreenX(x-173), y-105);
				attack.OnShow();
			}
		}
		else
		{
			die.SetTopLeft(map->ScreenX(x), y);
			die.OnShow();
		}
	}
}