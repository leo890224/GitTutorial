#ifndef CATBASE_H
#define CATBASE_H
#include "Cat.h"

namespace game_framework
{
	class CatBase : public Cat
	{
	public:
		CatBase();
		int GetX2();
		int GetY2();
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow(Background*);		// �N���l�ϧζK��e��
		bool MeetDog(Dog*);             // �ˬd�O�_���쪯
		~CatBase();
	private:
		CAnimation good;
	};
}
#endif // !CATBASE_H
