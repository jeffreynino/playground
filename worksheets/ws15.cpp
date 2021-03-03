// Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 13
// Description: multiplication calculator
// Input: two numbers
// Output: result of multiplying the numbers

#include <iostream>

using namespace std;

void readValues(double&,double&);
double multiply(double,double);

int main(){
	double readValue1;
	double readValue2;
	
	readValues(readValue1,readValue2);

	cout << readValue1 << " * " << readValue2
	     << " = " << multiply(readValue1,readValue2) << endl;
}

void readValues (double& x, double& y){
	cout << "Enter two numbers ";
	cin >> x >> y;
}

double multiply (double x, double y){
	double z;
	z = x * y;
	return z;
}
