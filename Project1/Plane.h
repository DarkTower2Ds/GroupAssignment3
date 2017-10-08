#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include "Seat.h"
using namespace std;

class Plane
{
private:
	Seat **firstClass;	//Dynamic 2D Array of the Seats in first class
	Seat **economy;		//Dynamic 2D Array of the Seats in economy class
	int firstClassRow;	//Number of Rows of Seats in first class
	int firstClassCol;	//Number of Columns of Seats in first class
	int economyRow;		//Number of Rows of Seats in economy class
	int economyCol;		//Number of Columns of Seats in economy class

public:
	Plane();											//Default constructor
	Plane(int fcRow, int fcCol, int eRow, int eCol);	//Overloaded constructor w/ #s of rows and columns in each class
	void showAllSeat();									//Print the Seats on the plane
	void bookASeat();									//Book a Seat on the plane
	void checkASeat();									//Check if a Seat is booked on the plnae
	void clearASeat();									//Empty a Seat if it is booked
	void emptyPlane();									//Empty all of the Seats on the plane
	~Plane();											//Destructor

	//The following functions are I have added in order to make the printing and display of the seats more interesting and FUN
	void printEvenNose(int numOfCols);					//Prints the nose section of the aircraft when there's an even number of columns
	void printOddNose(int numOfCols);					//Prints the nose section of the aircraft when there's an odd number of columns
	int findWingPlacement();							//Determines where the wings will be printed. Returns an integer value representing the half-way point of the plane
	void printFuselage(int wingPlacement, int numOfCols);				//Prints the main body of the aircraft, including the wings
};

#endif