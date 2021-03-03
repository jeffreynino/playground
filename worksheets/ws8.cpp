// Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 8
// Reads in a letter and outputs grade range for that letter
// Input switch and cases for letters a-f, read in by char
// Output a value for the grade range of the read in case
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	char grade;
	
	cout << "Enter a letter grade: ";
	cin >> grade;

	switch (grade){
	
		case 'a':
		case 'A':

	cout << "Grade range is 90 - 100" << endl;
	break;

		case 'b':
		case 'B':

	cout << "Grade range is 80 - 89" << endl;
	break;
		
		case 'c':
		case 'C':

	cout << "Grade range is 70 - 79" << endl;
	break;

		case 'd':
		case 'D':

	cout << "Grade range is 60 - 69" << endl;
	break;

		case 'f':
		case 'F':
	
	cout << "Grade range is 50 - 59" << endl;
	break;

		default:

	cout << "Error - invalid letter grade" << endl;
	}
}
