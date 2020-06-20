#ifndef BACKGROUND_H
#define BACKGROUND_H

namespace game_framework {
	class Background
	{
	public:
		Background();
		void LoadBitmap();
		void SetMovingLeft(bool);
		void SetMovingRight(bool);
		int ScreenX(int);
		void OnMove();
		void OnShow();
	private:
		int sx, sy;
		bool IsMovingLeft;
		bool IsMovingRight;
		CAnimation map;
	};
}
#endif // !BACKGROUND_H