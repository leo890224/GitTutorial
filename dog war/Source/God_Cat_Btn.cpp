#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "audio.h"
#include "gamelib.h"
#include "God_Cat_Btn.h"

namespace game_framework
{
God_Cat_Btn::God_Cat_Btn()
{
    isClick = false;
    rising = false;
    sinking = false;
    choose = false;
    isTop = false;
    isBottom = false;
    isLeft = false;
    isRight = false;
    //isEnd = true;
    count = 1;
    delay = 0;
    counterA = 0;
    counterB = 0;
    counterC = 0;
    //X = 0;
    god_x = X_GOD;
    god_y = Y_GOD;
    god_choose_x = X_GOD_CHOOSE;
    god_choose_y = Y_GOD_CHOOSE;
    god_choose_sink = false;
    god_choose_rise = false;
    god_cure_x = X_GOD_CURE_TOTOP;
    god_cure_y = Y_GOD_CURE_TOTOP;
    isCure = false;
    halo_left_x = X_HALO_LEFT;
    halo_left_y = Y_HALO_LEFT;
}

void God_Cat_Btn::LoadBitmap()
{
    god.AddBitmap(God_cat, RGB(255, 255, 255));
    god.AddBitmap(God_cat_01, RGB(255, 255, 255));
    god.AddBitmap(God_cat_02, RGB(255, 255, 255));
    god.AddBitmap(God_cat_03, RGB(255, 255, 255));
    god.AddBitmap(God_cat_04, RGB(255, 255, 255));
    god.AddBitmap(God_cat_05, RGB(255, 255, 255));
    god.AddBitmap(God_cat_06, RGB(255, 255, 255));
    god.AddBitmap(God_cat_07, RGB(255, 255, 255));
    god.AddBitmap(God_cat_08, RGB(255, 255, 255));
    god.AddBitmap(God_cat_09, RGB(255, 255, 255));
    god.AddBitmap(God_cat_10, RGB(255, 255, 255));
    god.AddBitmap(God_cat_11, RGB(255, 255, 255));
    god.AddBitmap(God_cat_12, RGB(255, 255, 255));
    god.AddBitmap(God_cat_13, RGB(255, 255, 255));
    god.AddBitmap(God_cat_14, RGB(255, 255, 255));
    god.AddBitmap(God_cat_15, RGB(255, 255, 255));
    god.AddBitmap(God_cat_16, RGB(255, 255, 255));
    god.AddBitmap(God_cat_17, RGB(255, 255, 255));
    god.AddBitmap(God_cat_18, RGB(255, 255, 255));
    god.AddBitmap(God_cat_19, RGB(255, 255, 255));
    god.AddBitmap(God_cat_20, RGB(255, 255, 255));
    god.AddBitmap(God_cat_21, RGB(255, 255, 255));
    god.AddBitmap(God_cat_22, RGB(255, 255, 255));
    god.AddBitmap(God_cat_23, RGB(255, 255, 255));
    god.AddBitmap(God_cat_24, RGB(255, 255, 255));
    god.AddBitmap(God_cat_25, RGB(255, 255, 255));
    god.AddBitmap(God_cat_26, RGB(255, 255, 255));
    god.AddBitmap(God_cat_27, RGB(255, 255, 255));
    god.AddBitmap(God_cat_28, RGB(255, 255, 255));
    god.AddBitmap(God_cat_29, RGB(255, 255, 255));
    god.AddBitmap(God_cat_30, RGB(255, 255, 255));
    god.AddBitmap(God_cat_31, RGB(255, 255, 255));
    god.AddBitmap(God_cat_32, RGB(255, 255, 255));
    god.AddBitmap(God_cat_33, RGB(255, 255, 255));
    god.AddBitmap(God_cat_34, RGB(255, 255, 255));
    god.AddBitmap(God_cat_35, RGB(255, 255, 255));
    god.AddBitmap(God_cat_36, RGB(255, 255, 255));
    god.AddBitmap(God_cat_37, RGB(255, 255, 255));
    god.AddBitmap(God_cat_38, RGB(255, 255, 255));
    god.AddBitmap(God_cat_39, RGB(255, 255, 255));
    god.AddBitmap(God_cat_40, RGB(255, 255, 255));
    god.AddBitmap(God_cat_41, RGB(255, 255, 255));
    god.AddBitmap(God_cat_42, RGB(255, 255, 255));
    god.AddBitmap(God_cat_43, RGB(255, 255, 255));
    god.AddBitmap(God_cat_44, RGB(255, 255, 255));
    god_power.AddBitmap(God_power, RGB(255, 255, 255));
    god_choose.AddBitmap(God_choose, RGB(255, 255, 255));
    back.AddBitmap(return_btn, RGB(255, 255, 255));
    god_left.AddBitmap(God_left, RGB(255, 255, 255));
    god_leftM.AddBitmap(God_leftM, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_01, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_02, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_03, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_04, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_05, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_06, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_07, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_08, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_09, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_10, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_11, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_12, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_13, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_14, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_15, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_16, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_17, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_18, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_19, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_20, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_21, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_22, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_23, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_24, RGB(255, 255, 255));
    halo_left.AddBitmap(BlingL_25, RGB(255, 255, 255));
}

void God_Cat_Btn::OnMove()
{
    if (isClick)
    {
        if (sinking)
        {
            if (god_y <= 100)
            {
                god_y += (count / 8);
            }
            else
            {
                //isBottom = true;
                sinking = false;
                rising = true;
                count = 1;
            }
        }

        if (rising && delay >= 50)
        {
            god_y -= count;

            if (god_y < -100)
            {
                rising = false;
                choose = true;
            }
        }

        god.SetDelayCount(1);
        god.OnMove();
        count++;
        delay++;
    }
    else
    {
        count = 1;
        god_y = Y_GOD;
        god.SetDelayCount(4);
        god.OnMove();
    }

    if (choose)
    {
        if (god_choose_y >= 55)
        {
            god_choose_sink = true;
            god_choose_rise = false;
        }

        if (god_choose_y <= 25)
        {
            god_choose_rise = true;
            god_choose_sink = false;
        }

        if (god_choose_sink)	god_choose_y -= 1;

        if (god_choose_rise)	god_choose_y += 1;

        god_choose.OnMove();
        god_power.OnMove();
    }

    if (isCure)
    {
        //isEnd = false;
        if (!isTop)
        {
            if (god_cure_y >= -2000)
            {
                god_cure_y -= (counterA / 3);
            }
            else
            {
                isTop = true;
                //god_cure_x = X_GOD_CURE_TOTOP;
                //god_cure_y = Y_GOD_CURE_TOTOP;
                god_cure_x = X_GOD_CURE_TOBOTTOM;
                god_cure_y = Y_GOD_CURE_TOBOTTOM;
                counterA = 0;
                //isCure = false;
                //isTop = false;
            }

            god_left.OnMove();
            counterA += 2;
        }

        if (isTop)
        {
            if (god_cure_y <= -10)
            {
                god_cure_y += (counterB / 2);
            }
            else
            {
                isBottom = true;
                counterB = 0;
                //isCure = false;
                //isTop = false;
                //isBottom = false;
            }

            god_leftM.OnMove();
            counterB++;
        }

        if (isBottom)                    //20,-10    365,253    474,255
        {
            if (counterC <= 248)
            {
                if (counterC % 9 == 0)
                {
                    halo_left_x++;
                    halo_left_y++;
                }
            }
            else
            {
                halo_left_x = X_HALO_LEFT;
                halo_left_y = Y_HALO_LEFT;
                god_cure_x = X_GOD_CURE_TOTOP;
                god_cure_y = Y_GOD_CURE_TOTOP;
                counterC = 0;
                isBottom = false;
                isTop = false;
                isCure = false;
                //isEnd = true;
                //isClick = false;
            }

            halo_left.OnMove();
            counterC++;
        }
    }
}

void God_Cat_Btn::OnShow(Background* map)
{
    if (isClick)
    {
        //X = map->ScreenX(x);
        god.SetTopLeft(map->ScreenX(god_x), god_y);
        god.OnShow();

        if (choose)
        {
            god_choose.SetTopLeft(god_choose_x, god_choose_y);
            god_choose.OnShow();
            god_power.SetTopLeft(120, 190);
            god_power.OnShow();
            back.SetTopLeft(5, 400);
            back.OnShow();
        }
    }
    else if (isCure)
    {
        if (!isTop)
        {
            god_left.SetTopLeft(god_cure_x, god_cure_y);
            god_left.OnShow();
        }

        if (isTop)
        {
            god_leftM.SetTopLeft(god_cure_x, god_cure_y);
            god_leftM.OnShow();
        }

        if (isBottom)
        {
            halo_left.SetTopLeft(halo_left_x, halo_left_y);
            halo_left.OnShow();
        }
    }
    else
    {
        god.SetTopLeft(map->ScreenX(X_GOD), Y_GOD);
        god.OnShow();
    }
}

void God_Cat_Btn::Begin()
{
    isClick = true;
    sinking = true;
}

void God_Cat_Btn::SetIsCure(bool state)
{
    isCure = state;
}

/*void God_Cat_Btn::OnClick()
{
	isClick = true;
}*/

void God_Cat_Btn::SetClick(bool click)
{
    isClick = click;
}

/*void God_Cat_Btn::OnSinking()
{
	sinking = true;
}*/

void God_Cat_Btn::SetChoose(bool state)
{
    choose = state;
}

bool God_Cat_Btn::GetChoose()
{
    return choose;
}

bool God_Cat_Btn::GetIsEnd()
{
    return true;
}

/*void God_Cat_Btn::DelayReset()
{
	delay = 0;
}*/

void God_Cat_Btn::End()
{
    isClick = false;
    delay = 0;
    choose = false;
}

/*int God_Cat_Btn::GetScreenX()
{
	return X;
}*/

God_Cat_Btn::~God_Cat_Btn()
{
}
}