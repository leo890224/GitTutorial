#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Background.h"
#include "CEraser.h"
#include "Dog.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Dog: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	Dog::Dog()
	{
		Initialize();
	}

	int Dog::GetX1()
	{
		return x;
	}

	int Dog::GetY1()
	{
		return y;
	}

	int Dog::GetX2()
	{
		return x + walk.Width();
	}

	int Dog::GetY2()
	{
		return y + walk.Height();
	}

	void Dog::Initialize()
	{
		const int X_POS = 75;
		const int Y_POS = 270;
		x = X_POS;
		y = Y_POS;
		floor = 270;
		initial_velocity = velocity = 10;
		rising = isMovingLeft = isMovingRight = isAttack = false;
	}

	void Dog::LoadBitmap()
	{
		walk.AddBitmap(dog, RGB(255, 255, 255));
		walk.AddBitmap(dog2, RGB(255, 255, 255));
		walk.AddBitmap(dog, RGB(255, 255, 255));
		walk.AddBitmap(dog3, RGB(255, 255, 255));
		punch.AddBitmap(dog_punch, RGB(255, 255, 255));
		attack.AddBitmap(dog_attack, RGB(255, 255, 255));
		attack.AddBitmap(dog_attack2, RGB(255, 255, 255));
		attack.AddBitmap(dog_attack, RGB(255, 255, 255));
		attack.AddBitmap(dog_attack3, RGB(255, 255, 255));
		attack.AddBitmap(dog_attack, RGB(255, 255, 255));
	}

	void Dog::OnMove()
	{
		const int STEP_SIZE = 3;

		if (isMovingRight) {
			rising = true;
		}

		if (isMovingLeft)
		{
			x += STEP_SIZE;
			walk.SetDelayCount(4);
			walk.OnMove();
		}

		if (isAttack)
		{
			attack.SetDelayCount(3);
			attack.OnMove();
		}
		Jump();
	}

	void Dog::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Dog::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Dog::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void Dog::SetAttack(bool flag)
	{
		isAttack = flag;
	}

	bool Dog::MeetCat(CEraser *basic_cat)
	{
		if (x + walk.Width() >= basic_cat->GetX1())
		{
			return true;
		}
		return false;
	}

	void Dog::Jump()
	{
		if (rising) {			// �W�ɪ��A
			if (velocity > 0) {
				y -= velocity;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				x -= 3;
				velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				rising = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;	// �U������t(velocity)��1
			}
		}
		else {				// �U�����A
			if (y < floor - 1) {  // ��y�y���٨S�I��a�O
				x -= 3;
				y += velocity;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
			}
			else {
				y = floor;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
				velocity = initial_velocity; // ���]�W�ɪ�l�t��
			}
		}
	}

	void Dog::OnShow(background *map)
	{
		if (isMovingLeft) {
			walk.SetTopLeft(map->ScreenX(x), y);
			walk.OnShow();
		}
		else if (y != floor)
		{
			punch.SetTopLeft(map->ScreenX(x), y);
			punch.OnShow();
		}
		else if (isAttack)
		{
			attack.SetTopLeft(map->ScreenX(x), y);
			attack.OnShow();
			if (attack.IsFinalBitmap())
			{
				rising = true;
				attack.Reset();
				isAttack = false;
			}
		}
		else {
			walk.Reset();
			walk.SetTopLeft(map->ScreenX(x), y);
			walk.OnShow();
		}
	}
}