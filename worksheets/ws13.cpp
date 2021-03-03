// Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 13
// Description: writes name a number amount of times
// Input: name and number
// Output: the name a number of times

#include <iostream>
#include <string>

using namespace std;

void writeName (int, string);

int main(){
	int x;
	string y;

	cout << "Enter a number and a name: ";
	cin >> x >> y;

	writeName (x,y);
	cout << endl;
}

void writeName (int number, string name){
	while (number > 0){
		number--;
		cout << name << " ";
	}
}
