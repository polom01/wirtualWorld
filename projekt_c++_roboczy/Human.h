#pragma once
#include "World.h"
#include"Animal.h"
#include <iostream>


class Human : public  Animal {
	int skill;

public:
	Human(World *wo, int x, int y) {
		skill = 0;
		this->Set_World(wo);
		this->Set_initiative(4);
		this->Set_force(5);
		this->SetYposition(y);
		this->SetXposition(x);
		this->type = 'H';
		this->time = this->GetTime();
		this->SetColdown(0);
		std::cout << "urodziles sie :)" << GetXposition() << GetYposition() << Get_force() << Get_initiative() << std::endl;
	}


	Animal* createMe(World *world, int x, int y) override
	{
		return nullptr;
	}

	void Action() override;
	void TurnOnPower();

};