#include <iostream>
#include "Plane.cpp"
using namespace std;

int main()
{
	Plane COSC1430;
	char ch;
	//Cosmo's branch
	//Create an object named “COSC1430” of type Plane
	//o Make a loop that allow the user to continue using the program until the user chooses to exit
	//o Terminate the program.
	while (1 == 1)
	{
		cout << "Pick one of these options" << endl;
		cout << "1. Display all seat" << endl;
		cout << "2. Check a seat" << endl;
		cout << "3. Clear a seat" << endl;
		cout << "4. Book a seat" << endl;
		cout << "5. Empty all seat" << endl;
		cout << "6. Exit" << endl;
		cout << "input : ";
		cin >> ch;
		if (ch == '1')
		{
			COSC1430.showAllSeat();
		}
		else if (ch == '2')
		{
			COSC1430.checkASeat();
		}
		else if (ch == '3')
		{
			COSC1430.clearASeat();
		}
		else if (ch == '4')
		{
			COSC1430.bookASeat();
		}
		else if (ch == '5')
		{
			COSC1430.emptyPlane();
		}
		else if (ch == '6') //I added this to make it clearer how to exit and to allow for the user to retry if they accidentlly hit an invalid number - Alex
		{
			break;
		}
		else
		{
			cout << "That is not a possible selection. Please choose a number from 1 - 6." << endl; //I added this. See previous comment. - Alex
		}
	}
	return 0;
}