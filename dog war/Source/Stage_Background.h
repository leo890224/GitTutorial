#ifndef STAGE_BACKGROUND_H
#define STAGE_BACKGROUND_H

namespace game_framework {
	class Stage_Background
	{
	public:
		Stage_Background();
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
		CMovingBitmap map;
	};
}
#endif // !BACKGROUND_H