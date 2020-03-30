namespace game_framework {
	class background {
	public:
		background();
		void LoadBitmap();
		void SetMovingUp(bool);
		void SetMovingDown(bool);
		int ScreenX(int);
		void OnMove();
		void OnShow();
	private:
		int sx, sy;
		bool IsMovingUp;
		bool IsMovingDown;
		CAnimation map;
	};
}