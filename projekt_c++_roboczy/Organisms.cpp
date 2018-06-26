#include "Organisms.h"
int Organisms::GetXposition() { return this->position_x; }
int Organisms::GetYposition() { return this->position_y; }
char Organisms::GetType() { return type; }   
int Organisms::Get_force() { return force; }

int Organisms::GetTime() { return time; }
void Organisms::SetTime(int t) { time = t; }
int Organisms::GetInitiative() { return initiative; }
void Organisms::SetInitiative(int nwe) {  initiative=nwe; }
void Organisms::GetType(char T) { type = T; }
void Organisms::Set_force(int F) { force = F; }
void Organisms::SetXposition(int x) { position_x = x; }
void Organisms::SetYposition(int y) { position_y = y; }
int Organisms::GetColdown() { return coldown; }
void Organisms::SetColdown(int x) { coldown = x; }

