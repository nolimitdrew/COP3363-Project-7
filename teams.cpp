/* Name: Andrew Stade
Date: 4/23/2019
Section: 0004
Assignment: Homework #7 (NFL team records)
Due Date: 4/26/2019
About this project: To gain experience with using an array of structures, 
as well as with dynamic allocation of an array. 
This program provides further practice in file input, as well.
Assumptions: The user will only input variables.

All work below was performed by Andrew Stade */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

struct teamInfo
{
	int size;
	string teamname;
	int wins;
	int losses;
	int playoffs;
} ;

void menu();
void Print(ifstream & in1, teamInfo arr[], int size);



int main()
{
	char ofilename[25];
	ifstream in1;
	int select;
	int size = 0;
	int wins2 = 0;
	int limit = 0;
	int diff;

	do
	{
		in1.clear(); // Clears the input, allows for multiple program trials
	
		cout << "Please enter the name of the input file." << endl;
		cout << "Filename: " ;
		cin >> ofilename; // Asks for a file to he input
		
		in1.open(ofilename);
		if (!in1) // Error checking
		{
			cout << "That is not a valid file. Try again!\n";
		}
	
	} while (!in1) ;
	
	in1 >> size;
	teamInfo * arr = new teamInfo[size]; // Copies the input data to our array
	
	Print(in1, arr, size); // Runs the "print" function
	
	in1.close();

	
	do
	{
		menu(); // Call for the menu function 
		cin >> select; // User selects a menu option
	
		if (select == 1)
		{
			cout << "\nTeam W-L:" << endl; // Outputs all team records
			for (int i = 0; i < size; i++)
			{
				cout << arr[i].teamname << ' '<< arr[i].wins << '-'
				<< arr[i].losses << endl;
			}
			
			cout << endl;
		}
	
		else if (select == 2)
		{
			cout << "\nShow teams with at least how many wins? --> " ;
			cin >> wins2; // Asks the user for the minimum amount of wins.
			
			for (int i = 0; i < size; i++)
			{
				if (arr[i].wins >= wins2) /* If a team has enough wins,
											then it will be output */
				{
					cout << arr[i].teamname << endl;
				}
			}
			cout << endl;
		}
		
		else if (select == 3)
		{
			cout << "\nPlayoff teams:" << endl;
			
			for (int i = 0; i < size; i++)
			{
				if (arr[i].playoffs == 1) /* If the teams that make playoffs
											it will be output */
				{	
					cout << arr[i].teamname ;
					cout << ", " ; // Cannot get the final comma to be skipped
				}
				
			} 
			cout << endl;
			cout << endl;
		}
		
		else if (select == 4) 
		{
			
			for (int i = 0; i < size; i++)
			{
				diff = arr[i].wins - arr[i].losses; // Formula for team diff.
				cout << arr[i].teamname << ' ' ;
				if (diff > 0) // This is to add a '+' to the positve numbers.
				{
					cout << "+" ;
					cout << diff << endl;
				}
				if (diff < 0) // This just outputs any negative numbers as is.
				{
					cout << diff << endl;
				}
			}
			cout << endl;
		}
		
		else if (select == 5) // Yeah, kinda lost on this one, Oh well.
		{
			cout << "\nSorry Michael, No extra credit for me. :( " << endl;
			cout << endl;
			
		}
		
		else if (select != 0) // Error checking (only for numbers)
		{
			cout << endl;
			cout << "Invalid Choice." << endl;
			cout << endl;
		}
		
	} while (select != 0) ;
	
	cout << "\nGoodbye!" << endl;
	cout << endl;
	
	return 0;
}



void menu() // main menu (in a function to make int main() more clean) 
{
	cout << "Select one of the following choices:" << endl;
	cout << "        1 - View team Win/Loss records" << endl;
	cout << "        2 - Show teams with at least x wins" << endl;
	cout << "        3 - List teams that made the playoffs" << endl;
	cout << "        4 - Print teams and their Win Loss Differentials" << endl;
	cout << "        5 - Sort teams by their Win Loss Differentials" << endl;
	cout << "        0 - Exit program" << endl;
	cout << "------------------------------------------" << endl;
	cout << "Choice: " ;
}

void Print(ifstream & in1, teamInfo arr[], int size) // Reads in data from the input file
{
	int i;
	
	for(int i = 0; i < size; i++)
	{
		getline(in1, arr[i].teamname, ',');
		in1 >> arr[i].wins;
		in1.get();		// Use .get() in order to skip the commas/whitespace
		in1 >> arr[i].losses;
		in1.get();
		in1 >> arr[i].playoffs;
		in1.get();
	}

}


