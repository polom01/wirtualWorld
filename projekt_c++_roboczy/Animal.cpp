#include"Animal.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
//#include <typeinfo>


//usun
#include "Sheep.h"
#include "world.h"
#include "Wolf.h"
#include "Organisms.h"
#include "turtle.h"
#include "Antilope.h"
#include"Plant.h"/////////////////


 int Animal::GetTime() {
	 static int Ttt = 0;
	 Ttt++;
	 return Ttt ;
}

void Animal::Action() {
	//srand(time(NULL));//moze usunac /???
	int number = (std::rand() % 4) + 0;

	if (number == 0) {
		if (CheckPosition((position_x - 1), position_y)) {
			if(position_x>0)
			position_x--;  //lewa strona
		}
		else
			Collision(position_x - 1, position_y);
	}
	if (number == 1) {
		if (CheckPosition(position_x, position_y + 1)) {
		if(position_y<world01->GetHeight()-1)//-1 poniewaz jak mamy hight 4 to liczy sie 0 1 2 3
			position_y++;
		}
		else
			Collision(position_x, position_y + 1);
	}
	if (number == 2) {
		if (CheckPosition((position_x + 1), position_y)) {
			if (position_x < world01->GetWidth()-1)
				position_x++;
		}
		else
			Collision((position_x + 1), position_y);
	}
	if (number == 3) {
		if (CheckPosition(position_x, position_y - 1)) {
		if(position_y>0)
			position_y--;
		}
		else
			Collision(position_x, position_y - 1);
	}
}

void Animal::Collision(int x, int y) {



	//std::cout << "kolizja : " <<std::endl;
	//std::cout << typeid(world01->organizm[0]->).name() << std::endl;
	//std::cout << typeid(this).name() << std::endl;

	for (int a = 0; a < world01->organizm.size(); a++) {
		if ((world01->organizm[a]->GetXposition() == x) && (world01->organizm[a]->GetYposition() == y))
		{
			if (world01->organizm[a]->GetType() == type) {
				NewAnimal(x , y );
				break;
			}
			//else if (typeid(world01->organizm[a]).name()!=typeid(this).name()) {
			//	std::cout << typeid(world01->organizm[a]).name() << std::endl;
			//	std::cout << typeid(this).name() << std::endl;
		//	}
			else {
				Fight(x,y);
				break;
			}
		}
	}
	

}

void Animal::Fight(int PlaceX, int PlaceY) {

	int size = world01->organizm.size();

	for (int a = 0; a < size; a++) {
		if ((world01->organizm[a]->GetXposition() == PlaceX) && (world01->organizm[a]->GetYposition() == PlaceY)) {


			Turtle *an = dynamic_cast <Turtle *>(world01->organizm[a]);
			if ((an != 0)&&(Get_force()<5)) {
				std::cout << "zolw przepedzil napastnika" << std::endl;
				break;
			}

			Antilope *ab = dynamic_cast <Antilope *>(world01->organizm[a]);
			int number = (std::rand() % 2) + 0;
			if ((ab != 0) && (number==0)) {
				std::cout << "antylopa uciekla" << std::endl;
				world01->organizm[a]->SetXposition(position_x);
				world01->organizm[a]->SetYposition(position_y);
				position_x = PlaceX;
				position_y = PlaceY;
				break;
			}


			if (world01->organizm[a]->Get_force() <= this->force) {         //wygrywa atakujacy
				std::cout << world01->organizm[a]->GetType() << " przegral z " <<GetType()<< std::endl;
				world01->organizm[a]->EatMe(PlaceX, PlaceY, position_x, position_y);
				position_x = PlaceX;
				position_y = PlaceY;
				break;
			}
			else {
				for (int b = 0; b <size; b++) {
					if ((world01->organizm[b]->GetXposition() == position_x) && (world01->organizm[b]->GetYposition() == position_y)) {
						std::cout << GetType() << " przegral z " << world01->organizm[a]->GetType() << std::endl;
			
						
						size = world01->organizm.size();////////////////////////
						world01->organizm.erase(world01->organizm.begin() + b);
						world01->organizm.resize(size - 1);

						Plant *ab = dynamic_cast <Plant *>(world01->organizm[a]);/////////////////////
						if (ab != 0) {
							ab->EatMe(PlaceX, PlaceY, position_x, position_y);
						}////////////////
						break;
					}
				}
				break;
			}	
		}
		
	}
}

//void Animal::Set_force(int New_force) { this->force = New_force; }
//int Animal::Get_force() { return force; }

void Animal::Set_initiative(int New_initiative) { this->initiative = New_initiative; }
int Animal::Get_initiative() { return this->initiative; }
void Animal::Set_World(World *w) { 
	if(this!=NULL)
		this->world01 = w;
	
}

void Animal::SetXposition(int x) { this->position_x = x; }
void Animal::SetYposition(int y) { this->position_y = y; }
//int Animal::GetXposition() { return this->position_x; }
//int Animal::GetYposition() { return this->position_y; }

bool Animal::CheckPosition(int x, int y) {
	for (int a = 0; a < world01->organizm.size(); a++) {
		if ((world01->organizm[a]->GetXposition() == x) && (world01->organizm[a]->GetYposition() == y))
			return false;
	}
	return true;

}


World* Animal::GetWorld() {
	if(world01!=0)
	return this->world01;
	else return 0;
}

