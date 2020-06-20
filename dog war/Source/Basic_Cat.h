#ifndef BASIC_CAT_H
#define BASIC_CAT_H
#include "Cat.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	class Dog;
	class Basic_Cat : public Cat
	{
	public:
		Basic_Cat();
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
		bool rising;			    // true��W�ɡBfalse��U��
		int initial_velocity;	    // ��l�t��
		int velocity;			    // �ثe���t��(�I/��)
	};
}
#endif // !BASIC_CAT_H