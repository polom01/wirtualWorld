#pragma once
#include "Organisms.h"


class Animal : public  Organisms {

public:
	virtual Animal* createMe(World *world, int x, int y) = 0;

	void Action() override;
	void Collision(int x, int y) override;
	void EatMe(int x, int y, int EaterX, int EaterY) override;


	void Set_initiative(int New_initiative);
	int Get_initiative();

	void Set_World(World *w);

	void SetXposition(int x) ;
	void SetYposition(int y) ;
	//int GetXposition() ;
	//int GetYposition() ;
	bool CheckPosition(int x  ,int y);

	World* GetWorld();
	void NewAnimal(int PositionXParent, int PositionYParent);

	void Fight(int PlaceX, int PlaceY);
	static int GetTime();
	char GetType();




	

};
