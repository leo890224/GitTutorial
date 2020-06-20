#ifndef GOD_CAT_BTN_H
#define GOD_CAT_BTN_H
#include "Background.h"

namespace game_framework
{

class God_Cat_Btn
{
    public:
        God_Cat_Btn();
        void LoadBitmap();
        void OnMove();
        void OnShow(Background*);
        void Begin();
        void SetIsCure(bool);
        //void OnClick();
        void SetClick(bool);
        //void OnSinking();
        void SetChoose(bool);
        bool GetChoose();
        bool GetIsEnd();
        // void DelayReset();
        void End();
        //int GetScreenX();
        ~God_Cat_Btn();

    private:
        const int X_GOD = 375;
        const int Y_GOD = 10;
        const int X_GOD_CHOOSE = 25;
        const int Y_GOD_CHOOSE = 25;
        const int X_GOD_POWER = 120;
        const int Y_GOD_POWER = 190;
        const int X_GOD_CURE_TOTOP = -450;
        const int Y_GOD_CURE_TOTOP = 700;
        const int X_GOD_CURE_TOBOTTOM = 20;
        const int Y_GOD_CURE_TOBOTTOM = -400;
        const int X_HALO_LEFT = 335;
        const int Y_HALO_LEFT = 205;

        CAnimation god;
        CAnimation god_choose;
        CAnimation god_power;
        CAnimation back;
        CAnimation god_left;
        CAnimation god_leftM;
        CAnimation halo_left;
        CAnimation halo_right;
        bool isClick;
        bool rising;
        bool sinking;
        bool choose;
        bool god_choose_sink;
        bool god_choose_rise;
        bool isCure;
        bool isTop;
        bool isBottom;
        bool isLeft;
        bool isRight;
        //bool isEnd;
        int count;
        int delay;
        int counterA;
        int counterB;
        int counterC;
        //int X;
        int god_x;
        int god_y;
        int god_choose_x;
        int god_choose_y;
        int god_cure_x;
        int god_cure_y;
        int halo_left_x;
        int halo_left_y;
};
}
#endif
