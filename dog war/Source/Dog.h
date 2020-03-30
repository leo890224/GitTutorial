namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////

	class Dog
	{
	public:
		Dog();
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		void Initialize();				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow(background *);					// 將擦子圖形貼到畫面
		bool MeetCat(CEraser *);        // 檢查是否打到貓
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
		void SetAttack(bool flag);
		void Jump();                    //設定彈跳
	protected:
		CAnimation walk;		    // 走路的動畫
		CAnimation punch;           // 擊退的動畫
		CAnimation attack;          // 攻擊的動畫
		int x, y;					// 擦子左上角座標
		int floor;				    // 地板的Y座標
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isAttack;
		bool rising;			    // true表上升、false表下降
		int initial_velocity;	    // 初始速度
		int velocity;			    // 目前的速度(點/次)
	};
}