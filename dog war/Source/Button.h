#ifndef BUTTON_H
#define BUTTON_H

namespace game_framework
{
	class Button
	{
	public:
		Button();
		void onClick();
		void SetMoney(int);
		virtual void OnMove() = 0;
		virtual void OnShow() = 0;
		virtual void LoadBitmap() = 0;
		~Button();

	protected:
		int x, y;
		bool isClick;
		bool isClickable;
		int delay_count;
		int money;
	};
}
#endif // !BUTTON_H
