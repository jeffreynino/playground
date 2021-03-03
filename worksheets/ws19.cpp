#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int rows = 10;
const int columns = 7;
void rowSumCalculator(int myArray[][10],int rowCount,int colCount);
void openFile(ifstream&, string);
int main(){
	ifstream infile;
	string prompt;
	openFile(infile, prompt);
	int myArray[columns][rows];
	for(int i=0; i<columns;i++){
		for(int j=0;j<rows;j++){
			infile >> myArray[i][j];
		}
	}
	rowSumCalculator(myArray,rows,columns);
}
void openFile(ifstream& infile, string prompt){
	do{
		cout << "Enter file to process: ";
		cin >> prompt;
		infile.open(prompt.c_str());
		infile.is_open();
		if (infile.is_open()==false){
			cout << "Error - \"" << prompt
			     << "\" did not open" << endl;
		}
	}while (infile.is_open()==false);
}
void rowSumCalculator(int myArray[][10],int rowCount,int colCount){
	for(int i=0;i<colCount;i++){
		int sum=0;
		for(int j=0;j<rowCount;j++){
			cout << right << setw(4) << myArray[i][j];
			cout << " ";
			sum +=myArray[i][j];
		}
		cout << " = " << right << setw(4) << sum << endl;
	}
}

