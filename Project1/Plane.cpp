#include "Plane.h"

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
	if (economyCol > firstClassCol)
		numOfCols = economyCol + 2;
	else
		numOfCols = firstClassCol + 2;
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
	Seat *colIterator = *rowIterator;
	for (int i = 0; i < firstClassRow; i++)
	{
		colIterator = *rowIterator;
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
		colIterator = *rowIterator;
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
	return (firstClassRow + economyRow) / 2;
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

	for (int i = 0; i < firstClassRow; i++)
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
		for (int j = 0; j < firstClassCol; j++)
		{
			cout << colIterator->booking << " ";

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

	for (int i = 0; i < economyRow; i++)
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
		for (int j = 0; j < economyCol; j++)
		{
			cout << colIterator->booking << " ";

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