void Animal::NewAnimal(int PositionXParent , int PositionYParent ) {

	int NewPositionX=-1;
	int NewPositionY=-1;
	int count = 0;
	int number = (std::rand() % 6) + 0;
	if (position_y == PositionYParent) {
		if (position_x < PositionXParent) {
			do {
				if (number == 0) {
					NewPositionX = position_x - 1;
					NewPositionY = position_y;
				}
				else if (number == 1) {
					NewPositionX = position_x;
					NewPositionY = position_y + 1;

				}
				else if (number == 2) {
					NewPositionX = PositionXParent;
					NewPositionY = position_y + 1;

				}
				else if (number == 3) {
					NewPositionX = PositionXParent + 1;
					NewPositionY = position_y;

				}
				else if (number == 4) {
					NewPositionX = PositionXParent;
					NewPositionY = position_y - 1;

				}
				else if (number == 5) {
					NewPositionX = position_x;
					NewPositionY = position_y - 1;

				}
				else {
					std::cout << "wygenerowano za duza liczbe" << std::endl;
				}
				count++;
				number = (number + count)%6;
				//std::cout << CheckPosition(NewPositionX, NewPositionY) << std::endl;////////////////////////
			} while ((!CheckPosition(NewPositionX, NewPositionY))&&(count<6));

		}
		else {
			do {
				if (number == 0) {
					NewPositionX = PositionXParent - 1;
					NewPositionY = position_y;
				}
				else if (number == 1) {
					NewPositionX = PositionXParent;
					NewPositionY = position_y + 1;

				}
				else if (number == 2) {
					NewPositionX = position_x;
					NewPositionY = position_y + 1;

				}
				else if (number == 3) {
					NewPositionX = position_x + 1;
					NewPositionY = position_y;

				}
				else if (number == 4) {
					NewPositionX = position_x;
					NewPositionY = position_y - 1;

				}
				else if (number == 5) {
					NewPositionX = PositionXParent;
					NewPositionY = position_y - 1;

				}
				else {
					std::cout << "wygenerowano za duza liczbe" << std::endl;
				}
				count++;
				number = (number + count) % 6;
				//std::cout << CheckPosition(NewPositionX, NewPositionY) << std::endl;////////////////////////
			} while ((!CheckPosition(NewPositionX, NewPositionY)) && (count<6));

		}
	}
	else {
		if (position_y < PositionYParent) {
			do {
				if (number == 0) {
					NewPositionX = PositionXParent - 1;
					NewPositionY = position_y;
				}
				else if (number == 1) {
					NewPositionX = PositionXParent;
					NewPositionY = position_y -1;

				}
				else if (number == 2) {
					NewPositionX = position_x+1;
					NewPositionY = position_y ;

				}
				else if (number == 3) {
					NewPositionX = position_x + 1;
					NewPositionY = PositionYParent;

				}
				else if (number == 4) {
					NewPositionX = position_x;
					NewPositionY = PositionYParent - 1;

				}
				else if (number == 5) {
					NewPositionX = PositionXParent-1;
					NewPositionY = PositionYParent ;

				}
				else {
					std::cout << "wygenerowano za duza liczbe" << std::endl;
				}
				count++;
				number = (number + count) % 6;
			//	std::cout << CheckPosition(NewPositionX, NewPositionY) << std::endl;////////////////////////
			} while ((!CheckPosition(NewPositionX, NewPositionY)) && (count<6));
		}
		else {
			do {
				if (number == 0) {
					NewPositionX = PositionXParent - 1;
					NewPositionY = PositionYParent;
				}
				else if (number == 1) {
					NewPositionX = PositionXParent;
					NewPositionY = PositionYParent - 1;

				}
				else if (number == 2) {
					NewPositionX = position_x + 1;
					NewPositionY = PositionYParent;

				}
				else if (number == 3) {
					NewPositionX = position_x + 1;
					NewPositionY = position_y;

				}
				else if (number == 4) {
					NewPositionX = position_x;
					NewPositionY = position_y - 1;

				}
				else if (number == 5) {
					NewPositionX = PositionXParent - 1;
					NewPositionY = position_y;

				}
				else {
					std::cout << "wygenerowano za duza liczbe" << std::endl;
				}
				count++;
				number = (number + count) % 6;
				//std::cout << CheckPosition(NewPositionX, NewPositionY) << std::endl;////////////////////////
			} while ((!CheckPosition(NewPositionX, NewPositionY)) && (count<6));

		}
	}

	if ((NewPositionX >= 0) && (NewPositionY >= 0)&&(NewPositionX <world01->GetWidth() ) && (NewPositionY < world01->GetHeight())&&(CheckPosition(NewPositionX, NewPositionY)))
	{

		world01->organizm.push_back(this->createMe(world01, NewPositionX, NewPositionY));

	}
	//else std::cout << "pozycje sa ujemne void ANIMAL::NEWANIMAL" << std::endl;


}

void  Animal::EatMe(int x, int y, int EaterX, int EaterY) {
	int size = world01->organizm.size();

	for (int a = 0; a < size; a++) {
		if ((world01->organizm[a]->GetXposition() == x) && (world01->organizm[a]->GetYposition() == y)) {
			Organisms* oop = world01->organizm[a];
			world01->organizm.erase(world01->organizm.begin() + a);
			world01->organizm.resize(size - 1);
			delete oop;
			break;
		}
	}
}


char Animal::GetType() { return type; };