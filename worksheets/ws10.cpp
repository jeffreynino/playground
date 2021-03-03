// Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 10 Homework
// write hello five times using different loops
// input a for loop, a while loop, and a do while loop
// output the kind of loop, then hello five times
#include <iostream>

using namespace std;

int main(){
	cout << "for loop" << endl;
	for (int i=0; i<5; i++){
		cout << "hello ";
	}
	cout << endl;
	cout << endl;
	int wloop=0;	//while loop int
	int dwloop=0;	//do while loop int
	cout << "while loop" << endl;
	while (wloop < 5){
		wloop++;
		cout << "hello ";
	}
	cout << endl;
	cout << endl;
	cout << "do while loop" << endl;
	do {
		dwloop++;
		cout << "hello ";
	} while (dwloop < 5);
	cout << endl;
}
