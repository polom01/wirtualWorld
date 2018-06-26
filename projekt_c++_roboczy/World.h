#pragma once
#include "Organisms.h"

#include<iostream>
#include <cstdlib>
#include <ctime>
#include<vector>


class World {

	int height;
	int width;

public:

	std::vector <Organisms *> organizm;
	









	World() {
		;	//width = 20;//20 //4 do prob
		//height = 20; //20 //zmienic na dowolny do wpidania
	
	}


	void DoTour();
	void DrawWorld();
	void Initialization();	
	static bool mysort(Organisms* right, Organisms* left);
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	bool CheckPosition(int x, int y);
	void Save();
	void Load();
};

