// Jeffrey Nino, 5005572268, CS135 Section 1004, Assignment 2
// Calculation for time it takes for a rock to hit lava
// input h and iV and use formulas to calculate fV and time
// fV and time

#include <iostream>
#include <cmath>	//new library to use sqrt and pow

using namespace std;

int main()
{
	double g=64.348118; // gravity
	double iV; // initial velocity variable
	double h; // height variable

	cout << "Welcome to the Bedrock Volcano Rock Drop" << endl;
	cout << "****************************************" << endl;
	cout << "Distance from volcano rim to lava(ft): ";
	cin >> h;	// first input from keyboard for height
	cout << "Inital velocity (ft/sec): ";
	cin >> iV;	// second input from keyboard for initial velocity

	double fV;
	fV = sqrt(pow(iV,2.0)+g*h); // formula for final velocity
	
	double t;
	t=(fV-iV)/(0.5*g); // formula for time
	
	cout << "Final velocity: " << fV << " feet/second" << endl;
	cout << "Time to ground: " << t << " seconds" << endl;
	cout << "Thank you for playing" << endl;
}
