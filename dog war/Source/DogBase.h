#ifndef DOGBASE_H
#define DOGBASE_H
#include "Dog.h"

namespace game_framework
{
	class DogBase : public Dog
	{
	public:
		DogBase();
		int GetX2();
		int GetY2();
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow(Background*);		// �N���l�ϧζK��e��
		bool MeetCat(Cat*);
		~DogBase();
	private:
		CAnimation good;
	};
}
#endif // !DOGBASE_H
