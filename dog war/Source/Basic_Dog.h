#ifndef BASIC_DOG_H
#define BASIC_DOG_H
#include "Dog.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	class Cat;
	class Basic_Dog : public Dog
	{
	public:
		Basic_Dog();
		int GetX2();					// ���l�k�U�� x �y��
		int GetY2();					// ���l�k�U�� y �y��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();				    // �������l
		void OnShow(Background*);		// �N���l�ϧζK��e��
		bool MeetCat(Cat*);             // �ˬd�O�_�����
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
#endif // !DOG_H