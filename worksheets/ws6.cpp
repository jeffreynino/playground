//Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 6 HW
// radius to circumference
// input radius
// output circumference
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double r;
	double pi=3.14159; // constant pi
	
	cout << fixed << showpoint;
	cout << setprecision(2); // setting radius precision to 2

	cout << "Enter the radius: ";
	cin >> r;

	double C=2*pi*r; // formula for circumference
	
	cout << fixed << showpoint;
	cout << setprecision(2); // setting circumference precision to 2
	
	cout << "Circumference of a circle with a radius of ";
        cout <<	r << " is " << C << endl;

}
