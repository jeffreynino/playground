// Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 7 Homework
// Input two variables and finding which of them is larger
// two numbers and two strings
// the largest numebr and the largest string
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float x;
	float y;

	cout << "Enter two numbers (double): ";
	cin >> x >> y;

	static_cast<double>(x);
	static_cast<double>(y);

	cout << "You entered " << x << " and " << y << endl;
	cout << "The largest is ";
		if (x > y)
			cout << x << endl;
		if (y > x)
			cout << y << endl;
	
	string boy;
	string girl;

	cout << "Enter two strings: ";
	cin >> boy >> girl;

	cout << "You entered \"" << boy
	     <<  "\" and \"" << girl << "\"" << endl;
	
	cout << "The largest is ";
		if (boy > girl)
			cout << "\"" << boy << "\"" << endl;
		if (girl > boy)
			cout << "\"" << girl << "\"" << endl;
}
