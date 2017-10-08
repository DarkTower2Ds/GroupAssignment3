#include "Plane.h"

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
    
    firstClass[firstClassRows][firstClassCols]; //FOR THE RECORD I THINK THIS IS CURRENTLY INCORRECT AND I WILL CHANGE IT IF IT DOESN'T WORK. THIS IS NOT THE PROPER WAY TO DECLARE DYNAMIC 2D ARRAYS - Alex
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

//I don' think it's at all necessary to have these getters and setters here. They are NOT required and serve no purpose in our code as it is. - Alex
/*
//Getters
int Plane::getEconomyRows()
{ return economyRows;}
int Plane::getEconomyCols()
{ return economyCols;}

void Plane::setFirstClass(int rows,int cols)
{
	firstClassRows = rows;
    firstClassCols = cols;
}

//Setters
void setEconomyClass(int rows,int cols)
{
	economyRows = rows;
	economyCols = cols;
}
*/

void Plane::bookASeat() {
	/*
	 • ask whether a user wants a seat in firstClass or economy
	 • ask for the row they want to sit in, and the seat number in that row
	 • If seat is available, book it. Else, inform user that it’s already booked
	 */
	int choice, row, column;
	cout << "First Class(1) or Economy(2)?";
	cin >> choice;

	if (choice == 1) {
		cout << "You're now booking a First Class seat" << endl;
		cout << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> column;
		cout << endl;

		if ((firstClass[row][column].isBooked == false) || (firstClass[row][column].status = '-')) //Same problem as below in the economy part of this function - Alex
		{
			cout << "Thank you, your booked seat is at Row: " << row << " Column: " << column << endl;
			firstClass[row][column].status = 'X';
		}
		else if (firstClass[row][column].isBooked == true) //And here - Alex
		{
			cout << "Sorry, this seat is already booked." << endl;
		}
		else if ((column > firstClassCols) || (row > firstClassRows)) //This statement was present for economy but not for first class, and I don't know why, because it's equally important to check that the user input for first class is valid, too. - Alex
		{
			cout << "Sorry, your input is invalid. Please choose again." << endl;
			bookASeat();
		}
	}

	else if (choice == 2) {
		cout << "You're now booking an Economy seat" << endl;
		cout << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> column;
		cout << endl;

		if ((economy[row][column].isBooked == false) || (economy[row][column].status = '-')) //everything past the || is unnecessary. It's called a "short circuit" error - Alex
		{
			cout << "Thank you, your booked seat is at Row: " << row << " Column: " << column << endl;
			economy[row][column].status = 'X';
		}
		else if ((economy[row][column].isBooked == true)) //I added this other if statement here because you can't have two else's like that without another if statment of some kind. - Alex
		{
			cout << "Sorry, this seat is already booked.";
		}
		else if ((column > economyCols) || (row > economyRows))
		{
		cout << "Sorry, your input is invalid. Please choose again." << endl;
		bookASeat();
		}
	}
}



void Plane::checkASeat()
{
	/*
	 • ask if user want firstClass or economy seat
	 • ask for the row/col numbers of the seat they want to check
	 • Inform user whether or not the seat is booked
	 */
	int choice, row, column;
	cout << "First Class(1) or Economy(2)?";
	cin >> choice;

	if (choice == 1) {
		cout << "You're now checking for a First Class seat" << endl;
		cout << "Which Row?: ";
		cin >> row;
		cout << "Which Column?: ";
		cin >> column;
		cout << endl;

		if ((firstClass[row][column].isBooked == false) || (firstClass[row][column].status = '-')) //Same stuff as in the previous function - Alex
		{
			cout << "The seat is available for booking!";
		}
		else if(firstClass[row][column].isBooked == true)
		{
			cout << "Sorry, this seat is already booked." << endl;
		}
		else if ((column > firstClassCols) || (row > firstClassRows))
		{
			cout << "Sorry, your input is invalid. Please choose again." << endl;
			bookASeat();
		}
	}

	else if (choice == 2)
	{
		cout << "You're now checking for an Economy seat" << endl;
		cout << "Which Row?: ";
		cin >> row;
		cout << "Which Column?: ";
		cin >> column;
		cout << endl;

		if ((economy[row][column].isBooked == false) || (economy[row][column].status = '-')) //This is the same problem as in  the bookASeat function. - Alex
		{
			cout << "The seat is available for booking!";
		}
		else if ((economy[row][column].isBooked == true)) //And here - Alex
		{
			cout << "Sorry, this seat is already booked." << endl;
		}
		else //And here - Alex
		{
		cout << "Sorry, your input is invalid. Please choose again." << endl;
		checkASeat();
		}
	}
}
/*
	"Show all the seats in correct order (both first class and economy class)"
*/
void Plane::showAllSeat()
{
	/* THIS IS THE BORING ONE THAT SHOULD 100% WORK
	Seat **rowIterator = firstClass;
	Seat *colIterator = *rowIterator;

	cout << "First Class\n----------" << endl;
	for (int i = 0; i < firstClassRow; i++)
	{
		colIterator = *rowIterator;
		for (int j = 0; j < firstClassCol; j++)
		{
			cout << colIterator->booking << " ";

			colIterator++;
		}
		cout << endl;

		rowIterator++;
	}

	rowIterator = economy;

	cout << "Economy Class\n-------------" << endl;
	for (int i = 0; i < economyRow; i++)
	{
		colIterator = *rowIterator;
		for (int j = 0; j < economyCol; j++)
		{
			cout << colIterator->booking << " ";

			colIterator++;
		}
		cout << endl;

		rowIterator++;
	}
	*/
	//THIS IS THE FUN ONE:
	//Find which class has more columns of Seats and set numOfCols to the greater value
	int numOfCols = 0;
	if (economyCols > firstClassCols)
		numOfCols = economyCols + 2;
	else
		numOfCols = firstClassCols + 2;
	if (numOfCols < 13)
		numOfCols = 15;
	//Determine whether the number of columns is odd and call the appropriate function
	if (numOfCols % 2 == 1)
		printOddNose(numOfCols);
	else
		printEvenNose(numOfCols);

	//Determine where the wings will be placed and set wingPlacement to that value
	int wingPlacement = 0;
	wingPlacement = findWingPlacement();

	//Print the fuselage
	printFuselage(wingPlacement, numOfCols);
}

