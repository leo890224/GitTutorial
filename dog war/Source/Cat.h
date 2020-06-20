#ifndef CAT_H
#define CAT_H
#include "Background.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
	class Dog;
	class Cat
	{
	public: 
		Cat();
		int GetX1();					// 擦子左上角 x 座標
		int GetY1();					// 擦子左上角 y 座標
		virtual int GetX2() = 0;
		virtual int GetY2() = 0;
		bool isAlive();
		virtual void LoadBitmap() = 0;				// 載入圖形
		virtual void OnMove() = 0;					// 移動擦子
		virtual void OnShow(Background*) = 0;		// 將擦子圖形貼到畫面
		virtual bool MeetDog(Dog*) = 0;             // 檢查是否打到狗
		void Hurt(int);
		void SetAttack(bool flag);
		int GetBlood();
	protected:
		int x, y;					// 擦子左上角座標
		int Attack;
		int blood;
		int floor;				    // 地板的Y座標
		bool isDead;
		bool isAttack;
		bool diff;
		int count;
		int delay_count;
	};
}
#endif // !CAT_H