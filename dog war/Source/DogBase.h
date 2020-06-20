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
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow(Background*);		// 將擦子圖形貼到畫面
		bool MeetCat(Cat*);
		~DogBase();
	private:
		CAnimation good;
	};
}
#endif // !DOGBASE_H
