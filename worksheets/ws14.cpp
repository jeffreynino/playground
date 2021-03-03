#include <iostream>

using namespace std;

double circle(double);

int main(){
	double radius;
	cout << "Enter radius: ";
	cin >> radius;
	cout << "Circumference = " << circle(radius) << endl;
}

double circle(double x){
	double pi = 3.14159;
	x = x*pi*2;
	return x;
}


