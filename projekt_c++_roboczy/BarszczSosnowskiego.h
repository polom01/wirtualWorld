#pragma once
#include "Plant.h"
#include "World.h"
#include "Animal.h"
class BarszczSosnowskiego :public Plant {
public:
	BarszczSosnowskiego(World *wo, int x, int y) {
		std::cout << "powstal nowy Barszcz Sosnowskiego" << std::endl;
		this->Set_World(wo);
		this->SetInitiative(0);
		this->time = this->GetTime();
		this->SetType('K');
		this->Set_force(10);
		this->SetYposition(y);
		this->SetXposition(x);
	}

	Plant* createMe(World *world, int x, int y) override
	{
		Plant *newOne = new BarszczSosnowskiego(world, x, y);
		return newOne;
	}

	void EatMe(int x, int y, int EaterX, int EaterY) {

		int size = world01->organizm.size();

		for (int a = 0; a < size; a++) {
		 {
				std::cout << "barszcz  zostal zjedzony " << std::endl;
				Organisms* oop = world01->organizm[a];
				world01->organizm.erase(world01->organizm.begin() + a);
				world01->organizm.resize(size - 1);
				delete oop;
				break;
			}
		}
	};

	void Action() override {
		KillAll();
		Plant::Action();
	}


	void KillAll(){
		int size = world01->organizm.size();
		int x = this->GetXposition();
		int y = this->GetYposition();
		int tab[5] = { 0,0,0,0, 0 };
		int index = 0;

		for (int a = 0; a < size; a++) {
			if ((world01->organizm[a]->GetXposition() == x+1) && (world01->organizm[a]->GetYposition() == y)) {
				Animal *an = dynamic_cast <Animal*>(world01->organizm[a]);
				if (an != 0) {
					std::cout << "kill " << world01->organizm[a]->GetType() << std::endl;
					tab[index] = a;
					index++;
				}
			}
			else if ((world01->organizm[a]->GetXposition() == x-1) && (world01->organizm[a]->GetYposition() == y)) {
				Animal *an = dynamic_cast <Animal*>(world01->organizm[a]);
				if (an != 0) {
					std::cout << "kill " << world01->organizm[a]->GetType() << std::endl;
					tab[index] = a;
					index++;
				}
			}

			else if ((world01->organizm[a]->GetXposition() == x ) && (world01->organizm[a]->GetYposition() == y-1)) {
				Animal *an = dynamic_cast <Animal*>(world01->organizm[a]);
				if (an != 0) {
					std::cout << "kill " << world01->organizm[a]->GetType() << std::endl;
					tab[index] = a;
					index++;

				}
			}

			else if ((world01->organizm[a]->GetXposition() == x ) && (world01->organizm[a]->GetYposition() == y+1)) {
				Animal *an = dynamic_cast <Animal*>(world01->organizm[a]);
				if (an != 0) {
					std::cout << "kill " << world01->organizm[a]->GetType() << std::endl;
					tab[index] = a;
					index++;

				}
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				if (tab[i] < tab[i + 1]) {
					int t = tab[i + 1];
					tab[i + 1] = tab[i];
					tab[i] = t;
				}
			}
		}

		for (int t = 0; t < index; t++) {
			world01->organizm.erase(world01->organizm.begin() + tab[t]);
		}
		if ((index > 0) && (index <= size))
			world01->organizm.resize(size - index);
	}

};