/*
	"Ask if the user wants first class or economy class.
	 Ask for the Row and Column they want.
	 If the seat was not booked, book it. Otherwise, inform the user is booked."
*/
void Plane::bookASeat()
{

}


void Plane::clearASeat()
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
        clearASeat();
        }
        
}


void Plane::emptyPlane()
{
    /*
     • clean all seats on the plane and put it back to empty
     */
	Seat **rowIterator = firstClass;
	Seat *colIterator = *rowIterator;
	for (int i = 0; i < firstClassRows; i++)
	{
		colIterator = *rowIterator;
		for (int j = 0; j < firstClassCols; j++)
		{
			colIterator->status = '-';
			colIterator->isBooked = false;

			colIterator++;
		}

		rowIterator++;
	}

	rowIterator = economy;
	for (int i = 0; i < economyRows; i++)
	{
		colIterator = *rowIterator;
		for (int j = 0; j < economyCols; j++)
		{
			colIterator->status = '-';
			colIterator->isBooked = false;

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






/*
	HERE BEGINS THE FUN
*/
void Plane::printEvenNose(int numOfCols)
{
	int numOfRows = 0;
	numOfRows = numOfCols / 2;

	for (int i = 0; i < numOfRows; i++)
	{
		cout << "     "; //to leave space for the wings
		bool printedLeft = false;
		int leftIndex = numOfRows - i - 1;
		int distanceBetween = i * 2;

		for (int j = 0; j < numOfCols; j++)
		{
			if (printedLeft && (j / leftIndex == distanceBetween))
			{
				cout << "\\";
			}
			else if (!printedLeft && (j == leftIndex))
			{
				cout << "/";
			}
			else
			{
				cout << " ";
			}
		}

		cout << endl;
	}
}

void Plane::printOddNose(int numOfCols)
{
	int numOfRows = 0;
	numOfRows = numOfCols / 2 + 1;

	for (int i = 0; i < numOfRows; i++)
	{
		cout << "     "; //to leave space for the wings

		bool printedLeft = false;
		int leftIndex = numOfRows - i - 1;
		int distanceBetween = 2 * (i - 1) + 1;

		for (int j = 0; j < numOfCols; j++)
		{
			if ((i == 0) && (j == (numOfCols / 2)))
			{
				cout << "^";
			}
			else if ((i != 0) && printedLeft && (j / leftIndex == distanceBetween))
			{
				cout << "\\";
			}
			else if ((i != 0) && !printedLeft && (j == leftIndex))
			{
				cout << "/";
			}
			else
			{
				cout << " ";
			}

			cout << endl;
		}
	}
}

int Plane::findWingPlacement()
{
	return (firstClassRows + economyRows) / 2;
}

void Plane::printFuselage(int wingPlacement, int numOfCols)
{
	Seat **rowIterator = firstClass;
	Seat *colIterator = *rowIterator;
	int wingCounter = 0;

	cout << "     | First Class";
	for (int i = 0; i < numOfCols - 11; i++)
		cout << " ";
	cout << " |";

	for (int i = 0; i < firstClassRows; i++)
	{
		if (wingCounter == wingPlacement)
		{
			cout << "-----| ";
		}
		else
		{
			cout << "     | ";
		}

		colIterator = *rowIterator;
		for (int j = 0; j < firstClassCols; j++)
		{
			cout << colIterator->status << " ";

			colIterator++;
		}
		cout << endl;

		rowIterator++;

		if (wingCounter == wingPlacement)
		{
			cout << " |-----";
		}
		else
		{
			cout << " |-----";
		}
		wingCounter++;
	}

	rowIterator = economy;

	cout << "     | EconomyClass";
	for (int i = 0; i < numOfCols - 11; i++)
		cout << " ";
	cout << " |";

	for (int i = 0; i < economyRows; i++)
	{
		if (wingCounter == wingPlacement)
		{
			cout << "-----| ";
		}
		else
		{
			cout << "     | ";
		}

		colIterator = *rowIterator;
		for (int j = 0; j < economyCols; j++)
		{
			cout << colIterator->status << " ";

			colIterator++;
		}
		cout << endl;

		rowIterator++;

		if (wingCounter == wingPlacement)
		{
			cout << " |-----";
		}
		else
		{
			cout << " |-----";
		}
		wingCounter++;
	}
}