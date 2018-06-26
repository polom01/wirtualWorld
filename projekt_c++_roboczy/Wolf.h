#pragma once
#include"Animal.h"
#include<iostream>
class Wolf : public Animal {
public:
	Wolf(World *wo, int x, int y) {
		this->Set_World(wo);
		Set_force(9);
		Set_initiative(5);
		this->SetYposition(y);
		this->SetXposition(x);
		this->type = 'W';
		this->time = this->GetTime();
		std::cout << "wilk sie urodzil :)" << std::endl;
	}

	Animal* createMe(World *world, int x, int y) override
	{
		Animal *newOne = new Wolf(world, x, y);
		return newOne;
	}


};
