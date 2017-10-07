#include <iostream>
#include "Plane.h"
using namespace std;

/*
	Default Constructor
 • Ask for num of rows and cols of both firstClass and economy(using cin),
   and store them in the relevant member variables.
 • Initialize the double dimensional arrays for firstClass and economy
*/
Plane::Plane()
{
    int newFirstClassRow, newFirstClassCol;
    int newEconRow, newEconCol;
    
    cout<<"How many rows for First Class?";
    cin>>newFirstClassRow;
    cout<<endl;
    cout<<"How many columns for First Class?";
    cin>>newFirstClassCol;
    cout<<endl;
    cout<<"How many rows for Economy?";
    cin>>newEconRow;
    cout<<endl;
    cout<<"How many columns for Economy?";
    cin>>newEconCol;
    cout<<endl;
    
    
    firstClassRows = newFirstClassRow;
    firstClassCols = newFirstClassCol;
    economyRows = newEconRow;
    economyCols = newEconCol;
    
    firstClass[firstClassRows][firstClassCols];
    economy[economyRows][economyCols];
 
}

/*
	Overload Constructor
 • Store all the row and col data into the member variables.
 • Initialize the double dimensional arrays for firstClass and economy
*/
Plane::Plane(int newFirstClassRow,int newFirstClassCol, int newEconRow,int newEconCol){
    firstClassRows = newFirstClassRow;
    firstClassCols = newFirstClassCol;
    economyRows = newEconRow;
    economyCols = newEconCol;
    firstClass[firstClassRows][firstClassCols];
    economy[economyRows][economyCols];
}

int Plane::getFirstClassRows()
{ return firstClassRows;}
int Plane::getFirstClassCols()
{ return firstClassCols;}
                                            //Getters
int Plane::getEconomyRows()
{ return economyRows;}
int Plane::getEconomyCols()
{ return economyCols;}

void setFirstClass(int Rows,int Cols){
    firstClassRows = Rows;
    firstclassCols = Cols;
}                                           //Setters
void setEconomyClass(int Rows,int Cols){
    economyRows = Rows;
    economyCols = Cols;
}


void Plane::displaySeats()
{
    /*
     
     • Print (formatted neatly) all the seats in correct order (both firstClass and economy)
     • The user should be able to tell from the display which seats are available
     and which are booked
     
     */
}


void Plane::bookSeat(){
    /*
     • ask whether a user wants a seat in firstClass or economy
     • ask for the row they want to sit in, and the seat number in that row
     • If seat is available, book it. Else, inform user that it’s already booked
     */
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
        
        if((firstClass[row][column].isBooked == false) || (firstClass[row][column].status = '-')){
            cout<<"Thank you, your booked seat is at Row: "<<row<<" Column: "<<column<<endl;
            firstClass[row][column].status = 'X';
        }
        else{
            cout<<"Sorry, this seat is already booked."<<endl;
        }
    }
    
    else if(choice == 2){
        cout<<"You're now booking an Economy seat"<<endl;
        cout<<"Row: ";
        cin>>row;
        cout<<"Column: ";
        cin>>column;
        cout<<endl;
        
        if((economy[row][column].isBooked == false) || (economy[row][column].status = '-')){
            cout<<"Thank you, your booked seat is at Row: "<<row<<" Column: "<<column<<endl;
            economy[row][column].booking = 'X';
        }
        else{
            cout<<"Sorry, this seat is already booked.";
    }
    else{
        cout<<"Sorry, your input is invalid. Please choose again."<<endl;
        bookSeat();
    }
}



void Plane::checkSeat()
{
    /*
     • ask if user want firstClass or economy seat
     • ask for the row/col numbers of the seat they want to check
     • Inform user whether or not the seat is booked
     */
    int choice, row, column;
    cout<<"First Class(1) or Economy(2)?";
    cin>>choice;
    
    if(choice == 1){
        cout<<"You're now checking for a First Class seat"<<endl;
        cout<<"Which Row?: ";
        cin>>row;
        cout<<"Which Column?: ";
        cin>>column;
        cout<<endl;
        
        if((firstClass[row][column].isBooked == false) || (firstClass[row][column].status = '-')){
            cout<<"The seat is available for booking!";
        }
        else{
            cout<<"Sorry, this seat is already booked."<<endl;
        }
    }
    
    else if(choice == 2){
        cout<<"You're now checking for an Economy seat"<<endl;
        cout<<"Which Row?: ";
        cin>>row;
        cout<<"Which Column?: ";
        cin>>column;
        cout<<endl;
        
        if((economy[row][column].isBooked == false) || (economy[row][column].status = '-')){
            cout<<"The seat is available for booking!";
        }
        else{
            cout<<"Sorry, this seat is already booked."<<endl;
    }
    else{
        cout<<"Sorry, your input is invalid. Please choose again."<<endl;
        checkSeat();
    }
    
}


void Plane::clearSeat()
{
    /*
     • ask whether user wants to clear firstClass or economy seat
     • ask for the row/col numbers of the seat they want to clear
     • If booked, empty the seat. Else, inform user that seat was not booked
     */
    int choice, row, column;
    cout<<"Would you like to clear: First Class seat (1) or Economy sea (2)?";
    cin>>choice;
    
    if(choice == 1){
        cout<<"You're now clearing a First Class seat"<<endl;
        cout<<"Which Row?: ";
        cin>>row;
        cout<<"Which Column?: ";
        cin>>column;
        cout<<endl;
        
        if((firstClass[row][column].isBooked == true) || (firstClass[row][column].status = 'X')){
            firstClass[row][column].status = '-';
        }
        else{
            cout<<"This is an empty seat."<<endl;
        }
    }
    
    else if(choice == 2){
        cout<<"You're clearing an Economy seat"<<endl;
        cout<<"Which Row?: ";
        cin>>row;
        cout<<"Which Column?: ";
        cin>>column;
        cout<<endl;
        
        if((economy[row][column].isBooked == true) || (economy[row][column].status = 'X')){
            economy[row][column].status = '-';
        }
        else{
            cout<<"This is an empty seat."<<endl;
        }
    }
    else{
        cout<<"Sorry, your input is invalid. Please choose again."<<endl;
        clearSeat();
        }
        
    }

}


void Plane::clearAllSeats()
{
    /*
     • clean all seats on the plane and put it back to empty
     */
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


Plane::~Plane()
{
  /*
  • Delete all seats in the plane
  • MUST Delete two dimensional arrays
  • Will be called when the user exits the program
  */
	delete [] firstClass;
	delete [] economy;
}
