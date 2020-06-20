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
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow(Background*);		// 將擦子圖形貼到畫面
		bool MeetDog(Dog*);             // 檢查是否打到狗
		~CatBase();
	private:
		CAnimation good;
	};
}
#endif // !CATBASE_H
