#pragma warning(disable: 4996)
#include "Human.h"
#include "World.h"
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


using namespace std;


void Human::Action() {
	cout << "	p = super moc, strzalki = wykonaj ruch" << endl;
	world01->DrawWorld();
	

	//coldown = time;
	 int time = 0;
	time = GetColdown();
	if (time > 0) {
		if (time > 5) {
			cout << "twoja moc wciaz jest wlaczona" << endl;
			this->TurnOnPower();
		}

		time--;
	}
	char move = getch();
	if ((move == 'p')){
		if (time == 0) {
			cout << "uzyles swojej mocy. zmien swoja pozycje uzywajac strzalek" << endl;
			this->TurnOnPower();
			time = 10;
		}
		else cout << "musisz jeszcze troche poczekac" << endl;

		getch();
		move = getch();
	}
	else if (move == 'l') {
		world01->Load();
		world01->DrawWorld();
		getch();
		move = getch();
	}
	else if ((move == 's')) {
		world01->Save();
		getch();
		move = getch();
	}
	else{
		move = getch();
	}
	system("cls");
	if ((move == UP)&&(GetYposition()>0)){
		if (CheckPosition((position_x), position_y - 1)) {
			position_y -= 1;
		}
		else Collision((position_x ), position_y-1);
	}
	else if ((move == DOWN)&& (GetYposition()<world01->GetHeight()-1)){
		if (CheckPosition((position_x), position_y + 1)) {
			position_y += 1;
		}
		else Collision((position_x), position_y + 1);
	}
	else if ((move == LEFT) && (GetXposition() > 0)) {
		if (CheckPosition((position_x - 1), position_y)) {
			position_x -= 1;
		}
		else Collision((position_x - 1), position_y);
	}
	else if ((move == RIGHT)&& (GetXposition()<world01->GetWidth() - 1)){
		if (CheckPosition((position_x + 1), position_y)) {
			position_x += 1;
		}
		else Collision((position_x + 1), position_y);
	}
	SetColdown(time);
	//world01->DrawWorld();
	
}

void Human::TurnOnPower() {
	int size = world01->organizm.size();
	int x = this->GetXposition();
	int y = this->GetYposition();
	int tab[4] = { 0,0,0,0 };
	int index = 0;

		for (int a = 0; a < size; a++) {
			if ((world01->organizm[a]->GetXposition() == x + 1) && (world01->organizm[a]->GetYposition() == y)) {
				cout << "zabiles " << world01->organizm[a]->GetType() << endl;
				tab[index] = a;
				index++;
			}
			else if ((world01->organizm[a]->GetXposition() == x - 1) && (world01->organizm[a]->GetYposition() == y)) {
				cout << "zabiles " << world01->organizm[a]->GetType() << endl;
				tab[index] = a;
				index++;

			}

			else if ((world01->organizm[a]->GetXposition() == x) && (world01->organizm[a]->GetYposition() == y - 1)) {
				cout << "zabiles " << world01->organizm[a]->GetType() << endl;
				tab[index] = a;
				index++;


			}

			else if ((world01->organizm[a]->GetXposition() == x) && (world01->organizm[a]->GetYposition() == y + 1)) {
				cout << "zabiles " << world01->organizm[a]->GetType() << endl;
				tab[index] = a;
				index++;

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

