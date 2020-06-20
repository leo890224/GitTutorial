#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include "audio.h"
#include "gamelib.h"
#include "Background.h"
#include "Basic_Dog.h"
#include "Cat.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// Basic_Dog: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	Basic_Dog::Basic_Dog()
	{
		srand((int)time(NULL));
		int random = rand() % 20 - 15;
		const int X_POS = 75;
		const int Y_POS = 250;
		x = X_POS;
		y = Y_POS + random;
		Attack = 10;
		blood = 100;
		floor = 250 + random;
		initial_velocity = velocity = 10;
		rising = isJump = isAttack = isDead = false;
		count = delay_count = 0;
		money = 20;
	}

	int Basic_Dog::GetX2()
	{
		return x + walk.Width();
	}

	int Basic_Dog::GetY2()
	{
		return y + die.Height();
	}

	void Basic_Dog::LoadBitmap()
	{
		walk.AddBitmap(dog, RGB(255, 255, 255));
		walk.AddBitmap(dog2, RGB(255, 255, 255));
		walk.AddBitmap(dog, RGB(255, 255, 255));
		walk.AddBitmap(dog3, RGB(255, 255, 255));
		punch.AddBitmap(dog_punch, RGB(255, 255, 255));
		attack.AddBitmap(dog, RGB(255, 255, 255));
		attack.AddBitmap(dog_attack, RGB(255, 255, 255));
		attack.AddBitmap(dog_attack2, RGB(255, 255, 255));
		attack.AddBitmap(dog_attack, RGB(255, 255, 255));
		attack.AddBitmap(dog_attack3, RGB(255, 255, 255));
		die.AddBitmap(die1, RGB(255, 255, 255));
		die.AddBitmap(die2, RGB(255, 255, 255));
		die.AddBitmap(die3, RGB(255, 255, 255));
		die.AddBitmap(die4, RGB(255, 255, 255));
	}

	void Basic_Dog::OnMove()
	{
		const int STEP_SIZE = 2;

		if (!isDead)
		{
			if (!isJump && !isAttack)
			{
				x += STEP_SIZE;
				walk.SetDelayCount(5);
				walk.OnMove();
			}

			if (isAttack)
			{
				attack.SetDelayCount(5);

				if (attack.IsFinalBitmap())
				{
					attack.SetDelayCount(15);
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

	bool Basic_Dog::MeetCat(Cat* enemy)
	{
		if (!isDead)
		{
			if (enemy->isAlive() && (x + walk.Width() >= enemy->GetX1()))
			{
				if (delay_count-- <= 0)
				{
					delay_count = 35;
					enemy->Hurt(Attack);
				}
				return true;
			}
			return false;
		}
		return false;
	}

	void Basic_Dog::Jump()
	{
		if (rising)  			// �W�ɪ��A
		{
			if (velocity > 0)
			{
				y -= velocity;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				x -= 3;
				velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else
			{
				rising = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;	// �U������t(velocity)��1
			}

			isJump = true;
		}
		else  				// �U�����A
		{
			if (y < floor)    // ��y�y���٨S�I��a�O
			{
				x -= 3;
				y += velocity;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
			}
			else
			{
				y = floor;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
				velocity = initial_velocity; // ���]�W�ɪ�l�t��
				isJump = false;
			}
		}
	}

	void Basic_Dog::OnShow(Background* map)
	{
		if (!isDead)
		{
			if (!isJump && !isAttack)
			{
				walk.SetTopLeft(map->ScreenX(x), y);
				walk.OnShow();
			}

			if (isJump)
			{
				punch.SetTopLeft(map->ScreenX(x), y);
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

				attack.SetTopLeft(map->ScreenX(x), y);
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