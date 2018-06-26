#pragma once
#include "Plant.h"
#include "World.h"
class Grass :public Plant {
public:
	Grass(World *wo, int x, int y) {
		std::cout << "powstala nowa trawa" << std::endl;
		this->Set_World(wo);
		this->SetInitiative(0);
		this->time = this->GetTime();
		this->SetType('G');
		this->Set_force(0);
		this->SetYposition(y);
		this->SetXposition(x);
	}

	Plant* createMe(World *world, int x, int y) override
	{
		Plant *newOne = new Grass(world, x, y);
		return newOne;
	}

	void EatMe(int x ,int y , int EaterX , int EaterY) {
		
		 int size=	world01->organizm.size();

		for (int a = 0; a < size; a++) {
			if ((world01->organizm[a]->GetXposition() == x) && (world01->organizm[a]->GetYposition() == y)) {
				std::cout << "trawa zostala zjedzona " << std::endl;
				Organisms* oop = world01->organizm[a];
				world01->organizm.erase(world01->organizm.begin() + a);
				world01->organizm.resize(size - 1);
				delete oop;
				break;
			}
		}
	};

};
