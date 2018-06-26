#pragma once

#include"Animal.h"
#include "World.h"
#include<iostream>
#include <cstdlib>
#include <ctime>


class Fox : public  Animal {
public:
	Fox(World *wo, int x, int y) {
		this->Set_World(wo);
		this->Set_initiative(7);
		this->Set_force(3);
		this->SetYposition(y);
		this->SetXposition(x);
		this->type = 'L';
		this->time = this->GetTime();
		std::cout << "lis sie urodzil :)"  << std::endl;
	}

	Animal* createMe(World *world, int x, int y) override
	{
		Animal *newOne = new Fox(world, x, y);
		return newOne;
	}

	void Collision(int x , int y) override {

		//std::cout << "kolizja lisa : " << std::endl;
		//std::cout << typeid(world01->organizm[0]->).name() << std::endl;
		//std::cout << typeid(this).name() << std::endl;
		int size = world01->organizm.size();
		for (int a = 0; a < size; a++) {
			if ((world01->organizm[a]->GetXposition() == x) && (world01->organizm[a]->GetYposition() == y))
			{
				if (world01->organizm[a]->GetType() == type) {
					NewAnimal(x, y);
					break;
				}
				else {
					if (world01->organizm[a]->Get_force() <= Get_force()){
						Animal::Fight(x, y);
					break;
				}
					else {
						std::cout << "lis sie nie przemiescil" << std::endl;
						break;
					}
				}
			}
			if(size > world01->organizm.size())size = world01->organizm.size();
		}

	}

};