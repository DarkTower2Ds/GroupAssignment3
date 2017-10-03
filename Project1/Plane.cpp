#include <iostream>
#include "Plane.h"
using namespace std;

/*
	Default Constructor
	"Prompts the user to input the number of rows and columns of Seats
	 for first class and economy class,
	 then class the overload constructor with those values."
*/
Plane::Plane()
{

}

/*
	Overload Constructor
	"Store all of the row and column data into the private variables.
	 Initialize the 2D arrays firstClass and Economy."
*/
Plane::Plane(int flRow, int flCol, int eRow, int eCol)
{

}

/*
	"Show all the seats in correct order (both first class and economy class)"
*/
void Plane::showAllSeat()
{

}

/*
	"Ask if the user wants first class or economy class.
	 Ask for the Row and Column they want.
	 If the seat was not booked, book it. Otherwise, inform the user is booked."
*/
void Plane::bookASeat()
{

}

/*
	"Ask if the user wants [to check] first class or economy class.
	 Ask for the row and column [of the Seat they want to check].
	 Inform the user [whether] the seat is booked."
*/
void Plane::checkASeat()
{

}

/*
	"Ask if the user if they want [to clear] first class or economy class.
	 Ask for the row and column [of the Seat they want to clear].
	 If the Seat is booked, empty the Seat. Else, inform the user the Seat is empty.
*/
void Plane::clearASeat()
{

}

/*
	"Clean all of the Seats on the Plane and put [them] back to empty."
*/
void Plane::emptyPlane()
{

}

/*
	"Delete all Seats in the Plane.
	 [This] will be called when the user wants to exit the program."
*/
Plane::~Plane()
{

}