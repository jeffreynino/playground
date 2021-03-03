#include <iostream>
#include <string>

using namespace std;

int main(){

	int input;
	string month;
	cin >> input;

	while (cin) {
		switch (input){
			case 1: month = "January"; break;
			case 2: month = "February"; break;
			case 3: month = "March"; break;
			case 4: month = "April"; break;
			case 5: month = "May"; break;
			case 6: month = "June"; break;
			case 7: month = "July"; break;
			case 8: month = "August"; break;
			case 9: month = "September"; break;
			case 10: month = "October"; break;
			case 11: month = "November"; break;
			case 12: month = "December"; break;
			default: month = "invalid";
			}
		cout << "The month you entered is " << month << endl;
		cin >> input;
	}
}

