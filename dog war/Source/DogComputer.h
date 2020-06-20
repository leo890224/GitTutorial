#ifndef DOGCOMPUTER_H
#define DOGCOMPUTER_H
#include<vector>
#include"Dog.h"
#include"Basic_Dog.h"
#include"DogBase.h"

namespace game_framework 
{
	class DogComputer
	{
	public:
		DogComputer();
		void LoadEnemy(int);
		void CallEnemy();
		vector<Dog*>* GetEnemy();
		int GetMaxBlood();
	private:
		int type, max_blood, Enemy[20][5];
		vector<Dog*> enemy;
	};
}
#endif


