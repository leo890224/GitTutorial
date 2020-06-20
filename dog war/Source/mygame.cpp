/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and Cat.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <vector>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "Background.h"

namespace game_framework
{
/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame* g)
    : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
    //
    // ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
    //     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
    //
    ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
    //
    // �}�l���J���
    //
    background.LoadBitmap(Start);
    start_init.LoadBitmap(start_btn);
    start_flash.AddBitmap(start_btn2);
    start_flash.AddBitmap(start_btn3);
    start_press.AddBitmap(start_btn4);
    start_press.AddBitmap(start_btn5);
    start_press.AddBitmap(start_btn);
    start_press.AddBitmap(start_btn);
    isPress = unPress = false;
    Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
    //
    // ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
    //
}

void CGameStateInit::OnBeginState()
{
    isPress = unPress = false;
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    /*const char KEY_ESC = 27;
    const char KEY_SPACE = ' ';

    if (nChar == KEY_SPACE)
    {
        CAudio::Instance()->Stop(AUDIO_MENU);
        GotoGameState(GAME_STATE_RUN);						// ������GAME_STATE_RUN
    }
    else if (nChar == KEY_ESC)								// Demo �����C������k
        PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��*/
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
    if (point.x >= 177 && point.x <= 461 && point.y >= 266 && point.y <= 320)
    {
        isPress = true;
    }
}

void CGameStateInit::OnLButtonUp(UINT nFlags, CPoint point)
{
    if (point.x >= 177 && point.x <= 461 && point.y >= 266 && point.y <= 320)
    {
        isPress = false;
        unPress = true;
    }
}

void CGameStateInit::OnMove()
{
    if (isPress)
    {
        start_flash.OnMove();
    }

    if (unPress)
    {
        start_press.OnMove();
    }
}

void CGameStateInit::OnShow()
{
    //
    // �K�Wlogo
    //
    background.SetTopLeft(0, 0);
    background.ShowBitmap();

    if (isPress)
    {
        start_flash.SetTopLeft(162, 263);
        start_flash.OnShow();
    }
    else if (unPress)
    {
        start_press.SetTopLeft(162, 263);
        start_press.OnShow();

        if (start_press.IsFinalBitmap())
        {
            unPress = false;
            start_press.Reset();
            CAudio::Instance()->Stop(AUDIO_MENU);
            GotoGameState(GAME_STATE_RUN);
        }
    }
    else
    {
        start_init.SetTopLeft(162, 263);
        start_init.ShowBitmap();
    }

    //
    // Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
    //
    /*CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
    CFont f, *fp;
    f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
    fp = pDC->SelectObject(&f);					// ��� font f
    pDC->SetBkColor(RGB(0, 0, 0));
    pDC->SetTextColor(RGB(255, 255, 0));
    pDC->TextOut(120, 220, "Please click mouse or press SPACE to begin.");
    pDC->TextOut(5, 395, "Press Ctrl-F to switch in between window mode and full screen mode.");

    if (ENABLE_GAME_PAUSE)
        pDC->TextOut(5, 425, "Press Ctrl-Q to pause the Game.");

    pDC->TextOut(5, 455, "Press Alt-F4 or ESC to Quit.");
    pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
    CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC*/
}

CGameStateStage::CGameStateStage(CGame* g) : CGameState(g)
{
}

void CGameStateStage::OnInit()
{
    ShowInitProgress(25);	// �@�}�l��loading�i�׬�0%
    world.LoadBitmap(world_map);
    return_init.LoadBitmap(return_btn, RGB(255, 255, 255));
    return_flash.AddBitmap(return_btn2, RGB(255, 255, 255));
    return_flash.AddBitmap(return_btn3, RGB(255, 255, 255));
    return_press.AddBitmap(return_btn4, RGB(255, 255, 255));
    return_press.AddBitmap(return_btn5, RGB(255, 255, 255));
    return_press.AddBitmap(return_btn, RGB(255, 255, 255));
    return_press.AddBitmap(return_btn, RGB(255, 255, 255));
    Sleep(300);
}

void CGameStateStage::OnBeginState()
{
    isPress = unPress = false;
}

void CGameStateStage::OnLButtonDown(UINT nFlags, CPoint point)
{
    if (point.x <= 77 && point.y >= 405)
    {
        isPress = true;
    }
}

void CGameStateStage::OnLButtonUp(UINT nFlags, CPoint point)
{
    if (point.x <= 77 && point.y >= 405)
    {
        isPress = false;
        unPress = true;
    }
}

void CGameStateStage::OnMove()
{
    if (isPress)
    {
        return_flash.OnMove();
    }

    if (unPress)
    {
        return_press.OnMove();
    }
}

