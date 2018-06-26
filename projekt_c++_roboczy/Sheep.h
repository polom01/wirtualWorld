#pragma once
#include"Animal.h"

#include<iostream>
#include <cstdlib>
#include <ctime>


class Sheep : public  Animal {
	public:
	Sheep(World *wo , int x , int y) {
		this->Set_World(wo);
		this->Set_initiative(4);
		this->Set_force(4);
		this->SetYposition(y);
		this->SetXposition(x);
		this->type = 'S';
		this->time = this->GetTime();
		std::cout << "owca sie urodzila :)"<< std::endl;
	}
	

	Animal* createMe(World *world, int x, int y) override
	{
		Animal *newOne = new Sheep(world, x, y);
		return newOne;
	}

};