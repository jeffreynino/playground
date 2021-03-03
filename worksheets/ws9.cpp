// Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 9
// print out range of numbers starting at read input for a read input
// while loop to count every possible intger
// every possible int given the starting number and the amount counted

#include <iostream>

using namespace std;

int main(){
	
	int startingNumber;
	int numberCount;
	
	cout << "Enter the starting number: ";
	cin >> startingNumber;

	cout << "Enter how many numbers to print: ";
	cin >> numberCount;

	cout << startingNumber << " ";

	while (numberCount > 1){
		startingNumber+=1;
		cout << startingNumber << " ";
		numberCount--;
	}
	cout << endl;
}
