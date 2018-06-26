#pragma once
#include "Organisms.h"
#define PRAWDOPODOBIENSTWO 10

class Plant : public  Organisms {


public:



	void Action() ;
	void Collision(int x , int y) ;
	virtual void EatMe(int x ,int y, int EaterX, int EaterY) = 0;
	virtual Plant* createMe(World *world, int x, int y) =0;
	
	bool CheckPosition(int x , int y);
	//void Set_force(int new_force) ;
	//int Get_force();

	void SetTime(int t);
	int GetInitiative();
	void SetInitiative(int nwe);
	void SetType(char T);
	char GetType();


	void SetXposition(int x) ;
	void SetYposition(int y) ;
	int GetXposition() ;
	int GetYposition();

	void Set_World(World *w);

	int GetTime();
	//zerowa inicjatywa


};
