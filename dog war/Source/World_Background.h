#ifndef WORLD_BACKGROUND_H
#define WORLD_BACKGROUND_H

namespace game_framework {
	class World_Background
	{
	public:
		World_Background();
		void LoadBitmap();
		int ScreenX(int);
		int ScreenY(int);
		void OnMove(int, int);
		void OnShow();
	private:
		int sx, sy;
		CMovingBitmap map;
	};
}
#endif // !BACKGROUND_H