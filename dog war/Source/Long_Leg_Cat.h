#ifndef LONG_LEG_CAT_H
#define LONG_LEG_CAT_H
#include "Cat.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	class Dog;
	class Long_Leg_Cat : public Cat
	{
	public:
		Long_Leg_Cat();
		int GetX2();					// ���l�k�U�� x �y��
		int GetY2();					// ���l�k�U�� y �y��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow(Background*);		// �N���l�ϧζK��e��
		bool MeetDog(Dog*);             // �ˬd�O�_���쪯
		void Jump();                    //�]�w�u��
	private:
		CAnimation walk;		    // �������ʵe
		CAnimation punch;           // ���h���ʵe
		CAnimation attack;          // �������ʵe
		CAnimation die;
		bool isJump;
		bool rising;			    // true���W�ɡBfalse���U��
		int initial_velocity;	    // ��l�t��
		int velocity;			    // �ثe���t��(�I/��)
	};
}
#endif // !LONG_LEG_CAT_H