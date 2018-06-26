#pragma once
#pragma once
#include"Animal.h"

#include<iostream>
#include <cstdlib>
#include <ctime>


class Turtle : public  Animal {
public:
	Turtle(World *wo, int x, int y) {
		this->Set_World(wo);
		this->Set_initiative(1);
		this->Set_force(2);
		this->SetYposition(y);
		this->SetXposition(x);
		this->type = 'Z';
		this->time = this->GetTime();
		std::cout << "zolw sie urodzil :)" << std::endl;
	}
	

	Animal* createMe(World *world, int x, int y) override
	{
		Animal *newOne = new Turtle(world, x, y);
		return newOne;
	}

	void Action() override {
		int number = (std::rand() % 4) + 0;
		if (number == 0) {
			Animal::Action();
		}
	}


};