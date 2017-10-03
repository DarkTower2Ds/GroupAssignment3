#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include "Seat.h"
using namespace std;

class Plane
{
private:
	Seat **firstClass;
	Seat **economy;
	int firstClassRow;
	int firstClassCol;
	int economyRow;
	int economyCol;

public:
	Plane();
	Plane(int fcRow, int fcCol, int eRow, int eCol);
	void showAllSeat();
	void bookASeat();
	void checkASeat();
	void clearASeat();
	void emptyPlane();
	~Plane();
};

#endif