#include<iostream>
#include "world.h"
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
#include "windows.h"


// o sow_thistle
// s sheep
// w wolf
// G Grass
// U guarana
// B wolf_berry
// k barszcz sosnowskiego
// L fox
// z zolw



int main() {
	SetConsoleTitleA("Kacper Polom 165324");
	srand(time(NULL));
	World w;
	World *wor=&w;
	w.Initialization();
		int a = 0;
		while (a == 0) {
			std::cout << "o - mlecz , s - owca , w - wilk , G - trawa , U - guarana , B - wilcze jagody , K - barszcz sosnowsiego , L - lis , z - zolw" << std::endl;
			
			w.DoTour();
	
			for (int b = 0; b < w.organizm.size(); b++) {
				a = 1;
				Human *an = dynamic_cast <Human*>(w.organizm[b]);
				if (an != 0) {
					a = 0;
					break;
				}
			}
		}
	
	std::cout<<std::endl << "przegrales !!!"<<std::endl;
	return 0;
}