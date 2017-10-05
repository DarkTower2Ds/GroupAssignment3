#include <iostream>
#include "Plane.h"
using namespace std;

/*
	Default Constructor
	"Prompts the user to input the number of rows and columns of Seats
	 for first class and economy class,
	 then make a call to the overload constructor with those values."
*/
Plane::Plane()
{
    int newFirstClassRow, newFirstClassCol;
    int newEconRow, newEconCol;
    cout<<"How many rows for First Class?"<<endl;
    cin>>newFirstClassRow;
    cout<<endl;
    cout<<"How many columns for First Class?"<<endl;
    cin>>newFirstClassCol;
    cout<<endl;
    
    cout<<"How many rows for Economy?"<<endl;
    cin>>newEconRow;
    cout<<endl;
    cout<<"How many columns for Economy?"<<endl;
    cin>>newEconCol;
    cout<<endl;
    
    Plane(newFirstClassRow, newFirstClassCol,newEconRow, newEconCol);
}

/*
	Overload Constructor
	"Store all of the row and column data into the private variables.
	 Initialize the 2D arrays firstClass and Economy."
*/
Plane::Plane(int newFirstClassRow,int newFirstClassCol, int newEconRow,int newEconCol){
    firstClassRow = newFirstClassRow;
    firstClassCol = newFirstClassCol;
    econRow = newEconRow;
    econCol = newEconCol;
    Seat firstClass[firstClassRow][firstClassCol];
    Seat economy[econRow][econCol];
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
void Plane::bookASeat(){
    int choice, row, column;
    cout<<"First Class(1) or Economy(2)?";
    cin>>choice;
    
    if(choice == 1){
        cout<<"You're now booking a First Class seat"<<endl;
        cout<<"Row: ";
        cin>>row;
        cout<<"Column: ";
        cin>>column;
        cout<<endl;
        
        if((firstClass[row][column].isEmpty == true) || (firstClass[row][column].booking = '-')){
            cout<<"Thank you, your booked seat is at Row: "<<row<<" Column: "<<column<<endl;
            firstClass[row][column].booking = 'x';
        }
        else{
            cout<<"Sorry, this seat is already booked.";
        }
    }
    
    else if(choice == 2){
        cout<<"You're now booking an Economy seat"<<endl;
        cout<<"Row: ";
        cin>>row;
        cout<<"Column: ";
        cin>>column;
        cout<<endl;
        
        if((economy[row][column].isEmpty == true) || (economy[row][column].booking = '-')){
            cout<<"Thank you, your booked seat is at Row: "<<row<<" Column: "<<column<<endl;
            economy[row][column].booking = 'x';
        }
        else{
            cout<<"Sorry, this seat is already booked.";
        }
    }
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
	Seat **rowIterator = firstClass;
	for (int i = 0; i < firstClassRow; i++)
	{
		Seat *colIterator = *rowIterator;
		for (int j = 0; j < firstClassCol; j++)
		{
			colIterator->booking = '-';
			colIterator->isEmpty = true;

			colIterator++;
		}

		rowIterator++;
	}

	rowIterator = economy;
	for (int i = 0; i < economyRow; i++)
	{
		Seat *colIterator = *rowIterator;
		for (int j = 0; j < economyCol; j++)
		{
			colIterator->booking = '-';
			colIterator->isEmpty = true;

			colIterator++;
		}

		rowIterator++;
	}
}

/*
	"Delete all Seats in the Plane.
	 [This] will be called when the user wants to exit the program."
*/
Plane::~Plane()
{
	delete [] firstClass;
	delete [] economy;
}
