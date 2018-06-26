#include "World.h"

#include "Sheep.h"
#include "Wolf.h"
#include "Grass.h"
#include "Sow-Thistle.h"
#include "Guarana.h"
#include "WolfBerry.h"
#include "BarszczSosnowskiego.h"
#include "fox.h"
#include "Turtle.h"
#include "Human.h"
#include "Antilope.h"
#pragma warning( disable : 4996 )

#include <algorithm> 


using namespace std; 
void World::DoTour() {

	std::sort(organizm.begin(), organizm.end(), mysort);

	//dopisac sortwanie
	int size = organizm.size();
	
	for (int a = 0; a < size; a++) {
		//std::cout << "zwierzak nr :" <<  a << " x: " << organizm[a]->GetXposition()<<" y: " << organizm[a]->GetYposition() <<" typ "<<organizm[a]->GetType() <<std::endl;
		organizm[a]->Action();
		if (size > organizm.size())size = organizm.size();
	}

}

void World::DrawWorld() { //zmienic na aktualizowanie
	for (int a = 0; a < height + 2; a++) {
		for (int b = 0; b < width + 2; b++) {
			int spr=0;
			if ((a == 0)||(a==height+1)||(b==0)||(b==width+1)) {
				cout << "X";
				spr = 1;
			}
			for (int c = 0; c < organizm.size(); c++) {
				if ((organizm[c]->GetXposition() == b-1) && (organizm[c]->GetYposition() == a-1)) {
					cout << organizm[c]->GetType();
					spr = 1;
					break;
			}
			}
			if (spr == 0) {
				cout << " ";
			}
			
		}
		cout << endl;
	}
}

bool World::mysort(Organisms* right, Organisms* left)
{
	if (right->GetInitiative() == left->GetInitiative())// ==0
	{
		return right->GetTime() < left->GetTime();
	}

	return right->GetInitiative() > left->GetInitiative();
}

void World::Initialization() {
	int szerokosc = 0;
	int wysokosc = 0;
	int x, y;
	do {
		cout << "wpisz szerokosc :" << endl;
		cin >> szerokosc;
		cout << "wpisz wysokosc :" << endl;
		cin >> wysokosc;
		if (szerokosc*wysokosc < 150) {
			cout << "podales za maly rozmiar sprobuj jeszcze raz minimalny rozmiar to 150 " << endl;
		}
	} while (szerokosc*wysokosc < 150);
	height = wysokosc;
	width = szerokosc;
	Organisms*	newOne1 = new Human(this, 0, 0);
	organizm.push_back(newOne1);

	for (int i = 0; i < 16; i++) {
		do {
			x = (std::rand() % szerokosc) + 0;
			y = (std::rand() % wysokosc) + 0;
		} while (CheckPosition(x, y));
		if (i < 2) {
			Organisms*	newOne = new Sheep(this, x, y);
			organizm.push_back(newOne);
		}
		else if (i < 4) {
			Organisms*	newOne = new Wolf(this, x, y);
			organizm.push_back(newOne);
		}
		else if (i < 6) {
			Organisms*	newOne = new Sow_Thistle(this, x, y);
			organizm.push_back(newOne);
		}
		else if (i < 8) {
			Organisms*	newOne = new Guarana(this, x, y);
			organizm.push_back(newOne);
		}
		else if (i < 10) {
			Organisms*	newOne = new Wolf_Berry(this, x, y);
			organizm.push_back(newOne);
		}
		else if (i < 12) {
			Organisms*	newOne = new BarszczSosnowskiego(this, x, y);
			organizm.push_back(newOne);
		}
		else if (i < 14) {
			Organisms*	newOne = new Fox(this, x, y);
			organizm.push_back(newOne);
		}
		else if (i < 16) {
			Organisms*	newOne = new Turtle(this, x, y);
			organizm.push_back(newOne);
		}
		

	}
}

bool World::CheckPosition(int x, int y) {
	for (int a = 0; a < organizm.size(); a++) {
		if ((organizm[a]->GetXposition() == x) && (organizm[a]->GetYposition() == y))
			return true;
	}
	return false;

}

void World::Save() {
	int size = organizm.size();
	FILE *file;
	file = fopen("SaveWorld.txt", "w+");
	fprintf(file, "%d %d %d \n", height , width , size);
	for (int i = 0; i < size; i++) {
		if(organizm[i]->GetType()!='H')
		fprintf(file, "%c %d %d %d %d %d \n",organizm[i]->GetType(), organizm[i]->GetXposition(), organizm[i]->GetYposition(), organizm[i]->Get_force(), organizm[i]->GetInitiative() , organizm[i]->GetTime());
		else fprintf(file, "%c %d %d %d %d %d %d \n", organizm[i]->GetType(), organizm[i]->GetXposition(), organizm[i]->GetYposition(), organizm[i]->Get_force(), organizm[i]->GetInitiative(), organizm[i]->GetTime() , organizm[i]->GetColdown());
	}
	fclose(file);
}

void World::Load() {
	organizm.clear();
	FILE *file;
	Organisms *newOne;
	file = fopen("SaveWorld.txt", "r");
	char T;
	int number , size , tempForce , tempTime , tempX , tempY , tempIni;
	fscanf(file, " %d", &number);
	height = number;
	fscanf(file, " %d", &number);
	width = number;
	fscanf(file, " %d", &size);

	for (int a = 0; a < size; a++) {

		fscanf(file, " %c", &T);
		fscanf(file, "%d", &tempX);
		fscanf(file, "%d", &tempY);
		fscanf(file, "%d", &tempForce);
		fscanf(file, "%d", &tempIni);
		fscanf(file, "%d", &tempTime);
		switch (T)
		{


		case 'A':newOne = new Antilope(this, tempX, tempY); break;
		case 'L':newOne = new Fox(this, tempX, tempY); break;
		case 'S':newOne = new Sheep(this, tempX, tempY); break;
		case 'W':newOne = new Wolf(this, tempX, tempY); break;
		case 'Z':newOne = new Turtle(this, tempX, tempY); break;
		case 'U':newOne = new Guarana(this, tempX, tempY); break;
		case 'K':newOne = new BarszczSosnowskiego(this, tempX, tempY); break;
		case 'G':newOne = new Grass(this, tempX, tempY); break;
		case 'B':newOne = new Wolf_Berry(this, tempX, tempY); break;
		case 'H': {
			newOne = new Human(this, tempX, tempY);
			int d;
			fscanf(file, "%d", &d);
			newOne->SetColdown(d); break;
		}
		default:newOne = new Sow_Thistle(this, tempX, tempY);
		}
		

		newOne->Set_force(tempForce);
		newOne->SetTime(tempTime);
		newOne->SetInitiative(tempIni);

		this->organizm.push_back(newOne);

	}



	fclose(file);
}