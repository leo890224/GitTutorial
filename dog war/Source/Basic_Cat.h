#ifndef BASIC_CAT_H
#define BASIC_CAT_H
#include "Cat.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////
	class Dog;
	class Basic_Cat : public Cat
	{
	public:
		Basic_Cat();
		int GetX2();					// 擦子右下角 x 座標
		int GetY2();					// 擦子右下角 y 座標
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow(Background*);		// 將擦子圖形貼到畫面
		bool MeetDog(Dog*);             // 檢查是否打到狗
		void Jump();                    //設定彈跳
	private:
		CAnimation walk;		    // 走路的動畫
		CAnimation punch;           // 擊退的動畫
		CAnimation attack;          // 攻擊的動畫
		CAnimation die;
		bool isJump;
		bool rising;			    // true表上升、false表下降
		int initial_velocity;	    // 初始速度
		int velocity;			    // 目前的速度(點/次)
	};
}
#endif // !BASIC_CAT_H