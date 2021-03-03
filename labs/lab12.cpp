#include <iostream>
#include <fstream>

using namespace std;

const int MAX_CLASS_SIZE = 30;

void printArray(int[], int);
void bubblesort(int[], int);

int main(int argc, char* argv[]){
	if (argc != 2){
		cout << "Error: invalid command line arguments." << endl;
		return 1;
	}

	ifstream fin;
	fin.open(argv[1]);

	if (!fin.is_open()){
		cout << "Error: unable to open input file." << endl;
		return 1;
	}

	int grades[MAX_CLASS_SIZE];
	int count = 0;

	while(fin >> grades[count]){
		count++;
	}

	cout << "List before sort:" << endl;
	printArray(grades, count);
	cout << endl;

	cout << "List after sort:" << endl;
	bubblesort(grades, count);
	printArray(grades, count);
	cout << endl;
}

void printArray(int x[MAX_CLASS_SIZE], int y){
	for (int j=0; j<y; j++){
		cout << x[j] << " ";
	}
	cout << endl;
}

void bubblesort(int x[MAX_CLASS_SIZE], int y){
	int temp;
	for (int i=0; i<y-1; i++){
		for (int o=0; o<y-i-1; o++){	
			if (x[o]<x[o+1]){
				temp = x[o+1];
				x[o+1] = x[o];
				x[o] = temp;
			}
		}
	}
}


