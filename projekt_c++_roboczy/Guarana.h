#pragma once
#include "Plant.h"
#include "World.h"
class Guarana :public Plant {
public:
	Guarana(World *wo, int x, int y) {
		std::cout << "powstala nowa guarana" << std::endl;
		this->Set_World(wo);
		this->SetInitiative(0);
		this->time = this->GetTime();
		this->SetType('U');
		this->Set_force(0);
		this->SetYposition(y);
		this->SetXposition(x);
	}

	Plant* createMe(World *world, int x, int y) override
	{
		Plant *newOne = new Guarana(world, x, y);
		return newOne;
	}

	void EatMe(int x, int y, int EaterX, int EaterY) {

		int size = world01->organizm.size();
		int spr=0;
		for (int a = 0; a < size; a++) {
			if ((world01->organizm[a]->GetXposition() == x) && (world01->organizm[a]->GetYposition() == y)) {
				std::cout << "guarana zostala zjedzona " << std::endl;
				Organisms* oop = world01->organizm[a];
				world01->organizm.erase(world01->organizm.begin() + a);
				world01->organizm.resize(size - 1);
				delete oop;
				spr++;
				
			}
			else if ((world01->organizm[a]->GetXposition() == EaterX) && (world01->organizm[a]->GetYposition() == EaterY)) {
				int FFF = world01->organizm[a]->Get_force() + 3;
				world01->organizm[a]->Set_force(FFF);
				spr++;
			}

			if (spr >= 2) {
				break;
			}
		}

	};
};