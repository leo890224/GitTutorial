#ifndef DOG_H
#define DOG_H
#include "Background.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	class Cat;
	class Dog
	{
	public:
		Dog();
		int GetX1();					// ���l���W�� x �y��
		int GetY1();					// ���l���W�� y �y��
		virtual int GetX2() = 0;
		virtual int GetY2() = 0;
		bool isAlive();
		virtual void LoadBitmap() = 0;				// ���J�ϧ�
		virtual void OnMove() = 0;					// �������l
		virtual void OnShow(Background*) = 0;		// �N���l�ϧζK��e��
		virtual bool MeetCat(Cat*) = 0;             // �ˬd�O�_�����
		void Hurt(int);
		void SetAttack(bool flag);
		void SetBlood(int);
		int GetBlood();
		int GetMoney();
	protected:
		int x, y;					// ���l���W���y��
		int Attack;
		int blood;
		int floor;				    // �a�O��Y�y��
		bool isDead;
		bool isAttack;
		bool diff;
		int count;
		int delay_count;
		int money;
	};
}
#endif // !DOG_H