void CGameStateStage::OnShow()
{
    world.SetTopLeft(0, 0);
    world.ShowBitmap();

    if (isPress)
    {
        return_flash.SetTopLeft(0, 405);
        return_flash.OnShow();
    }
    else if (unPress)
    {
        return_press.SetTopLeft(0, 405);
        return_press.OnShow();

        if (return_press.IsFinalBitmap())
        {
            unPress = false;
            return_press.Reset();
            GotoGameState(GAME_STATE_INIT);
        }
    }
    else
    {
        return_init.SetTopLeft(0, 405);
        return_init.ShowBitmap();
    }
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����������A(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame* g)
    : CGameState(g)
{
}

void CGameStateOver::OnMove()
{
    counter--;

    if (counter < 0)
    {
        CAudio::Instance()->Play(AUDIO_MENU);
        GotoGameState(GAME_STATE_INIT);
    }
}

void CGameStateOver::OnBeginState()
{
    counter = 30 * 5; // 5 seconds
}

void CGameStateOver::OnInit()
{
    //
    // ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
    //     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
    //
    ShowInitProgress(75);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
    //
    // �}�l���J���
    //
    Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
    //
    // �̲׶i�׬�100%
    //
    ShowInitProgress(100);
    CAudio::Instance()->Play(AUDIO_MENU);
}

void CGameStateOver::OnShow()
{
    CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
    CFont f, *fp;
    f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
    fp = pDC->SelectObject(&f);					// ��� font f
    pDC->SetBkColor(RGB(0, 0, 0));
    pDC->SetTextColor(RGB(255, 255, 0));
    char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
    sprintf(str, "Game Over ! (%d)", counter / 30);
    pDC->TextOut(240, 210, str);
    pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
    CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame* g) : CGameState(g)//, NUMBALLS(28)
{
    //ball = new CBall [NUMBALLS];
    //picX = picY = 0;
}

CGameStateRun::~CGameStateRun()
{
}


void CGameStateRun::OnBeginState()
{
    money = 0;
    max_money = 1000;
    addspeed = 1;
    upgrade_money = 200;
    wallet_level = 1;

    for (int i = 0; i < (int)Cats.size(); i++)
    {
        delete Cats[i];
    }

    Cats.clear();

    for (vector<Dog*>::iterator iter = Dogs.GetEnemy()->begin(); iter != Dogs.GetEnemy()->end();)
    {
        iter = Dogs.GetEnemy()->erase(iter);
    }

    Cats.push_back(new CatBase);
    Cats[0]->LoadBitmap();
    Dogs.LoadEnemy(1);
    CAudio::Instance()->Play(AUDIO_BATTLE);			// ���� MIDI
}

void CGameStateRun::OnMove()							// ���ʹC������
{
    for (int i = 0; i < (int)Buttons.size(); i++)
    {
        Buttons[i]->SetMoney(money);
        Buttons[i]->OnMove();
    }

    for (int i = 0; i < (int)Cats.size(); i++)
    {
        vector<Dog*>::iterator iter = Dogs.GetEnemy()->begin();
        Cats[i]->OnMove();
        int index_dog = FindEnemy_dog(Cats[i]->GetX1(), Cats[i]->GetX2());                                       //------------------------------------------------------��ĤH
        Cats[i]->SetAttack(Cats[i]->MeetDog(*(iter + index_dog)));
    }

    for (vector<Dog*>::iterator iter = Dogs.GetEnemy()->begin(); iter != Dogs.GetEnemy()->end(); iter++)
    {
        (*iter)->OnMove();
        int index_cat = FindEnemy_cat((*iter)->GetX1(), (*iter)->GetX2());                                       //-------------------------------------------------------��ĤH
        (*iter)->SetAttack((*iter)->MeetCat(Cats[index_cat]));
    }

    for (int i = 0; i < (int)Cats.size(); i++)
    {
        if (Cats[i]->GetY2() < 10)
        {
            delete Cats[i];
            Cats.erase(Cats.begin() + i);
        }
    }

    for (vector<Dog*>::iterator iter = Dogs.GetEnemy()->begin(); iter != Dogs.GetEnemy()->end();)
    {
        if ((*iter)->GetY2() < 10)
        {
            money += (*iter)->GetMoney();

            if (money > max_money) money = max_money;

            iter = Dogs.GetEnemy()->erase(iter);
        }
        else
        {
            iter++;
        }
    }

    if (money < max_money)
    {
        counter++;

        if (counter > 1)
        {
            money += addspeed;
            Number.SetInteger(money);
            counter = 0;
        }
    }

    map.OnMove();
    upgrade_btn.SetMoney(money);
    upgrade_btn.SetLevel(wallet_level);
    upgrade_btn.SetUpgradeMoney(upgrade_money);
    upgrade_btn.OnMove();
    god_cat_btn.OnMove();
    //god_cat_btn.Cure();
    Dogs.CallEnemy();

    if ((*Dogs.GetEnemy()->begin())->GetBlood() <= 0 || Cats[0]->GetBlood() <= 0)
    {
        CAudio::Instance()->Stop(AUDIO_BATTLE);
        GotoGameState(GAME_STATE_OVER);
    }
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
    //
    // ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
    //     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
    //
    ShowInitProgress(50);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
    //
    // �}�l���J���
    //
    map.LoadBitmap();
    upgrade_btn.LoadBitmap();
    god_cat_btn.LoadBitmap();
    Buttons.push_back(new Basic_Cat_Btn);
    Buttons.push_back(new Tank_Cat_Btn);
    Buttons.push_back(new Long_Leg_Cat_Btn);
    Buttons.push_back(new Battle_Cat_Btn);
    Cats.push_back(new CatBase);

    for (int i = 0; i < (int)Buttons.size(); i++)
        Buttons[i]->LoadBitmap();

    Cats[0]->LoadBitmap();
    Dogs.LoadEnemy(1);
    //
    // ��������Loading�ʧ@�A�����i��
    //
    Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
    //
    // �~����J��L���
    //
    Number.LoadBitmap();
    CAudio::Instance()->Load(AUDIO_MENU, "sounds\\menu.mp3");	// ���J�s��1���n��lake.mp3
    CAudio::Instance()->Load(AUDIO_BATTLE, "sounds\\battle.mp3");	// ���J�s��2���n��ntut.mid
    CAudio::Instance()->Load(AUDIO_GOD, "sounds\\God.mp3");
    //
    // ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
    //
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    const char KEY_LEFT = 0x25; // keyboard���b�Y
    const char KEY_UP = 0x26; // keyboard�W�b�Y
    const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
    const char KEY_DOWN = 0x28; // keyboard�U�b�Y
    const char KEY_Z = 0x5A;
    const char KEY_X = 0x58;

    if (nChar == KEY_LEFT)
    {
        map.SetMovingLeft(true);
        //Cats->SetMovingRight(true);
        //Dogs->SetMovingLeft(true);
    }

    if (nChar == KEY_RIGHT)
    {
        map.SetMovingRight(true);
        //Cats.SetMovingRight(true);
        //Dogs.SetMovingRight(true);
    }

    if (nChar == KEY_UP)
    {
        //map.SetMovingUp(true);
    }

    if (nChar == KEY_DOWN)
    {
        //map.SetMovingDown(true);
    }

    //gamemap.OnKeyDown(nChar);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    const char KEY_LEFT = 0x25; // keyboard���b�Y
    const char KEY_UP = 0x26; // keyboard�W�b�Y
    const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
    const char KEY_DOWN = 0x28; // keyboard�U�b�Y
    const char KEY_Z = 0x5A;
    const char KEY_X = 0x58;

    if (nChar == KEY_LEFT)
    {
        map.SetMovingLeft(false);
        //Cats.SetMovingLeft(false);
        //Dogs.SetMovingLeft(false);
    }

    if (nChar == KEY_RIGHT)
    {
        map.SetMovingRight(false);
        //Cats.SetMovingRight(false);
        //Dogs.SetMovingRight(false);
    }

    if (nChar == KEY_UP)
    {
        //map.SetMovingUp(false);
    }

    if (nChar == KEY_DOWN)
    {
        //map.SetMovingDown(false);
    }

    if (nChar == KEY_Z)
    {
        Cats.push_back(new Basic_Cat);
        Cats[Cats.size() - 1]->LoadBitmap();
    }
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
    if (point.x <= 107 && point.y >= 386 && wallet_level <= 8 && money >= upgrade_money)
    {
        money -= upgrade_money;
        upgrade_money += 200;
        addspeed += 1;
        wallet_level += 1;
        max_money += 450;
    }

    if (point.x >= 135 && point.x <= 210 && point.y >= 410 && point.y <= 470 && money >= 50)
    {
        money -= 50;
        Cats.push_back(new Basic_Cat);
        Cats[Cats.size() - 1]->LoadBitmap();
        Buttons[0]->onClick();
    }

    if (point.x >= 222 && point.x <= 297 && point.y >= 410 && point.y <= 470 && money >= 100)
    {
        money -= 100;
        Cats.push_back(new Tank_Cat);
        Cats[Cats.size() - 1]->LoadBitmap();
        Buttons[1]->onClick();
    }

    if (point.x >= 309 && point.x <= 384 && point.y >= 410 && point.y <= 470 && money >= 400)
    {
        money -= 400;
        Cats.push_back(new Long_Leg_Cat);
        Cats[Cats.size() - 1]->LoadBitmap();
        Buttons[2]->onClick();
    }

    if (point.x >= 396 && point.x <= 471 && point.y >= 410 && point.y <= 470 && money >= 200)
    {
        money -= 200;
        Cats.push_back(new Battle_Cat);
        Cats[Cats.size() - 1]->LoadBitmap();
        Buttons[3]->onClick();
    }

    if (((point.x) + sx) >= 375 && ((point.x) + sx) <= 465 && point.y >= 10 && point.y <= 100 && !god_cat_btn.GetChoose())
    {
        god_cat_btn.Begin();
        CAudio::Instance()->Stop(AUDIO_BATTLE);
        CAudio::Instance()->Play(AUDIO_GOD);
        //god_cat_btn.OnClick();
        //god_cat_btn.OnSinking();
    }

    if (god_cat_btn.GetChoose())
    {
        if (point.x >= 160 && point.x <= 210 && point.y >= 220 && point.y <= 270)
        {
            CAudio::Instance()->Stop(AUDIO_GOD);
        }

        if (point.x >= 253 && point.x <= 303 && point.y >= 220 && point.y <= 270)
        {
            CAudio::Instance()->Stop(AUDIO_GOD);
        }

        if (point.x >= 347 && point.x <= 396 && point.y >= 220 && point.y <= 270)
        {
            god_cat_btn.SetIsCure(true);
            god_cat_btn.End();
            //CAudio::Instance()->Stop(AUDIO_GOD);
        }

        if (point.x >= 440 && point.x <= 490 && point.y >= 220 && point.y <= 270)
        {
            CAudio::Instance()->Stop(AUDIO_GOD);
        }
    }

    if (point.x >= 10 && point.x <= 80 && point.y >= 403 && point.y <= 438 && god_cat_btn.GetChoose())
    {
        god_cat_btn.End();
        CAudio::Instance()->Stop(AUDIO_GOD);
        CAudio::Instance()->Play(AUDIO_BATTLE);
        //god_cat_btn.SetClick(false);
        //god_cat_btn.DelayReset();
    }
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
    // �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
    //Cats.SetMovingRight(true);
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
    // Cats.SetMovingRight(false);
}

void CGameStateRun::OnShow()
{
    map.OnShow();
    upgrade_btn.OnShow();
    Number.ShowBitmap(1, money, max_money, 615, 0);
    Number.ShowBitmap(2, Cats[0]->GetBlood(), 4000, map.ScreenX(665), 136);
    Number.ShowBitmap(2, (*Dogs.GetEnemy()->begin())->GetBlood(), Dogs.GetMaxBlood(), map.ScreenX(265), 136);

    if (wallet_level < 8) Number.ShowBitmap(3, upgrade_money, 0, 40, 460);

    for (int i = 0; i < (int)Buttons.size(); i++)
        Buttons[i]->OnShow();

    for (vector<Dog*>::iterator iter = Dogs.GetEnemy()->begin(); iter != Dogs.GetEnemy()->end(); iter++)
        (*iter)->OnShow(&map);

    for (int i = 0; i < (int)Cats.size(); i++)
        Cats[i]->OnShow(&map);					// �K�W���l

    god_cat_btn.OnShow(&map);
}

/*int CGameStateRun::FindFirst_cat()
{
    int firstX = 668, index = 0;

    for (int i = 0; i < (int) Cats.size(); i++)
    {
        if (Cats[i]->GetX1() <= firstX && Cats[i]->isAlive())
        {
            firstX = Cats[i]->GetX1();
            index = i;
        }
    }

    return index;
}

int CGameStateRun::FindFirst_dog()
{
	int firstX =0, index = 0;
	int i = 0;
	for (vector<Dog*>::iterator iter = Dogs.GetEnemy()->begin(); iter != Dogs.GetEnemy()->end(); iter++)
    {
        if ((*iter)->GetX2() >= firstX && (*iter)->isAlive())
        {
            firstX = (*iter)->GetX2();
            index = i;
        }
		i++;
    }
    return index;
}*/

int CGameStateRun::FindEnemy_dog(int X1, int X2)
{
    int i = 0, index = 0;

    for (vector<Dog*>::iterator iter = Dogs.GetEnemy()->begin(); iter != Dogs.GetEnemy()->end(); iter++)
    {
        if ((*iter)->GetX2() >= X1 && (*iter)->GetX2() < X2 && (*iter)->isAlive())
        {
            index = i;
        }

        i++;
    }

    return index;
}

int CGameStateRun::FindEnemy_cat(int X1, int X2)
{
    int index = 0;

    for (int i = 0; i < (int)Cats.size(); i++)
    {
        if (Cats[i]->GetX1() <= X2 && Cats[i]->GetX1() > X1 && Cats[i]->isAlive())
        {
            index = i;
        }
    }

    return index;
}

}