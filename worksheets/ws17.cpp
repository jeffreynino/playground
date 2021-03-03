// Jeffrey Nino, 5005572268, CS135 Section 1004, Worksheet 13
// Description: takes average of infile
// Input: infile
// Output: average of infile

#include <iostream>
#include <fstream>
using namespace std;
int main(){
	double x[100];
	double sum;
	ifstream inFile;
	inFile.open("wksheet17.txt");
	inFile.is_open();
	if(inFile.is_open()==false){
		cout << "Error - input file not detected" << endl;
		exit(0);
	}
	for (int i=0; i<100; i++){
		inFile >> x[i];
		sum +=x[i];
	}
	double average = sum/100;
	cout << "Average is " << average << endl;
}
