#pragma once
#pragma once
#include"Animal.h"
#include "World.h"

#include<iostream>
#include <cstdlib>
#include <ctime>


class Antilope : public  Animal {
public:
	Antilope(World *wo, int x, int y) {
		this->Set_World(wo);
		this->Set_initiative(4);
		this->Set_force(4);
		this->SetYposition(y);
		this->SetXposition(x);
		this->type = 'A';
		this->time = this->GetTime();
		std::cout << "antylopa sie urodzila :)"<< std::endl;
	}

	Animal* createMe(World *world, int x, int y) override
	{
		Animal *newOne = new Antilope(world, x, y);
		return newOne;
	}

	void Action() override {
		int number = (std::rand() % 4) + 0;

		if (number == 0) {
			if (CheckPosition((position_x - 2), position_y)) {
				if (position_x > 1) {
					position_x--;
					position_x--;
				}//lewa strona
			}
			else
				Collision(position_x - 2, position_y);
		}
		if (number == 1) {
			if (CheckPosition(position_x, position_y + 2)) {
				if (position_y < world01->GetHeight() - 2) {  //-1 poniewaz jak mamy hight 4 to liczy sie 0 1 2 3
					position_y++;
					position_y++;
				}
			}
			else
				Collision(position_x, position_y + 2);
		}
		if (number == 2) {
			if (CheckPosition((position_x + 2), position_y)) {
				if (position_x < world01->GetWidth() - 2) {
					position_x++;
					position_x++;
				}
			}
			else
				Collision((position_x + 2), position_y);
		}
		if (number == 3) {
			if (CheckPosition(position_x, position_y - 2)) {
				if (position_y > 1) {
					position_y--;
					position_y--;
				}
			}
			else
				Collision(position_x, position_y - 2);
		}
	}


};