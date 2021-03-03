// Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 11 Homework
// add two numbers, looping until two numbers are entered
// input: while loop for if cin fails
// output: an error message until two acceptable inputs are given

#include <iostream>

using namespace std;

int main(){

	double x; // input 1
	double y; // input 2
	cout << "Enter two numbers: ";
	cin >> x >> y;

	while (cin.fail() == true) {
		
		cin.clear(); // flush cin
		cin.ignore(10000,'\n'); // ignore previous inputs up to 10000
		cout << "Error - Enter the numbers again" << endl;

		cout << "Enter two numbers: "; //loop
		cin >> x >> y;

	}
	double z=x+y; // result of sum
	cout << x << " + " << y << " = " << z << endl;
}
