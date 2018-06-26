#pragma once
class World;
class Organisms {
	
protected:

	int force, initiative, position_x, position_y ;
	World * world01;
	char type;
	int time , coldown;
public:
	 virtual void Action() = 0;
	 virtual void Collision(int x , int y) =0;
	 virtual void EatMe(int x, int y, int EaterX, int EaterY)=0 ;
	 int GetXposition() ;
	 int GetYposition() ;
	 char GetType() ;
	 int Get_force() ;
	 void Set_force(int F) ;
	int GetTime();
	void SetTime(int t);

	int GetInitiative();
	void SetInitiative(int nwe);
	void GetType(char T);
	int GetColdown();
	void SetColdown(int x);

	 void SetXposition(int x);
	 void SetYposition(int y);
	

};


// type = s ->sheep
