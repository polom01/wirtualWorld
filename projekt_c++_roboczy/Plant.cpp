#include"Plant.h"
#include"World.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
void Plant::Action() {
	int number = (std::rand() % PRAWDOPODOBIENSTWO) + 0;
	if (number == 0) {

		int number = (std::rand() % 4) + 0;


		if (number == 0) {
			if (CheckPosition((position_x - 1), position_y)) {
				if (position_x > 0) {
					world01->organizm.push_back(createMe(world01, position_x - 1, position_y));
				}
			}
		}
		else if (number == 1) {
			if (CheckPosition(position_x , position_y+1)) {
				if (position_y<world01->GetHeight()-1) {
					world01->organizm.push_back(createMe(world01, position_x , position_y+1));
				}
			}
		}
		else if (number == 2) {
			if (CheckPosition(position_x, position_y - 1)) {
				if (position_y>0) {
					world01->organizm.push_back(createMe(world01, position_x , position_y-1));
				}
			}
		}
		else if (number == 3) {
			if (CheckPosition(position_x + 1, position_y )) {
				if (position_x<world01->GetWidth()-1) {
					world01->organizm.push_back(createMe(world01, position_x + 1, position_y));
				}
			}
		}
 

	}
}

bool Plant::CheckPosition(int x, int y) {
	for (int a = 0; a < world01->organizm.size(); a++) {
		if ((world01->organizm[a]->GetXposition() == x) && (world01->organizm[a]->GetYposition() == y))
			return false;
	}
	return true;

}

//void Plant::Set_force(int new_force) { force = new_force; }
//int Plant::Get_force() { return force; }


void Plant::Set_World(World *w) {
	if (this != NULL)
		this->world01 = w;

}

void Plant::Collision(int x, int y) {
	;
}

void Plant::SetXposition(int x) { this->position_x = x; }
void Plant::SetYposition(int y) { this->position_y = y; }
int Plant::GetXposition() { return this->position_x; }
int Plant::GetYposition() { return this->position_y; }

int Plant::GetTime() {
	static int Ttt = 0;
	Ttt++;
	return Ttt;
}


void Plant::SetTime(int t) { time = t; }
int Plant::GetInitiative() { return initiative; }
void Plant::SetInitiative(int nwe) { initiative = nwe; }
void Plant::SetType(char T) { type = T; }
char Plant::GetType() { return type; };