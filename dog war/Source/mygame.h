/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
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
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and Cat.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include "World_Background.h"
#include "Stage_Background.h"
#include "Cat.h"
#include "Basic_Cat.h"
#include "Tank_Cat.h"
#include "Long_Leg_Cat.h"
#include "Battle_Cat.h"
#include "CatBase.h"
/////////////////////////////////////////////////////////////////////////////
#include "Dog.h"
#include "Basic_Dog.h"
#include "DogBase.h"
#include "DogComputer.h"
/////////////////////////////////////////////////////////////////////////////
#include "Button.h"
#include "Upgrade_Btn.h"
#include "Basic_Cat_Btn.h"
#include "Tank_Cat_Btn.h"
#include "Long_Leg_Cat_Btn.h"
#include "Battle_Cat_Btn.h"
#include "God_Cat_Btn.h"
#include <vector>

namespace game_framework
{
/////////////////////////////////////////////////////////////////////////////
// Constants
/////////////////////////////////////////////////////////////////////////////

enum AUDIO_ID  				// 定義各種音效的編號
{
    //AUDIO_DING,				// 0
    AUDIO_MENU,					// 1
    AUDIO_BATTLE,				// 2
	AUDIO_GOD
};

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
// 每個Member function的Implementation都要弄懂
/////////////////////////////////////////////////////////////////////////////

class CGameStateInit : public CGameState
{
    public:
        CGameStateInit(CGame* g);
        void OnInit();  								// 遊戲的初值及圖形設定
        void OnBeginState();							// 設定每次重玩所需的變數
        void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
        void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);
    protected:
		void OnMove();
        void OnShow();									// 顯示這個狀態的遊戲畫面
    private:
		bool isPress, unPress;
        CMovingBitmap background;
		CMovingBitmap start_init;
		CAnimation start_press;
		CAnimation start_flash;
};

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
// 每個Member function的Implementation都要弄懂
/////////////////////////////////////////////////////////////////////////////

class CGameStateStage : public CGameState
{
	public:
		CGameStateStage(CGame* g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);
		void OnKeyDown(UINT, UINT, UINT);
	protected:
		void OnMove();
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		bool isPress, unPress;
		bool battle_start;
		int stage;
		int nx, ny;
		int pin_x, pin_y;
		int stage_x;
		int L_x, R_x, bias;
		CAnimation Pin;
		World_Background map;
		CMovingBitmap return_init;
		CMovingBitmap Stage1;
		CMovingBitmap Stage2;
		CMovingBitmap Left;
		CMovingBitmap Right;
		vector<CMovingBitmap> stages;
		CAnimation return_press;
		CAnimation return_flash;
		CAnimation battle_press;
		CAnimation battle_flash;
};

class CGameStateRun : public CGameState
{
    public:
        CGameStateRun(CGame* g);
        ~CGameStateRun();
        void OnBeginState();							// 設定每次重玩所需的變數
        void OnInit();  								// 遊戲的初值及圖形設定
        void OnKeyDown(UINT, UINT, UINT);
        void OnKeyUp(UINT, UINT, UINT);
        void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
        void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
        void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作
        void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
        void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
        //int FindFirst_cat();
        //int FindFirst_dog();
		int FindEnemy_dog(int,int);
		int FindEnemy_cat(int,int);
    protected:
        void OnMove();									// 移動遊戲元素
        void OnShow();									// 顯示這個狀態的遊戲畫面
    private:
        vector<Cat*> Cats;
		DogComputer Dogs;
        CInteger	Number;	  //數字顯示
		int money = 0;
		int max_money = 1000;
		int addspeed=1;
		int upgrade_money = 200;
		int wallet_level = 1;
		Background		map;
		vector<Button*> Buttons;
		Upgrage_btn upgrade_btn;
		God_Cat_Btn god_cat_btn;
		int counter=0;
		int sx=130;
		//int move = 0;
		//int index_cat = 0;
		//int index_dog = 0;
};

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
// 每個Member function的Implementation都要弄懂
/////////////////////////////////////////////////////////////////////////////

class CGameStateOver : public CGameState
{
    public:
        CGameStateOver(CGame* g);
        void OnBeginState();							// 設定每次重玩所需的變數
        void OnInit();
    protected:
        void OnMove();									// 移動遊戲元素
        void OnShow();									// 顯示這個狀態的遊戲畫面
    private:
        int counter;	// 倒數之計數器
};
}