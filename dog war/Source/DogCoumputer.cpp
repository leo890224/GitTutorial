#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <fstream>
#include <string>
#include <strstream>
#include <iostream>
#include "DogCoumputer.h"
namespace game_framework {
	DogComputer::DogComputer()
	{
	}
	void DogComputer::LoadEnemy(int level)
	{

		int data[20][5];
		string line, search = "stage" + to_string(level);
		ifstream File("dog.txt");

		while (!File.eof()) {
			getline(File, line);
			if (line == search) {
				File >> type;
				File >> max_blood;
				for (int i = 0; i < type; i++) {
					for (int j = 0; j < 5; j++) {
						File >> data[i][j];
					}
				}
				break;
			}
		}
		for (int i = 0; i < type; i++) {
			for (int j = 0; j < 5; j++) {
				Enemy[i][j] = data[i][j];
			}
		}
		max_blood = 4000;
		enemy.push_back(new DogBase);
		enemy[0]->LoadBitmap();
		enemy[0]->SetBlood(max_blood);
		File.close();
	}

	void DogComputer::CallEnemy()
	{

		for (int i = 0; i < type; i++) {
				if (Enemy[i][2] >= (enemy[0]->GetBlood()/max_blood)*100) {
					if (Enemy[i][1] >= 1) {
						if (Enemy[i][4] == 0 && Enemy[i][3]==0) {
							enemy.push_back(new Basic_Dog);
							enemy[enemy.size() - 1]->LoadBitmap();
							Enemy[i][1] -= 1;
						}
						else if ((CSpecialEffect::GetCurrentTimeCount() - Enemy[i][3] * 30)>=0 &&(CSpecialEffect::GetCurrentTimeCount() - Enemy[i][3] *30) % (Enemy[i][4]*30) == 0) {
							enemy.push_back(new Basic_Dog);
							enemy[enemy.size() - 1]->LoadBitmap();
							Enemy[i][1] -= 1;
						}
					}
				}
		}
		int time = CSpecialEffect::GetCurrentTimeCount();
		TRACE("------------%d\n", time);
	}

	vector<Dog*>*DogComputer::GetEnemy()
	{
		return &enemy;
	}
}

