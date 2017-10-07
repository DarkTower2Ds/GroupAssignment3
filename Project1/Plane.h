#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include "Seat.h"
using namespace std;

struct Seat
{
    char status;    // '-' if the seat is empty,'X' if the seat is booked
    bool isBooked;    //True if the seat is empty, false if available
};

class Plane
{
private:
	Seat **firstClass;	//Dynamic 2D Array of the Seats in first class
	Seat **economy;		//Dynamic 2D Array of the Seats in economy class
	int firstClassRows;	//Number of Rows of Seats in first class
	int firstClassCols;	//Number of Columns of Seats in first class
	int economyRows;		//Number of Rows of Seats in economy class
	int economyCols;		//Number of Columns of Seats in economy class

public:
	Plane();											//Default constructor
	Plane(int fcRow, int fcCol, int eRow, int eCol);	//Overloaded constructor w/ #s of rows and                          columns in each class
    
	void displaySeats();								//Print the Seats on the plane
	void bookSeat();									//Book a Seat on the plane
	void checkSeat();									//Check if a Seat is booked on the plnae
	void clearSeat();									//Empty a Seat if it is booked
	void clearAllSeats();								//Empty all of the Seats on the plane
	~Plane(); //Destructor
    
    void setFirstClass(int,int);
    void setEconomyClass(int,int);  //Setters
    
    int getFirstClassRows();
    int getFirstClassCols();    //Getters
    int getEconomyRows();
    int getEconomyCols();
    
    
};

#endif
