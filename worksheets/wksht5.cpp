// Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 5 Homework
// reads in an angle in degrees, and computes sin and cos of angle
// conversion to radians and compute sin and cos
// the sin and cos of given degree

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double degrees; // defined degree
	const double pi = 3.14159; // constant pi
	
	cout << "Enter an angle value, in degrees: ";
	cin >> degrees; // input from keyboard

	double radians = degrees * (pi/180); // conversion to radians
	double x = sin(radians); // compute for sin
	double y = cos(radians); // compute fro cos

	cout << "sin ( " << degrees << " ) = " << x << endl;
	cout << "cos ( " << degrees << " ) = " << y << endl;
}
